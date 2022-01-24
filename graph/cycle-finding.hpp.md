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
  bundledCode: "#line 1 \"graph/cycle-finding.hpp\"\ntemplate<typename G>\nvector<pair<int,\
    \ int>> find_cycle(const G &graph, const bool directed = true) {\n\tvector<int>\
    \ idx(graph.size(), -1), vis(graph.size(), 0);\n\tvector<pair<int, int>> cycle;\n\
    \tbool fin = 0;\n\n\tconst auto dfs = [&](const auto &self, int u, int id, int\
    \ p) -> int {\n\t\tidx[u] = id, vis[u] = 1;\n\t\tfor (int v : graph[u]) {\n\t\t\
    \tif (fin)\n\t\t\t\treturn -1;\n\t\t\tif (!directed && v == p)\n\t\t\t\tcontinue;\n\
    \t\t\tif (idx[u] == idx[v]) {\n\t\t\t\tcycle.emplace_back(u, v);\n\t\t\t\treturn\
    \ v;\n\t\t\t}\n\t\t\tif (vis[v])\n\t\t\t\tcontinue;\n\t\t\tint k = self(self,\
    \ v, id, u);\n\t\t\tif (k != -1) {\n\t\t\t\tcycle.emplace_back(u, v);\n\t\t\t\t\
    if (u == k) {\n\t\t\t\t\tfin = 1;\n\t\t\t\t\treturn -1;\n\t\t\t\t}\n\t\t\t\treturn\
    \ k;\n\t\t\t}\n\t\t}\n\t\tidx[u] = -1;\n\t\treturn -1;\n\t};\n\n\tfor (int i =\
    \ 0; i < graph.size(); i++) {\n\t\tif (vis[i])\n\t\t\tcontinue;\n\t\tdfs(dfs,\
    \ i, i, -1);\n\t\tif (fin) {\n\t\t\treverse(cycle.begin(), cycle.end());\n\t\t\
    \treturn cycle;\n\t\t}\n\t}\n\treturn vector<pair<int, int>>{};\n}\n"
  code: "template<typename G>\nvector<pair<int, int>> find_cycle(const G &graph, const\
    \ bool directed = true) {\n\tvector<int> idx(graph.size(), -1), vis(graph.size(),\
    \ 0);\n\tvector<pair<int, int>> cycle;\n\tbool fin = 0;\n\n\tconst auto dfs =\
    \ [&](const auto &self, int u, int id, int p) -> int {\n\t\tidx[u] = id, vis[u]\
    \ = 1;\n\t\tfor (int v : graph[u]) {\n\t\t\tif (fin)\n\t\t\t\treturn -1;\n\t\t\
    \tif (!directed && v == p)\n\t\t\t\tcontinue;\n\t\t\tif (idx[u] == idx[v]) {\n\
    \t\t\t\tcycle.emplace_back(u, v);\n\t\t\t\treturn v;\n\t\t\t}\n\t\t\tif (vis[v])\n\
    \t\t\t\tcontinue;\n\t\t\tint k = self(self, v, id, u);\n\t\t\tif (k != -1) {\n\
    \t\t\t\tcycle.emplace_back(u, v);\n\t\t\t\tif (u == k) {\n\t\t\t\t\tfin = 1;\n\
    \t\t\t\t\treturn -1;\n\t\t\t\t}\n\t\t\t\treturn k;\n\t\t\t}\n\t\t}\n\t\tidx[u]\
    \ = -1;\n\t\treturn -1;\n\t};\n\n\tfor (int i = 0; i < graph.size(); i++) {\n\t\
    \tif (vis[i])\n\t\t\tcontinue;\n\t\tdfs(dfs, i, i, -1);\n\t\tif (fin) {\n\t\t\t\
    reverse(cycle.begin(), cycle.end());\n\t\t\treturn cycle;\n\t\t}\n\t}\n\treturn\
    \ vector<pair<int, int>>{};\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/cycle-finding.hpp
  requiredBy: []
  timestamp: '2022-01-24 05:58:44-08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/cycle-finding.yosupo-cycle-detection.test.cpp
documentation_of: graph/cycle-finding.hpp
layout: document
redirect_from:
- /library/graph/cycle-finding.hpp
- /library/graph/cycle-finding.hpp.html
title: graph/cycle-finding.hpp
---
