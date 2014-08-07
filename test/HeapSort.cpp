#include <iostream>
#include <TestLib.hpp>
#include <heap/heap.hpp>

int main() {
  std::vector<int> a;
  populate_array(a,test_size);
  std::vector<int> b = a;
  bool passed_test = false;

  std::cout << "Heap sort\n";
  std::cout << "Before sort a[]: {";
  print_array(a);
  /* Sort */
  heap_sort(a);
  /* Print Array */
  std::cout << "After sort a[]: {";
  print_array(a);
  passed_test = check_vs_stl(a,b);
  return passed_test ? 0 : 1;
}


