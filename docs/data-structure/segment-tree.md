---
title: Segment Tree
documentation_of: //data-structure/segment-tree.hpp
---

## Segment Tree

### Summary

The segment tree is an online range query point update data structure that supports the following operations:
- Given some indicies $l, r$ such that $l \leq r$, returns the value $\Pi_{i = l}^r a_i$, where "$\cdot$" is an associative function.
- Given an index $i$ and a value $v$, applies an update of $v$ to $a_i$. 

Both these operations are performed in $\mathcal{O}(\log n)$ time, where $n$ is the number of elements represented by the segment tree. The total space used is $2n$. All indices are 0-based. 

### Preconditions

- `B` is a class with the following defined:
  - `T`: The node type.
  - `const T dval`: The identity element, such that for any element $a$ it satisfies $a \cdot dval = dval \cdot a = a$.
  - `T merge(T a, T b)`: Merges two nodes with values $a$ and $b$. 
  - `void apply(T &a, T b)`: Applies an update of value $b$ to a node with value $a$. 
- "$\cdot$" is a commutative function (i.e. $a \cdot b = b \cdot a$ for all $a, b \in S$). 

### Methods

- `SegTree()`: Constructs an empty `Segtree` object.
- `SegTree(size_t _n)`: Constructs a `Segtree` object with initial capacity $n$ filled with the default value.
- `void init(int _n)`: Initializes a `Segtree` object with capacity $n$ filled with the default value in linear time. 
- `void update(int i, T v)`: Applies an update of $v$ to $a_i$ in logarithmic time. 
- `T query(int l, int r)`: Returns $\Pi_{i = l}^r a_i$ in logarithmic time. 
- `T operator[](int i)`: Returns $a_i$ in constant time. 