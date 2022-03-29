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
    }\n#line 2 \"graph/dijkstra.hpp\"\n\ntemplate<typename T>\npair<vector<long long>,\
    \ vector<int>> dijkstra(const vector<vector<pair<int, T>>> &G, int s) {\n\tint\
    \ n = G.size();\n\tpriority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T,\
    \ int>>> pq;\n\tvector<T> dis(n, numeric_limits<T>::max());\n\tvector<int> par(n,\
    \ -1);\n\n\tpq.emplace(0, s);\n\tdis[s] = 0;\n\tpar[s] = s;\n\twhile (!pq.empty())\
    \ {\n\t\tauto [d, u] = pq.top(); pq.pop();\n\t\tif (d != dis[u])\n\t\t\tcontinue;\n\
    \t\tfor (auto [v, w] : G[u])\n\t\t\tif (chmin(dis[v], d + w)) {\n\t\t\t\tpar[v]\
    \ = u;\n\t\t\t\tpq.emplace(dis[v], v);\n\t\t\t}\n\t}\n\treturn {dis, par};\n}\n"
  code: "#include \"utility/chmin.hpp\"\n\ntemplate<typename T>\npair<vector<long\
    \ long>, vector<int>> dijkstra(const vector<vector<pair<int, T>>> &G, int s) {\n\
    \tint n = G.size();\n\tpriority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T,\
    \ int>>> pq;\n\tvector<T> dis(n, numeric_limits<T>::max());\n\tvector<int> par(n,\
    \ -1);\n\n\tpq.emplace(0, s);\n\tdis[s] = 0;\n\tpar[s] = s;\n\twhile (!pq.empty())\
    \ {\n\t\tauto [d, u] = pq.top(); pq.pop();\n\t\tif (d != dis[u])\n\t\t\tcontinue;\n\
    \t\tfor (auto [v, w] : G[u])\n\t\t\tif (chmin(dis[v], d + w)) {\n\t\t\t\tpar[v]\
    \ = u;\n\t\t\t\tpq.emplace(dis[v], v);\n\t\t\t}\n\t}\n\treturn {dis, par};\n}"
  dependsOn:
  - utility/chmin.hpp
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2022-03-29 12:51:37-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/dijkstra.aizu-shortest-path.test.cpp
  - verify/dijkstra.aizu-single-source-shortest-path.test.cpp
documentation_of: graph/dijkstra.hpp
layout: document
title: Dijkstra's Algorithm
---

## Dijkstra's Algorithm