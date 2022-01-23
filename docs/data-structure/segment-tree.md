---
title: Segment Tree
documentation_of: //data-structure/segment-tree.hpp
---

## Segment Tree

### Summary

A data structure built on monoids $(S \; \cdot : S \times S \rightarrow S, e \in S)$ i.e., the algebraic structure that satisfies the following properties:
- Associativity: $(a \cdot b) \cdot c = a \cdot (b \cdot c)$ for all $a, b, c \in S$
- Identity: there exists some element $e$ such that $a \cdot e = e \cdot a = a$ for all $a \in S$

For an array of size $n$, it can process the following operations in $\mathcal{O}(\log n)$ time:
- Update an element
- Query an interval

### Preconditions

- `B` is a class with the following defined:
  - `T`: A type.
  - `const T dval`: The identity element.
  - `void apply(T &a, T b)`: Applies an update of value `b` to a node with value `a`. 
  - `T merge(T a, T b)`: Merges two nodes with values `a` and `b`. 

### Methods

- `SegTree()`: Constructs an empty `Segtree` object.
- `SegTree(size_t _n)`: Constructs a `Segtree` object with initial capacity `_n` filled with the default value.
- `void init(int _n)`: Initializes a `Segtree` object with capacity `_n` filled with the default value. 
- `void update(int i, T v)`: Updates node `i` with value `v`.
- `T query(int l, int r)`: Queries the range from `l` to `r` inclusive. 
- `T operator[](int i)`: Returns the value of the element at index `i`. 