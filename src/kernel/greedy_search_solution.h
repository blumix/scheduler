/// \file kernel/greedy_search_solution.h

#ifndef GREEDY_SEARCH_SOLUTION_H
#define GREEDY_SEARCH_SOLUTION_H

#include <vector>
#include <unordered_set>

typedef int group_id;
typedef int subject_id;

typedef int uid;
class QProgressBar;

std::vector<std::vector<std::pair<group_id, subject_id> > > search_best_solution (
    const std::vector<std::unordered_set<uid>> &possibilities_sets,
    unsigned group_count,
    QProgressBar *progress_bar
);

#endif // GREEDY_SEARCH_SOLUTION_H
