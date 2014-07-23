#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_
#include <vector>
#include <iostream>
template <class T> class BinaryTreeIter;

/* A basic generic node */
template <typename T>
class BinaryTreeNode {
  private:
    T item;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
  public:
    BinaryTreeNode(T elem) {
      item = elem;
      left = nullptr;
      right = nullptr;
    }

    BinaryTreeNode<T>() {
      left = nullptr;
      right = nullptr;
    }

    BinaryTreeNode<T>* get_left() { return left;}
    BinaryTreeNode<T>* get_right() { return right;}
    void set_left(BinaryTreeNode<T> *n) {left = n;}
    void set_right(BinaryTreeNode<T> *n) {right = n;}
    bool has_left() { return left != nullptr;}
    bool has_right() { return right != nullptr;}
    T& get_item() { return item;}
    bool geq(T elem) { return elem <= this->item; }
};
/* Interface to a binary tree class which we will be extending */
template <typename T>
class BinaryTree {


  friend class BinaryTreeIter<T>;
  private:
    BinaryTreeNode<T> *root;
    size_t no_nodes;
    void destroy_tree(BinaryTreeNode<T>* node);
    void insert_into(T elem,BinaryTreeNode<T>* node);
    void insert_left(T elem, BinaryTreeNode<T>* node);
    void insert_right(T elem, BinaryTreeNode<T>* node);
  public:
    typedef BinaryTreeIter<T> iterator;
    typedef ptrdiff_t difference_type;
    typedef size_t size_type;
    typedef T value_type;
    typedef T * pointer;
    typedef T & reference;

    BinaryTree();
    ~BinaryTree();
    void insert(T elem);
    BinaryTreeNode<T>* search(T elem);
    void remove(T elem);
    size_t size() { return no_nodes; }
    iterator begin() { return iterator(*this); }
    iterator end() { return iterator(*this); }
};

/* in-order traversal iterator */
template <typename T>
class BinaryTreeIter {
  private:
  BinaryTree<T> &tree;
  std::vector<BinaryTreeNode<T>*> stack;
  BinaryTreeNode<T> *elem;
  BinaryTreeNode<T> *velem;
  public:
    BinaryTreeIter(BinaryTree<T> &btree) : tree(btree) {
      elem = tree.root;
      while (elem != nullptr) {
        stack.push_back(elem);
        elem = elem->get_left();
      }
      velem = stack.back();
      stack.pop_back();
    };

    T & operator*() {
      return velem->get_item();
    }

    typename BinaryTree<T>::iterator & operator++() {
      /* next node in travesal*/
      while (!stack.empty() || elem != nullptr) {
        if (elem != nullptr) {
          stack.push_back(elem);
          elem = elem->get_left();
        } else {
          velem = stack.back();
          stack.pop_back();
          elem = velem;
          elem = elem->get_right();
          break;
        }
      }
      return *this;
    }
};




#include <binary_tree/BinaryTree.hxx>
template <typename T>
void bst_sort(std::vector<T> &vec);

#endif
