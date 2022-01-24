---
title: Lazy Segment Tree
documentation_of: //data-structure/lazy-segment-tree.hpp
---

## Lazy Segment Tree

### Summary

A data structure built on monoids $(S \; \cdot : S \times S \rightarrow S, e \in S)$ i.e., the algebraic structure that satisfies the following properties:
- Associativity: $(a \cdot b) \cdot c = a \cdot (b \cdot c)$ for all $a, b, c \in S$
- Identity: there exists some element $e$ such that $a \cdot e = e \cdot a = a$ for all $a \in S$

For an array of size $n$, it can process the following operations in $\mathcal{O}(\log n)$ time:
- Update a range of elements
- Query an interval

### Preconditions

- `B` is a class with the following defined:
  - `T`: The node type.
  - `L`: The update type.
  - `const T Tdval`: The identity element for T.
  - `const L Ldval`: The identity element for L. 
  - `void apply(T &a, L &b, L c, int l, int r)`: Applies an update of value `c` spanning from `l` to `r` inclusive to a node with value `a` and lazy value `b`. 
  - `T merge(T a, T b)`: Merges two nodes with values `a` and `b`. 

### Methods

- `SegTree()`: Constructs an empty `Segtree` object.
- `SegTree(size_t _n)`: Constructs a `Segtree` object with initial capacity `_n` filled with the default node value.
- `void init(int _n)`: Initializes a `Segtree` object with capacity `_n` filled with the default node value. 
- `void update(int l, int r, L v)`: Updates indicies `l` to `r` inclusive with value `v`.
- `T query(int l, int r)`: Queries the range from `l` to `r` inclusive. 