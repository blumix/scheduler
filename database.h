#ifndef DATABASE_H
#define DATABASE_H

#include "group_profile.h"

#include <map>

class database
{
public:
  database();
  int add_new_group ();
  group_profile &get_group (int group_id);
  std::vector<int> get_group_ids ();
private:
  std::map<int, group_profile> m_groups;
  int m_group_id = 0;
};

#endif // DATABASE_H
