#include <iostream>
#include <tuple>
#include <peak_finding/peak.hpp>
#include <sorting/merge_sort.hpp>

int main() {
  /* 1D Peak Finding */
  std::vector<int> a;
  bool found = false;
  int peak_index = -1;

  a.push_back(1);
  a.push_back(2);
  a.push_back(1);

  std::tie(found,peak_index) = find_peak(a);

  if (found)
    std::cout << "Found a peak at a[" << peak_index << "]\n";
  else
    std::cout << "No peak found in data\n";

  /* Some sorting */
  a.push_back(7);
  a.push_back(3);
  a.push_back(5);
  a.push_back(2);

  std::cout << "Sorting array a[]: {";
  for (size_t i = 0; i < a.size(); i++) {
    std::cout << a[i];
    if (i < a.size() - 1)
      std::cout << ", ";
  }
  std::cout << "}\nAfter merge sort a[]: {";
  merge_sort<int>(a);
  for (size_t i = 0; i < a.size(); i++) {
    std::cout << a[i];
    if (i < a.size() - 1)
      std::cout << ", ";
  }
  std::cout << "}\n";
  return 0;
}
