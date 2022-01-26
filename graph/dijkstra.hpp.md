---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/chmin.hpp
    title: Chmin
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/dijkstra.aizu-shortest-path.test.cpp
    title: verify/dijkstra.aizu-shortest-path.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/dijkstra.aizu-single-source-shortest-path.test.cpp
    title: verify/dijkstra.aizu-single-source-shortest-path.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utility/chmin.hpp\"\ntemplate<typename T>\nbool chmin(T\
    \ &a, T b) {\n\tif (a > b) {\n\t\ta = b;\n\t\treturn true;\n\t}\n\treturn false;\n\
    }\n#line 2 \"graph/dijkstra.hpp\"\n\ntemplate<typename G>\npair<vector<long long>,\
    \ vector<int>> dijkstra(const G &graph, int s) {\n\tpriority_queue<pair<long long,\
    \ int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;\n\tvector<long\
    \ long> dis(graph.size(), LLONG_MAX);\n\tvector<int> par(graph.size(), -1);\n\n\
    \tpq.emplace(0, s);\n\tdis[s] = 0;\n\tpar[s] = s;\n\twhile (!pq.empty()) {\n\t\
    \tauto [d, u] = pq.top(); pq.pop();\n\t\tif (d != dis[u])\n\t\t\tcontinue;\n\t\
    \tfor (auto [v, w] : graph[u])\n\t\t\tif (chmin(dis[v], d + w)) {\n\t\t\t\tpar[v]\
    \ = u;\n\t\t\t\tpq.emplace(dis[v], v);\n\t\t\t}\n\t}\n\treturn {dis, par};\n}\n"
  code: "#include \"utility/chmin.hpp\"\n\ntemplate<typename G>\npair<vector<long\
    \ long>, vector<int>> dijkstra(const G &graph, int s) {\n\tpriority_queue<pair<long\
    \ long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;\n\
    \tvector<long long> dis(graph.size(), LLONG_MAX);\n\tvector<int> par(graph.size(),\
    \ -1);\n\n\tpq.emplace(0, s);\n\tdis[s] = 0;\n\tpar[s] = s;\n\twhile (!pq.empty())\
    \ {\n\t\tauto [d, u] = pq.top(); pq.pop();\n\t\tif (d != dis[u])\n\t\t\tcontinue;\n\
    \t\tfor (auto [v, w] : graph[u])\n\t\t\tif (chmin(dis[v], d + w)) {\n\t\t\t\t\
    par[v] = u;\n\t\t\t\tpq.emplace(dis[v], v);\n\t\t\t}\n\t}\n\treturn {dis, par};\n\
    }"
  dependsOn:
  - utility/chmin.hpp
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2022-01-26 06:14:01-08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/dijkstra.aizu-single-source-shortest-path.test.cpp
  - verify/dijkstra.aizu-shortest-path.test.cpp
documentation_of: graph/dijkstra.hpp
layout: document
title: Dijkstra's Algorithm
---

## Dijkstra's Algorithm

### Summary

Finds the shortest path from a source $S$ in a directed or undirected weighted graph. Returns both the distance to each node as well as the shortest path tree. 

### Parameters
- `const G& graph`: A `std::vector<T>` that describes the graph, where `T` is an iterable data structure containing integers.
- `int S`: The source vertex, `S` must be in `graph`. 