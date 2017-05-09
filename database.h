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

  std::vector<std::vector<int>> m_result_schedule;
};

#endif // DATABASE_H
