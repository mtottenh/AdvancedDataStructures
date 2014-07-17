#include <peak.hpp>

/* Some helper functions */
bool boundary (int a, size_t b) {
  return (a == 0) || ( a == b-1);
}

int neighbour (int a, size_t b) {
  if (a == 0)
    return 1;
  if (a == b-1)
    return b-2;
}

/* Naieve Approach, O(n) */
std::pair<bool,int> find_peak(std::vector<int> lst) {
  bool peak = false;
  int index = -1;
  while( !peak && index < lst.size()) {
    index++;
    if (!boundary(index,lst.size())) {
      /* General Case */
      peak = peak || ((lst[index] >= lst[index-1]) &&
                      (lst[index] >= lst[index+1]));
    } else {
      /* Boundary Case */
      peak = peak || lst[index] >= lst[neighbour(index,lst.size())];
    }
  }
  return std::make_pair(peak,index);
}
