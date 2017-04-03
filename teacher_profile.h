#ifndef TEACHER_PROFILE_H
#define TEACHER_PROFILE_H

#include <QString>


class teacher_profile
{
public:
  teacher_profile();
  int get_id () {return m_teacher_id;}
  int get_subject_id () {return m_subject_id;}
  QString get_name () {return m_name;}
private:
  int m_teacher_id = 0;
  int m_subject_id = 0;
  QString m_name = {};
};

#endif // TEACHER_PROFILE_H
