---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/cycle-finding.yosupo-cycle-detection.test.cpp
    title: verify/cycle-finding.yosupo-cycle-detection.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/cycle-finding.hpp\"\n#pragma region find_cycle\n\n\
    #ifndef CYCLE_FINDING_HPP\n#define CYCLE_FINDING_HPP\n\nvector<pair<int, int>>\
    \ find_cycle(const vector<vector<int>> &G, bool directed) {\n\tint n = G.size();\n\
    \tvector<int> idx(n, -1);\n\tvector<bool> vis(n, false);\n\tvector<pair<int, int>>\
    \ cycle;\n\tbool fin = 0;\n\n\tconst auto dfs = [&](const auto &self, int u, int\
    \ id, int p) -> int {\n\t\tidx[u] = id;\n\t\tvis[u] = true;\n\t\tfor (int v :\
    \ G[u]) {\n\t\t\tif (fin)\n\t\t\t\treturn -1;\n\t\t\tif (!directed && v == p)\n\
    \t\t\t\tcontinue;\n\t\t\tif (idx[u] == idx[v]) {\n\t\t\t\tcycle.emplace_back(u,\
    \ v);\n\t\t\t\treturn v;\n\t\t\t}\n\t\t\tif (vis[v])\n\t\t\t\tcontinue;\n\t\t\t\
    int k = self(self, v, id, u);\n\t\t\tif (k != -1) {\n\t\t\t\tcycle.emplace_back(u,\
    \ v);\n\t\t\t\tif (u == k) {\n\t\t\t\t\tfin = 1;\n\t\t\t\t\treturn -1;\n\t\t\t\
    \t}\n\t\t\t\treturn k;\n\t\t\t}\n\t\t}\n\t\tidx[u] = -1;\n\t\treturn -1;\n\t};\n\
    \n\tfor (int i = 0; i < n; i++) {\n\t\tif (vis[i])\n\t\t\tcontinue;\n\t\tdfs(dfs,\
    \ i, i, -1);\n\t\tif (fin) {\n\t\t\treverse(cycle.begin(), cycle.end());\n\t\t\
    \treturn cycle;\n\t\t}\n\t}\n\treturn vector<pair<int, int>>{};\n}\n\ntemplate<typename\
    \ T>\nvector<pair<int, int>> find_cycle(const vector<vector<pair<int, T>>> &G,\
    \ bool directed) {\n\tint n = G.size();\n\tvector<int> idx(n, -1);\n\tvector<bool>\
    \ vis(n, false);\n\tvector<pair<int, int>> cycle;\n\tbool fin = 0;\n\n\tconst\
    \ auto dfs = [&](const auto &self, int u, int id, int p) -> int {\n\t\tidx[u]\
    \ = id;\n\t\tvis[u] = true;\n\t\tfor (auto [v, w] : G[u]) {\n\t\t\tif (fin)\n\t\
    \t\t\treturn -1;\n\t\t\tif (!directed && v == p)\n\t\t\t\tcontinue;\n\t\t\tif\
    \ (idx[u] == idx[v]) {\n\t\t\t\tcycle.emplace_back(u, v);\n\t\t\t\treturn v;\n\
    \t\t\t}\n\t\t\tif (vis[v])\n\t\t\t\tcontinue;\n\t\t\tint k = self(self, v, id,\
    \ u);\n\t\t\tif (k != -1) {\n\t\t\t\tcycle.emplace_back(u, v);\n\t\t\t\tif (u\
    \ == k) {\n\t\t\t\t\tfin = 1;\n\t\t\t\t\treturn -1;\n\t\t\t\t}\n\t\t\t\treturn\
    \ k;\n\t\t\t}\n\t\t}\n\t\tidx[u] = -1;\n\t\treturn -1;\n\t};\n\n\tfor (int i =\
    \ 0; i < n; i++) {\n\t\tif (vis[i])\n\t\t\tcontinue;\n\t\tdfs(dfs, i, i, -1);\n\
    \t\tif (fin) {\n\t\t\treverse(cycle.begin(), cycle.end());\n\t\t\treturn cycle;\n\
    \t\t}\n\t}\n\treturn vector<pair<int, int>>{};\n}\n\n#endif\n\n#pragma endregion\
    \ find_cycle\n"
  code: "#pragma region find_cycle\n\n#ifndef CYCLE_FINDING_HPP\n#define CYCLE_FINDING_HPP\n\
    \nvector<pair<int, int>> find_cycle(const vector<vector<int>> &G, bool directed)\
    \ {\n\tint n = G.size();\n\tvector<int> idx(n, -1);\n\tvector<bool> vis(n, false);\n\
    \tvector<pair<int, int>> cycle;\n\tbool fin = 0;\n\n\tconst auto dfs = [&](const\
    \ auto &self, int u, int id, int p) -> int {\n\t\tidx[u] = id;\n\t\tvis[u] = true;\n\
    \t\tfor (int v : G[u]) {\n\t\t\tif (fin)\n\t\t\t\treturn -1;\n\t\t\tif (!directed\
    \ && v == p)\n\t\t\t\tcontinue;\n\t\t\tif (idx[u] == idx[v]) {\n\t\t\t\tcycle.emplace_back(u,\
    \ v);\n\t\t\t\treturn v;\n\t\t\t}\n\t\t\tif (vis[v])\n\t\t\t\tcontinue;\n\t\t\t\
    int k = self(self, v, id, u);\n\t\t\tif (k != -1) {\n\t\t\t\tcycle.emplace_back(u,\
    \ v);\n\t\t\t\tif (u == k) {\n\t\t\t\t\tfin = 1;\n\t\t\t\t\treturn -1;\n\t\t\t\
    \t}\n\t\t\t\treturn k;\n\t\t\t}\n\t\t}\n\t\tidx[u] = -1;\n\t\treturn -1;\n\t};\n\
    \n\tfor (int i = 0; i < n; i++) {\n\t\tif (vis[i])\n\t\t\tcontinue;\n\t\tdfs(dfs,\
    \ i, i, -1);\n\t\tif (fin) {\n\t\t\treverse(cycle.begin(), cycle.end());\n\t\t\
    \treturn cycle;\n\t\t}\n\t}\n\treturn vector<pair<int, int>>{};\n}\n\ntemplate<typename\
    \ T>\nvector<pair<int, int>> find_cycle(const vector<vector<pair<int, T>>> &G,\
    \ bool directed) {\n\tint n = G.size();\n\tvector<int> idx(n, -1);\n\tvector<bool>\
    \ vis(n, false);\n\tvector<pair<int, int>> cycle;\n\tbool fin = 0;\n\n\tconst\
    \ auto dfs = [&](const auto &self, int u, int id, int p) -> int {\n\t\tidx[u]\
    \ = id;\n\t\tvis[u] = true;\n\t\tfor (auto [v, w] : G[u]) {\n\t\t\tif (fin)\n\t\
    \t\t\treturn -1;\n\t\t\tif (!directed && v == p)\n\t\t\t\tcontinue;\n\t\t\tif\
    \ (idx[u] == idx[v]) {\n\t\t\t\tcycle.emplace_back(u, v);\n\t\t\t\treturn v;\n\
    \t\t\t}\n\t\t\tif (vis[v])\n\t\t\t\tcontinue;\n\t\t\tint k = self(self, v, id,\
    \ u);\n\t\t\tif (k != -1) {\n\t\t\t\tcycle.emplace_back(u, v);\n\t\t\t\tif (u\
    \ == k) {\n\t\t\t\t\tfin = 1;\n\t\t\t\t\treturn -1;\n\t\t\t\t}\n\t\t\t\treturn\
    \ k;\n\t\t\t}\n\t\t}\n\t\tidx[u] = -1;\n\t\treturn -1;\n\t};\n\n\tfor (int i =\
    \ 0; i < n; i++) {\n\t\tif (vis[i])\n\t\t\tcontinue;\n\t\tdfs(dfs, i, i, -1);\n\
    \t\tif (fin) {\n\t\t\treverse(cycle.begin(), cycle.end());\n\t\t\treturn cycle;\n\
    \t\t}\n\t}\n\treturn vector<pair<int, int>>{};\n}\n\n#endif\n\n#pragma endregion\
    \ find_cycle"
  dependsOn: []
  isVerificationFile: false
  path: graph/cycle-finding.hpp
  requiredBy: []
  timestamp: '2022-05-05 12:57:09-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/cycle-finding.yosupo-cycle-detection.test.cpp
documentation_of: graph/cycle-finding.hpp
layout: document
title: Cycle Finding
---

## Cycle Finding

TODO: Rewrite with [Y-Combinator](https://dutinmeow.github.io/library/utility/y-combinator.hpp). 