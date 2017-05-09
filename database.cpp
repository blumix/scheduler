#include "database.h"
#include "kernel/common_defines.h"

database::database()
{
  m_groups = std::make_unique<index_table<group_profile>> ();
  m_teachers = std::make_unique<index_table<teacher_profile>> ();

  m_result_schedule.resize (common_defines::all_timeslots);

  for (int idx = 0; idx < common_defines::all_timeslots; idx++)
    m_result_schedule[idx] = std::vector<int> (m_groups->get_ids ().size (), -1);
}
