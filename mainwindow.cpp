#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  m_model = std::make_unique<QStandardItemModel> (3,3);
  QStandardItem *item = new QStandardItem(QString("kostyan pidaras"));
  m_model->setItem(1, 0, item);
  ui->main_window_tableView->setModel (m_model.get ());
}

MainWindow::~MainWindow()
{
  delete ui;
}
