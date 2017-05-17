#ifndef TEACHER_PROFILE_H
#define TEACHER_PROFILE_H

#include <QString>


class teacher_profile
{
public:
  teacher_profile (int id);
  int get_id () const
  {
    return m_id;
  }
  QString get_name () const
  {
    return m_name;
  }
  const std::vector<QString> &get_subjects() const
  {
    return m_subjects;
  }

  std::vector<QString> &get_subjects()
  {
    return m_subjects;
  }
  void set_name (QString name)
  {
    m_name = name;
  }
private:
  int m_id = 0;
  std::vector<QString> m_subjects;
  QString m_name = {};
};

#endif // TEACHER_PROFILE_H
