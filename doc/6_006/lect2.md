[<](lect1_5.md)Sorting [>](./lect3.md)
======================================
Basic Algorithms:
-----------------
  * Insertion Sort
    * Maintain invariant that LHS of array is sorted, insert next element into array using pairwise swaps.
  * Merge Sort 
    * Divide and conquore.
    * Work happens in the merge operation.

Heaps & Heap Sort
-----------------
Can be used as a way of representing an array. Consider the Tree:

```
    A
   / \
  B   C
```

Heap defined as either:
  * Minheap: A < B and A < C and B and C are Minheaps 
  * Maxheap: A > B and A > C and B and C are Maxheaps 

Sorting using a heap is equivilent to building a heap over the array and calling extract_max() / extract_min() successively. This takes O(n lg n) time.


BST
---
A BST has the following properties:
  * Consits of nodes & pointers (Pointer Machine Model)
  * At most 2 children
  * Inserts take O(1) time once the correct place is found (similar to linked lists).
  * Nodes can be *augmented* with aditional data e.g.
    * Height(n) : The length longest path from `n` to a leaf
    * Depth(n) : The length of the  path from the root to `n`
    * SubTree(n): Number of members of the subtree rooted at node `n`

Sorting using a BST is equivilent to performing an in-order traversal of the tree. Sorting using
BSTs take O(nh) time where h is the height of the tree. There are several techiniques to ensure a tree
is ballanced (see [AVL Trees](./lect2_5.md)) so that sorting takes O(n lg n) time.

BST's in partiular are useful because they give extra functionality which heaps do not, for example we can find predecessor() / sucessor() in O(1) time using a BST.
