---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/union-find.hpp
    title: Union Find
  - icon: ':heavy_check_mark:'
    path: graph/graph-util.hpp
    title: Graph Utility
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
    \  vector<int> par, siz;\n\n    UnionFind() = default;\n\n    UnionFind(int n)\
    \ { init(n); }\n\n    void init(int n) {\n        par.resize(n);\n        siz.resize(n);\n\
    \        iota(par.begin(), par.end(), 0);\n        fill(siz.begin(), siz.end(),\
    \ 1);\n    }\n\n    int find(int u) {\n        if (u == par[u])\n            return\
    \ u;\n        return par[u] = find(par[u]);\n    }\n\n    bool merge(int u, int\
    \ v) {\n        u = find(u), v = find(v);\n        if (u == v)\n            return\
    \ false;\n        if (siz[u] > siz[v]) {\n            par[v] = u;\n          \
    \  siz[u] += siz[v];\n        } else {\n            par[u] = v;\n            siz[v]\
    \ += siz[u];\n        }\n        return true;\n    }\n\n    int size(int u) {\
    \ return siz[find(u)]; }\n};\n#line 1 \"graph/graph-util.hpp\"\nusing u_graph\
    \ = vector<vector<int>>;\n\nusing u_edgelist = vector<pair<int, int>>;\n\nusing\
    \ u_matgraph = vector<vector<bool>>;\n\nu_graph to_graph(size_t n, const u_edgelist\
    \ &E) {\n\tu_graph G(n);\n\tfor (auto [u, v] : E)\n\t\tG[u].push_back(v);\n\t\
    return G;\n}\n\nu_graph to_graph(const u_matgraph &M) {\n\tsize_t n = M.size();\n\
    \tu_graph G(n);\n\tfor (int u = 0; u < n; u++)\n\t\tfor (int v = 0; v < n; v++)\n\
    \t\t\tif (M[u][v])\n\t\t\t\tG[u].push_back(v);\n\treturn G;\n}\n\nu_edgelist to_edgelist(const\
    \ u_graph &G) {\n\tsize_t n = G.size();\n\tu_edgelist E;\n\tfor (int u = 0; u\
    \ < n; u++) \n\t\tfor (int v : G[u])\n\t\t\tE.emplace_back(u, v);\n\treturn E;\n\
    }\n\nu_edgelist to_edgelist(const u_matgraph &M) {\n\tsize_t n = M.size();\n\t\
    u_edgelist E;\n\tfor (int u = 0; u < n; u++)\n\t\tfor (int v = 0; v < n; v++)\n\
    \t\t\tif (M[u][v])\n\t\t\t\tE.emplace_back(u, v);\n\treturn E;\n}\n\nu_matgraph\
    \ to_matgraph(const u_graph &G) {\n\tint n = G.size();\n\tu_matgraph M(n, vector<bool>(n,\
    \ false));\n\tfor (int u = 0; u < n; u++)\n\t\tfor (int v : G[u])\n\t\t\tM[u][v]\
    \ = true;\n\treturn M;\n}\n\nu_matgraph to_matgraph(size_t n, const u_edgelist\
    \ &E) {\n\tu_matgraph M(n, vector<bool>(n, false));\n\tfor (auto [u, v] : E)\n\
    \t\tM[u][v] = true;\n\treturn M;\n}\n\ntemplate<typename T>\nusing graph = vector<vector<pair<int,\
    \ T>>>;\n\ntemplate<typename T>\nusing edgelist = vector<tuple<int, int, T>>;\n\
    \ntemplate<typename T>\nusing matgraph = vector<vector<T>>;\n\ntemplate<typename\
    \ T>\ngraph<T> to_graph(size_t n, const edgelist<T> &E) {\n\tgraph<T> G(n);\n\t\
    for (auto [u, v, w] : E)\n\t\tG[u].emplace_back(v, w);\n\treturn G;\n}\n\ntemplate<typename\
    \ T>\ngraph<T> to_graph(const matgraph<T> &M, const T dval) {\n\tsize_t n = M.size();\n\
    \tgraph<T> G(n);\n\tfor (int u = 0; u < n; u++)\n\t\tfor (int v = 0; v < n; v++)\n\
    \t\t\tif (M[u][v] != dval)\n\t\t\t\tG[u].emplace_back(v, M[u][v]);\n\treturn G;\n\
    }\n\ntemplate<typename T>\nedgelist<T> to_edgelist(const graph<T> &G) {\n\tsize_t\
    \ n = G.size();\n\tedgelist<T> E;\n\tfor (int u = 0; u < n; u++)\n\t\tfor (auto\
    \ [v, w] : G[u])\n\t\t\tE.emplace_back(u, v, w);\n\treturn E;\n}\n\ntemplate<typename\
    \ T>\nedgelist<T> to_edgelist(const matgraph<T> &M, const T dval) {\n\tsize_t\
    \ n = M.size();\n\tedgelist<T> E;\n\tfor (int u = 0; u < n; u++)\n\t\tfor (int\
    \ v = 0; v < n; v++)\n\t\t\tif (M[u][v] != dval)\n\t\t\t\tE.emplace_back(u, v,\
    \ M[u][v]);\n\treturn E;\n}\n\ntemplate<typename T>\nmatgraph<T> to_matgraph(const\
    \ graph<T> &G, const T dval) {\n\tsize_t n = G.size();\n\tmatgraph<T> M(n, vector<T>(n,\
    \ dval));\n\tfor (int u = 0; u < n; u++)\t\n\t\tfor (auto [v, w] : G[u])\n\t\t\
    \tM[u][v] = w;\n\treturn M;\n}\n\ntemplate<typename T>\nmatgraph<T> to_matgraph(size_t\
    \ n, const edgelist<T> &E, const T dval) {\n\tmatgraph<T> M(n, vector<T>(n, dval));\n\
    \tfor (auto [u, v, w] : E)\n\t\tM[u][v] = w;\n\treturn M;\n}\n#line 3 \"graph/kruskal.hpp\"\
    \n\ntemplate<typename T>\ngraph<T> kruskal(size_t n, edgelist<T> E) {\n\tgraph<T>\
    \ mst(n);\n\tif (n <= 1)\n\t\treturn mst;\n\tUnionFind dsu(n);\n\tsort(E.begin(),\
    \ E.end(), \n\t\t[](auto a, auto b) { \n\t\t\treturn get<2>(a) < get<2>(b); \n\
    \t\t}\n\t);\n\tfor (auto [u, v, w] : E) {\n\t\tif (dsu.merge(u, v)) {\n\t\t\t\
    mst[u].emplace_back(v, w);\n\t\t\tmst[v].emplace_back(u, w);\n\t\t}\n\t\tif (dsu.size(0)\
    \ == n)\n\t\t\tbreak;\n\t}\n\treturn mst;\n}\n"
  code: "#include \"data-structure/union-find.hpp\"\n#include \"graph/graph-util.hpp\"\
    \n\ntemplate<typename T>\ngraph<T> kruskal(size_t n, edgelist<T> E) {\n\tgraph<T>\
    \ mst(n);\n\tif (n <= 1)\n\t\treturn mst;\n\tUnionFind dsu(n);\n\tsort(E.begin(),\
    \ E.end(), \n\t\t[](auto a, auto b) { \n\t\t\treturn get<2>(a) < get<2>(b); \n\
    \t\t}\n\t);\n\tfor (auto [u, v, w] : E) {\n\t\tif (dsu.merge(u, v)) {\n\t\t\t\
    mst[u].emplace_back(v, w);\n\t\t\tmst[v].emplace_back(u, w);\n\t\t}\n\t\tif (dsu.size(0)\
    \ == n)\n\t\t\tbreak;\n\t}\n\treturn mst;\n}"
  dependsOn:
  - data-structure/union-find.hpp
  - graph/graph-util.hpp
  isVerificationFile: false
  path: graph/kruskal.hpp
  requiredBy: []
  timestamp: '2022-02-02 11:52:42-08:00'
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
