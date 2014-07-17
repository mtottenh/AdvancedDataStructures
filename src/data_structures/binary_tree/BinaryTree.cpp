#include <BinaryTree.hpp>
template <typename T>
BinaryTree<T>::BinaryTree() {
  root = nullptr;
}

template <typename T>
BinaryTree<T>::~BinaryTree() {
  destroy_tree(this->root);
}
template <typename T>
void BinaryTree<T>::destroy_tree(BinaryTreeNode<T>* node) {
  if (node != nullptr) {
    destroy_tree(node->getLeft());
    destroy_tree(node->getRight());
    delete node;
  }
}
template <typename T>
void BinaryTree<T>::insert(T elem) {

}

