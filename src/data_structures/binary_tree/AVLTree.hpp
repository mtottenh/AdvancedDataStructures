#ifndef __AVLTREE_H__
#define __AVLTREE_H__
#include <binary_tree/BinaryTree.hpp>

template <typename T>
class AVLTree : public BinaryTree<T> {
  private:
    int stuff;
};
template <typename T>
void avl_sort(std::vector<T> &vec) {
  AVLTree<T> tree;
  for (auto &a: vec) {
    tree.insert(a);
  }
  auto it = tree.begin();
  for (size_t idx = 0; idx < vec.size(); idx++) {
    vec[idx] = *it;
    ++it;
  }
}
#endif
