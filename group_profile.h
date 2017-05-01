#ifndef GROUP_PROFILE_H
#define GROUP_PROFILE_H

#include <vector>


class group_profile
{
public:
  group_profile (int id);

  int get_group_num () const {return m_group_num;}
  int get_group_id () const {return m_group_id;}
  int get_cource ()const {return m_cource;}
  int get_thread ()const {return m_thread;}
  void set_cource (int course) {m_cource = course;}
  void set_num (int num) {m_group_num = num;}
  void set_thread (int thread) {m_thread = thread;}
  std::vector<int> &get_mutable_lessons() {return m_lessons_id;}
private:
  int m_group_id = -1;
  int m_group_num = 1;
  int m_cource = 0;
  int m_thread = 1;
  //just teacher ids
  std::vector<int> m_lessons_id;//if you have the same lesson twice a week just put two same ids here
};

#endif // GROUP_PROFILE_H
