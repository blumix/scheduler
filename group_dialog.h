#ifndef GROUP_DIALOG_H
#define GROUP_DIALOG_H

#include "database.h"

#include <QDialog>

namespace Ui {
  class group_dialog;
}

class group_dialog : public QDialog
{
  Q_OBJECT

public:
  explicit group_dialog(database *db, QWidget *parent = 0);
  ~group_dialog();
public slots:
  void add_button_clicked ();

private:
  Ui::group_dialog *ui;
  database *m_db;
};

#endif // GROUP_DIALOG_H
