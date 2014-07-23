#include <heap.hpp>
#include <iostream>

void Heap::print() {
  for (size_t i = 0; i < data.size(); i++) {
    std::cout << "h[" << i << "]: " << data[i] << "\t";
  }
  std::cout << "\n";
}
void heap_sort(std::vector<int> &vec) {
  Heap h(vec,true);
  h.build_heap();
  h.print();
  for (size_t i = 0; i < vec.size(); i++) {
    vec[i] = h.extract();
    std::cout << "v[" << i<< "]: " << vec[i] << "\t";
  }
  std::cout <<  "\ndone\n";
}
int Heap::extract() {
  int value = data[0];
  data[0] = data[data.size() - 1];
  data[data.size() - 1] = value;
  data.pop_back();
  heapify(0);

 // for (size_t i = data.size() - 1; i != 0; i--) {
 //   heapify(i);
//  }

  return value;
}

void Heap::build_heap() {
  for (size_t i = data.size()/2; i != 0; i--) {
    heapify(i);
  }
  heapify(0);
}
/* TODO - Add checks to see that a node actually has children...*/
void Heap::heapify(size_t node) {
  auto l = left_child(node);
  auto r = right_child(node);
  size_t child = node;

  if (l.second && data[node] >= data[l.first]) {
    child = l.first;
  }
  if (r.second && data[child] >= data[r.first]) {
    child = r.first;
  }

  if (child != node) {
    auto temp = data[node];
    data[node] = data[child];
    data[child] = temp;
    heapify(child);
  }
}

std::pair<size_t,bool> Heap::parent(size_t node) {
  return std::make_pair(node/2,true);
}

std::pair<size_t,bool> Heap::left_child(size_t node) {
  size_t candidate = node*2 + 1;
  return std::make_pair(candidate,candidate < data.size());
}

std::pair<size_t,bool> Heap::right_child(size_t node) {
  size_t candidate = node*2 + 2;
  return std::make_pair(candidate, candidate < data.size() );
}


