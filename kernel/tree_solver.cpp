/// \file kernel/tree_solver.cpp

#include "kernel/tree_solver.h"

void tree_solver::construct_adjacency_list (const std::vector<tree_node> &input_data)
{
  for (const auto &current_element : input_data)
    {
      std::vector<tree_node> adjacted_nodes;
      for (const auto &node : input_data)
        {
          if (current_element.is_neighbour (node))
            adjacted_nodes.push_back (node);
        }
      m_adjacency_list[current_element] =  adjacted_nodes;
    }
}
