---
title: Recursive Segment Tree
documentation_of: //data-structure/recursive-segment-tree.hpp
---

## Recursive Segment Tree

### Summary

Segment Trees are a general class of online data structures, represented by a complete binary tree with the leaves built on an array such that all nodes in the tree (excluding leaves) are a function of its children. More specifically, it supports:
- Given two indices $l, r$, it finds $\sum_{k = l}^r a_k$, or the sum of values in the range $[l, r]$.
- Given an index $i$ and a value $v$, assigns $a_i$ to $v$. 

Both these operations are performed in $\mathcal{O}(\log n)$, where $n$ is the number of elements represented by the segment tree. The total space complexity is linear (more specifically, it allocates $2n$ memory). Note that all indices are zero-based. For a similar data structure, see the [binary index tree](https://dutinmeow.github.io/library/data-structure/binary-index-tree.hpp). 

It is important to note that this version implements segment tree recusively, which incurs a higher runtime and a memory upperbound of $4n$ (as opposed to $2n$ from the iterative version). Alternatively, see the [iterative segment tree](https://dutinmeow.github.io/library/data-structure/segment-tree.hpp).

### Documentation

- `segtree()`: Constructs an empty segment tree.
- `void init(int n)`: Initializes a segment tree of size $n$. This takes $\mathcal{O}(n)$ time.
- `void init(Iterator begin, Iterator end)`: Initializes a segment tree with values specified by $\texttt{begin}$ and $\texttt{end}$. This runs in $\mathcal{O}(n)$ time.
- `void update(int i, T v)`: Assigns $a_i$ to value $v$. This runs in $\mathcal{O}(\log n)$. 
- `T query(int l, int r)`: Returns $\sum_{k = l}^r a_k$. This runs in $\mathcal{O}(\log n)$ time.
- `T operator[](int i)`: Returns $a_i$. This runs in $\mathcal{O}(1)$ time.

Note that the following methods and variables are meant to be modified or overriden. 
- `T dval`: This variable is the default value, which depends on the type of $T$ and $\texttt{merge}$ function. For any $v \neq \texttt{dval}$, $\texttt{dval}$ should satisfy $v = \texttt{merge}(v, \texttt{dval})$. For instance, a sum operator would mean that $\texttt{dval} = 0$, and a min operator would mean that $\texttt{dval} = \infty$. 
- `T merge(T a, T b)`: Specifies how values are to be combined. It takes in two values and merges them into a single value. 
- `T apply(T &a, T b)`: Applies an update with value $b$ to a node with value $a$. This will most likely always be the `=` or `+=` operator. 

