#ifndef _ISORT_H_
#define _ISORT_H_
#include <vector>
#include <cstdlib>
#include <iostream>

/* Pre - vector vec has a type T which is comparable
 * Post - vec is sorted in ascending order */
template <typename T>
void insertion_sort(std::vector<T> &vec);

/* Define specialization of template function*/
extern template void insertion_sort<int>(std::vector<int> &vec);


#endif
