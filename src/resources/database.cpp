#include <QMessageBox>
#include <fstream>
#include <iostream>
#include "src/misc/common_defines.h"
#include "src/resources/database.h"
#include "src/resources/group_profile.h"


database::database()
{
  m_groups = std::make_unique<index_table<group_profile>> ();
  m_teachers = std::make_unique<index_table<teacher_profile>> ();

  m_result_schedule.resize (common_defines::all_timeslots);

}

static int callback (void *, int , char **, char **)
{
  return 0;
}

bool check_owerrite (const std::string& name)
{
  std::ifstream f(name.c_str());
  if (!f.good())
    return true;

  return QMessageBox::question ( nullptr, "Warning",
                                 "File already exists, do you whant to overwrite it?"
                                 , QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes;
}


void database::save_to_sql_db()
{
  sqlite3 *db;
  char *zErrMsg = 0;
  int rc;

  /* Open database */
  if (!check_owerrite ("schedule.db"))
    return;
  std::ofstream ofs;
  ofs.open("schedule.db", std::ofstream::out | std::ofstream::trunc);
  ofs.close();
  rc = sqlite3_open ("schedule.db", &db);
  if ( rc )
    {
      std::cout<<"Can't open database: "<<sqlite3_errmsg (db);
      return;
    }
  else
    std::cout<<"Opened database successfully\n";

  const char *sql_create = "CREATE TABLE IF NOT EXISTS GROUPS(ID INT PRIMARY KEY ,"\
                           " NUM INT ,"\
                           " ED_YEAR INT ,"\
                           " THREAD INT);";

  /* Execute SQL statement */
  rc = sqlite3_exec (db, sql_create, callback, 0, &zErrMsg);
  if ( rc != SQLITE_OK )
    {
      std::cout<<"SQL error: "<< zErrMsg;
      sqlite3_free (zErrMsg);
      return;
    }

  const char *sql_create_teachers = "CREATE TABLE IF NOT EXISTS TEACHERS(ID INT PRIMARY KEY ,"\
                           " NAME VARCHAR);";

  /* Execute SQL statement */
  rc = sqlite3_exec (db, sql_create_teachers, callback, 0, &zErrMsg);
  if ( rc != SQLITE_OK )
    {
      std::cout<<"SQL error: "<< zErrMsg;
      sqlite3_free (zErrMsg);
      return;
    }

  const char *sql_create_subjects = "CREATE TABLE IF NOT EXISTS SUBJECTS(ID INT,"\
                                    " NAME VARCHAR);";
  /* Execute SQL statement */
  rc = sqlite3_exec (db, sql_create_subjects, callback, 0, &zErrMsg);
  if ( rc != SQLITE_OK )
    {
      std::cout<<"SQL error: "<< zErrMsg;
      sqlite3_free (zErrMsg);
      return;
    }



  std::cout<<"Table created successfully\n";

  QString sql_req_str = get_sql_for_groups ();
  /* Create SQL statement */
  const char *sql_req = sql_req_str.toUtf8 ().data ();

  /* Execute SQL statement */
  rc = sqlite3_exec (db, sql_req, callback, 0, &zErrMsg);
  if ( rc != SQLITE_OK )
    {
      std::cout<<"SQL error: "<<zErrMsg;
      sqlite3_free (zErrMsg);
    }


  sql_req_str = get_sql_for_teachers ();
  /* Create SQL statement */
  const char *sql_req_teachers = sql_req_str.toUtf8 ().data ();

  /* Execute SQL statement */
  rc = sqlite3_exec (db, sql_req_teachers, callback, 0, &zErrMsg);
  if ( rc != SQLITE_OK )
    {
      std::cout<<"SQL error: "<<zErrMsg;
      sqlite3_free (zErrMsg);
    }

  for (const auto &elem : m_teachers->get_ids ())
    {
      sql_req_str = get_sql_for_subjects (m_teachers->get_data (elem));
      /* Create SQL statement */
      const char *sql_req_subjects = sql_req_str.toUtf8 ().data ();

      /* Execute SQL statement */
      rc = sqlite3_exec (db, sql_req_subjects, callback, 0, &zErrMsg);
      if ( rc != SQLITE_OK )
        {
          std::cout<<"SQL error: "<<zErrMsg;
          sqlite3_free (zErrMsg);
        }
    }

  fprintf (stdout, "Records created successfully\n");

  sqlite3_close (db);
}

void database::load_from_sql_db()
{
  m_groups = std::make_unique<index_table<group_profile>> ();
  m_teachers = std::make_unique<index_table<teacher_profile>> ();
  sqlite3 *db;
  char *zErrMsg = 0;
  int rc;
  /* Open database */
  rc = sqlite3_open ("schedule.db", &db);
  if ( rc )
    {
      std::cout<<"Can't open database: "<<sqlite3_errmsg (db);
      return;
    }

  std::cout<<"Opened database successfully\n";
  std::cout<<"Reading Groups..\n.";
/// gorups
  /* Create SQL statement */
  const char *sql_groups = "SELECT * from GROUPS";

  /* Execute SQL statement */
  rc = sqlite3_exec (db, sql_groups, callback_for_group, static_cast<void*>(m_groups.get ()), &zErrMsg);
  if ( rc != SQLITE_OK )
    {
      std::cout<<"SQL error: "<<zErrMsg;
      sqlite3_free (zErrMsg);
    }
///teachers
  std::cout<<"Reading Teachers...\n";
  /* Create SQL statement */
  const char *sql_teachers = "SELECT * from TEACHERS";

  /* Execute SQL statement */
  rc = sqlite3_exec (db, sql_teachers, callback_for_teacher, static_cast<void*>(m_teachers.get ()), &zErrMsg);
  if ( rc != SQLITE_OK )
    {
      std::cout<<"SQL error: "<<zErrMsg;
      sqlite3_free (zErrMsg);
    }

///subjects
  std::cout<<"Reading Subjects\n";

  for (const auto &id : m_teachers->get_ids ())
    {
      /* Create SQL statement */
      std::string sql_subjects = std::string ("SELECT * from SUBJECTS WHERE ID=") + std::to_string (id) + ";";

      /* Execute SQL statement */
      rc = sqlite3_exec (db, sql_subjects.c_str (), callback_for_subjects, static_cast<void*>(&m_teachers->get_data (id)), &zErrMsg);
      if ( rc != SQLITE_OK )
        {
          std::cout<<"SQL error: "<<zErrMsg;
          sqlite3_free (zErrMsg);
        }
    }

  std::cout<<"Operation done successfully\n";
  sqlite3_close (db);
}

QString database::get_sql_for_groups()
{
  QString in_res = "INSERT INTO GROUPS (ID,NUM,ED_YEAR,THREAD)";
  QString ret;
  for (const auto &elem : m_groups->get_ids())
    {
      ret += in_res;
      auto &data = m_groups->get_data (elem);
      QString val = "VALUES (";
      val += QString::number (data.get_group_id ()) + ", ";
      val += QString::number (data.get_group_num ()) + ", ";
      val += QString::number (data.get_ed_year ()) + ", ";
      val += QString::number (data.get_thread ()) + ");";

      ret += val;
    }
  return ret;
}

QString database::get_sql_for_teachers ()
{
  QString in_res = "INSERT INTO TEACHERS (ID,NAME)";
  QString ret;
  for (const auto &elem : m_teachers->get_ids())
    {
      ret += in_res;
      auto &data = m_teachers->get_data (elem);
      QString val = "VALUES (";
      val += QString::number (data.get_id ()) + ", '";
      val += data.get_name () + "');";
      ret += val;
    }
  return ret;
}

QString database::get_sql_for_subjects (const teacher_profile &data)
{
  QString in_res = "INSERT INTO SUBJECTS (ID,NAME)";
  QString ret;
  for (const auto &elem : data.get_subjects ())
    {
      ret += in_res;
      QString val = "VALUES (";
      val += QString::number (data.get_id ()) + ", '";
      val += elem + "');";
      ret += val;
    }
  return ret;
}


void database::export_results (QString filename)
{
  std::ofstream myfile;
  myfile.open (filename.toUtf8 ());
  if (!myfile.is_open ())
    return;
  myfile<<"time;group;lesson\n";

  int time_num = 0;
  for (const auto &time : m_result_schedule)
    {
      for (const auto &group : time)
        {
          const auto &data = m_groups->get_data (group.first);
          myfile<<time_num                                ;
          myfile<<";"                                     ;
          myfile<<data.get_ed_year ()                      ;
          myfile<<data.get_thread ()                      ;
          myfile<<data.get_group_num ()                   ;
          myfile<<";"                                     ;
          myfile<<data.get_lessons ()[group.second].second;
          myfile<<"\n"                                    ;
        }
      time_num++;
    }
  myfile.close();
}

int callback_for_group (void *v_groups, int argc, char **argv, char **)
{
  index_table<group_profile>* groups = static_cast<index_table<group_profile>*> (v_groups);
  if (!groups)
    return 0;

  //  id      0
  //  num     1
  //  ed_year 2
  //  tread   3

  if (argc < 4)
    return 0;

  int id = argv[0] ? atoi (argv [0]) : -1;
  if (id < 0)
    return 0;
  int res = groups->create_new (id);
  if (res < 0)
    return 0;

  auto &data = groups->get_data (res);

  data.set_num (argv[1] ? atoi (argv[1]) : 1);
  data.set_ed_year (argv[2] ? atoi (argv[2]) : 1);
  data.set_thread (argv[3] ? atoi (argv[3]) : 0);
  return 0;
}

int callback_for_teacher (void *v_teachers, int argc, char **argv, char **)
{
  index_table<teacher_profile>* teachers = static_cast<index_table<teacher_profile>*> (v_teachers);
  if (!teachers)
    return 0;

  //  id  0
  //  name 1

  if (argc < 2)
    return 0;

  int id = argv[0] ? atoi (argv [0]) : -1;
  if (id < 0)
    return 0;
  int res = teachers->create_new (id);
  if (res < 0)
    return 0;

  auto &data = teachers->get_data (res);

  data.set_name (QString::fromUtf8 (argv[1]));
  return 0;
}


int callback_for_subjects(void *teacher, int argc, char **argv, char **)
{
  teacher_profile *data = static_cast<teacher_profile *> (teacher);

  if (!data)
    return 0;

  // teacher id   0
  // subject      1

  if (argc < 2)
    return 0;

  data->get_subjects ().push_back (QString::fromUtf8 (argv[1]));
  return 0;
}
