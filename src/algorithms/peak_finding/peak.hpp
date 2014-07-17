#ifndef _PEAK_FINDING_H_
#define _PEAK_FINDING_H_
#include <vector>
#include <utility>
#include <cstdlib>
bool boundary(int a, size_t b);
int neighbour(int a, size_t b);
std::pair<bool,int> find_peak(std::vector<int> lst);

#endif
