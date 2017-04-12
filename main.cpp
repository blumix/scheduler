#include "mainwindow.h"
#include <QApplication>

#include "kernel/tree_solver.h"
#include <iostream>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  w.show();

  /// test of calculation
  std::vector<tree_node> vector_of_nodes;
  vector_of_nodes.push_back ({0, 1, 2, 3});
  vector_of_nodes.push_back ({1, 5, 6, 7});
  vector_of_nodes.push_back ({2, 9, 10, 12});
  vector_of_nodes.push_back ({3, 1, 3, 5});
  vector_of_nodes.push_back ({4, 4, 2, 1});
  vector_of_nodes.push_back ({5, 5, 2, 7});

  tree_solver solver;
  solver.calculate (vector_of_nodes);
  ///

  return a.exec();
}
