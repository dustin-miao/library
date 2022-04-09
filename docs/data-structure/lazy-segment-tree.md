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