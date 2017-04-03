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
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=c++14
