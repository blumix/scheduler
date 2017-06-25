/// \file src/resources/database.h

#ifndef DATABASE_H
#define DATABASE_H

#include "src/resources/group_profile.h"
#include "src/misc/index_table.h"
#include "src/resources/teacher_profile.h"

#include <map>
#include <vector>
#include <bits/unique_ptr.h>


#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>


int callback_for_group   (void *v_groups, int argc, char **argv, char **);
int callback_for_teacher (void *v_teachers, int argc, char **argv, char **);
int callback_for_subjects (void *teacher, int argc, char **argv, char **);


class database
{
public:
  database();
  std::unique_ptr<index_table<group_profile>> m_groups;
  std::unique_ptr<index_table<teacher_profile>> m_teachers;

  std::vector<std::vector<std::pair<int,int>>> m_result_schedule;

  void save_to_sql_db ();
  void load_from_sql_db ();

  std::string get_sql_for_groups();
  std::string get_sql_for_teachers();
  std::string get_sql_for_subjects (const teacher_profile &data);

  void export_results (QString filename);
private:
};

#endif // DATABASE_H
