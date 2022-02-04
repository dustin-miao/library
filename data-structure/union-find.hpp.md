---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.hpp
    title: Kruskal's Algorithm
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/kruskal.aizu-minimum-spanning-tree.test.cpp
    title: verify/kruskal.aizu-minimum-spanning-tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/union-find.aizu-disjoint-union.test.cpp
    title: verify/union-find.aizu-disjoint-union.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/union-find.yosupo-unionfind.test.cpp
    title: verify/union-find.yosupo-unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/union-find.hpp\"\nstruct UnionFind {\n  \
    \  vector<int> par, siz;\n\n    UnionFind() = default;\n\n    UnionFind(int n)\
    \ { init(n); }\n\n    void init(int n) {\n        par.resize(n);\n        siz.resize(n);\n\
    \        iota(par.begin(), par.end(), 0);\n        fill(siz.begin(), siz.end(),\
    \ 1);\n    }\n\n    int find(int u) {\n        if (u == par[u])\n            return\
    \ u;\n        return par[u] = find(par[u]);\n    }\n\n    bool merge(int u, int\
    \ v) {\n        u = find(u), v = find(v);\n        if (u == v)\n            return\
    \ false;\n        if (siz[u] > siz[v]) {\n            par[v] = u;\n          \
    \  siz[u] += siz[v];\n        } else {\n            par[u] = v;\n            siz[v]\
    \ += siz[u];\n        }\n        return true;\n    }\n\n    int size(int u) {\
    \ return siz[find(u)]; }\n};\n"
  code: "struct UnionFind {\n    vector<int> par, siz;\n\n    UnionFind() = default;\n\
    \n    UnionFind(int n) { init(n); }\n\n    void init(int n) {\n        par.resize(n);\n\
    \        siz.resize(n);\n        iota(par.begin(), par.end(), 0);\n        fill(siz.begin(),\
    \ siz.end(), 1);\n    }\n\n    int find(int u) {\n        if (u == par[u])\n \
    \           return u;\n        return par[u] = find(par[u]);\n    }\n\n    bool\
    \ merge(int u, int v) {\n        u = find(u), v = find(v);\n        if (u == v)\n\
    \            return false;\n        if (siz[u] > siz[v]) {\n            par[v]\
    \ = u;\n            siz[u] += siz[v];\n        } else {\n            par[u] =\
    \ v;\n            siz[v] += siz[u];\n        }\n        return true;\n    }\n\n\
    \    int size(int u) { return siz[find(u)]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/union-find.hpp
  requiredBy:
  - graph/kruskal.hpp
  timestamp: '2022-02-02 10:15:02-08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/union-find.aizu-disjoint-union.test.cpp
  - verify/union-find.yosupo-unionfind.test.cpp
  - verify/kruskal.aizu-minimum-spanning-tree.test.cpp
documentation_of: data-structure/union-find.hpp
layout: document
title: Union Find
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
