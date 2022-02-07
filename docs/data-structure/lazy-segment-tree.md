---
title: Lazy Segment Tree
documentation_of: //data-structure/lazy-segment-tree.hpp
---

## Lazy Segment Tree

### Summary
The lazy segment tree is an online range query range update data structure that supports the following operations:
- Given some indicies $l, r$ such that $l \leq r$, returns the value $\Pi_{i = l}^r a_i$, where "$\cdot$" is an associative function.
- Given some indicies $l, r$ such that $l \leq r$ and a value $v$, applies an update of $v$ to $a_i \forall i \in [l, r]$. 

Both these operations are performed in $\mathcal{O}(\log n)$ time, where $n$ is the number of elements represented by the segment tree. The space complexity is $\mathcal{O}(q \log n)$, where $q$ is the number of update operations performed. All indices are 0-based. 

### Preconditions
- `B` is a class with the following defined:
  - `T`: The node type.
  - `L`: The update type.
  - `const T Tdval`: The identity node type, such that for any element $a$ it satisfies $a \cdot dval = dval \cdot a = a$.
  - `const L Ldval`: The identity update type, such that any update $v$ applied to some node with lazy value $Ldval$ returns $v$. 
  - `T merge(T a, T b)`: Merges two nodes with values $a$ and $b$. 
  - `void apply(T &a, L &b, L c, int l, int r)`: Applies an update with value $c$ to a node with node value $a$, lazy value $b$ and spans a range from $l$ to $r$. 

### Methods
- `SegTree()`: Constructs an empty `Segtree` object.
- `SegTree(size_t _n)`: Constructs a `Segtree` object with initial capacity $n$ filled with the default value.
- `void init(int _n)`: Initializes a `Segtree` object with capacity $n$ filled with the default value in linear time. 
- `void update(int l, int r, T v)`: Applies an update of $v$ to $a_i \forall i \in [l, r]$ in logarithmic time. 
- `T query(int l, int r)`: Returns $\Pi_{i = l}^r a_i$ in logarithmic time. 