#include "src/resources/database.h"
#include "src/misc/common_defines.h"
#include <iostream>
#include <fstream>
#include "src/resources/group_profile.h"

database::database()
{
  m_groups = std::make_unique<index_table<group_profile>> ();
  m_teachers = std::make_unique<index_table<teacher_profile>> ();

  m_result_schedule.resize (common_defines::all_timeslots);

}

static int callback(void *, int argc, char **argv, char **azColName){
   for(int i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

void database::save_to_sql_db()
{
  sqlite3 *db;
  char *zErrMsg = 0;
  int rc;

  /* Open database */
  rc = sqlite3_open("schedlue.db", &db);
  if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return;
    }else{
      fprintf(stderr, "Opened database successfully\n");
    }

  const char *sql_create = "CREATE TABLE IF NOT EXISTS GROUPS(ID INT PRIMARY KEY ,"\
        " NUM INT ,"\
        " ED_YEAR INT ,"\
        " THREAD INT);";

     /* Execute SQL statement */
     rc = sqlite3_exec(db, sql_create, callback, 0, &zErrMsg);
     if( rc != SQLITE_OK ){
     fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
     }else{
        fprintf(stdout, "Table created successfully\n");
     }

  std::string sql_req_str = get_sql_for_groups ();
  /* Create SQL statement */
  const char *sql_req = sql_req_str.c_str ();

  /* Execute SQL statement */
  rc = sqlite3_exec(db, sql_req, callback, 0, &zErrMsg);
  if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
    }else{
      fprintf(stdout, "Records created successfully\n");
    }
  sqlite3_close(db);
}

void database::load_from_sql_db()
{
  m_groups = std::make_unique<index_table<group_profile>> ();
  m_teachers = std::make_unique<index_table<teacher_profile>> ();
  sqlite3 *db;
  char *zErrMsg = 0;
  int rc;
  /* Open database */
  rc = sqlite3_open("schedlue.db", &db);
  if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return;
    }else{
      fprintf(stderr, "Opened database successfully\n");
    }

  /* Create SQL statement */
  const char *sql = "SELECT * from GROUPS";

  /* Execute SQL statement */
  rc = sqlite3_exec(db, sql, callback_for_group, (void*)m_groups.get (), &zErrMsg);
  if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
    }else{
      fprintf(stdout, "Operation done successfully\n");
    }
  sqlite3_close(db);
}

std::string database::get_sql_for_groups()
{
  std::string in_res = "INSERT INTO GROUPS (ID,NUM,ED_YEAR,THREAD)";
  std::string ret;
  for (const auto &elem : m_groups->get_ids())
    {
      ret += in_res;
      auto &data = m_groups->get_data(elem);
      std::string val = "VALUES (";
      val += std::to_string (data.get_group_id ()) + ", ";
      val += std::to_string (data.get_group_num ()) + ", ";
      val += std::to_string (data.get_course ()) + ", ";
      val += std::to_string (data.get_thread ()) + ");";

      ret += val;
    }
  return ret.c_str ();
}


void database::export_results(QString filename)
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
          myfile<<data.get_course ()                      ;
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

int callback_for_group(void *v_groups, int argc, char **argv, char **)
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

  int id = argv[0] ? atoi(argv [0]) : -1;
  if (id < 0)
    return 0;
  int res = groups->create_new (id);
  if (res < 0)
    return 0;

  auto &data = groups->get_data (res);

  data.set_num (argv[1] ? atoi(argv[1]) : 1);
  data.set_cource (argv[2] ? atoi(argv[2]) : 1);
  data.set_thread (argv[3] ? atoi(argv[3]) : 0);
  return 0;
}
