/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTreeView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAdd_group_profile;
    QAction *actionAdd_teacher_profile;
    QAction *actionAdd_auditorium;
    QAction *actionSave;
    QAction *actionOpen;
    QAction *actionExport_As;
    QAction *actionExport_file_name;
    QAction *actionSet_Room_Count;
    QAction *save;
    QAction *load;
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QTreeView *groups_tree;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QTreeView *all_subjects;
    QVBoxLayout *verticalLayout_2;
    QPushButton *add_arrow;
    QPushButton *remove_arrow;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QListView *selected_subjects;
    QGridLayout *gridLayout;
    QPushButton *groups_button;
    QGridLayout *gridLayout_2;
    QSpinBox *rooms_count;
    QLabel *label;
    QLineEdit *file_name;
    QLabel *label_2;
    QPushButton *run_calculation;
    QPushButton *teacher_button;
    QMenuBar *menuBar;
    QMenu *menuAdd_content;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(954, 582);
        actionAdd_group_profile = new QAction(MainWindow);
        actionAdd_group_profile->setObjectName(QString::fromUtf8("actionAdd_group_profile"));
        actionAdd_teacher_profile = new QAction(MainWindow);
        actionAdd_teacher_profile->setObjectName(QString::fromUtf8("actionAdd_teacher_profile"));
        actionAdd_auditorium = new QAction(MainWindow);
        actionAdd_auditorium->setObjectName(QString::fromUtf8("actionAdd_auditorium"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionExport_As = new QAction(MainWindow);
        actionExport_As->setObjectName(QString::fromUtf8("actionExport_As"));
        actionExport_file_name = new QAction(MainWindow);
        actionExport_file_name->setObjectName(QString::fromUtf8("actionExport_file_name"));
        actionSet_Room_Count = new QAction(MainWindow);
        actionSet_Room_Count->setObjectName(QString::fromUtf8("actionSet_Room_Count"));
        save = new QAction(MainWindow);
        save->setObjectName(QString::fromUtf8("save"));
        load = new QAction(MainWindow);
        load->setObjectName(QString::fromUtf8("load"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setMinimumSize(QSize(685, 334));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 1005, 531));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        groups_tree = new QTreeView(horizontalLayoutWidget);
        groups_tree->setObjectName(QString::fromUtf8("groups_tree"));

        verticalLayout_3->addWidget(groups_tree);


        horizontalLayout_2->addLayout(verticalLayout_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        all_subjects = new QTreeView(horizontalLayoutWidget);
        all_subjects->setObjectName(QString::fromUtf8("all_subjects"));

        verticalLayout->addWidget(all_subjects);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        add_arrow = new QPushButton(horizontalLayoutWidget);
        add_arrow->setObjectName(QString::fromUtf8("add_arrow"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("right-arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        add_arrow->setIcon(icon);
        add_arrow->setIconSize(QSize(32, 32));

        verticalLayout_2->addWidget(add_arrow);

        remove_arrow = new QPushButton(horizontalLayoutWidget);
        remove_arrow->setObjectName(QString::fromUtf8("remove_arrow"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("left-arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        remove_arrow->setIcon(icon1);
        remove_arrow->setIconSize(QSize(32, 32));

        verticalLayout_2->addWidget(remove_arrow);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_5 = new QLabel(horizontalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_4->addWidget(label_5);

        selected_subjects = new QListView(horizontalLayoutWidget);
        selected_subjects->setObjectName(QString::fromUtf8("selected_subjects"));

        verticalLayout_4->addWidget(selected_subjects);


        horizontalLayout_3->addLayout(verticalLayout_4);


        horizontalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout->addLayout(horizontalLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groups_button = new QPushButton(horizontalLayoutWidget);
        groups_button->setObjectName(QString::fromUtf8("groups_button"));

        gridLayout->addWidget(groups_button, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        rooms_count = new QSpinBox(horizontalLayoutWidget);
        rooms_count->setObjectName(QString::fromUtf8("rooms_count"));
        rooms_count->setMinimum(1);
        rooms_count->setMaximum(999);
        rooms_count->setValue(10);

        gridLayout_2->addWidget(rooms_count, 0, 1, 1, 1);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        file_name = new QLineEdit(horizontalLayoutWidget);
        file_name->setObjectName(QString::fromUtf8("file_name"));

        gridLayout_2->addWidget(file_name, 1, 1, 1, 1);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 2, 0, 1, 1);

        run_calculation = new QPushButton(horizontalLayoutWidget);
        run_calculation->setObjectName(QString::fromUtf8("run_calculation"));

        gridLayout->addWidget(run_calculation, 3, 0, 3, 1);

        teacher_button = new QPushButton(horizontalLayoutWidget);
        teacher_button->setObjectName(QString::fromUtf8("teacher_button"));

        gridLayout->addWidget(teacher_button, 1, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 954, 25));
        menuAdd_content = new QMenu(menuBar);
        menuAdd_content->setObjectName(QString::fromUtf8("menuAdd_content"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setEnabled(true);
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuAdd_content->menuAction());
        menuAdd_content->addAction(actionAdd_group_profile);
        menuAdd_content->addAction(actionAdd_teacher_profile);
        menuAdd_content->addSeparator();
        menuAdd_content->addAction(save);
        menuAdd_content->addAction(load);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionAdd_group_profile->setText(QApplication::translate("MainWindow", "Groups", 0, QApplication::UnicodeUTF8));
        actionAdd_teacher_profile->setText(QApplication::translate("MainWindow", "Teachers/Subjects", 0, QApplication::UnicodeUTF8));
        actionAdd_auditorium->setText(QApplication::translate("MainWindow", "Add auditorium", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open...", 0, QApplication::UnicodeUTF8));
        actionExport_As->setText(QApplication::translate("MainWindow", "Export As...", 0, QApplication::UnicodeUTF8));
        actionExport_file_name->setText(QApplication::translate("MainWindow", "Set Export Filename", 0, QApplication::UnicodeUTF8));
        actionSet_Room_Count->setText(QApplication::translate("MainWindow", "Set Room Count...", 0, QApplication::UnicodeUTF8));
        save->setText(QApplication::translate("MainWindow", "save", 0, QApplication::UnicodeUTF8));
        load->setText(QApplication::translate("MainWindow", "load", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Groups:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "All Subjects:", 0, QApplication::UnicodeUTF8));
        add_arrow->setText(QString());
        remove_arrow->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Selected Subjects:", 0, QApplication::UnicodeUTF8));
        groups_button->setText(QApplication::translate("MainWindow", "Groups", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Room count:", 0, QApplication::UnicodeUTF8));
        file_name->setText(QApplication::translate("MainWindow", "res.csv", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Results:", 0, QApplication::UnicodeUTF8));
        run_calculation->setText(QApplication::translate("MainWindow", "Run Calculation", 0, QApplication::UnicodeUTF8));
        teacher_button->setText(QApplication::translate("MainWindow", "Teachers/Subjects", 0, QApplication::UnicodeUTF8));
        menuAdd_content->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
