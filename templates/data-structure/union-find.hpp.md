---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"templates/data-structure/union-find.hpp\"\nstruct UnionFind\
    \ {\n    vector<int> par, siz;\n\n    UnionFind() = default;\n\n    UnionFind(int\
    \ n) { init(n); }\n\n    void init(int n) {\n        par.resize(n);\n        siz.resize(n);\n\
    \        iota(par.begin(), par.end(), 0);\n        fill(siz.begin(), siz.end(),\
    \ 1);\n    }\n\n    int find(int u) {\n        if (u == par[u])\n            return\
    \ u;\n        return par[u] = find(par[u]);\n    }\n\n    bool merge(int u, int\
    \ v) {\n        u = find(u), v = find(v);\n        if (u == v)\n            return\
    \ false;\n        if (siz[u] > siz[v]) {\n            par[v] = u;\n          \
    \  siz[u] += siz[v];\n        } else {\n            par[u] = v;\n            siz[v]\
    \ += siz[u];\n        }\n        return true;\n    }\n\n    int size(int u) {\
    \ return siz[find(u)]; }\n};\n"
  code: "struct UnionFind {\n    vector<int> par, siz;\n\n    UnionFind() = default;\n\
    \n    UnionFind(int n) { init(n); }\n\n    void init(int n) {\n        par.resize(n);\n\
    \        siz.resize(n);\n        iota(par.begin(), par.end(), 0);\n        fill(siz.begin(),\
    \ siz.end(), 1);\n    }\n\n    int find(int u) {\n        if (u == par[u])\n \
    \           return u;\n        return par[u] = find(par[u]);\n    }\n\n    bool\
    \ merge(int u, int v) {\n        u = find(u), v = find(v);\n        if (u == v)\n\
    \            return false;\n        if (siz[u] > siz[v]) {\n            par[v]\
    \ = u;\n            siz[u] += siz[v];\n        } else {\n            par[u] =\
    \ v;\n            siz[v] += siz[u];\n        }\n        return true;\n    }\n\n\
    \    int size(int u) { return siz[find(u)]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: templates/data-structure/union-find.hpp
  requiredBy: []
  timestamp: '2022-02-04 20:52:31-08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: templates/data-structure/union-find.hpp
layout: document
redirect_from:
- /library/templates/data-structure/union-find.hpp
- /library/templates/data-structure/union-find.hpp.html
title: templates/data-structure/union-find.hpp
---
