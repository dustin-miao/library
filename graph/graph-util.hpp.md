---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/cycle-finding.hpp
    title: Cycle Finding
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: Dijkstra's Algorithm
  - icon: ':heavy_check_mark:'
    path: graph/floyd-warshall.hpp
    title: Floyd-Warshall Algorithm
  - icon: ':x:'
    path: graph/kruskal.hpp
    title: Kruskal's Algorithm
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/cycle-finding.yosupo-cycle-detection.test.cpp
    title: verify/cycle-finding.yosupo-cycle-detection.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/dijkstra.aizu-shortest-path.test.cpp
    title: verify/dijkstra.aizu-shortest-path.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/dijkstra.aizu-single-source-shortest-path.test.cpp
    title: verify/dijkstra.aizu-single-source-shortest-path.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/floyd-warshall.all-pairs-shortest-path.test.cpp
    title: verify/floyd-warshall.all-pairs-shortest-path.test.cpp
  - icon: ':x:'
    path: verify/kruskal.aizu-minimum-spanning-tree.test.cpp
    title: verify/kruskal.aizu-minimum-spanning-tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/graph-util.hpp\"\nusing u_graph = vector<vector<int>>;\n\
    \nusing u_edgelist = vector<pair<int, int>>;\n\nusing u_matgraph = vector<vector<bool>>;\n\
    \nu_graph to_graph(size_t n, const u_edgelist &E) {\n\tu_graph G(n);\n\tfor (auto\
    \ [u, v] : E)\n\t\tG[u].push_back(v);\n\treturn G;\n}\n\nu_graph to_graph(const\
    \ u_matgraph &M) {\n\tsize_t n = M.size();\n\tu_graph G(n);\n\tfor (int u = 0;\
    \ u < n; u++)\n\t\tfor (int v = 0; v < n; v++)\n\t\t\tif (M[u][v])\n\t\t\t\tG[u].push_back(v);\n\
    \treturn G;\n}\n\nu_edgelist to_edgelist(const u_graph &G) {\n\tsize_t n = G.size();\n\
    \tu_edgelist E;\n\tfor (int u = 0; u < n; u++) \n\t\tfor (int v : G[u])\n\t\t\t\
    E.emplace_back(u, v);\n\treturn E;\n}\n\nu_edgelist to_edgelist(const u_matgraph\
    \ &M) {\n\tsize_t n = M.size();\n\tu_edgelist E;\n\tfor (int u = 0; u < n; u++)\n\
    \t\tfor (int v = 0; v < n; v++)\n\t\t\tif (M[u][v])\n\t\t\t\tE.emplace_back(u,\
    \ v);\n\treturn E;\n}\n\nu_matgraph to_matgraph(const u_graph &G) {\n\tint n =\
    \ G.size();\n\tu_matgraph M(n, vector<bool>(n, false));\n\tfor (int u = 0; u <\
    \ n; u++)\n\t\tfor (int v : G[u])\n\t\t\tM[u][v] = true;\n\treturn M;\n}\n\nu_matgraph\
    \ to_matgraph(size_t n, const u_edgelist &E) {\n\tu_matgraph M(n, vector<bool>(n,\
    \ false));\n\tfor (auto [u, v] : E)\n\t\tM[u][v] = true;\n\treturn M;\n}\n\ntemplate<typename\
    \ T>\nusing graph = vector<vector<pair<int, T>>>;\n\ntemplate<typename T>\nusing\
    \ edgelist = vector<tuple<int, int, T>>;\n\ntemplate<typename T>\nusing matgraph\
    \ = vector<vector<T>>;\n\ntemplate<typename T>\ngraph<T> to_graph(size_t n, const\
    \ edgelist<T> &E) {\n\tgraph<T> G(n);\n\tfor (auto [u, v, w] : E)\n\t\tG[u].emplace_back(v,\
    \ w);\n\treturn G;\n}\n\ntemplate<typename T>\ngraph<T> to_graph(const matgraph<T>\
    \ &M, const T dval) {\n\tsize_t n = M.size();\n\tgraph<T> G(n);\n\tfor (int u\
    \ = 0; u < n; u++)\n\t\tfor (int v = 0; v < n; v++)\n\t\t\tif (M[u][v] != dval)\n\
    \t\t\t\tG[u].emplace_back(v, M[u][v]);\n\treturn G;\n}\n\ntemplate<typename T>\n\
    edgelist<T> to_edgelist(const graph<T> &G) {\n\tsize_t n = G.size();\n\tedgelist<T>\
    \ E;\n\tfor (int u = 0; u < n; u++)\n\t\tfor (auto [v, w] : G[u])\n\t\t\tE.emplace_back(u,\
    \ v, w);\n\treturn E;\n}\n\ntemplate<typename T>\nedgelist<T> to_edgelist(const\
    \ matgraph<T> &M, const T dval) {\n\tsize_t n = M.size();\n\tedgelist<T> E;\n\t\
    for (int u = 0; u < n; u++)\n\t\tfor (int v = 0; v < n; v++)\n\t\t\tif (M[u][v]\
    \ != dval)\n\t\t\t\tE.emplace_back(u, v, M[u][v]);\n\treturn E;\n}\n\ntemplate<typename\
    \ T>\nmatgraph<T> to_matgraph(const graph<T> &G, const T dval) {\n\tsize_t n =\
    \ G.size();\n\tmatgraph<T> M(n, vector<T>(n, dval));\n\tfor (int u = 0; u < n;\
    \ u++)\t\n\t\tfor (auto [v, w] : G[u])\n\t\t\tM[u][v] = w;\n\treturn M;\n}\n\n\
    template<typename T>\nmatgraph<T> to_matgraph(size_t n, const edgelist<T> &E,\
    \ const T dval) {\n\tmatgraph<T> M(n, vector<T>(n, dval));\n\tfor (auto [u, v,\
    \ w] : E)\n\t\tM[u][v] = w;\n\treturn M;\n}\n"
  code: "using u_graph = vector<vector<int>>;\n\nusing u_edgelist = vector<pair<int,\
    \ int>>;\n\nusing u_matgraph = vector<vector<bool>>;\n\nu_graph to_graph(size_t\
    \ n, const u_edgelist &E) {\n\tu_graph G(n);\n\tfor (auto [u, v] : E)\n\t\tG[u].push_back(v);\n\
    \treturn G;\n}\n\nu_graph to_graph(const u_matgraph &M) {\n\tsize_t n = M.size();\n\
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
    \tfor (auto [u, v, w] : E)\n\t\tM[u][v] = w;\n\treturn M;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph-util.hpp
  requiredBy:
  - graph/floyd-warshall.hpp
  - graph/kruskal.hpp
  - graph/cycle-finding.hpp
  - graph/dijkstra.hpp
  timestamp: '2022-02-02 10:15:02-08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/kruskal.aizu-minimum-spanning-tree.test.cpp
  - verify/floyd-warshall.all-pairs-shortest-path.test.cpp
  - verify/dijkstra.aizu-single-source-shortest-path.test.cpp
  - verify/dijkstra.aizu-shortest-path.test.cpp
  - verify/cycle-finding.yosupo-cycle-detection.test.cpp
documentation_of: graph/graph-util.hpp
layout: document
title: Graph Utility
---

## Graph Utility

[Placeholder]