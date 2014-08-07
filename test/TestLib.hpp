#ifndef _TESTLIB_H_
#define _TESTLIB_H_
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

template <typename T>
void print_array(std::vector<T> &vec);

extern template void print_array<int>(std::vector<int> &vec);

/*
template <typename T>
bool check_arrays(std::vector<T> &vec_a, std::vector<T> &vec_b);
*/

template <typename T>
bool check_vs_stl(std::vector<T> &vec_a, std::vector<T> &vec_b);

extern template bool check_vs_stl<int>(std::vector<int> &vec_a, std::vector<int> &vec_b);

template <typename T>
void populate_array(std::vector<T> &vec, size_t num);

extern template void populate_array<int>(std::vector<int> &vec, size_t num);

const size_t test_size = 1000000;
#endif
