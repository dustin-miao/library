---
title: Segment Tree Beats
documentation_of: //data-structure/segment-tree-beats.hpp
---

## Segment Tree Beats

### Summary
The segment tree is an online range query range update data structure that supports the following operations:
- Given some indicies $l, r$ such that $l \leq r$ and a value $v$, assigns $\min(a_i, v)$ to $a_i$ for $i \in [l, r]$. 
- Given some indicies $l, r$ such that $l \leq r$ and a value $v$, assigns $\max(a_i, v)$ to $a_i$ for $i \in [l, r]$. 
- Given some indicies $l, r$ such that $l \leq r$ and a value $v$, assigns $a_i + v$ to $a_i$ for $i \in [l, r]$. 
- Given some indicies $l, r$ such that $l \leq r$, returns the value $\sum_l^r a_i$. 

The first three operations are performed in $\mathcal{O}(\log^2 n)$ time and the last is performed in $\mathcal{O}(\log n)$ time, where $n$ is the number of elements represented by the segment tree. The total space used is $4n$. All indices are 0-based. 