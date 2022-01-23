---
title: Binary Index Tree
documentation_of: //data-structure/binary-index-tree.hpp
---

## Binary Index Tree

### Summary

The binary index tree is an online range query point update data structure that supports the following operations:
- Given an index $i$, returns the value $\sum_{k = 1}^i a_k$.
- Given an index $i$ and a value $v$, assigns $a_i$ to $a_i + v$.

Both these operations are performed in $\mathcal{O}(\log n) time, where $n$ is the number of elements represented by the binary index tree. The total space complexity is linear. Note that all indices represented in a binary index tree are one-indexed.

### Methods

- `Fentree()`: Constructs an empty binary index tree.
- `Fentree(size_t _n)`: Constructs a binary index tree with initial size `_n`
- `void init(size_t n)`: Initializes a binary index tree object of size `_n` (meaning it can perform operations on the range $[1, n]$). Works in linear time.
- `void update(int i, T v)`: Sets the value of $a_i$ to $a_i + v$. 
- `T query(int i)`: Returns the value $\sum_{k = 1}^i a_k$.
- `T query(int l, int r)`: Returns the value $\sum_{k = l}^r a_k$. 
