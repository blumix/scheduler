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
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTreeView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_group_dialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QTreeView *treeView;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_2;
    QSpinBox *tread;
    QLabel *label;
    QSpinBox *cource;
    QLabel *label_3;
    QSpinBox *number;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_2;
    QPushButton *add_group_button;
    QPushButton *remove_group_button;

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
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 491, 321));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        treeView = new QTreeView(horizontalLayoutWidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        horizontalLayout->addWidget(treeView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        tread = new QSpinBox(horizontalLayoutWidget);
        tread->setObjectName(QString::fromUtf8("tread"));

        formLayout->setWidget(1, QFormLayout::FieldRole, tread);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        cource = new QSpinBox(horizontalLayoutWidget);
        cource->setObjectName(QString::fromUtf8("cource"));
        cource->setMinimum(1);

        formLayout->setWidget(2, QFormLayout::FieldRole, cource);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        number = new QSpinBox(horizontalLayoutWidget);
        number->setObjectName(QString::fromUtf8("number"));
        number->setMinimum(1);

        formLayout->setWidget(0, QFormLayout::FieldRole, number);

        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);


        verticalLayout->addLayout(formLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        add_group_button = new QPushButton(horizontalLayoutWidget);
        add_group_button->setObjectName(QString::fromUtf8("add_group_button"));

        verticalLayout_2->addWidget(add_group_button);

        remove_group_button = new QPushButton(horizontalLayoutWidget);
        remove_group_button->setObjectName(QString::fromUtf8("remove_group_button"));

        verticalLayout_2->addWidget(remove_group_button);


        verticalLayout->addLayout(verticalLayout_2);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(group_dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), group_dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), group_dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(group_dialog);
    } // setupUi

    void retranslateUi(QDialog *group_dialog)
    {
        group_dialog->setWindowTitle(QApplication::translate("group_dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("group_dialog", "Number", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("group_dialog", "Thread", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        cource->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        cource->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        label_3->setText(QApplication::translate("group_dialog", "Cource", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
        add_group_button->setText(QApplication::translate("group_dialog", "Add Group", 0, QApplication::UnicodeUTF8));
        remove_group_button->setText(QApplication::translate("group_dialog", "Remove Group", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class group_dialog: public Ui_group_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUP_DIALOG_H
