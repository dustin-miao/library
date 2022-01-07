---
title: Segment Tree
documentation_of: //data-structure/general-segment-tree.hpp
---

## Generalized Segment Tree

### Summary

Segment Trees are a general class of online data structures, represented by a complete binary tree with the leaves built on an array such that all nodes in the tree (excluding leaves) are a function of its children. This specific implementation requires said function to be commutative (such as sum, min, max, gcd, etc.). More specifically, it supports:
- Given two indices $l, r$, it finds $a_l \oplus a_{l + 1} \oplus \dots \oplus a_r$ where "$\oplus$" is a (commutative) operation.
- Given an index $i$ and a value $v$, assigns $a_i$ to $v$. 

Both these operations are performed in $\mathcal{O}(\log n)$, where $n$ is the number of elements represented by the segment tree. The total space complexity is linear (more specifically, it allocates $2n$ memory). Note that all indices are zero-based. For a similar data structure, see the [binary index tree](https://dutinmeow.github.io/library/data-structure/binary-index-tree.hpp). 

### Documentation

#### Parameters

- `typename T`: Type
- `typename merge_t`: Specifies how values are to be combined (essentially the "$\oplus$" operator). It takes in two values and merges them into a single value. In this specific use case, this function must be commutative (ie $\texttt{merge}(a, b) = \texttt{merge}(b, a)$). For non-commutative merge functions, see the [recursive implementation of segment tree](https://dutinmeow.github.io/library/data-structure/general-recursive-segment-tree.hpp). 
- `typename assign_t`: Applies an update with value $b$ to a node with value $a$. This will most likely always be the `=` or `+=` operator. 
- `T dval`: This variable is the default value, which depends on the type of $T$ and $\texttt{merge}$ function. For any $v \neq \texttt{dval}$, $\texttt{dval}$ should satisfy $v = \texttt{merge}(v, \texttt{dval})$. For instance, a sum operator would mean that $\texttt{dval} = 0$, and a min operator would mean that $\texttt{dval} = \infty$. 

#### Functions

- `segtree(merge_t merge, assign_t assign)`: Constructs an empty segment tree.
- `void init(int n)`: Initializes a segment tree of size $n$. This takes $\mathcal{O}(n)$ time.
- `void init(Iterator begin, Iterator end)`: Initializes a segment tree with values specified by $\texttt{begin}$ and $\texttt{end}$. This runs in $\mathcal{O}(n)$ time.
- `void update(int i, T v)`: Assigns $a_i$ to value $v$. This runs in $\mathcal{O}(\log n)$. 
- `T query(int l, int r)`: Returns $\bigoplus_{k = l}^r a_k$, where "$\oplus$" is a commutative merge function (defined in `merge` – see below). This runs in $\mathcal{O}(\log n)$ time.
- `T operator[](int i)`: Returns $a_i$. This runs in $\mathcal{O}(1)$ time.