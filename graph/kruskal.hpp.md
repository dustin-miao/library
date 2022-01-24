---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/union-find.hpp
    title: Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/kruskal.aizu-minimum-spanning-tree.test.cpp
    title: verify/kruskal.aizu-minimum-spanning-tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ setsize[find(u)];\n    }\n};\n#line 2 \"graph/kruskal.hpp\"\n\nvector<vector<pair<int,\
    \ long long>>> kruskal(int n, vector<tuple<int, int, long long>> edges) {\n\t\
    vector<vector<pair<int, long long>>> mst(n);\n\tif (n <= 1)\n\t\treturn mst;\n\
    \tUnionFind dsu(n);\n\tsort(edges.begin(), edges.end(), [](const tuple<int, int,\
    \ long long> &a, const tuple<int, int, long long> &b) { return get<2>(a) < get<2>(b);\
    \ });\n\tfor (auto [u, v, w] : edges) {\n\t\tif (dsu.merge(u, v)) {\n\t\t\tmst[u].emplace_back(v,\
    \ w);\n\t\t\tmst[v].emplace_back(u, w);\n\t\t}\n\t\tif (dsu.size(0) == n)\n\t\t\
    \tbreak;\n\t}\n\treturn mst;\n}\n"
  code: "#include \"data-structure/union-find.hpp\"\n\nvector<vector<pair<int, long\
    \ long>>> kruskal(int n, vector<tuple<int, int, long long>> edges) {\n\tvector<vector<pair<int,\
    \ long long>>> mst(n);\n\tif (n <= 1)\n\t\treturn mst;\n\tUnionFind dsu(n);\n\t\
    sort(edges.begin(), edges.end(), [](const tuple<int, int, long long> &a, const\
    \ tuple<int, int, long long> &b) { return get<2>(a) < get<2>(b); });\n\tfor (auto\
    \ [u, v, w] : edges) {\n\t\tif (dsu.merge(u, v)) {\n\t\t\tmst[u].emplace_back(v,\
    \ w);\n\t\t\tmst[v].emplace_back(u, w);\n\t\t}\n\t\tif (dsu.size(0) == n)\n\t\t\
    \tbreak;\n\t}\n\treturn mst;\n}"
  dependsOn:
  - data-structure/union-find.hpp
  isVerificationFile: false
  path: graph/kruskal.hpp
  requiredBy: []
  timestamp: '2022-01-24 09:06:47-08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/kruskal.aizu-minimum-spanning-tree.test.cpp
documentation_of: graph/kruskal.hpp
layout: document
title: Kruskal's Algorithm
---

## Kruskal's Algorithm

### Summary

Finds the minimum spanning tree of an undirected graph in $\mathcal{O}(\lvert E \rvert \log \lvert E \rvert)$. Returns the minimum spanning forest if a spanning tree doesn't exist

### Parameters
- `std::vector<std::tuple<int, int, long long>> edges`: A list of undirected edges $(\texttt{node1}, \texttt{node2}, \texttt{weight})$. 

