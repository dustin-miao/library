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