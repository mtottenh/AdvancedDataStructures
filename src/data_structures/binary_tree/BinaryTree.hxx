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
    destroy_tree(node->get_left());
    destroy_tree(node->get_right());
    delete node;
  }
}


/* Precondition - Node is never null
 * Inserts element `elem` into tree rooted at node */
template <typename T>
void BinaryTree<T>::insert_into(T elem, BinaryTreeNode<T>* node) {
/*  if (node->geq(elem))
    insert_left(elem,node);
  else
    insert_right(elem,node);
*/
  BinaryTreeNode<T>** node_ptr;
  node_ptr = node->geq(elem) ?  node->get_left_ptr() : node->get_right_ptr();
  if (*node_ptr == nullptr) {
    *node_ptr = new BinaryTreeNode<T> (elem);
  } else {
    insert_into(elem, *node_ptr);
  }
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

template <typename T>
void BinaryTree<T>::insert(T elem) {
  if (this->root == nullptr) {
    this->root = new BinaryTreeNode<T> (elem);
  } else {
    insert_into(elem,root);
  }
  no_nodes++;
}

/* Search for an item using binary search..*/
template <typename T>
BinaryTreeNode<T>* BinaryTree<T>::search(T elem) {
  return search_in(root,elem);
}

template <typename T>
BinaryTreeNode<T>* BinaryTree<T>::search_in(BinaryTreeNode<T>* node, T elem) {
  if ( node == nullptr || elem == node->get_item()) {
    return node;
  } else {
    if (elem <= node->get_item()) {
      return search_in(node->get_left(),elem);
    } else {
      return search_in(node->get_right(),elem);
    }
  }
}

/*
template <typename T>
BinaryTreeNode<T>* BinaryTree<T>::parent_of(BinaryTreeNode<T>* node) {
  if (node == root) {
    return nullptr;
  } else {
    if (node == root->get_left() || root->get_right())
      return root;

  }
}

template <typename T>
void BinaryTree<T>::remove_in(BinaryTreeNode<T>* tree,T elem) {
  auto delnode = search_in(tree,elem);
  if (node == nullptr) {
    return;
  } else {
    switch (delnode->no_children) {
      case 0:
        delete delnode;
        break;
      case 1:
        parent = parent_of(delnode);
        auto modptr = (parent->left == delnode) ? &parent->left : &parent->right;
        *modptr = (delnode->left == nullptr) ? delnode->right : delnode->left;
        delete delnode;
        break;
      case 2:
        auto min_node  = min_elem(delnode->right);
        delnode->item = min_node->item;
        remove_in(delnode->right,min_node->item);
        break;
    }
  }
}
*/
template <typename T>
void BinaryTree<T>::remove(T elem) {
//  remove_in(root,elem);
}

template <typename T>
void bst_sort(std::vector<T> &vec) {
  std::cout << "BST sort\n";
  BinaryTree<T> btree;
  for (auto &a : vec) {
    btree.insert(a);
  }
  auto it = btree.begin();
  for (size_t idx = 0; idx < vec.size(); idx++) {
    vec[idx] = *it;
    ++it;
  }
}
