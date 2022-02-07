---
title: Kciwnef Tree
documentation_of: //data-structure/kciwnef-tree.hpp
---

## Kciwnef Tree

### Summary
The kciwnef tree is an online point query range update data structure that supports the following operations:
- Given an index $i$, returns the value at $a_i$.
- Given some indicies $l, r$ such that $l \leq r$ and a value $v$, assigns $a_i$ to $a_i + v$ for $i \in [l, r]$

Both these operations are performed in $\mathcal{O}(\log n) time, where $n$ is the number of elements represented by the kciwnef tree. The total space used is $n$. All indices represented in a kciwnef tree are one-indexed.

### Methods
- `Kciwtree()`: Constructs an empty kciwnef tree.
- `Kciwtree(size_t _n)`: Constructs a kciwnef tree with initial size $n$.
- `void init(size_t _n)`: Initializes a kciwnef tree object of size $n$ (meaning it can perform operations on the range $[1, n]$). Works in linear time.
- `void update(int l, int r, T v)`: Sets the value of $a_i$ to $a_i + v$ for $i \in [l, r]$. 
- `T query(int i)`: Returns the value $a_i$.
- `T operator[](int i)`: Same as `query(int i)`. 