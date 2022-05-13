---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/chmin.hpp
    title: Chmin
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/prim.aizu-minimum-spanning-tree.test.cpp
    title: verify/prim.aizu-minimum-spanning-tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utility/chmin.hpp\"\n#pragma region chmin\n\n#ifndef CHMIN_HPP\n\
    #define CHMIN_HPP\n\ntemplate<typename T>\nbool chmin(T &a, T b) {\n\tif (a >\
    \ b) {\n\t\ta = b;\n\t\treturn true;\n\t}\n\treturn false;\n}\n\n#endif\n\n#pragma\
    \ endregion chmin\n#line 2 \"graph/prim.hpp\"\n\n#pragma region prim\n\n#ifndef\
    \ PRIM_HPP\n#define PRIM_HPP\n\nnamespace graph {\n\ttemplate<class T>\n\tvector<vector<pair<int,\
    \ T>>> prim(const vector<vector<pair<int, T>>> &G) {\n\t\tint n = G.size();\n\t\
    \tvector<vector<pair<int, T>>> mst(n);\n\t\tif (n <= 1)\n\t\t\treturn mst;\n\t\
    \tpriority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;\n\
    \t\tvector<T> dis(n, numeric_limits<T>::max());\n\t\tvector<int> par(n, -1);\n\
    \t\tvector<bool> vis(n, false);\n\n\t\tpq.emplace(0, 0);\n\t\tdis[0] = 0;\n\t\t\
    par[0] = 0;\n\t\twhile (!pq.empty()) {\n\t\t\tauto [d, u] = pq.top(); pq.pop();\n\
    \t\t\tif (vis[u])\n\t\t\t\tcontinue;\n\t\t\tvis[u] = true;\n\t\t\tif (u != 0)\
    \ {\n\t\t\t\tmst[u].emplace_back(par[u], d);\n\t\t\t\tmst[par[u]].emplace_back(u,\
    \ d);\n\t\t\t}\n\t\t\tfor (auto [v, w] : G[u])\n\t\t\t\tif (!vis[v] && chmin(dis[v],\
    \ w)) {\n\t\t\t\t\tpar[v] = u;\n\t\t\t\t\tpq.emplace(dis[v], v);\n\t\t\t\t}\n\t\
    \t}\n\t\treturn mst;\n\t}\n}\n\n#endif\n\n#pragma endregion prim\n"
  code: "#include \"utility/chmin.hpp\"\n\n#pragma region prim\n\n#ifndef PRIM_HPP\n\
    #define PRIM_HPP\n\nnamespace graph {\n\ttemplate<class T>\n\tvector<vector<pair<int,\
    \ T>>> prim(const vector<vector<pair<int, T>>> &G) {\n\t\tint n = G.size();\n\t\
    \tvector<vector<pair<int, T>>> mst(n);\n\t\tif (n <= 1)\n\t\t\treturn mst;\n\t\
    \tpriority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;\n\
    \t\tvector<T> dis(n, numeric_limits<T>::max());\n\t\tvector<int> par(n, -1);\n\
    \t\tvector<bool> vis(n, false);\n\n\t\tpq.emplace(0, 0);\n\t\tdis[0] = 0;\n\t\t\
    par[0] = 0;\n\t\twhile (!pq.empty()) {\n\t\t\tauto [d, u] = pq.top(); pq.pop();\n\
    \t\t\tif (vis[u])\n\t\t\t\tcontinue;\n\t\t\tvis[u] = true;\n\t\t\tif (u != 0)\
    \ {\n\t\t\t\tmst[u].emplace_back(par[u], d);\n\t\t\t\tmst[par[u]].emplace_back(u,\
    \ d);\n\t\t\t}\n\t\t\tfor (auto [v, w] : G[u])\n\t\t\t\tif (!vis[v] && chmin(dis[v],\
    \ w)) {\n\t\t\t\t\tpar[v] = u;\n\t\t\t\t\tpq.emplace(dis[v], v);\n\t\t\t\t}\n\t\
    \t}\n\t\treturn mst;\n\t}\n}\n\n#endif\n\n#pragma endregion prim"
  dependsOn:
  - utility/chmin.hpp
  isVerificationFile: false
  path: graph/prim.hpp
  requiredBy: []
  timestamp: '2022-05-13 08:14:05-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/prim.aizu-minimum-spanning-tree.test.cpp
documentation_of: graph/prim.hpp
layout: document
title: Prim's Algorithm
---

## Prim's Algorithm