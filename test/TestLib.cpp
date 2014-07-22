#include <TestLib.hpp>

template <typename T>
void print_array(std::vector<T> &vec) {
  /* Print Array */
  for (size_t i = 0; i < vec.size(); i++) {
    std::cout << vec[i];
    if (i < vec.size() - 1)
      std::cout << ", ";
  }
  std::cout <<"}\n";
}

template void print_array<int>(std::vector<int> &vec);


