#ifndef GROUP_PROFILE_H
#define GROUP_PROFILE_H


class group_profile
{
public:
  group_profile();
//  ~group_profile();

  int get_group_num (){return m_group_num;}
  int get_group_id () {return m_group_id;}
  int get_cource (){return m_cource;}
  int get_thread (){return m_thread;}
private:
  int m_group_id = 0;
  int m_group_num = 0;
  int m_cource = 0;
  int m_thread = 0;
};

#endif // GROUP_PROFILE_H
