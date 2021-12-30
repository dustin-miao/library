---
title: Union find
documentation_of: //data-structure/union-find.hpp
---

## Union Find

### Summary

Union Find is a data structure that maintains several disjoint sets. It supports the following operations:
- Given a vertex $u$, returns the root of the set of that contains $u$.
- Given two vertices $u, v$, merge them into a single set, provided they are not already in the same set.

The Union Find data structure supports both these operations in $\mathcal{O}(\alpha(n))$ time, where $n$ is the number of vertices maintained and $\alpha(n)$ is the inverse of the [Ackermann function](https://en.wikipedia.org/wiki/Ackermann_function). Note that $\alpha(n) \leq 6$ for all reasonable $n$ and can be regarded as a constant.

### Documentation

- `UnionFind()`: Constructs an empty `UnionFind` object. Works in $\mathcal{O}(1)$.
- `UnionFind(int n)`: Constructs a `UnionFind` object with $n$ disjoint sets. Works in $\mathcal{O}(n)$.
- `init(int n)`: Initializes the object such that it can store $n$ disjoing sets. Works in $\mathcal{O}(n)$.  
- `find(int u)`: Finds the root of the set in which $u$ is contained. Works in amortized $\mathcal{O}(\alpha(n))$.
- `merge(int u, int v)`: Merges the sets containing $u$ and $v$ into a single set, provided that they start out in different sets. Returns a boolean value indicating whether this operation was successful. Works in amortized $\mathcal{O}(\alpha(n))$.
- `size(int u)`: Finds the size of the set that contains $u$. Works in amortized $\mathcal{O}(\alpha(n))$
