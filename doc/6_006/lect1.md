Peak Finding Problem
====================
Toy problem we will use to discuss issues around designing efficeint algorithms. 

1D: Array of numbers 

| index | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|:----- |:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| value | a | b | c | d | e | f | g | h | i |

**a->i** are numbers, find a *peak* where a peak passes:
test(n) : position n is a peak if and only if, value[n]  >= value[n-1] and 
value[n] >= value[n+1]

```
The edges only have to look to one side
```

Problem
-------
*Find a peak if it exists* 

Code Implementing the algorithms can be found [here](../../src/algorithms/peak_finding/peak.cpp)

Straight forward algorithm:
* Linear scan of the list, starting from index 1 all the way to index 9.
  * For each element perform the test.
  * Stop the first time an element passes the test
Runtime is O(n).

