/// \file kernel/greedy_search_solution.cpp

#include "src/kernel/greedy_search_solution.h"
#include "src/misc/common_defines.h"

#include <iostream>
#include <algorithm>
#include <assert.h>
#include <QProgressBar>
#include <cmath>

static inline double factorial(double x)
{
  return std::tgamma (x + 1);
}

/// \returns heuristic value for single day
///
static inline int func_for_single_day (const std::vector<std::pair<group_id, subject_id>> &group_schedule, const size_t day_num)
{
  assert (group_schedule.size () != common_defines::all_timeslots);

  int curr_dist = 0.,
      sum_dist  = 0.;
  std::pair<int, int> prev_non_winwow (-1, -1);
  for (size_t idx = day_num * common_defines::timeslots_per_day;
       idx < common_defines::timeslots_per_day;
       idx++
       )
    {
      if (!common_defines::is_invalid_pair (group_schedule[idx]))
        {
          prev_non_winwow = group_schedule[idx];
          sum_dist += curr_dist;
          curr_dist = 0;
        }
      else
        {
          if (!common_defines::is_invalid_pair (prev_non_winwow))
            curr_dist++;
        }
    }

  return sum_dist;
}

static inline int heuristic_func (
    const std::vector<std::vector<std::pair<group_id, subject_id>>> &current_schedule,
    unsigned group_count
)
{
  int res = 0;

  for (unsigned group_id = 0; group_id < group_count; group_id++)
    {
      /// 1) Construct group schedule
      ///
      std::vector<std::pair<int, int>> group_schedule;
      for (const auto &timeslot_schedule : current_schedule)
        group_schedule.push_back (timeslot_schedule[group_id]);

      /// 2) Add its heuristic function to overall answer
      ///
      for (const auto &timeslot_schedule : current_schedule)
        {
          for (size_t day_num = 0; day_num < common_defines::days_per_work_week; day_num++)
            res += func_for_single_day (timeslot_schedule, day_num);
        }
    }
  return res;
}

std::vector<std::vector<std::pair<group_id, subject_id> > > search_best_solution (
    const std::vector<std::unordered_set<uid>> &possibilities_sets,
    unsigned group_count,
    QProgressBar *progress_bar
    )
{
  auto possibilities_size = possibilities_sets.size ();

  if (possibilities_size > common_defines::all_timeslots)
    return {};
  std::string bitmask (possibilities_size, 1);
  bitmask.resize (common_defines::all_timeslots, 0);

  std::vector<std::vector<std::pair<group_id, subject_id>>> result_schedule, current_schedule;

  int min_hf = 1000,
      step = 0.;

  unsigned long all_steps = factorial (common_defines::all_timeslots) / factorial (possibilities_size)
                                     / factorial (common_defines::all_timeslots - possibilities_size);
  // print integers and permute bitmask
  do
    {
      progress_bar->setValue (100 * step++ / all_steps);
      current_schedule.clear ();
      current_schedule.resize (common_defines::all_timeslots);
      for (size_t idx = 0; idx < common_defines::all_timeslots; idx++)
        {
          current_schedule[idx].clear ();
          current_schedule[idx] = std::vector<std::pair<group_id, subject_id>> (group_count);
        }

      int p_idx = 0;
      for (size_t i = 0; i < common_defines::all_timeslots; ++i)
        {
          if (bitmask[i])
            {
              for (auto &subject_id : possibilities_sets[p_idx])
                current_schedule[i].push_back ({0, subject_id});
              p_idx++;
            }
        }
      int current_hf = heuristic_func (current_schedule, group_count);
      if (current_hf < min_hf)
        {
          min_hf = current_hf;
          result_schedule = current_schedule;
        }
    }
  while (std::prev_permutation (bitmask.begin (), bitmask.end ()));

  return result_schedule;
}
