---
title: Sparse Table
documentation_of: //data-structure/sparse-table.hpp
---

## Sparse Table

### Summary
The sparse table is an online data structure that supports range min and max queries in constant time. The space used is $\mathcal{O}(n \log n)$. All indices are 0-indexed.

### Methods
- `SparseTable()`: Constructs an empty sparse table.
- `Fentree(I l, I r)`: Constructs a sparse table with elements specified by iterators $[l, r)$.
- `void init(I l, I r)`: Initializes a sparse table with elements specified by iterators $[l, r)$ in $\mathcal{O}(n \log n)$ time, where $n$ is the number of elements between $l$ and $r$. .
- `T query(int l, int r)`: Returns the value $\min(a_l, a_{l + 1}, \dots, a_r)$ in $\mathcal{O}(1)$ time. 
