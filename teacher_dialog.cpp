#include "teacher_dialog.h"
#include "ui_teacher_dialog.h"

teacher_dialog::teacher_dialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::teacher_dialog)
{
  ui->setupUi(this);
}

teacher_dialog::~teacher_dialog()
{
  delete ui;
}
