#include "src/gui/mainwindow.h"
#include <QApplication>

#include "src/kernel/tree_solver.h"
#include <iostream>

int main (int argc, char *argv[])
{
  QApplication a (argc, argv);
  MainWindow w;
  w.show();

  return a.exec();
}
