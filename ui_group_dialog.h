/********************************************************************************
** Form generated from reading UI file 'group_dialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUP_DIALOG_H
#define UI_GROUP_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QTableWidget>
#include <QtGui/QTreeView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_group_dialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QTreeView *treeView;
    QTableWidget *tableWidget;

    void setupUi(QDialog *group_dialog)
    {
        if (group_dialog->objectName().isEmpty())
            group_dialog->setObjectName(QString::fromUtf8("group_dialog"));
        group_dialog->resize(491, 352);
        buttonBox = new QDialogButtonBox(group_dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(150, 320, 341, 31));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalLayoutWidget = new QWidget(group_dialog);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 471, 301));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        treeView = new QTreeView(horizontalLayoutWidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        horizontalLayout->addWidget(treeView);

        tableWidget = new QTableWidget(horizontalLayoutWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        horizontalLayout->addWidget(tableWidget);


        retranslateUi(group_dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), group_dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), group_dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(group_dialog);
    } // setupUi

    void retranslateUi(QDialog *group_dialog)
    {
        group_dialog->setWindowTitle(QApplication::translate("group_dialog", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class group_dialog: public Ui_group_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUP_DIALOG_H
