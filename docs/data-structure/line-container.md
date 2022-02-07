---
title: Line Container
documentation_of: //data-structure/line-container.hpp
---

## Line Container

## Summary

The line container is an online set of lines that supports the following operations:
- Given some linear function $f(x) = mx + b$, inserts it into the set.
- Given some location $x$, returns the maximum of $f(x)$ for all functions $f$ in the set. 

Both these operations are performed in $\mathcal{O}(\log n)$ time, and the data structure has space complexity proportional to $O(q)$, where $q$ is the number of update operations performed. Note that deleting and random access is not possible. 

### Methods
- `LineContainer()`: Constructs an empty line container.
- `void add(long long m, long long b)`: Adds a linear function $mx + b$. 
- `long long query(long long x)`: Returns $\max(f_1(x), f_2(x), \dots, f_q(x))$ where $q$ is the number of updates thus far and $f_i$ is the linear function inserted on the $i$th step. 