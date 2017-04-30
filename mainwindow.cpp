#include "group_dialog.h"
#include "teacher_dialog.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStandardItemModel>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  m_db = std::make_unique<database> ();
  m_model = std::make_unique<QStandardItemModel> (3,3);

  if (!connect (ui->actionAdd_group_profile, SIGNAL (triggered()), this, SLOT (group_changed_clicked ()) ))
    qDebug() <<"connection failed!";
  if (!connect (ui->actionAdd_teacher_profile, SIGNAL (triggered()), this, SLOT (teacher_changed_clicked ()) ))
    qDebug() <<"connection failed!";
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::group_changed_clicked()
{
  group_dialog dlg (m_db.get (), this);
  dlg.exec ();
}


void MainWindow::teacher_changed_clicked()
{
  teacher_dialog dlg (m_db.get (), this);
  dlg.exec ();
}

