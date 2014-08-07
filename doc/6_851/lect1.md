Time Sensitive Data Structures.
==============================

Model of Computation
--------------------
* Pointer Machine
  * Bunch of Nodes with fields
    * Pointer to another node
    * NULL 
    * Data
  * X and Y are fields are the root Node (Always have a root node).  

Example operations
   Can create nodes
    x = new node
   Can look at fields
    x = y.field
   Set fields
    x.field = y

Temporal Data structures
------------------------
Come in two types:
* Persistance
  * Never destroy old universes.

* Retroactivity **HARDER**
  * Like back to the future.


Persistance
===========
Goal: - Remember Everything

* Keep all versions of the data structure.
* All DS operations are relative to specified version 
* an pdate makes and returns a new version

Four levels of persistance
--------------------------
1. Partial persistance
  * Only allowed to update latest version
  * Versions are linearly ordered
  * Can query old versions, but can't change them, only change most recent one

2. Full persistence (*branching universe model*)
  * Update any version.
  * Versions form a tree.

3. Confluent persistance
  * Can `combine` two versions to make a new version
  * Can't destroy old versions.
  * Versions form a `DAG`






