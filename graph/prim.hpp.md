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
    \ PRIM_HPP\n#define PRIM_HPP\n\ntemplate<class T>\nvector<vector<pair<int, T>>>\
    \ prim(const vector<vector<pair<int, T>>> &G) {\n\tint n = G.size();\n\tvector<vector<pair<int,\
    \ T>>> mst(n);\n\tif (n <= 1)\n\t\treturn mst;\n\tpriority_queue<pair<T, int>,\
    \ vector<pair<T, int>>, greater<pair<T, int>>> pq;\n\tvector<T> dis(n, numeric_limits<T>::max());\n\
    \tvector<int> par(n, -1);\n\tvector<bool> vis(n, false);\n\n\tpq.emplace(0, 0);\n\
    \tdis[0] = 0;\n\tpar[0] = 0;\n\twhile (!pq.empty()) {\n\t\tauto [d, u] = pq.top();\
    \ pq.pop();\n\t\tif (vis[u])\n\t\t\tcontinue;\n\t\tvis[u] = true;\n\t\tif (u !=\
    \ 0) {\n\t\t\tmst[u].emplace_back(par[u], d);\n\t\t\tmst[par[u]].emplace_back(u,\
    \ d);\n\t\t}\n\t\tfor (auto [v, w] : G[u])\n\t\t\tif (!vis[v] && chmin(dis[v],\
    \ w)) {\n\t\t\t\tpar[v] = u;\n\t\t\t\tpq.emplace(dis[v], v);\n\t\t\t}\n\t}\n\t\
    return mst;\n}\n\n#endif\n\n#pragma endregion prim\n"
  code: "#include \"utility/chmin.hpp\"\n\n#pragma region prim\n\n#ifndef PRIM_HPP\n\
    #define PRIM_HPP\n\ntemplate<class T>\nvector<vector<pair<int, T>>> prim(const\
    \ vector<vector<pair<int, T>>> &G) {\n\tint n = G.size();\n\tvector<vector<pair<int,\
    \ T>>> mst(n);\n\tif (n <= 1)\n\t\treturn mst;\n\tpriority_queue<pair<T, int>,\
    \ vector<pair<T, int>>, greater<pair<T, int>>> pq;\n\tvector<T> dis(n, numeric_limits<T>::max());\n\
    \tvector<int> par(n, -1);\n\tvector<bool> vis(n, false);\n\n\tpq.emplace(0, 0);\n\
    \tdis[0] = 0;\n\tpar[0] = 0;\n\twhile (!pq.empty()) {\n\t\tauto [d, u] = pq.top();\
    \ pq.pop();\n\t\tif (vis[u])\n\t\t\tcontinue;\n\t\tvis[u] = true;\n\t\tif (u !=\
    \ 0) {\n\t\t\tmst[u].emplace_back(par[u], d);\n\t\t\tmst[par[u]].emplace_back(u,\
    \ d);\n\t\t}\n\t\tfor (auto [v, w] : G[u])\n\t\t\tif (!vis[v] && chmin(dis[v],\
    \ w)) {\n\t\t\t\tpar[v] = u;\n\t\t\t\tpq.emplace(dis[v], v);\n\t\t\t}\n\t}\n\t\
    return mst;\n}\n\n#endif\n\n#pragma endregion prim"
  dependsOn:
  - utility/chmin.hpp
  isVerificationFile: false
  path: graph/prim.hpp
  requiredBy: []
  timestamp: '2022-05-05 12:57:09-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/prim.aizu-minimum-spanning-tree.test.cpp
documentation_of: graph/prim.hpp
layout: document
title: Prim's Algorithm
---

## Prim's Algorithm