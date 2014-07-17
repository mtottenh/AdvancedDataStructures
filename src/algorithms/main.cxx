#include <iostream>
#include <tuple>
#include <peak_finding/peak.hpp>
int main() {
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

  return 0;
}
