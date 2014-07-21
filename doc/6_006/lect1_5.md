[**<**](./lect1.md) 1.5 Models of Computation [**>**](./lect2.md)
================================================================

A model of computation specifies what can be done in O(1) time.

Random Access Machine (RAM) Model
---------------------------------
This is typically the most basic model whch we build ontop of.
Memory is represented as one large array.
  * Acessing elements of the array happens in O(1) time.
  * Field operations (*,/,-,+) happen in constant time. 

Pointer Machine Model
---------------------
A *Pointer Machine* consists of a set of *nodes*, where each node as O(1) *fields*.

A field can either be a *value* or a *pointer* to another node.
  * Acessing fields of a node happens in O(1) time.
  *

This model is useful when reasoning about data structures such as Binary Trees.

Python Model
------------
This specifies the complexity of certain operations in python. Below is a brief rundown for refrence:
  * 
  * append()
  * extend()



