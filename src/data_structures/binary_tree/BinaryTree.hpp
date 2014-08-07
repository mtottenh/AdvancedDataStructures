#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_
#include <vector>
#include <iostream>
template <class T> class BinaryTreeIter;
template <class T> class InOrderBinaryTreeIter;
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
    typedef InOrderBinaryTreeIter<T> iterator;
    typedef PreOrderBinaryTreeIter<T> pre_order_iterator;
    typedef PostOrderBinaryTreeIter<T> post_order_iterator;

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

  friend class InOrderBinaryTreeIter<T>;
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
#include <iterator>
template <typename T>
class InOrderBinaryTreeIter : public std::iterator<std::forward_iterator_tag, T> {
  private:
  BinaryTree<T> &tree;
  std::vector<BinaryTreeNode<T>*> stack;
  /* Current node to be looked at */
  BinaryTreeNode<T> *current_elem;
  BinaryTreeNode<T> *elem;

  public:
    InOrderBinaryTreeIter(BinaryTree<T> &btree) : tree(btree) {
      elem = tree.root;
      /* Go to leftmost node */
      while (elem != nullptr) {
        stack.push_back(elem);
        elem = elem->get_left();
      }
      /*now elem == nullptr and stack.back() = leftmost node */
      current_elem = stack.back();
      elem = current_elem->get_right();
      stack.pop_back();
    };

    T & operator*() {
      return current_elem->get_item();
    }
    typename BinaryTree<T>::iterator & operator++() {
      /* PRE: elem is the root of a subtree*/
      while (elem != nullptr) {
        stack.push_back(elem);
        elem = elem->get_left();
      }
      /* POST:
       * elem == nullptr
       * stack.back() = left most node of subtree  from PRE*/
      if (!stack.empty() && elem == nullptr) {
        current_elem = stack.back();
        stack.pop_back();
        elem = current_elem->get_right();
      }
      return *this;
    }
    /* Probably doesn't work very well... lets find out
    typename BinaryTree<T>::iterator & operator--() {
      stack.push_back(current_elem);
      current_elem = current_elem->get_left();
      elem = nullptr;
      return *this;
    }*/
   bool operator==(const InOrderBinaryTreeIter<T>& rhs) {
           bool condition = true;
           condition &= current_elem == rhs.current_elem;
           condition &= elem == rhs.elem;
           return condition;
   }
   bool operator!=(const InOrderBinaryTreeIter<T>& rhs) {return !(*this == rhs);}
   T *operator->() const { return current_elem;};

};

/* Pre-Order Tree Traversal */
template <typename T>
class PreOrderBinaryTreeIter : public std::iterator<std::forward_iterator_tag, T> {
  private:
    BinaryTree<T> &tree;
    std::vector<BinaryTreeNode<T>*> stack;
    /* Current node to be looked at */
    BinaryTreeNode<T> *elem;

  public:
    PreOrderBinaryTreeIter(BinaryTree<T> &btree) : tree(btree) {
      elem = tree.root;
    };

    T & operator*() {
      return elem->get_item();
    }
    typename BinaryTree<T>::iterator & operator++() {
      stack.push_back(elem)
      elem = elem->get_left();

      if (!stack.empty() && elem == nullptr) {
        elem = stack.back();
        stack.pop_back();
        elem = elem->get_right();
      }
      return *this;
    }
    bool operator==(const PreOrderBinaryTreeIter<T>& rhs) {
           bool condition = true;
           condition &= elem == rhs.elem;
           return condition;
    }
    bool operator!=(const PreOrderBinaryTreeIter<T>& rhs) {return !(*this == rhs);}
    T *operator->() const { return elem;};
};




/* Post Order Tree Traversal */
template <typename T>
class PostOrderBinaryTreeIter : public std::iterator<std::forward_iterator_tag, T> {
  private:
  BinaryTree<T> &tree;
  std::vector<BinaryTreeNode<T>*> stack;
  /* Current node to be looked at */
  BinaryTreeNode<T> *current_elem;
  BinaryTreeNode<T> *elem;

  public:
    InOrderBinaryTreeIter(BinaryTree<T> &btree) : tree(btree) {
      elem = tree.root;
      /* Go to leftmost node */
      while (elem != nullptr) {
        stack.push_back(elem);
        elem = elem->get_left();
      }
      /*now elem == nullptr and stack.back() = leftmost node */
      current_elem = stack.back();
      elem = current_elem->get_right();
      stack.pop_back();
    };

    T & operator*() {
      return current_elem->get_item();
    }
    typename BinaryTree<T>::iterator & operator++() {
      /* PRE: elem is the root of a subtree*/
      while (elem != nullptr) {
        stack.push_back(elem);
        elem = elem->get_left();
      }
      /* POST:
       * elem == nullptr
       * stack.back() = left most node of subtree  from PRE*/
      if (!stack.empty() && elem == nullptr) {
        current_elem = stack.back();
        stack.pop_back();
        elem = current_elem->get_right();
      }
      return *this;
    }
    /* Probably doesn't work very well... lets find out
    typename BinaryTree<T>::iterator & operator--() {
      stack.push_back(current_elem);
      current_elem = current_elem->get_left();
      elem = nullptr;
      return *this;
    }*/
   bool operator==(const InOrderBinaryTreeIter<T>& rhs) {
           bool condition = true;
           condition &= current_elem == rhs.current_elem;
           condition &= elem == rhs.elem;
           return condition;
   }
   bool operator!=(const InOrderBinaryTreeIter<T>& rhs) {return !(*this == rhs);}
   T *operator->() const { return current_elem;};

};





#include <binary_tree/BinaryTree.hxx>

#endif
