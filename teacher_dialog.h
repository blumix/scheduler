#ifndef TEACHER_DIALOG_H
#define TEACHER_DIALOG_H

#include <QDialog>

namespace Ui {
  class teacher_dialog;
}

class teacher_dialog : public QDialog
{
  Q_OBJECT

public:
  explicit teacher_dialog(QWidget *parent = 0);
  ~teacher_dialog();

private:
  Ui::teacher_dialog *ui;
};

#endif // TEACHER_DIALOG_H
