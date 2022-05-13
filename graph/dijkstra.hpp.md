---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/chmin.hpp
    title: Chmin
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/dijkstra.aizu-single-source-shortest-path.test.cpp
    title: verify/dijkstra.aizu-single-source-shortest-path.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/dijkstra.yosupo-shortest-path.test.cpp
    title: verify/dijkstra.yosupo-shortest-path.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utility/chmin.hpp\"\n#pragma region chmin\n\n#ifndef CHMIN_HPP\n\
    #define CHMIN_HPP\n\ntemplate<typename T>\nbool chmin(T &a, T b) {\n\tif (a >\
    \ b) {\n\t\ta = b;\n\t\treturn true;\n\t}\n\treturn false;\n}\n\n#endif\n\n#pragma\
    \ endregion chmin\n#line 2 \"graph/dijkstra.hpp\"\n\n#pragma region dijkstra\n\
    \n#ifndef DIJKSTRA_HPP\n#define DIJKSTRA_HPP\n\nnamespace graph {\n\ttemplate<typename\
    \ T>\n\tpair<vector<long long>, vector<int>> dijkstra(const vector<vector<pair<int,\
    \ T>>> &G, int s) {\n\t\tint n = G.size();\n\t\tpriority_queue<pair<T, int>, vector<pair<T,\
    \ int>>, greater<pair<T, int>>> pq;\n\t\tvector<T> dis(n, numeric_limits<T>::max());\n\
    \t\tvector<int> par(n, -1);\n\n\t\tpq.emplace(0, s);\n\t\tdis[s] = 0;\n\t\tpar[s]\
    \ = s;\n\t\twhile (!pq.empty()) {\n\t\t\tauto [d, u] = pq.top(); pq.pop();\n\t\
    \t\tif (d != dis[u])\n\t\t\t\tcontinue;\n\t\t\tfor (auto [v, w] : G[u])\n\t\t\t\
    \tif (chmin(dis[v], d + w)) {\n\t\t\t\t\tpar[v] = u;\n\t\t\t\t\tpq.emplace(dis[v],\
    \ v);\n\t\t\t\t}\n\t\t}\n\t\treturn {dis, par};\n\t}\n}\n\n#endif\n\n#pragma endregion\
    \ dijkstra\n"
  code: "#include \"utility/chmin.hpp\"\n\n#pragma region dijkstra\n\n#ifndef DIJKSTRA_HPP\n\
    #define DIJKSTRA_HPP\n\nnamespace graph {\n\ttemplate<typename T>\n\tpair<vector<long\
    \ long>, vector<int>> dijkstra(const vector<vector<pair<int, T>>> &G, int s) {\n\
    \t\tint n = G.size();\n\t\tpriority_queue<pair<T, int>, vector<pair<T, int>>,\
    \ greater<pair<T, int>>> pq;\n\t\tvector<T> dis(n, numeric_limits<T>::max());\n\
    \t\tvector<int> par(n, -1);\n\n\t\tpq.emplace(0, s);\n\t\tdis[s] = 0;\n\t\tpar[s]\
    \ = s;\n\t\twhile (!pq.empty()) {\n\t\t\tauto [d, u] = pq.top(); pq.pop();\n\t\
    \t\tif (d != dis[u])\n\t\t\t\tcontinue;\n\t\t\tfor (auto [v, w] : G[u])\n\t\t\t\
    \tif (chmin(dis[v], d + w)) {\n\t\t\t\t\tpar[v] = u;\n\t\t\t\t\tpq.emplace(dis[v],\
    \ v);\n\t\t\t\t}\n\t\t}\n\t\treturn {dis, par};\n\t}\n}\n\n#endif\n\n#pragma endregion\
    \ dijkstra"
  dependsOn:
  - utility/chmin.hpp
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2022-05-13 08:14:05-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/dijkstra.aizu-single-source-shortest-path.test.cpp
  - verify/dijkstra.yosupo-shortest-path.test.cpp
documentation_of: graph/dijkstra.hpp
layout: document
title: Dijkstra's Algorithm
---

## Dijkstra's Algorithm