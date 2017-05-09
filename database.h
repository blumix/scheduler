#ifndef DATABASE_H
#define DATABASE_H

#include "group_profile.h"
#include "index_table.h"
#include "teacher_profile.h"

#include <map>
#include <vector>
#include <bits/unique_ptr.h>


class database
{
public:
  database();
  std::unique_ptr<index_table<group_profile>> m_groups;
  std::unique_ptr<index_table<teacher_profile>> m_teachers;

  std::vector<std::vector<std::pair<int,int>>> m_result_schedule;

  void export_results (QString filename);
};

#endif // DATABASE_H
