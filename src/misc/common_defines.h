/// \file kernel/common_defines.h
/// \brief Common defines
#ifndef COMMON_DEFINES_H
#define COMMON_DEFINES_H

#include <vector>

namespace common_defines
{
/// \brief Number of timeslots, e.g. 6 days * 5 ed_years
constexpr int timeslots_per_day = 5;

constexpr int days_per_work_week = 6;

constexpr int all_timeslots = 30;


/// Invalid pair <=> one of indices is negative
///
inline bool is_invalid_pair (const std::pair<int, int> &c_pair)
{
  if (c_pair.first < 0 || c_pair.second < 0)
    return true;
  return false;
}
};

#endif // COMMON_DEFINES_H
