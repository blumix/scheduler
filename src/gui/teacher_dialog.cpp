#include "teacher_dialog.h"
#include "ui_teacher_dialog.h"

teacher_dialog::teacher_dialog (database *db, QWidget *parent) :
  QDialog (parent),
  ui (new Ui::teacher_dialog), m_db (db)
{
  ui->setupUi (this);
  m_name_model = std::make_unique<QStandardItemModel> (this);
  m_subj_model = std::make_unique<QStandardItemModel> (this);

  fill_name_model ();
  fill_subj_model (-1);

  ui->teachers_list->setModel (m_name_model.get ());
  ui->subjects_list->setModel (m_subj_model.get ());


  connect (ui->add_t_button, SIGNAL (clicked ()), this, SLOT (add_name ()));
  connect (ui->add_s_button, SIGNAL (clicked ()), this, SLOT (add_subj ()));
  connect (ui->remove_t_button, SIGNAL (clicked ()), this, SLOT (remove_name ()));
  connect (ui->remove_s_button, SIGNAL (clicked ()), this, SLOT (remove_subj ()));
  connect (ui->teachers_list->selectionModel (), SIGNAL (selectionChanged (const QItemSelection, const QItemSelection)),
           this, SLOT (update_models ()));
  connect (m_name_model.get (), SIGNAL (itemChanged (QStandardItem *)), this, SLOT (save_new_name (QStandardItem *)));
  connect (m_subj_model.get (), SIGNAL (itemChanged (QStandardItem *)), this, SLOT (save_new_subj (QStandardItem *)));

}

teacher_dialog::~teacher_dialog()
{
  delete ui;
}

void teacher_dialog::save_new_name (QStandardItem *item)
{
  int ind = item->data ().toInt ();
  m_db->m_teachers->get_data (ind).set_name (item->data (Qt::EditRole).toString ());
}

void teacher_dialog::save_new_subj (QStandardItem *item)
{
  auto selected = ui->teachers_list->currentIndex ();
  if (!selected.isValid ())
    return;
  int idx = m_name_model->data (selected, Qt::UserRole + 1).toInt ();
  int row = item->row ();
  m_db->m_teachers->get_data (idx).get_subjects ()[row] =  item->data (Qt::EditRole).toString ();
}

void teacher_dialog::update_models ()
{
  auto selected = ui->teachers_list->currentIndex ();
  if (!selected.isValid ())
    return;
  QVariant data = m_name_model->data (selected, Qt::UserRole + 1);
  fill_subj_model (data.toInt ());
}



void teacher_dialog::fill_name_model ()
{
  m_name_model->clear();
  QStandardItem *name_parent_item = m_name_model->invisibleRootItem();
  for (const auto &elem: m_db->m_teachers->get_ids ())
    {
      const auto &val = m_db->m_teachers->get_data (elem);
      QStandardItem *item = new QStandardItem();
      item->setText (QString ("%1").arg (val.get_name ()));
      item->setData (QVariant (val.get_id ()));
      name_parent_item->appendRow (item);
    }
}


void teacher_dialog::fill_subj_model (int t_id)
{
  m_subj_model->clear();
  if (t_id == -1 || !m_db->m_teachers->is_id_valid (t_id))
    return;
  QStandardItem *subj_parent_item = m_subj_model->invisibleRootItem();
  for (const auto &elem: m_db->m_teachers->get_data (t_id).get_subjects ())
    {
      QStandardItem *item = new QStandardItem();
      item->setText (QString ("%1").arg (elem));
      subj_parent_item->appendRow (item);
    }
}


void teacher_dialog::add_name ()
{
  int new_id = m_db->m_teachers->create_new();
  auto &val = m_db->m_teachers->get_data (new_id);
  val.set_name (ui->teachers_name->text ());

  fill_name_model ();
  update_models ();
}

void teacher_dialog::add_subj ()
{
  auto selected = ui->teachers_list->currentIndex ();
  if (!selected.isValid ())
    return;
  QVariant data = m_name_model->data (selected, Qt::UserRole + 1);
  auto &val = m_db->m_teachers->get_data (data.toInt ());
  val.get_subjects ().push_back (ui->subject_name->text ());
  fill_subj_model (data.toInt ());
}



void teacher_dialog::remove_name ()
{
  auto selected = ui->teachers_list->currentIndex ();
  if (!selected.isValid ())
    return;
  int idx = m_name_model->data (selected, Qt::UserRole + 1).toInt ();
  m_db->m_teachers->remove (idx);

  fill_name_model ();
  update_models ();
}

void teacher_dialog::remove_subj ()
{
  auto selected = ui->teachers_list->currentIndex ();
  if (!selected.isValid ())
    return;
  QVariant data = m_name_model->data (selected, Qt::UserRole + 1);

  auto selected_s = ui->subjects_list->currentIndex ();
  if (!selected_s.isValid ())
    return;
  int row = selected_s.row ();

  auto &val = m_db->m_teachers->get_data (data.toInt ());
  val.get_subjects ().erase (val.get_subjects ().begin () + row);
  fill_subj_model (data.toInt ());
}
