#ifndef GROUP_DIALOG_H
#define GROUP_DIALOG_H

#include "database.h"

#include <QDialog>
#include <QStandardItemModel>

#include <bits/unique_ptr.h>

namespace Ui {
  class group_dialog;
}

class group_dialog : public QDialog
{
  Q_OBJECT

public:
  explicit group_dialog(database *db, QWidget *parent = 0);
  ~group_dialog();

private slots:
  void add_button_clicked ();
  void course_changed();
  void selection_changed();
  void num_changed();
  void thread_changed();

private:
  void fill_the_model();

private:
  Ui::group_dialog *ui;
  database *m_db;
  std::unique_ptr<QStandardItemModel> m_model;
};

#endif // GROUP_DIALOG_H
