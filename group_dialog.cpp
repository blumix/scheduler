#include "group_dialog.h"
#include "ui_group_dialog.h"

#include <QStandardItemModel>




group_dialog::group_dialog(database *db, QWidget *parent) :
  QDialog(parent),
  ui(new Ui::group_dialog), m_db (db)
{
  ui->setupUi(this);

  QStandardItemModel *model = new QStandardItemModel(this);
  QStandardItem *parentItem = model->invisibleRootItem();
  int row = 0;
  for (auto val : m_db->get_group_ids ())
    {
      QStandardItem *item = new QStandardItem();
      item->setText (QString::number (m_db->get_group (val).get_group_num ()));
      parentItem->setChild(row++,0,item);
    }
  QTreeView *treeView = new QTreeView(this);
  treeView->setModel(model);

  connect (ui->add_group_button, SIGNAL (clicked ()), this, SLOT(add_button_clicked ()));
}

group_dialog::~group_dialog()
{
  delete ui;
}

void group_dialog::add_button_clicked()
{
  int new_group_id = m_db->add_new_group ();
  QStandardItem *parentItem = model->invisibleRootItem();
  QStandardItem *item = new QStandardItem();
  item->setText (QString::number (m_db->get_group (new_group_id).get_group_num ()));
  parentItem->setChild(parentItem->rowCount (),0,item);
}
