#-------------------------------------------------
#
# Project created by QtCreator 2017-04-01T20:55:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = scheduler
TEMPLATE = app


SOURCES += src/main.cpp\
           src/gui/group_dialog.cpp \
           src/gui/mainwindow.cpp \
           src/gui/teacher_dialog.cpp \
           src/kernel/greedy_search_solution.cpp \
           src/kernel/tree_solver.cpp \
           src/misc/index_table.cpp \
           src/resources/database.cpp \
           src/resources/group_profile.cpp \
           src/resources/teacher_profile.cpp

HEADERS  += src/gui/group_dialog.h \
            src/gui/mainwindow.h \
            src/gui/teacher_dialog.h \
            src/kernel/greedy_search_solution.h \
            src/kernel/tree_solver.h \
            src/misc/common_defines.h \
            src/misc/index_table.h \
            src/resources/database.h \
            src/resources/group_profile.h \
            src/resources/teacher_profile.h


FORMS    += src/gui/group_dialog.ui \
            src/gui/mainwindow.ui \
            src/gui/teacher_dialog.ui

#QMAKE_CXXFLAGS += -std=c++14
CONFIG += c++14
RESOURCES += res.qrc

QMAKE_CXXFLAGS += -std=c++14
#CONFIG += c++14

LIBS += -lsqlite3
