#ifndef _TESTLIB_H_
#define _TESTLIB_H_
#include <iostream>
#include <vector>

template <typename T>
void print_array(std::vector<T> &vec);
extern template void print_array<int>(std::vector<int> &vec);

/*
template <typename T>
bool check_arrays(std::vector<T> &vec_a, std::vector<T> &vec_b);

template <typename T>
bool check_vs_stl(std::vector<T> &vec);
*/
#endif
