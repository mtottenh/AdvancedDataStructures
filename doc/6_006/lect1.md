Peak Finding Problem [>](./lect2.md)
====================
Toy problem we will use to discuss issues around designing efficeint algorithms. 

*Find __a__ peak if it exists* 

Code implementing the algorithms can be found [**HERE**](../../src/algorithms/peak_finding/peak.cpp)


1D Version
----------

| index | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|:----- |:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| value | a | b | c | d | e | f | g | h | i |

where **a** through **i** are numbers, a peak passes the following test:

```
test(n) : position n is a peak if and only if, 
value[n]  >= value[n-1] and 
value[n] >= value[n+1]

*The edges only have to look to one side
```

**Straight forward algorithm (*O(n)*)**

* Linear scan of the list, starting from index 1 all the way to index 9.
  * For each element perform the test.
  * Stop the first time an element passes the test

**Recursive Algorithm (*O(lg(n))*)**

* if value[n/2] < value[n/2 -1]
  * then only look at the left half ( 1 .. n/2 -1) to look for a peak
* else if value[n/2] < value[n/2 +1] 
  * then look at the right half ( n/2 + 1 .. n) to look for a peak
* else value[n/2] is a peak 

[*Argue that this algorithm is correct*](./prob_set1.pdf)

**Complexity Analysis of the Recursive Algorithm**

Worst Case:
* recursive case: T(n) = O(1) + T(n/2)
* base case :     T(1) = O(1)

T(n) = O(1) + ... + O(n) = O(lg(n))



2D Version
----------
Grid with n rows and m columns.

| index | 1 | 2 | 3 | 4 |
|:----- |:-:|:-:|:-:|:-:|
| 1     |   | c |   |   |
| 2     | b | a | d |   |
| 3     |   | e |   |   |
| 4     |   |   |   |   |

A peak here is defined intuitively like a hill:
 * a is a 2d peak iff a >= b, a >=d, a >= c, a >=e

Using The example array...

| index |  1 |  2 |  3 |  4 |
|:----- |:--:|:--:|:--:|:--:|
| 1     |    |    |    |    |
| 2     | 14 | 13 | 12 |    |
| 3     | 15 | 9  | 11 | 17 |
| 4     | 16 | 17 | 19 | 20 |


**Greedy Ascent Algorithm (*O(nm)*)** 

Roughly:
* Pick an arbitrary start point
  * Look to the left, 
    * If left > current Go left
    * Else Go right
  * If you hit an edge Go down.

You will need to choose default traversal directions & starting points, e.g. left
first, down first.

**Recursive Version (*O(n lg(m))*)**  

* Pick middle column (j = m/2)
* Find global maximum on column j (i,j)
* Compare (i,j-1), (i,j), (i,j+1)
  * Pick left cols if (i,j-1) > (i,j)
    * Solve the prolbem with 1/2 the number of cols
  * else Pick right cols if (i,j+1) > (i,j)
    * Solve the problem with 1/2 the number of cols
  * else (i,j) is a 2D peak.
* When you have a single column find the global maximum and you are done.

**Complexity Analysis of Recursive Version**

Recurence relation: 

                    T(n,m) = T(n,m/2) + O(n)  *(O(n) for maximum)*

                    T(n,1) = O(n)

                 => T(n,m) = O(n) + .. + O(n) = O(n lg(m))




