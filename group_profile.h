#ifndef GROUP_PROFILE_H
#define GROUP_PROFILE_H

#include <vector>


class group_profile
{
public:
  group_profile(int id);
//  ~group_profile();

  int get_group_num (){return m_group_num;}
  int get_group_id () {return m_group_id;}
  int get_cource (){return m_cource;}
  int get_thread (){return m_thread;}
  std::vector<int> &get_mutable_cources() {return m_lessons_id;}
private:
  int m_group_id = -1;
  int m_group_num = 0;
  int m_cource = 0;
  int m_thread = 0;
  std::vector<int> m_lessons_id;
};

#endif // GROUP_PROFILE_H
