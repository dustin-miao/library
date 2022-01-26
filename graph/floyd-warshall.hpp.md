---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/chmin.hpp
    title: Chmin
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/floyd-warshall.all-pairs-shortest-path.test.cpp
    title: verify/floyd-warshall.all-pairs-shortest-path.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utility/chmin.hpp\"\ntemplate<typename T>\nbool chmin(T\
    \ &a, T b) {\n\tif (a > b) {\n\t\ta = b;\n\t\treturn true;\n\t}\n\treturn false;\n\
    }\n#line 2 \"graph/floyd-warshall.hpp\"\n\ntemplate<typename G>\nvoid floyd_warshall(G\
    \ &graph, const long long INF = LLONG_MAX) {\n\tint n = graph.size();\n\tfor (int\
    \ k = 0; k < n; k++)\n\t\tfor (int i = 0; i < n; i++)\n\t\t\tfor (int j = 0; j\
    \ < n; j++)\n\t\t\t\tif (graph[i][k] < INF && graph[k][j] < INF)\n\t\t\t\t\tchmin(graph[i][j],\
    \ graph[i][k] + graph[k][j]);\n\tfor (int i = 0; i < n; i++)\n\t\tfor (int j =\
    \ 0; j < n; j++)\n\t\t\tfor (int k = 0; k < n; k++)\n\t\t\t\tif (graph[i][k] <\
    \ INF && graph[k][j] < INF && graph[k][k] < 0)\n\t\t\t\t\tgraph[i][j] = -INF;\n\
    }\n"
  code: "#include \"utility/chmin.hpp\"\n\ntemplate<typename G>\nvoid floyd_warshall(G\
    \ &graph, const long long INF = LLONG_MAX) {\n\tint n = graph.size();\n\tfor (int\
    \ k = 0; k < n; k++)\n\t\tfor (int i = 0; i < n; i++)\n\t\t\tfor (int j = 0; j\
    \ < n; j++)\n\t\t\t\tif (graph[i][k] < INF && graph[k][j] < INF)\n\t\t\t\t\tchmin(graph[i][j],\
    \ graph[i][k] + graph[k][j]);\n\tfor (int i = 0; i < n; i++)\n\t\tfor (int j =\
    \ 0; j < n; j++)\n\t\t\tfor (int k = 0; k < n; k++)\n\t\t\t\tif (graph[i][k] <\
    \ INF && graph[k][j] < INF && graph[k][k] < 0)\n\t\t\t\t\tgraph[i][j] = -INF;\n\
    }"
  dependsOn:
  - utility/chmin.hpp
  isVerificationFile: false
  path: graph/floyd-warshall.hpp
  requiredBy: []
  timestamp: '2022-01-26 10:28:49-08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/floyd-warshall.all-pairs-shortest-path.test.cpp
documentation_of: graph/floyd-warshall.hpp
layout: document
title: Floyd-Warshall Algorithm
---

## Floyd-Warshall Algorithm

### Summary

Finds the shortest path between all nodes in $\mathcal{O}(n^3)$ time, where $n$ is the number of nodes. Works for both undirected and directed graphs. For nodes that have a potentially infinitly low distance (e.g. there exists some negative cycle), returns $-\infty$.

### Parameters
- `G &graph`: An adjacency matrix 
- `long long INF`: Some value of infinity used to denote that an edge does not exist between two nodes.  