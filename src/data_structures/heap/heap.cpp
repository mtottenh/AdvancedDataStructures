#include <heap.hpp>

void Heap::build_heap() {
  for (size_t i = data.size()/4; i >= 0; i--) {
    heapify(i);
  }
}
/* TODO - Add checks to see that a node actually has children...*/
void Heap::heapify(size_t node) {
 if (data[node] < data[left_child(node)] ||
     data[node] < data[right_child(node)]) {

   /* Swap with the maximum & heapify */
 }

}

size_t Heap::parent(size_t node) {
  return node/2;
}

size_t Heap::left_child(size_t node) {
  size_t candidate = node*2;
  return candidate >= data.size() ? -1 : candidate;
}

size_t Heap::right_child(size_t node) {
  size_t candidate = node*2 +1;
  return candidate >= data.size() ? -1 : candidate;
}


