---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/union-find.hpp
    title: Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/union-find-2d.aizu-disjoint-union.test.cpp
    title: verify/union-find-2d.aizu-disjoint-union.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/union-find-2d.yosupo-unionfind.test.cpp
    title: verify/union-find-2d.yosupo-unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/union-find.hpp\"\nstruct UnionFind {\n  \
    \  vector<int> par, siz;\n\n    UnionFind() = default;\n\n    UnionFind(int n)\
    \ { init(n); }\n\n    void init(int n) {\n        par.resize(n);\n        siz.resize(n);\n\
    \        iota(par.begin(), par.end(), 0);\n        fill(siz.begin(), siz.end(),\
    \ 1);\n    }\n\n    int find(int u) {\n        if (u == par[u])\n            return\
    \ u;\n        return par[u] = find(par[u]);\n    }\n\n    bool merge(int u, int\
    \ v) {\n        u = find(u), v = find(v);\n        if (u == v)\n            return\
    \ false;\n        if (siz[u] > siz[v]) {\n            par[v] = u;\n          \
    \  siz[u] += siz[v];\n        } else {\n            par[u] = v;\n            siz[v]\
    \ += siz[u];\n        }\n        return true;\n    }\n\n    int size(int u) {\
    \ return siz[find(u)]; }\n};\n#line 2 \"data-structure/union-find-2d.hpp\"\n\n\
    struct UnionFind2d {\n\tint n, m;\n\tUnionFind dsu;\n\n\tUnionFind2d() = default;\n\
    \n\tUnionFind2d(int _n, int _m) { init(_n, _m); }\n\n\tvoid init(int _n, int _m)\
    \ { \n\t\tn = _n, m = _m;\n\t\tdsu.init(n * m); \n\t}\n\n\tint find(int ui, int\
    \ uj) { return dsu.find(ui * m + uj); }\n\n\tbool merge(int ui, int uj, int vi,\
    \ int vj) { return dsu.merge(ui * m + uj, vi * m + vj); }\n};\n\n"
  code: "#include \"data-structure/union-find.hpp\"\n\nstruct UnionFind2d {\n\tint\
    \ n, m;\n\tUnionFind dsu;\n\n\tUnionFind2d() = default;\n\n\tUnionFind2d(int _n,\
    \ int _m) { init(_n, _m); }\n\n\tvoid init(int _n, int _m) { \n\t\tn = _n, m =\
    \ _m;\n\t\tdsu.init(n * m); \n\t}\n\n\tint find(int ui, int uj) { return dsu.find(ui\
    \ * m + uj); }\n\n\tbool merge(int ui, int uj, int vi, int vj) { return dsu.merge(ui\
    \ * m + uj, vi * m + vj); }\n};\n\n"
  dependsOn:
  - data-structure/union-find.hpp
  isVerificationFile: false
  path: data-structure/union-find-2d.hpp
  requiredBy: []
  timestamp: '2022-03-31 14:26:29-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/union-find-2d.aizu-disjoint-union.test.cpp
  - verify/union-find-2d.yosupo-unionfind.test.cpp
documentation_of: data-structure/union-find-2d.hpp
layout: document
title: Union Find 2d
---

## Union Find 2d