#include <iostream>
#include <heap/heap.hpp>

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

  std::cout << "Heap sort\n";

  /* Print Array */
  std::cout << "Before sort a[]: {";
  for (size_t i = 0; i < a.size(); i++) {
    std::cout << a[i];
    if (i < a.size() - 1)
      std::cout << ", ";
  }
  std::cout <<"}\n";
  /* Sort */
  heap_sort(a);

  /* Print Array */
  std::cout << "After sort a[]: {";
  for (size_t i = 0; i < a.size(); i++) {
    std::cout << a[i];
    if (i < a.size() - 1)
      std::cout << ", ";
  }
  std::cout <<"}\n";


  return 0;
}


