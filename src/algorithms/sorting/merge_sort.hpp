#ifndef _MSORT_H_
#define _MSORT_H_
#include <iostream>
#include <cstdlib>
#include <vector>

template <typename T>
void merge_sort(std::vector<T> &vec);

extern template void merge_sort<int>(std::vector<int> &vec);

#endif
