/// \file kernel/greedy_search_solution.h

#ifndef GREEDY_SEARCH_SOLUTION_H
#define GREEDY_SEARCH_SOLUTION_H

#include <vector>
#include <unordered_set>

typedef int uid;

void search_best_solution (const std::vector<std::unordered_set<uid>> &possibilities_set, size_t group_count);

#endif // GREEDY_SEARCH_SOLUTION_H

