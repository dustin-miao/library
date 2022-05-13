---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/union-find.hpp
    title: Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/kruskal.aizu-minimum-spanning-tree.test.cpp
    title: verify/kruskal.aizu-minimum-spanning-tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/union-find.hpp\"\n#pragma region union_find\n\
    \nstruct union_find {\n    vector<int> par, siz;\n\n    union_find() = default;\n\
    \n    union_find(int n) { init(n); }\n\n    void init(int n) {\n        par.resize(n);\n\
    \        siz.resize(n);\n        iota(par.begin(), par.end(), 0);\n        fill(siz.begin(),\
    \ siz.end(), 1);\n    }\n\n    int find(int u) {\n        if (u == par[u])\n \
    \           return u;\n        return par[u] = find(par[u]);\n    }\n\n    bool\
    \ merge(int u, int v) {\n        u = find(u), v = find(v);\n        if (u == v)\n\
    \            return false;\n        if (siz[u] > siz[v]) {\n            par[v]\
    \ = u;\n            siz[u] += siz[v];\n        } else {\n            par[u] =\
    \ v;\n            siz[v] += siz[u];\n        }\n        return true;\n    }\n\n\
    \    int size(int u) { return siz[find(u)]; }\n};\n\n#pragma endregion union_find\n\
    #line 2 \"graph/kruskal.hpp\"\n\n#pragma region kruskal\n\n#ifndef KRUSKAL_HPP\n\
    #define KRUSKAL_HPP\n\nnamespace graph {\n\ttemplate<class T>\n\tvector<vector<pair<int,\
    \ T>>> kruskal(int n, vector<tuple<int, int, T>> E) {\n\t\tvector<vector<pair<int,\
    \ T>>> mst(n);\n\t\tif (n <= 1)\n\t\t\treturn mst;\n\t\tunion_find dsu(n);\n\t\
    \tsort(E.begin(), E.end(), \n\t\t\t[](auto a, auto b) { \n\t\t\t\treturn get<2>(a)\
    \ < get<2>(b); \n\t\t\t}\n\t\t);\n\t\tfor (auto [u, v, w] : E) {\n\t\t\tif (dsu.merge(u,\
    \ v)) {\n\t\t\t\tmst[u].emplace_back(v, w);\n\t\t\t\tmst[v].emplace_back(u, w);\n\
    \t\t\t}\n\t\t\tif (dsu.size(0) == n)\n\t\t\t\tbreak;\n\t\t}\n\t\treturn mst;\n\
    \t}\n}\n\n#endif\n\n#pragma endregion kruskal\n"
  code: "#include \"data-structure/union-find.hpp\"\n\n#pragma region kruskal\n\n\
    #ifndef KRUSKAL_HPP\n#define KRUSKAL_HPP\n\nnamespace graph {\n\ttemplate<class\
    \ T>\n\tvector<vector<pair<int, T>>> kruskal(int n, vector<tuple<int, int, T>>\
    \ E) {\n\t\tvector<vector<pair<int, T>>> mst(n);\n\t\tif (n <= 1)\n\t\t\treturn\
    \ mst;\n\t\tunion_find dsu(n);\n\t\tsort(E.begin(), E.end(), \n\t\t\t[](auto a,\
    \ auto b) { \n\t\t\t\treturn get<2>(a) < get<2>(b); \n\t\t\t}\n\t\t);\n\t\tfor\
    \ (auto [u, v, w] : E) {\n\t\t\tif (dsu.merge(u, v)) {\n\t\t\t\tmst[u].emplace_back(v,\
    \ w);\n\t\t\t\tmst[v].emplace_back(u, w);\n\t\t\t}\n\t\t\tif (dsu.size(0) == n)\n\
    \t\t\t\tbreak;\n\t\t}\n\t\treturn mst;\n\t}\n}\n\n#endif\n\n#pragma endregion\
    \ kruskal"
  dependsOn:
  - data-structure/union-find.hpp
  isVerificationFile: false
  path: graph/kruskal.hpp
  requiredBy: []
  timestamp: '2022-05-13 08:14:05-07:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/kruskal.aizu-minimum-spanning-tree.test.cpp
documentation_of: graph/kruskal.hpp
layout: document
title: Kruskal's Algorithm
---

## Kruskal's Algorithm