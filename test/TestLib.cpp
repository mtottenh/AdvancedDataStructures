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

template <typename T>
bool check_arrays(std::vector<T> &vec_a, std::vector<T> &vec_b) {
  if (vec_a.size() != vec_b.size()) {
    return false;
  } else {
    bool check = true;
    for(int i = 0; i < vec_a.size(); i++) {
      check &= vec_a[i] == vec_b[i];
    }
    return check;
  }
}
template bool check_arrays<int>(std::vector<int> &vec_a, std::vector<int> &vec_b);

template <typename T>
bool check_vs_stl(std::vector<T> &vec_a, std::vector<T> &vec_b) {
  std::sort(vec_b.begin(),vec_b.end());
  return check_arrays(vec_a,vec_b);
}

template bool check_vs_stl<int>(std::vector<int> &vec_a, std::vector<int> &vec_b);

