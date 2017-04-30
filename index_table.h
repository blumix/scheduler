#ifndef INDEX_TABLE_H
#define INDEX_TABLE_H

#include <map>
#include <vector>
#include <assert.h>

template <typename T>
class index_table
{
public:
  index_table()
  {

  }

  int create_new()
  {
    int id = m_idx;
    m_table.insert(std::pair<int, T>(id, T(id)));
    m_idx++;
    return id;
  }

  T &get_data(int id)
  {
    auto res = m_table.find (id);
    assert (res != m_table.end ());
    return m_table.at (id);
  }


  std::vector<int> get_ids()
  {
    std::vector<int> ret;
    for (auto val : m_table)
      ret.push_back (val.first);

    return ret;
  }

  bool is_id_valid (int id)
  {
    return m_table.find (id) != m_table.end ();
  }

  void remove (int idx)
  {
    m_table.erase (idx);
  }

private:
  std::map<int, T> m_table;
  int m_idx = 0;
};

#endif // INDEX_TABLE_H
