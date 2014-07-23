#include <iostream>
#include <TestLib.hpp>
#include <binary_tree/AVLTree.hpp>

int main() {
  bool passed_test = false;
  std::vector<int> a;
  a.push_back(1);
  a.push_back(3);
  a.push_back(2);
  a.push_back(9);
  a.push_back(4);
  a.push_back(1);
  a.push_back(7);
  a.push_back(5);
  std::vector<int> b = a;

  std::cout << "AVL sort\n";
  std::cout << "Before sort a[]: {";
  print_array(a);
  /* Sort */
  avl_sort(a);
  /* Print Array */
  std::cout << "After sort a[]: {";
  print_array(a);
  passed_test = check_vs_stl(a,b);
  if (passed_test)
    std::cout << "Test Passed\n";
  else
    std::cout << "Test Failed\n";
  return passed_test ? 0 : 1;
}


