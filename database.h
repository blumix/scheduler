#ifndef DATABASE_H
#define DATABASE_H

#include "group_profile.h"
#include "index_table.h"
#include "teacher_profile.h"

#include <map>
#include <bits/unique_ptr.h>


class database
{
public:
  database();
  std::unique_ptr<index_table<group_profile>> m_groups;
  std::unique_ptr<index_table<teacher_profile>> m_teachers;
};

#endif // DATABASE_H
