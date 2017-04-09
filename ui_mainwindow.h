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
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
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
    QWidget *centralWidget;
    QTableView *main_window_tableView;
    QMenuBar *menuBar;
    QMenu *menuFIle;
    QMenu *menuAdd_content;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 300);
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
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        main_window_tableView = new QTableView(centralWidget);
        main_window_tableView->setObjectName(QString::fromUtf8("main_window_tableView"));
        main_window_tableView->setGeometry(QRect(5, -59, 391, 391));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 25));
        menuFIle = new QMenu(menuBar);
        menuFIle->setObjectName(QString::fromUtf8("menuFIle"));
        menuAdd_content = new QMenu(menuBar);
        menuAdd_content->setObjectName(QString::fromUtf8("menuAdd_content"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setEnabled(true);
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFIle->menuAction());
        menuBar->addAction(menuAdd_content->menuAction());
        menuFIle->addAction(actionSave);
        menuFIle->addAction(actionOpen);
        menuFIle->addAction(actionExport_As);
        menuAdd_content->addAction(actionAdd_group_profile);
        menuAdd_content->addAction(actionAdd_teacher_profile);
        menuAdd_content->addAction(actionAdd_auditorium);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionAdd_group_profile->setText(QApplication::translate("MainWindow", "change group profiles", 0, QApplication::UnicodeUTF8));
        actionAdd_teacher_profile->setText(QApplication::translate("MainWindow", "Add teacher  profile", 0, QApplication::UnicodeUTF8));
        actionAdd_auditorium->setText(QApplication::translate("MainWindow", "Add auditorium", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open...", 0, QApplication::UnicodeUTF8));
        actionExport_As->setText(QApplication::translate("MainWindow", "Export As...", 0, QApplication::UnicodeUTF8));
        menuFIle->setTitle(QApplication::translate("MainWindow", "FIle", 0, QApplication::UnicodeUTF8));
        menuAdd_content->setTitle(QApplication::translate("MainWindow", "Add content..", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
