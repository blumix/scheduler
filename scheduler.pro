#-------------------------------------------------
#
# Project created by QtCreator 2017-04-01T20:55:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = scheduler
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    group_profile.cpp \
    teacher_profile.cpp \
    room_profile.cpp \
    group_dialog.cpp \
    database.cpp \
    kernel/tree_solver.cpp

HEADERS  += mainwindow.h \
    group_profile.h \
    teacher_profile.h \
    room_profile.h \
    group_dialog.h \
    database.h \
    kernel/tree_solver.h

FORMS    += mainwindow.ui \
    group_dialog.ui

QMAKE_CXXFLAGS += -std=c++14
