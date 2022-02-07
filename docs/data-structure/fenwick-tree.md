---
title: Fenwick Tree
documentation_of: //data-structure/fenwick-tree.hpp
---

## Fenwick Tree

### Summary
The fenwick tree is an online range query point update data structure that supports the following operations:
- Given an index $i$, returns the value $\sum_{k = 1}^i a_k$.
- Given an index $i$ and a value $v$, assigns $a_i$ to $a_i + v$.

Both these operations are performed in $\mathcal{O}(\log n) time, where $n$ is the number of elements represented by the fenwick tree. The total space used is $n$. All indices represented in a fenwick tree are one-indexed.

### Methods
- `Fentree()`: Constructs an empty fenwick tree.
- `Fentree(size_t _n)`: Constructs a fenwick tree with initial size $n$.
- `void init(size_t _n)`: Initializes a fenwick tree object of size $n$ (meaning it can perform operations on the range $[1, n]$). Works in linear time.
- `void update(int i, T v)`: Sets the value of $a_i$ to $a_i + v$. 
- `T query(int i)`: Returns the value $\sum_{k = 1}^i a_k$.
- `T query(int l, int r)`: Returns the value $\sum_{k = l}^r a_k$. 
