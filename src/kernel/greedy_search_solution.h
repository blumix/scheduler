/// \file kernel/greedy_search_solution.h

#ifndef GREEDY_SEARCH_SOLUTION_H
#define GREEDY_SEARCH_SOLUTION_H

#include <vector>
#include <unordered_set>

typedef int uid;

std::vector<std::vector<std::pair<int, int> > > search_best_solution (
  const std::vector<std::unordered_set<uid>> &possibilities_sets,
  size_t group_count
);

#endif // GREEDY_SEARCH_SOLUTION_H
