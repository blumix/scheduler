#ifndef TREE_SOLVER_H
#define TREE_SOLVER_H

/// \file kernel/tree_solver.h
#include <unordered_map>
#include <vector>

struct tree_node
{
  int group_id = 0;
  int room_id = 0;
  int teacher_id = 0;

  bool is_neighbour (const tree_node &rhs) const
  {
    return ((room_id == rhs.room_id) || (group_id == rhs.group_id) || (teacher_id == rhs.teacher_id));
  }

  /// for map
  bool operator== (const tree_node &rhs) const
  {
    return (   room_id    == rhs.room_id
            && group_id   == rhs.group_id
            && teacher_id == rhs.teacher_id);
  }
};

namespace std
{
  template<>
  struct hash<tree_node>
  {
    size_t operator()(const tree_node &node) const
    {
      std::hash<int> int_hasher;
      return (int_hasher (node.group_id) ^ (int_hasher (node.room_id) ^ (int_hasher (node.teacher_id) << 1)) << 1);
    }
  };
}

class tree_solver
{
public:
  void calculate (const std::vector<tree_node> &input_data);

private:
  void construct_adjacency_list (const std::vector<tree_node> &input_data);
  void set_colors ();

  /// Debug info
  ///
  void print_vector (const std::vector<tree_node> &vector);

private:
  std::unordered_map<tree_node, std::vector<tree_node>> m_adjacency_list;
  std::unordered_map<tree_node, int> m_colors;
};

#endif // TREE_SOLVER_H
