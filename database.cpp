#include "database.h"

database::database()
{
  m_groups = std::make_unique<index_table<group_profile>> ();
  m_teachers = std::make_unique<index_table<teacher_profile>> ();
}
