---
title: Union Find
documentation_of: //data-structure/union-find.hpp
---

## Union Find

### Summary
Union-Find is an online data structure that maintains several disjoint sets, and supports the following operations:
- Given a vertex $u$, returns the root of the set of that contains $u$.
- Given two vertices $(u, v)$, merge them into a single set, provided they are not already in the same set.
- Determine the size of the set in which $u$ is contained. 

These operations are performed in amortized $\mathcal{O}(\alpha(n))$ time, where $n$ is the number of vertices maintained and $\alpha(n)$ is the inverse of the [Ackermann function](https://en.wikipedia.org/wiki/Ackermann_function). The data structure has a linear space complexity.