Peak Finding Problem
====================
Toy problem we will use to discuss issues around designing efficeint algorithms. 

1D: Array of numbers 

| index | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|:----- |:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| value | a | b | c | d | e | f | g | h | i |

**a->i** are numbers, find a *peak* where a peak is defined as:
Position 2 is a peak if and only if, b >= a and b >= c

```
The edges only have to look to one side
```

Problem
-------
*Find a peak if it exists* 

Straight forward algorithm:
* Start from left

