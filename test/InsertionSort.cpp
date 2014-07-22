#include <iostream>
#include <TestLib.hpp>
#include <sorting/insertion_sort.hpp>

int main() {
  std::vector<int> a;
  a.push_back(1);
  a.push_back(3);
  a.push_back(2);
  a.push_back(9);
  a.push_back(4);
  a.push_back(1);
  a.push_back(7);
  a.push_back(5);

  std::cout << "Insertion sort\n";
  std::cout << "Before sort a[]: {";
  print_array(a);
  /* Sort */
  insertion_sort(a);
  /* Print Array */
  std::cout << "After sort a[]: {";
  print_array(a);

  return 0;
}


