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

/* vec: Destination array to merge into
 * vec_a & vec_b: arrays to merge
 */
template <typename T>
void merge(std::vector<T> &vec, std::vector<T> &vec_a, std::vector<T> &vec_b) {
  size_t idx_a = 0;
  size_t idx_b = 0;
  for (size_t i = 0; i < vec.size(); i++) {
    if (idx_a >= vec_a.size()) {
      vec[i] = vec_b[idx_b];
      idx_b++;
    }
    else if (idx_b >= vec_b.size()) {
      vec[i] = vec_a[idx_a];
      idx_a++;
    }
    else if (vec_a[idx_a] < vec_b[idx_b]) {
      vec[i] = vec_a[idx_a];
      idx_a++;
    } else {
      vec[i] = vec_b[idx_b];
      idx_b++;
    }
  }
}

template <typename T>
void split (std::vector<T> &vec, std::vector<T> &vec_a, std::vector<T> &vec_b) {
  for (size_t i = 0; i < vec.size()/2; i++) {
    vec_a.push_back(vec[i]);
  }
  for (size_t i = vec.size()/2; i < vec.size(); i++) {
    vec_b.push_back(vec[i]);
  }
}

template <typename T>
void merge_sort(std::vector<T> &vec) {
  if (vec.size() > 1) {
    std::vector<T> vec_a;
    std::vector<T> vec_b;
    split(vec,vec_a,vec_b);
    merge_sort(vec_a);
    merge_sort(vec_b);
    merge(vec,vec_a,vec_b);
  }
}

template void merge_sort<int>(std::vector<int> &vec);
