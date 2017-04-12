/********************************************************************************
** Form generated from reading UI file 'teacher_dialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHER_DIALOG_H
#define UI_TEACHER_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTreeView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_teacher_dialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QTreeView *treeView;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *name_linedit;
    QLineEdit *subject_linedit;
    QLabel *label_4;
    QPushButton *pushButton;

    void setupUi(QDialog *teacher_dialog)
    {
        if (teacher_dialog->objectName().isEmpty())
            teacher_dialog->setObjectName(QString::fromUtf8("teacher_dialog"));
        teacher_dialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(teacher_dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(50, 260, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalLayoutWidget = new QWidget(teacher_dialog);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(9, 9, 381, 251));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        treeView = new QTreeView(horizontalLayoutWidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        horizontalLayout->addWidget(treeView);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        name_linedit = new QLineEdit(horizontalLayoutWidget);
        name_linedit->setObjectName(QString::fromUtf8("name_linedit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, name_linedit);

        subject_linedit = new QLineEdit(horizontalLayoutWidget);
        subject_linedit->setObjectName(QString::fromUtf8("subject_linedit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, subject_linedit);

        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);


        horizontalLayout->addLayout(formLayout);

        pushButton = new QPushButton(teacher_dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 260, 99, 27));

        retranslateUi(teacher_dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), teacher_dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), teacher_dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(teacher_dialog);
    } // setupUi

    void retranslateUi(QDialog *teacher_dialog)
    {
        teacher_dialog->setWindowTitle(QApplication::translate("teacher_dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("teacher_dialog", "Name", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("teacher_dialog", "Subject", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("teacher_dialog", "Add Teacher", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class teacher_dialog: public Ui_teacher_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHER_DIALOG_H
