#include <heap.hpp>
void heap_sort(std::vector<int> &vec) {
  Heap h(vec,true);
  h.build_heap();
  for (size_t i = 0; i < vec.size(); i++) {
    vec[i] = h.extract();
  }

}
int Heap::extract() {
  int value = data[0];
  for (size_t i = data.size() - 1; i >= 0; i--) {
    heapify(i);
  }
  return value;
}

void Heap::build_heap() {
  for (size_t i = data.size()/4; i >= 0; i--) {
    heapify(i);
  }
}
/* TODO - Add checks to see that a node actually has children...*/
void Heap::heapify(size_t node) {
 if (data[node] < data[left_child(node)] ||
     data[node] < data[right_child(node)]) {
   auto temp = data[node];
   size_t child;
   /* figure out which child to swap with */
   if (data[left_child(node)] > data[right_child(node)] ){
     child = left_child(node);
   } else {
     child = right_child(node);
   }
   data[node] = data[child];
   data[child] = temp;
   heapify(child);
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


