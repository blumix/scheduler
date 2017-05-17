/// \file src/gui/teacher_dialog.h

#ifndef TEACHER_DIALOG_H
#define TEACHER_DIALOG_H

#include "src/resources/database.h"

#include <QDialog>
#include <QStandardItemModel>

namespace Ui
{
class teacher_dialog;
}

class teacher_dialog : public QDialog
{
  Q_OBJECT

public:
  explicit teacher_dialog (database *db,QWidget *parent = 0);
  ~teacher_dialog();

private slots:
  void fill_name_model();
  void fill_subj_model (int t_id=-1);
  void add_name();
  void add_subj();
  void update_models();
  void save_new_name (QStandardItem *item);
  void save_new_subj (QStandardItem *item);
  void remove_subj();
  void remove_name();

private:
  Ui::teacher_dialog *ui;
  database *m_db;

  std::unique_ptr<QStandardItemModel> m_name_model;
  std::unique_ptr<QStandardItemModel> m_subj_model;

};

#endif // TEACHER_DIALOG_H
