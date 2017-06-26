#include "src/gui/group_dialog.h"
#include "src/gui/teacher_dialog.h"
#include "src/gui/mainwindow.h"
#include "ui_mainwindow.h"
#include "src/kernel/tree_solver.h"
#include "src/kernel/greedy_search_solution.h"

#include <iostream>
#include <QStandardItemModel>
#include <QDebug>

MainWindow::MainWindow (QWidget *parent) :
  QMainWindow (parent),
  ui (new Ui::MainWindow)
{
  ui->setupUi (this);
  m_db = std::make_unique<database> ();
  m_groups_model = std::make_unique<QStandardItemModel> (this);
  m_all_teachers_model = std::make_unique<QStandardItemModel> (this);
  m_selected_model = std::make_unique<QStandardItemModel> (this);

  ui->groups_tree->header()->hide();
  ui->groups_tree->setModel (m_groups_model.get ());

  ui->all_subjects->header()->hide();
  ui->all_subjects->setModel (m_all_teachers_model.get ());

  ui->selected_subjects->setModel (m_selected_model.get ());

  connect (ui->actionAdd_group_profile, SIGNAL (triggered()), this, SLOT (group_changed_clicked ()) );
  connect (ui->actionAdd_teacher_profile, SIGNAL (triggered()), this, SLOT (teacher_changed_clicked ()) );
  connect (ui->save, SIGNAL (triggered()), this, SLOT (save ()) );
  connect (ui->load, SIGNAL (triggered()), this, SLOT (load ()) );
  connect (ui->groups_button, SIGNAL (clicked ()), this, SLOT (group_changed_clicked ()) );
  connect (ui->teacher_button, SIGNAL (clicked()), this, SLOT (teacher_changed_clicked ()) );
  connect (ui->add_arrow, SIGNAL (clicked()), this, SLOT (select_subj ()));
  connect (ui->remove_arrow, SIGNAL (clicked()), this, SLOT (remove_subj ()));
  connect (ui->run_calculation, SIGNAL (clicked()), this, SLOT (run_calculation ()));

  connect (ui->groups_tree->selectionModel (), SIGNAL (selectionChanged (const QItemSelection, const QItemSelection)),
           this, SLOT (fill_selected_model ()));

}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::save ()
{
  m_db->save_to_sql_db();
}


void MainWindow::load ()
{
  m_db->load_from_sql_db();
  reset_models();
}


void MainWindow::group_changed_clicked()
{
  group_dialog dlg (m_db.get (), this);
  dlg.exec ();
  reset_models();
}


void MainWindow::reset_selection ()
{
  for (const auto &val : m_db->m_groups->get_ids ())
    {
      m_db->m_groups->get_data (val).get_subjects().clear ();
    }
}

void MainWindow::remove_subj ()
{
  auto selected = ui->all_subjects->currentIndex ();
  if (!selected.isValid ())
    return;

  auto selected_group = ui->groups_tree->currentIndex ();
  if (!selected_group.isValid ())
    return;
  QVariant data_group = m_groups_model->data (selected_group, Qt::UserRole + 1);
  int id_group = data_group.toInt ();
  if (id_group < 0)
    return;


  auto &subjects = m_db->m_groups->get_data (id_group).get_subjects();
  subjects.erase (subjects.begin () + selected.row ());
  fill_selected_model ();

}

void MainWindow::run_calculation ()
{
  // init tree_node vector
  std::vector<tree_node> input_vector;

  for (const auto &val : m_db->m_groups->get_ids ())
    {
      auto subjects = m_db->m_groups->get_data (val).get_subjects ();

      int subject_id = 0;
      for (const auto &subject : subjects)
        {
          int course_id = subject_id++;
          int group_id = m_db->m_groups->get_data (val).get_group_id ();
          int teacher_id = subject.second;
          tree_node curr_node (course_id, group_id, teacher_id);
          input_vector.push_back (curr_node);
        }
    }

  tree_solver solver;
  auto result = solver.calculate (input_vector);

  m_db->m_result_schedule = search_best_solution (result, m_db->m_groups->get_ids ().size ());

  m_db->export_results (ui->file_name->text ());
  qDebug() << "Succesfully calculated!";
}

void MainWindow::select_subj ()
{
  auto selected = ui->all_subjects->currentIndex ();
  if (!selected.isValid ())
    return;
  QVariant data = m_all_teachers_model->data (selected, Qt::UserRole + 1);
  int id = data.toInt ();
  if (id < 0)
    return;

  int row = selected.row ();

  const auto &id_data = m_db->m_teachers->get_data (id);
  QString str = id_data.get_name ();
  str += " (";
  str += id_data.get_subjects()[row];
  str += ")";

  auto selected_group = ui->groups_tree->currentIndex ();
  if (!selected_group.isValid ())
    return;
  QVariant data_group = m_groups_model->data (selected_group, Qt::UserRole + 1);
  int id_group = data_group.toInt ();
  if (id_group < 0)
    return;

  m_db->m_groups->get_data (id_group).get_subjects().push_back ({str, id});
  fill_selected_model ();
}

void MainWindow::fill_groups_model()
{
  int cources = 0;
  for (const auto &val : m_db->m_groups->get_ids ())
    {
      if (cources < m_db->m_groups->get_data (val).get_course ())
        {
          cources = m_db->m_groups->get_data (val).get_course ();
        }
    }
  m_groups_model->clear();
  QStandardItem *parent_item = m_groups_model->invisibleRootItem();
  std::vector<QStandardItem *> cource_items;
  for (int i = 1; i < cources + 1; i++)
    {
      QStandardItem *item = new QStandardItem();
      cource_items.push_back (item);
      item->setText (QString ("Course %1").arg (i));
      item->setFlags (Qt::ItemIsEnabled);
      parent_item->appendRow (item);
    }
  for (const auto &val : m_db->m_groups->get_ids ())
    {
      QStandardItem *item = new QStandardItem();
      auto group = m_db->m_groups->get_data (val);
      item->setText (QString ("Group %1%2").arg (group.get_thread ()).arg (group.get_group_num ()));
      item->setData (QVariant (group.get_group_id ()));
      cource_items[group.get_course () - 1]->appendRow (item);
    }
}


void MainWindow::fill_all_teachers_model()
{
  auto teachers = m_db->m_teachers.get ();
  m_all_teachers_model->clear();
  QStandardItem *parent_item = m_all_teachers_model->invisibleRootItem();
  for (const auto &elem : m_db->m_teachers->get_ids ())
    {
      QStandardItem *item = new QStandardItem();
      item->setText (teachers->get_data (elem).get_name ());
      item->setFlags (Qt::ItemIsEnabled);
      parent_item->appendRow (item);

      for (const auto &val : teachers->get_data (elem).get_subjects ())
        {
          QStandardItem *sub_item = new QStandardItem();
          sub_item->setText (val);
          sub_item->setData (QVariant (elem));
          item->appendRow (sub_item);
        }
    }
}


void MainWindow::fill_selected_model ()
{
  m_selected_model->clear();

  auto selected = ui->groups_tree->currentIndex ();
  if (!selected.isValid ())
    return;
  QVariant data = m_groups_model->data (selected, Qt::UserRole + 1);
  int group_id = data.toInt ();
  if (group_id < 0)
    return;


  QStandardItem *subj_parent_item = m_selected_model->invisibleRootItem();
  for (const auto &elem: m_db->m_groups->get_data (group_id).get_subjects ())
    {
      QStandardItem *item = new QStandardItem();
      item->setText (elem.first);
      item->setData (elem.second);
      subj_parent_item->appendRow (item);
    }
}



void MainWindow::reset_models()
{
  reset_selection ();
  fill_groups_model ();
  fill_all_teachers_model();
  fill_selected_model ();
}

void MainWindow::teacher_changed_clicked()
{
  teacher_dialog dlg (m_db.get (), this);
  dlg.exec ();
  reset_models();
}
