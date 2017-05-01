#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "database.h"

#include <QMainWindow>
#include <memory>

class QStandardItemModel;

namespace Ui {
  class MainWindow;
}


class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
private slots:
  void teacher_changed_clicked();
  void group_changed_clicked ();
private:
  void fill_groups_model ();

  Ui::MainWindow *ui;
  std::unique_ptr<database> m_db;
  std::unique_ptr<QStandardItemModel> m_groups_model;
};

#endif // MAINWINDOW_H
