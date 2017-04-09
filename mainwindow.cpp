#include "group_dialog.h"
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
  QStandardItem *item = new QStandardItem(QString("kostyan pidaras"));
  m_model->setItem(1, 0, item);
  ui->main_window_tableView->setModel (m_model.get ());

  if (!connect (ui->actionAdd_group_profile, SIGNAL (triggered()), this, SLOT (group_changed_clicked()) ))
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
