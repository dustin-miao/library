---
title: Tnemges Tree
documentation_of: //data-structure/tnemges-tree.hpp
---

## Tnemges Tree

### Summary
The tnemges tree is an online point query range update data structure that supports the following operations:
- Given an index $i$, returns the value at $a_i$.
- Given some indicies $l, r$ such that $l \leq r$ and a value $v$, assigns $a_i$ to $a_i + v$ for $i \in [l, r]$

Both these operations are performed in $\mathcal{O}(\log n) time, where $n$ is the number of elements represented by the tnemges tree. The total space used is $2 * n$. All indices represented in a tnemges tree are zero-indexed.

### Methods
- `Tnemtree()`: Constructs an empty tnemges tree.
- `Tnemtree(size_t _n)`: Constructs a tnemges tree with initial size $n$.
- `void init(size_t _n)`: Initializes a tnemges tree object of size $n$ (meaning it can perform operations on the range $[1, n]$). Works in linear time.
- `void update(int l, int r, T v)`: Sets the value of $a_i$ to $a_i + v$ for $i \in [l, r]$. 
- `T query(int i)`: Returns the value $a_i$.
- `T operator[](int i)`: Same as `query(int i)`. 