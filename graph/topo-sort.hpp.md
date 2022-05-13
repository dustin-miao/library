---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/topo-sort.topological-sort.test.cpp
    title: verify/topo-sort.topological-sort.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/topo-sort.hpp\"\n#pragma region topo_sort\n\n#ifndef\
    \ TOPO_SORT_HPP\n#define TOPO_SORT_HPP\n\nnamespace graph {\n\tvector<int> topo_sort(const\
    \ vector<vector<int>> &G) {\n\t\tint n = G.size();\n\t\tvector<bool> vis(n, false);\n\
    \t\tvector<int> ord;\n\t\tord.reserve(n);\n\n\t\tconst auto dfs = [&](const auto\
    \ &self, int u) -> void {\n\t\t\tvis[u] = true;\n\t\t\tfor (int v : G[u])\n\t\t\
    \t\tif (!vis[v])\n\t\t\t\t\tself(self, v);\n\t\t\tord.push_back(u);\n\t\t};\n\n\
    \t\tfor (int i = 0; i < n; i++)\n\t\t\tif (!vis[i])\n\t\t\t\tdfs(dfs, i);\n\t\t\
    reverse(ord.begin(), ord.end());\n\t\treturn ord;\n\t}\n}\n\n#endif\n\n#pragma\
    \ endregion topo_sort\n"
  code: "#pragma region topo_sort\n\n#ifndef TOPO_SORT_HPP\n#define TOPO_SORT_HPP\n\
    \nnamespace graph {\n\tvector<int> topo_sort(const vector<vector<int>> &G) {\n\
    \t\tint n = G.size();\n\t\tvector<bool> vis(n, false);\n\t\tvector<int> ord;\n\
    \t\tord.reserve(n);\n\n\t\tconst auto dfs = [&](const auto &self, int u) -> void\
    \ {\n\t\t\tvis[u] = true;\n\t\t\tfor (int v : G[u])\n\t\t\t\tif (!vis[v])\n\t\t\
    \t\t\tself(self, v);\n\t\t\tord.push_back(u);\n\t\t};\n\n\t\tfor (int i = 0; i\
    \ < n; i++)\n\t\t\tif (!vis[i])\n\t\t\t\tdfs(dfs, i);\n\t\treverse(ord.begin(),\
    \ ord.end());\n\t\treturn ord;\n\t}\n}\n\n#endif\n\n#pragma endregion topo_sort"
  dependsOn: []
  isVerificationFile: false
  path: graph/topo-sort.hpp
  requiredBy: []
  timestamp: '2022-05-13 08:14:05-07:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/topo-sort.topological-sort.test.cpp
documentation_of: graph/topo-sort.hpp
layout: document
title: Topological Sort
---

## Topological Sort

TODO: Rewrite with [Y-Combinator](https://dutinmeow.github.io/library/utility/y-combinator.hpp). 