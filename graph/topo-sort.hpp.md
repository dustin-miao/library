---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/topo-sort.topological-sort.test.cpp
    title: verify/topo-sort.topological-sort.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/topo-sort.hpp\"\n#pragma region topo_sort\n\n#ifndef\
    \ TOPO_SORT_HPP\n#define TOPO_SORT_HPP\n\nvector<int> topo_sort(const vector<vector<int>>\
    \ &G) {\n\tint n = G.size();\n\tvector<bool> vis(n, false);\n\tvector<int> ord;\n\
    \tord.reserve(n);\n\n\tconst auto dfs = [&](const auto &self, int u) -> void {\n\
    \t\tvis[u] = true;\n\t\tfor (int v : G[u])\n\t\t\tif (!vis[v])\n\t\t\t\tself(self,\
    \ v);\n\t\tord.push_back(u);\n\t};\n\n\tfor (int i = 0; i < n; i++)\n\t\tif (!vis[i])\n\
    \t\t\tdfs(dfs, i);\n\treverse(ord.begin(), ord.end());\n\treturn ord;\n}\n\n#endif\n\
    \n#pragma endregion topo_sort\n"
  code: "#pragma region topo_sort\n\n#ifndef TOPO_SORT_HPP\n#define TOPO_SORT_HPP\n\
    \nvector<int> topo_sort(const vector<vector<int>> &G) {\n\tint n = G.size();\n\
    \tvector<bool> vis(n, false);\n\tvector<int> ord;\n\tord.reserve(n);\n\n\tconst\
    \ auto dfs = [&](const auto &self, int u) -> void {\n\t\tvis[u] = true;\n\t\t\
    for (int v : G[u])\n\t\t\tif (!vis[v])\n\t\t\t\tself(self, v);\n\t\tord.push_back(u);\n\
    \t};\n\n\tfor (int i = 0; i < n; i++)\n\t\tif (!vis[i])\n\t\t\tdfs(dfs, i);\n\t\
    reverse(ord.begin(), ord.end());\n\treturn ord;\n}\n\n#endif\n\n#pragma endregion\
    \ topo_sort"
  dependsOn: []
  isVerificationFile: false
  path: graph/topo-sort.hpp
  requiredBy: []
  timestamp: '2022-05-05 12:57:09-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/topo-sort.topological-sort.test.cpp
documentation_of: graph/topo-sort.hpp
layout: document
title: Topological Sort
---

## Topological Sort

TODO: Rewrite with [Y-Combinator](https://dutinmeow.github.io/library/utility/y-combinator.hpp). 