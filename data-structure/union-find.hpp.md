---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/data-structure/yosupo-union-find.test.cpp
    title: verify/data-structure/yosupo-union-find.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/union-find.hpp\"\nstruct UnionFind {\n  \
    \  vector<int> parent, setsize;\n\n    UnionFind() = default;\n\n    UnionFind(int\
    \ n) { init(n); }\n\n    void init(int n) {\n        parent.resize(n);\n     \
    \   setsize.resize(n);\n        iota(parent.begin(), parent.end(), 0);\n     \
    \   fill(setsize.begin(), setsize.end(), 1);\n    }\n\n    int find(int u) {\n\
    \        if (u == parent[u])\n            return u;\n        return parent[u]\
    \ = find(parent[u]);\n    }\n\n    bool merge(int u, int v) {\n        u = find(u),\
    \ v = find(v);\n        if (u == v)\n            return false;\n        if (setsize[u]\
    \ > setsize[v]) {\n            parent[v] = u;\n            setsize[u] += setsize[v];\n\
    \        } else {\n            parent[u] = v;\n            setsize[v] += setsize[u];\n\
    \        }\n        return true;\n    }\n\n    int size(int u) {\n        return\
    \ setsize[find(u)];\n    }\n};\n"
  code: "struct UnionFind {\n    vector<int> parent, setsize;\n\n    UnionFind() =\
    \ default;\n\n    UnionFind(int n) { init(n); }\n\n    void init(int n) {\n  \
    \      parent.resize(n);\n        setsize.resize(n);\n        iota(parent.begin(),\
    \ parent.end(), 0);\n        fill(setsize.begin(), setsize.end(), 1);\n    }\n\
    \n    int find(int u) {\n        if (u == parent[u])\n            return u;\n\
    \        return parent[u] = find(parent[u]);\n    }\n\n    bool merge(int u, int\
    \ v) {\n        u = find(u), v = find(v);\n        if (u == v)\n            return\
    \ false;\n        if (setsize[u] > setsize[v]) {\n            parent[v] = u;\n\
    \            setsize[u] += setsize[v];\n        } else {\n            parent[u]\
    \ = v;\n            setsize[v] += setsize[u];\n        }\n        return true;\n\
    \    }\n\n    int size(int u) {\n        return setsize[find(u)];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/union-find.hpp
  requiredBy: []
  timestamp: '2021-12-29 22:06:41-08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/data-structure/yosupo-union-find.test.cpp
documentation_of: data-structure/union-find.hpp
layout: document
title: Union find
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
