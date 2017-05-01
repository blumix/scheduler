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
  m_groups_model = std::make_unique<QStandardItemModel> (this);

  if (!connect (ui->actionAdd_group_profile, SIGNAL (triggered()), this, SLOT (group_changed_clicked ()) ))
    qDebug() <<"connection failed!";
  if (!connect (ui->actionAdd_teacher_profile, SIGNAL (triggered()), this, SLOT (teacher_changed_clicked ()) ))
    qDebug() <<"connection failed!";
  if (!connect (ui->groups_button, SIGNAL (clicked ()), this, SLOT (group_changed_clicked ()) ))
    qDebug() <<"connection failed!";
  if (!connect (ui->teacher_button, SIGNAL (clicked()), this, SLOT (teacher_changed_clicked ()) ))
    qDebug() <<"connection failed!";

  ui->groups_tree->header()->hide();
  ui->groups_tree->setModel (m_groups_model.get ());
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::group_changed_clicked()
{
  group_dialog dlg (m_db.get (), this);
  dlg.exec ();
  fill_groups_model ();
}

void MainWindow::fill_groups_model()
{
  int cources = 0;
  for (const auto &val : m_db->m_groups->get_ids ())
    {
      if (cources < m_db->m_groups->get_data (val).get_cource ())
        {
          cources = m_db->m_groups->get_data (val).get_cource ();
        }
    }
  cources++;
  m_groups_model->clear();
  QStandardItem *parent_item = m_groups_model->invisibleRootItem();
  std::vector<QStandardItem *> cource_items;
  for (int i = 0; i < cources; i++)
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
      cource_items[group.get_cource ()]->appendRow (item);
    }
}


void MainWindow::teacher_changed_clicked()
{
  teacher_dialog dlg (m_db.get (), this);
  dlg.exec ();
}

