#ifndef TREE_SOLVER_H
#define TREE_SOLVER_H

/// \file kernel/tree_solver.h
#include <map>
#include <vector>

struct tree_node
{
  int room_id = 0;
  int group_id = 0;
  int teacher_id = 0;

  bool is_neighbour (const tree_node &rhs) const
  {
    return (room_id == rhs.room_id) || (group_id == rhs.group_id) || (teacher_id == rhs.teacher_id);
  }

  /// for map
  bool operator< (const tree_node &rhs) const
  {
    return (   room_id    < rhs.room_id
            && group_id   < rhs.group_id
            && teacher_id < rhs.teacher_id);
  }
};

class tree_solver
{
  void construct_adjacency_list (const std::vector<tree_node> &input_data);
private:
  std::map<tree_node, std::vector<tree_node>> m_adjacency_list;
};

#endif // TREE_SOLVER_H
