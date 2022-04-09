---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/union-find.hpp
    title: Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/kruskal.aizu-minimum-spanning-tree.test.cpp
    title: verify/kruskal.aizu-minimum-spanning-tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/union-find.hpp\"\nstruct union_find {\n \
    \   vector<int> par, siz;\n\n    union_find() = default;\n\n    union_find(int\
    \ n) { init(n); }\n\n    void init(int n) {\n        par.resize(n);\n        siz.resize(n);\n\
    \        iota(par.begin(), par.end(), 0);\n        fill(siz.begin(), siz.end(),\
    \ 1);\n    }\n\n    int find(int u) {\n        if (u == par[u])\n            return\
    \ u;\n        return par[u] = find(par[u]);\n    }\n\n    bool merge(int u, int\
    \ v) {\n        u = find(u), v = find(v);\n        if (u == v)\n            return\
    \ false;\n        if (siz[u] > siz[v]) {\n            par[v] = u;\n          \
    \  siz[u] += siz[v];\n        } else {\n            par[u] = v;\n            siz[v]\
    \ += siz[u];\n        }\n        return true;\n    }\n\n    int size(int u) {\
    \ return siz[find(u)]; }\n};\n#line 2 \"graph/kruskal.hpp\"\n\ntemplate<class\
    \ T>\nvector<vector<pair<int, T>>> kruskal(int n, vector<tuple<int, int, T>> E)\
    \ {\n\tvector<vector<pair<int, T>>> mst(n);\n\tif (n <= 1)\n\t\treturn mst;\n\t\
    union_find dsu(n);\n\tsort(E.begin(), E.end(), \n\t\t[](auto a, auto b) { \n\t\
    \t\treturn get<2>(a) < get<2>(b); \n\t\t}\n\t);\n\tfor (auto [u, v, w] : E) {\n\
    \t\tif (dsu.merge(u, v)) {\n\t\t\tmst[u].emplace_back(v, w);\n\t\t\tmst[v].emplace_back(u,\
    \ w);\n\t\t}\n\t\tif (dsu.size(0) == n)\n\t\t\tbreak;\n\t}\n\treturn mst;\n}\n"
  code: "#include \"data-structure/union-find.hpp\"\n\ntemplate<class T>\nvector<vector<pair<int,\
    \ T>>> kruskal(int n, vector<tuple<int, int, T>> E) {\n\tvector<vector<pair<int,\
    \ T>>> mst(n);\n\tif (n <= 1)\n\t\treturn mst;\n\tunion_find dsu(n);\n\tsort(E.begin(),\
    \ E.end(), \n\t\t[](auto a, auto b) { \n\t\t\treturn get<2>(a) < get<2>(b); \n\
    \t\t}\n\t);\n\tfor (auto [u, v, w] : E) {\n\t\tif (dsu.merge(u, v)) {\n\t\t\t\
    mst[u].emplace_back(v, w);\n\t\t\tmst[v].emplace_back(u, w);\n\t\t}\n\t\tif (dsu.size(0)\
    \ == n)\n\t\t\tbreak;\n\t}\n\treturn mst;\n}"
  dependsOn:
  - data-structure/union-find.hpp
  isVerificationFile: false
  path: graph/kruskal.hpp
  requiredBy: []
  timestamp: '2022-04-09 15:55:38-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/kruskal.aizu-minimum-spanning-tree.test.cpp
documentation_of: graph/kruskal.hpp
layout: document
title: Kruskal's Algorithm
---

## Kruskal's Algorithm