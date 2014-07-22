#include <sorting.hpp>

template <typename T>
void swap(std::vector<T> &vec, size_t idx_a, size_t idx_b) {
  T elem = vec[idx_a];
  vec[idx_a] = vec[idx_b];
  vec[idx_b] = elem;
}

template <typename T>
void insertion_sort(std::vector<T> &vec) {
  /* invariant - LHS of key is sorted after each itteration */
  for (size_t key = 1; key != vec.size(); key++) {
    size_t j = key;
    while (j > 0 && vec[j-1] > vec[j]) {
      swap(vec,j,j-1);
      j--;
    }
  }
}
/* manually instantiate int version */
template void insertion_sort<int>(std::vector<int> &vec);


