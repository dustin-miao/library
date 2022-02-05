---
title: Union Find
documentation_of: //data-structure/union-find.hpp
---

## Union Find

### Summary

Union-Find is an online data structure that maintains several disjoint sets that support the following operations:
- Given a vertex $u$, returns the root of the set of that contains $u$.
- Given two vertices $u, v$, merge them into a single set, provided they are not already in the same set.
- Determine the size of the set in which $u$ is contained. 

These operations are performed in amortized $\mathcal{O}(\alpha(n))$ time, where $n$ is the number of vertices maintained and $\alpha(n)$ is the inverse of the [Ackermann function](https://en.wikipedia.org/wiki/Ackermann_function). The data structure has a linear space complexity.

### Documentation

- `UnionFind()`: Constructs an empty `UnionFind` object. 
- `UnionFind(int n)`: Constructs a `UnionFind` object with $n$ disjoint sets in $\mathcal{O}(n)$.
- `void init(int n)`: Initializes the object such that it can store $n$ disjoing sets in $\mathcal{O}(n)$.  
- `int find(int u)`: Returns the root of the set in which $u$ is contained in amortized $\mathcal{O}(\alpha(n))$.
- `bool merge(int u, int v)`: Merges the sets containing $u$ and $v$ into a single set, provided that they start out in different sets. Returns a boolean value indicating whether this operation was successful. Works in amortized $\mathcal{O}(\alpha(n))$.
- `int size(int u)`: Returns the size of the set that contains $u$ in amortized $\mathcal{O}(\alpha(n))$