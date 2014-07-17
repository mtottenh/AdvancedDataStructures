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

    BinaryTreeNode<T>* getLeft() { return left;}
    BinaryTreeNode<T>* getRight() { return right;}
};
/* Interface to a binary tree class which we will be extending */
template <typename T>
class BinaryTree {
  private:
    BinaryTreeNode<T> *root;
    void destroy_tree(BinaryTreeNode<T>* node);
  public:
    BinaryTree();
    ~BinaryTree();
    void insert(T elem);
    BinaryTreeNode<T>* search(T elem);
//    void delete();
};

#endif
