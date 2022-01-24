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
    \ setsize[find(u)];\n    }\n};\n#line 2 \"graph/kruskal.hpp\"\n\ntemplate<typename\
    \ G>\nlong long kruskal(const G &graph) {\n\tvector<tuple<long long, int, int>>\
    \ edges;\n\tfor (int u = 0; u < graph.size(); u++)\n\t\tfor (auto [v, w] : graph[u])\n\
    \t\t\tedges.emplace_back(u, v, w);\n\treturn kruskal(graph.size(), edges);\n}\n\
    \nlong long kruskal(int n, vector<tuple<int, int, long long>> edges) {\n\tUnionFind\
    \ dsu(n);\n\tsort(edges.begin(), edges.end(), [](const tuple<int, int, long long>\
    \ &a, const tuple<int, int, long long> &b) {\n\t\treturn get<2>(a) < get<2>(b);\
    \ \n\t});\n\tlong long ret = 0;\n\tfor (auto [u, v, w] : edges) {\n\t\tif (dsu.merge(u,\
    \ v))\n\t\t\tret += w;\n\t\tif (dsu.size(0) == n)\n\t\t\treturn ret;\n\t}\n\t\
    return n <= 1 ? 0 : LLONG_MAX;\n}\n"
  code: "#include \"data-structure/union-find.hpp\"\n\ntemplate<typename G>\nlong\
    \ long kruskal(const G &graph) {\n\tvector<tuple<long long, int, int>> edges;\n\
    \tfor (int u = 0; u < graph.size(); u++)\n\t\tfor (auto [v, w] : graph[u])\n\t\
    \t\tedges.emplace_back(u, v, w);\n\treturn kruskal(graph.size(), edges);\n}\n\n\
    long long kruskal(int n, vector<tuple<int, int, long long>> edges) {\n\tUnionFind\
    \ dsu(n);\n\tsort(edges.begin(), edges.end(), [](const tuple<int, int, long long>\
    \ &a, const tuple<int, int, long long> &b) {\n\t\treturn get<2>(a) < get<2>(b);\
    \ \n\t});\n\tlong long ret = 0;\n\tfor (auto [u, v, w] : edges) {\n\t\tif (dsu.merge(u,\
    \ v))\n\t\t\tret += w;\n\t\tif (dsu.size(0) == n)\n\t\t\treturn ret;\n\t}\n\t\
    return n <= 1 ? 0 : LLONG_MAX;\n}"
  dependsOn:
  - data-structure/union-find.hpp
  isVerificationFile: false
  path: graph/kruskal.hpp
  requiredBy: []
  timestamp: '2022-01-24 07:06:40-08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/kruskal.aizu-minimum-spanning-tree.test.cpp
documentation_of: graph/kruskal.hpp
layout: document
title: Kruskal's Algorithm
---

## Kruskal's Algorithm

### Summary

Finds the minimum spanning tree of an undirected graph if it exists in $\mathcal{O}(|E| \log |E|)$. Returns `LLONG_MAX` if no spanning tree exists

### Parameters
- `std::vector<std::tuple<int, int, long long>> edges`: A list of undirected edges $(\texttt{node1}, \texttt{node2}, \texttt{weight})$. 

