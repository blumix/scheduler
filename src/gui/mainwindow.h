/// \file src/gui/mainwindow.h

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "src/resources/database.h"

#include <QMainWindow>
#include <memory>

class QStandardItemModel;

namespace Ui
{
class MainWindow;
}


class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow (QWidget *parent = 0);
  ~MainWindow();

private slots:
  void teacher_changed_clicked();
  void group_changed_clicked ();
  void fill_all_teachers_model();
  void fill_selected_model();
  void fill_groups_model ();
  void select_subj();
  void remove_subj();
  void run_calculation();
  void save();
  void load();

private:
  void reset_selection();
  void reset_models();

private:
  Ui::MainWindow *ui;
  std::unique_ptr<database> m_db;
  std::unique_ptr<QStandardItemModel> m_all_teachers_model;
  std::unique_ptr<QStandardItemModel> m_selected_model;
  std::unique_ptr<QStandardItemModel> m_groups_model;
};

#endif // MAINWINDOW_H
