#include "group_dialog.h"
#include "ui_group_dialog.h"

#include <QStandardItemModel>




group_dialog::group_dialog(database *db, QWidget *parent) :
  QDialog(parent),
  ui(new Ui::group_dialog), m_db (db)
{
  ui->setupUi(this);

  m_model = std::make_unique<QStandardItemModel>(this);
  fill_the_model ();
  ui->treeView->setModel(m_model.get ());

  connect (ui->add_group_button, SIGNAL (clicked ()), this, SLOT(add_button_clicked ()));
  connect (ui->cource, SIGNAL (editingFinished ()), this, SLOT (course_changed ()));
  connect (ui->number, SIGNAL (editingFinished ()), this, SLOT (num_changed ()));
  connect (ui->tread, SIGNAL (editingFinished ()), this, SLOT (tread_changed ()));
  connect (ui->treeView->selectionModel (), SIGNAL (selectionChanged (const QItemSelection, const QItemSelection)),
           this, SLOT (selection_changed ()));
}

group_dialog::~group_dialog()
{
  delete ui;
}

void group_dialog::fill_the_model()
{
  int cources = 0;
  for (auto val : m_db->get_group_ids ())
    {
      if (cources < m_db->get_group (val).get_cource ())
        {
          cources = m_db->get_group (val).get_cource ();
        }
    }
  cources++;
  m_model->clear();
  QStandardItem *parent_item = m_model->invisibleRootItem();
  std::vector<QStandardItem *> cource_items;
  for (int i = 0; i < cources; i++)
    {
      QStandardItem *item = new QStandardItem();
      cource_items.push_back (item);
      item->setText (QString ("Course %1").arg (i));
      parent_item->appendRow (item);
    }
  for (auto val : m_db->get_group_ids ())
    {
      QStandardItem *item = new QStandardItem();
      auto group = m_db->get_group (val);
      item->setText (QString ("Group %1%2").arg (group.get_thread ()).arg (group.get_group_num ()));
      item->setData (QVariant (group.get_group_id ()));
      cource_items[group.get_cource ()]->appendRow (item);
    }
}

void group_dialog::add_button_clicked()
{
  m_db->add_new_group ();
  fill_the_model ();
}


void group_dialog::course_changed ()
{
  auto selected = ui->treeView->currentIndex ();
  QVariant data = m_model->data(selected, Qt::UserRole + 1);
  int group_id = data.toInt ();
  if (group_id < 0)
    return;

  auto &group = m_db->get_group (group_id);
  group.set_cource (ui->cource->value () > 0 ? ui->cource->value () : 0);
  fill_the_model ();
}


void group_dialog::num_changed ()
{
  auto selected = ui->treeView->currentIndex ();
  QVariant data = m_model->data(selected, Qt::UserRole + 1);
  int group_id = data.toInt ();
  if (group_id < 0)
    return;

  auto &group = m_db->get_group (group_id);
  group.set_num (ui->number->value () > 0 ? ui->number->value () : 0);
  fill_the_model ();
}

void group_dialog::tread_changed ()
{
  auto selected = ui->treeView->currentIndex ();
  QVariant data = m_model->data(selected, Qt::UserRole + 1);
  int group_id = data.toInt ();
  if (group_id < 0)
    return;

  auto &group = m_db->get_group (group_id);
  group.set_thread (ui->tread->value () > 0 ? ui->tread->value () : 0);
  fill_the_model ();
}



void group_dialog::selection_changed ()
{
  auto selected = ui->treeView->currentIndex ();
  QVariant data = m_model->data(selected, Qt::UserRole + 1);
  ui->formLayout->setEnabled (true);
  if (!data.isValid ())
    {
      ui->formLayout->setEnabled (false);
      return;
    }
  int group_id = data.toInt ();
  if (group_id < 0)
    return;

  auto group = m_db->get_group (group_id);
  ui->cource->setValue (group.get_cource ());
  ui->number->setValue (group.get_group_num ());
  ui->tread->setValue (group.get_thread ());
}
