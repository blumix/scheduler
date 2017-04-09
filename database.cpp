#include "database.h"

database::database()
{

}

int database::add_new_group()
{
  int id = m_group_id;
  m_groups.insert(std::pair<int, group_profile>(m_group_id, group_profile(m_group_id)));
  m_group_id++;
  return id;
}

group_profile &database::get_group(int group_id)
{
  return m_groups.at (group_id);
}

std::vector<int> database::get_group_ids()
{
  std::vector<int> ret;
  for (auto val : m_groups)
    ret.push_back (val.first);
  return ret;
}
