---
title: Binary Index Tree
documentation_of: //data-structure/binary-index-tree.hpp
---

## Binary Index Tree

### Summary

The binary index tree is an online range query point update data structure that supports the following operations:
- Given an index $i$, returns the value $\sum_{k = 1}^i a_k$.
- Given an index $i$ and a value $v$, assigns $a_i$ to $a_i + v$.

Both these operations are performed in $\mathcal{O}(\log n) time, where $n$ is the number of elements represented by the binary index tree. The total space complexity is linear. Note that all indices represented in a binary index tree are one-indexed.

Binary index trees cannot support non-reversible queries. This almost completely limits BIT to exclusively sum queries. Thus, for type `T`, the addition and subtraction operator must be defined. For other range operations, see [segment tree](https://dutinmeow.github.io/library/data-structure/segment-tree.hpp).



### Documentation

- `fentree()`: Constructs an empty binary index tree.
- `fentree(int n)`: Constructs a binary index tree object of size $n$ (meaning it can perform operations on the range $[1, n]$). Works in linear time.
- `fentree(Iterator begin, Iterator end)`: Constructs a binary index tree initialized with values specified by $\texttt{begin}$ and $\texttt{end}$. Works in $\mathcal{O}(n \log n)$ time.
- `T query(int i)`: Returns the value $\sum_{k = 1}^i a_k$. Works in $\mathcal{O}(\log n)$.
- `T query(int l, int r)`: Returns the value $\sum_{k = l}^r a_k$. Works in $\mathcal{O}(\log n)$.
- `T operator[](int i)`: Returns the value at index $i$ in $\mathcal{O}(\log n)$. 
- `void update(int i, T v)`: Sets the value of $a_i$ to $a_i + v$. Works in $\mathcal{O}(\log n)$.
