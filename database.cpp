#include "database.h"
#include "kernel/common_defines.h"
#include <iostream>
#include <fstream>
#include "group_profile.h"

database::database()
{
  m_groups = std::make_unique<index_table<group_profile>> ();
  m_teachers = std::make_unique<index_table<teacher_profile>> ();

  m_result_schedule.resize (common_defines::all_timeslots);

//  for (int idx = 0; idx < common_defines::all_timeslots; idx++)
//    m_result_schedule[idx] = std::vector<int> (m_groups->get_ids ().size (), -1);
}

void database::export_results(QString filename)
{
  std::ofstream myfile;
  myfile.open (filename.toAscii ());
  if (!myfile.is_open ())
    return;
  myfile<<"time;group;lesson\n";

  int time_num = 0;
  for (const auto &time : m_result_schedule)
    {
      for (const auto &group : time)
        {
          const auto &data = m_groups->get_data (group.first);
          myfile<<time_num                                ;
          myfile<<";"                                     ;
          myfile<<data.get_course ()                      ;
          myfile<<data.get_thread ()                      ;
          myfile<<data.get_group_num ()                   ;
          myfile<<";"                                     ;
          myfile<<data.get_lessons ()[group.second].second;
          myfile<<"\n"                                    ;
        }
      time_num++;
    }
  myfile.close();
}
