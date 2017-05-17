/// \file kernel/greedy_search_solution.cpp

#include "src/kernel/greedy_search_solution.h"
#include "src/misc/common_defines.h"

#include <iostream>
#include <algorithm>

static inline int heuristic_func (const std::vector<std::vector<std::pair<int, int>>> &current_schedule)
{
  int res = 0;
  for (const auto &group_schedule : current_schedule)
    {
      (void)group_schedule;
      (void)res;
    }
  return res;
}

std::vector<std::vector<std::pair<int, int>>> search_best_solution (
    const std::vector<std::unordered_set<uid>> &possibilities_sets,
    size_t group_count
    )
{
  auto possibilities_size = possibilities_sets.size ();

  if (possibilities_size > common_defines::all_timeslots)
    return {};
  std::string bitmask (possibilities_size, 1);
  bitmask.resize (common_defines::all_timeslots, 0);

  std::vector<std::vector<std::pair<int, int>>> result_schedule, current_schedule;

  int min_hf = 1000;
  // print integers and permute bitmask
  do {
      current_schedule.clear ();
      current_schedule.resize (common_defines::all_timeslots);
      for (size_t idx = 0; idx < common_defines::all_timeslots; idx++)
        {
          current_schedule[idx].clear ();
          current_schedule[idx] = std::vector<std::pair<int, int>> (group_count);
        }

      int p_idx = 0;
      for (int i = 0; i < common_defines::all_timeslots; ++i)
        {
          if (bitmask[i])
            {
              for (auto &val : possibilities_sets[p_idx])
                {
                  current_schedule[i].push_back ({val, 0});
                }
              p_idx++;
              std::cout << " " << i;
            }
        }
      std::cout << std::endl;
      int current_hf = heuristic_func (current_schedule);
      if (current_hf < min_hf)
        {
          min_hf = current_hf;
          result_schedule = current_schedule;
        }
    } while (std::prev_permutation (bitmask.begin (), bitmask.end ()));

  return result_schedule;
}
