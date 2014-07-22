#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_
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
    bool geq(T elem) { return elem <= this->item; }
};
/* Interface to a binary tree class which we will be extending */
template <typename T>
class BinaryTree {
  private:
    BinaryTreeNode<T> *root;
    void destroy_tree(BinaryTreeNode<T>* node);
    void insert_into(T elem,BinaryTreeNode<T>* node);
    void insert_left(T elem, BinaryTreeNode<T>* node);
    void insert_right(T elem, BinaryTreeNode<T>* node);
  public:
    BinaryTree();
    ~BinaryTree();
    void insert(T elem);
    BinaryTreeNode<T>* search(T elem);
    void remove(T elem);
};

#endif
