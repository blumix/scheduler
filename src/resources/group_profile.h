#ifndef GROUP_PROFILE_H
#define GROUP_PROFILE_H

#include <vector>
#include <string>
#include <QString>

class group_profile
{
public:
  group_profile (int id);

  int get_group_num () const
  {
    return m_group_num;
  }
  int get_group_id () const
  {
    return m_group_id;
  }
  int get_ed_year ()const
  {
    return m_ed_year;
  }
  int get_thread ()const
  {
    return m_thread;
  }
  void set_ed_year (int ed_year)
  {
    m_ed_year = ed_year;
  }
  void set_num (int num)
  {
    m_group_num = num;
  }
  void set_thread (int thread)
  {
    m_thread = thread;
  }
  std::vector<std::pair <QString, int>> &get_lessons()
  {
    return m_lessons;
  }
  const std::vector<std::pair <QString, int>> &get_lessons() const
  {
    return m_lessons;
  }
private:
  int m_group_id = -1;
  int m_group_num = 1;
  int m_ed_year = 1;
  int m_thread = 0;
  //just teacher ids
  std::vector<std::pair <QString, int>> m_lessons;//if you have the same lesson twice a week just put two same ids here
};

#endif // GROUP_PROFILE_H
