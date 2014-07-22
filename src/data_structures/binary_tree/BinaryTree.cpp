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
  if (this->root == nullptr) {
    this->root = new BinaryTreeNode<T> (elem);
  } else {
    insert_into(elem,root);
  }
}

/* Precondition - Node is never null
 * Inserts element `elem` into tree rooted at node */
template <typename T>
void BinaryTree<T>::insert_into(T elem, BinaryTreeNode<T>* node) {
  if (node->geq(elem))
    insert_left(elem,node);
  else
    insert_right(elem,node);
}

template <typename T>
void BinaryTree<T>::insert_left(T elem, BinaryTreeNode<T>* node) {
  if (node->has_left()) {
    insert_into(elem,node->get_left());
  } else {
    node->set_left(new BinaryTreeNode<T> (elem) );
  }
}


template <typename T>
void BinaryTree<T>::insert_right(T elem, BinaryTreeNode<T>* node) {
  if (node->has_right()) {
    insert_into(elem,node->get_right());
  } else {
    node->set_right(new BinaryTreeNode<T> (elem) );
  }
}
