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
    #ifndef CYCLE_FINDING_HPP\n#define CYCLE_FINDING_HPP\n\nnamespace graph {\n\t\
    vector<pair<int, int>> find_cycle(const vector<vector<int>> &G, bool directed)\
    \ {\n\t\tint n = G.size();\n\t\tvector<int> idx(n, -1);\n\t\tvector<bool> vis(n,\
    \ false);\n\t\tvector<pair<int, int>> cycle;\n\t\tbool fin = 0;\n\n\t\tconst auto\
    \ dfs = [&](const auto &self, int u, int id, int p) -> int {\n\t\t\tidx[u] = id;\n\
    \t\t\tvis[u] = true;\n\t\t\tfor (int v : G[u]) {\n\t\t\t\tif (fin)\n\t\t\t\t\t\
    return -1;\n\t\t\t\tif (!directed && v == p)\n\t\t\t\t\tcontinue;\n\t\t\t\tif\
    \ (idx[u] == idx[v]) {\n\t\t\t\t\tcycle.emplace_back(u, v);\n\t\t\t\t\treturn\
    \ v;\n\t\t\t\t}\n\t\t\t\tif (vis[v])\n\t\t\t\t\tcontinue;\n\t\t\t\tint k = self(self,\
    \ v, id, u);\n\t\t\t\tif (k != -1) {\n\t\t\t\t\tcycle.emplace_back(u, v);\n\t\t\
    \t\t\tif (u == k) {\n\t\t\t\t\t\tfin = 1;\n\t\t\t\t\t\treturn -1;\n\t\t\t\t\t\
    }\n\t\t\t\t\treturn k;\n\t\t\t\t}\n\t\t\t}\n\t\t\tidx[u] = -1;\n\t\t\treturn -1;\n\
    \t\t};\n\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\tif (vis[i])\n\t\t\t\tcontinue;\n\
    \t\t\tdfs(dfs, i, i, -1);\n\t\t\tif (fin) {\n\t\t\t\treverse(cycle.begin(), cycle.end());\n\
    \t\t\t\treturn cycle;\n\t\t\t}\n\t\t}\n\t\treturn vector<pair<int, int>>{};\n\t\
    }\n\n\ttemplate<typename T>\n\tvector<pair<int, int>> find_cycle(const vector<vector<pair<int,\
    \ T>>> &G, bool directed) {\n\t\tint n = G.size();\n\t\tvector<int> idx(n, -1);\n\
    \t\tvector<bool> vis(n, false);\n\t\tvector<pair<int, int>> cycle;\n\t\tbool fin\
    \ = 0;\n\n\t\tconst auto dfs = [&](const auto &self, int u, int id, int p) ->\
    \ int {\n\t\t\tidx[u] = id;\n\t\t\tvis[u] = true;\n\t\t\tfor (auto [v, w] : G[u])\
    \ {\n\t\t\t\tif (fin)\n\t\t\t\t\treturn -1;\n\t\t\t\tif (!directed && v == p)\n\
    \t\t\t\t\tcontinue;\n\t\t\t\tif (idx[u] == idx[v]) {\n\t\t\t\t\tcycle.emplace_back(u,\
    \ v);\n\t\t\t\t\treturn v;\n\t\t\t\t}\n\t\t\t\tif (vis[v])\n\t\t\t\t\tcontinue;\n\
    \t\t\t\tint k = self(self, v, id, u);\n\t\t\t\tif (k != -1) {\n\t\t\t\t\tcycle.emplace_back(u,\
    \ v);\n\t\t\t\t\tif (u == k) {\n\t\t\t\t\t\tfin = 1;\n\t\t\t\t\t\treturn -1;\n\
    \t\t\t\t\t}\n\t\t\t\t\treturn k;\n\t\t\t\t}\n\t\t\t}\n\t\t\tidx[u] = -1;\n\t\t\
    \treturn -1;\n\t\t};\n\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\tif (vis[i])\n\
    \t\t\t\tcontinue;\n\t\t\tdfs(dfs, i, i, -1);\n\t\t\tif (fin) {\n\t\t\t\treverse(cycle.begin(),\
    \ cycle.end());\n\t\t\t\treturn cycle;\n\t\t\t}\n\t\t}\n\t\treturn vector<pair<int,\
    \ int>>{};\n\t}\n}\n\n#endif\n\n#pragma endregion find_cycle\n"
  code: "#pragma region find_cycle\n\n#ifndef CYCLE_FINDING_HPP\n#define CYCLE_FINDING_HPP\n\
    \nnamespace graph {\n\tvector<pair<int, int>> find_cycle(const vector<vector<int>>\
    \ &G, bool directed) {\n\t\tint n = G.size();\n\t\tvector<int> idx(n, -1);\n\t\
    \tvector<bool> vis(n, false);\n\t\tvector<pair<int, int>> cycle;\n\t\tbool fin\
    \ = 0;\n\n\t\tconst auto dfs = [&](const auto &self, int u, int id, int p) ->\
    \ int {\n\t\t\tidx[u] = id;\n\t\t\tvis[u] = true;\n\t\t\tfor (int v : G[u]) {\n\
    \t\t\t\tif (fin)\n\t\t\t\t\treturn -1;\n\t\t\t\tif (!directed && v == p)\n\t\t\
    \t\t\tcontinue;\n\t\t\t\tif (idx[u] == idx[v]) {\n\t\t\t\t\tcycle.emplace_back(u,\
    \ v);\n\t\t\t\t\treturn v;\n\t\t\t\t}\n\t\t\t\tif (vis[v])\n\t\t\t\t\tcontinue;\n\
    \t\t\t\tint k = self(self, v, id, u);\n\t\t\t\tif (k != -1) {\n\t\t\t\t\tcycle.emplace_back(u,\
    \ v);\n\t\t\t\t\tif (u == k) {\n\t\t\t\t\t\tfin = 1;\n\t\t\t\t\t\treturn -1;\n\
    \t\t\t\t\t}\n\t\t\t\t\treturn k;\n\t\t\t\t}\n\t\t\t}\n\t\t\tidx[u] = -1;\n\t\t\
    \treturn -1;\n\t\t};\n\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\tif (vis[i])\n\
    \t\t\t\tcontinue;\n\t\t\tdfs(dfs, i, i, -1);\n\t\t\tif (fin) {\n\t\t\t\treverse(cycle.begin(),\
    \ cycle.end());\n\t\t\t\treturn cycle;\n\t\t\t}\n\t\t}\n\t\treturn vector<pair<int,\
    \ int>>{};\n\t}\n\n\ttemplate<typename T>\n\tvector<pair<int, int>> find_cycle(const\
    \ vector<vector<pair<int, T>>> &G, bool directed) {\n\t\tint n = G.size();\n\t\
    \tvector<int> idx(n, -1);\n\t\tvector<bool> vis(n, false);\n\t\tvector<pair<int,\
    \ int>> cycle;\n\t\tbool fin = 0;\n\n\t\tconst auto dfs = [&](const auto &self,\
    \ int u, int id, int p) -> int {\n\t\t\tidx[u] = id;\n\t\t\tvis[u] = true;\n\t\
    \t\tfor (auto [v, w] : G[u]) {\n\t\t\t\tif (fin)\n\t\t\t\t\treturn -1;\n\t\t\t\
    \tif (!directed && v == p)\n\t\t\t\t\tcontinue;\n\t\t\t\tif (idx[u] == idx[v])\
    \ {\n\t\t\t\t\tcycle.emplace_back(u, v);\n\t\t\t\t\treturn v;\n\t\t\t\t}\n\t\t\
    \t\tif (vis[v])\n\t\t\t\t\tcontinue;\n\t\t\t\tint k = self(self, v, id, u);\n\t\
    \t\t\tif (k != -1) {\n\t\t\t\t\tcycle.emplace_back(u, v);\n\t\t\t\t\tif (u ==\
    \ k) {\n\t\t\t\t\t\tfin = 1;\n\t\t\t\t\t\treturn -1;\n\t\t\t\t\t}\n\t\t\t\t\t\
    return k;\n\t\t\t\t}\n\t\t\t}\n\t\t\tidx[u] = -1;\n\t\t\treturn -1;\n\t\t};\n\n\
    \t\tfor (int i = 0; i < n; i++) {\n\t\t\tif (vis[i])\n\t\t\t\tcontinue;\n\t\t\t\
    dfs(dfs, i, i, -1);\n\t\t\tif (fin) {\n\t\t\t\treverse(cycle.begin(), cycle.end());\n\
    \t\t\t\treturn cycle;\n\t\t\t}\n\t\t}\n\t\treturn vector<pair<int, int>>{};\n\t\
    }\n}\n\n#endif\n\n#pragma endregion find_cycle"
  dependsOn: []
  isVerificationFile: false
  path: graph/cycle-finding.hpp
  requiredBy: []
  timestamp: '2022-05-13 08:14:05-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/cycle-finding.yosupo-cycle-detection.test.cpp
documentation_of: graph/cycle-finding.hpp
layout: document
title: Cycle Finding
---

## Cycle Finding

TODO: Rewrite with [Y-Combinator](https://dutinmeow.github.io/library/utility/y-combinator.hpp). 