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
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_teacher_dialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QListView *teachers_list;
    QFormLayout *formLayout;
    QLineEdit *teachers_name;
    QLabel *label;
    QPushButton *add_t_button;
    QPushButton *remove_t_button;
    QVBoxLayout *verticalLayout_3;
    QListView *subjects_list;
    QFormLayout *formLayout_2;
    QLineEdit *subject_name;
    QLabel *label_3;
    QPushButton *add_s_button;
    QPushButton *remove_s_button;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *teacher_dialog)
    {
        if (teacher_dialog->objectName().isEmpty())
            teacher_dialog->setObjectName(QString::fromUtf8("teacher_dialog"));
        teacher_dialog->resize(794, 388);
        verticalLayout_2 = new QVBoxLayout(teacher_dialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        teachers_list = new QListView(teacher_dialog);
        teachers_list->setObjectName(QString::fromUtf8("teachers_list"));

        verticalLayout->addWidget(teachers_list);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignCenter);
        formLayout->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        teachers_name = new QLineEdit(teacher_dialog);
        teachers_name->setObjectName(QString::fromUtf8("teachers_name"));

        formLayout->setWidget(0, QFormLayout::FieldRole, teachers_name);

        label = new QLabel(teacher_dialog);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        add_t_button = new QPushButton(teacher_dialog);
        add_t_button->setObjectName(QString::fromUtf8("add_t_button"));

        formLayout->setWidget(1, QFormLayout::FieldRole, add_t_button);

        remove_t_button = new QPushButton(teacher_dialog);
        remove_t_button->setObjectName(QString::fromUtf8("remove_t_button"));

        formLayout->setWidget(1, QFormLayout::LabelRole, remove_t_button);


        verticalLayout->addLayout(formLayout);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        subjects_list = new QListView(teacher_dialog);
        subjects_list->setObjectName(QString::fromUtf8("subjects_list"));

        verticalLayout_3->addWidget(subjects_list);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        subject_name = new QLineEdit(teacher_dialog);
        subject_name->setObjectName(QString::fromUtf8("subject_name"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, subject_name);

        label_3 = new QLabel(teacher_dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_3);

        add_s_button = new QPushButton(teacher_dialog);
        add_s_button->setObjectName(QString::fromUtf8("add_s_button"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, add_s_button);

        remove_s_button = new QPushButton(teacher_dialog);
        remove_s_button->setObjectName(QString::fromUtf8("remove_s_button"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, remove_s_button);


        verticalLayout_3->addLayout(formLayout_2);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_2->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(teacher_dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(teacher_dialog);
        QObject::connect(buttonBox, SIGNAL(rejected()), teacher_dialog, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), teacher_dialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(teacher_dialog);
    } // setupUi

    void retranslateUi(QDialog *teacher_dialog)
    {
        teacher_dialog->setWindowTitle(QApplication::translate("teacher_dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("teacher_dialog", "Name:", 0, QApplication::UnicodeUTF8));
        add_t_button->setText(QApplication::translate("teacher_dialog", "Add Teacher", 0, QApplication::UnicodeUTF8));
        remove_t_button->setText(QApplication::translate("teacher_dialog", "Romove Teacher", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("teacher_dialog", "Subject:", 0, QApplication::UnicodeUTF8));
        add_s_button->setText(QApplication::translate("teacher_dialog", "Add Subject", 0, QApplication::UnicodeUTF8));
        remove_s_button->setText(QApplication::translate("teacher_dialog", "Remove Subject", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class teacher_dialog: public Ui_teacher_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHER_DIALOG_H
