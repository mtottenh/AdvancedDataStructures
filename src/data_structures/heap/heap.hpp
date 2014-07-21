#ifndef __HEAP__H__
#define __HEAP__H__
#include <vector>
#include <cstdlib>

/* Heap implmented over a vector
 * TODO: template this class to make it more generic
 */
void heap_sort(std::vector<int> &vec);

class Heap {
  private:
    std::vector<int> data;
    bool is_maxheap;

    void heapify(size_t node);
    size_t parent(size_t node);
    size_t left_child(size_t node);
    size_t right_child(size_t node);

  public:

    Heap() {is_maxheap = true;};
    Heap(std::vector<int> input, bool type) {
      is_maxheap = type;
      for(auto a : input) { data.push_back(a); }
    };
    ~Heap() {};


    void build_heap();
    void insert(int elem);
    int extract();
    //void delete(size_t node);
};


#endif
