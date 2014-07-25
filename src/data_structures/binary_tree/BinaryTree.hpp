#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_
#include <vector>
#include <iostream>
template <class T> class BinaryTreeIter;
template <typename T> void bst_sort(std::vector<T> &vec);

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
    BinaryTreeNode<T>** get_left_ptr() { return &left;}
    BinaryTreeNode<T>** get_right_ptr() { return &right;}
    void set_left(BinaryTreeNode<T> *n) {left = n;}
    void set_right(BinaryTreeNode<T> *n) {right = n;}
    bool has_left() { return left != nullptr;}
    bool has_right() { return right != nullptr;}
    T& get_item() { return item;}
    bool geq(T elem) { return elem <= this->item; }
};


/* Interface to a binary tree class which we will be extending */
template <typename T>
class IBST {
  public:
    typedef BinaryTreeIter<T> iterator;
    typedef ptrdiff_t difference_type;
    typedef size_t size_type;
    typedef T value_type;
    typedef T * pointer;
    typedef T & reference;

    virtual void remove (T elem) = 0;
    virtual void insert (T elem) = 0;
    virtual BinaryTreeNode<T>* search (T elem) = 0;
    virtual size_t size() = 0;
    virtual iterator begin() = 0;
    virtual iterator end() = 0;
};

/* Implementation of an unballanced BST */
template <typename T>
class BinaryTree : public IBST<T> {

  friend class BinaryTreeIter<T>;
  typedef typename IBST<T>::iterator iterator;

  private:
    BinaryTreeNode<T> *root;
    size_t no_nodes;
    void destroy_tree(BinaryTreeNode<T>* node);
    BinaryTreeNode<T>* search_in(BinaryTreeNode<T>* node, T elem);
    void insert_into(T elem,BinaryTreeNode<T>* node);
    void insert_left(T elem, BinaryTreeNode<T>* node);
    void insert_right(T elem, BinaryTreeNode<T>* node);
  public:
    BinaryTree();
    ~BinaryTree();

    virtual BinaryTreeNode<T>* search(T elem);
    virtual void remove(T elem);
    virtual void insert(T elem);
    virtual size_t size() { return no_nodes; }
    virtual iterator begin() { return iterator(*this); }

    /*TODO - fix this */
    virtual iterator end() { return iterator(*this); }
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

    typename IBST<T>::iterator & operator++() {
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
    /* TODO :- Implement equality and prefix ++ */
};




#include <binary_tree/BinaryTree.hxx>

#endif
