---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/union-find.hpp
    title: Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"verify/union-find.yosupo-unionfind.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"data-structure/union-find.hpp\"\nstruct UnionFind\
    \ {\n    vector<int> par, siz;\n\n    UnionFind() = default;\n\n    UnionFind(int\
    \ n) { init(n); }\n\n    void init(int n) {\n        par.resize(n);\n        siz.resize(n);\n\
    \        iota(par.begin(), par.end(), 0);\n        fill(siz.begin(), siz.end(),\
    \ 1);\n    }\n\n    int find(int u) {\n        if (u == par[u])\n            return\
    \ u;\n        return par[u] = find(par[u]);\n    }\n\n    bool merge(int u, int\
    \ v) {\n        u = find(u), v = find(v);\n        if (u == v)\n            return\
    \ false;\n        if (siz[u] > siz[v]) {\n            par[v] = u;\n          \
    \  siz[u] += siz[v];\n        } else {\n            par[u] = v;\n            siz[v]\
    \ += siz[u];\n        }\n        return true;\n    }\n\n    int size(int u) {\
    \ return siz[find(u)]; }\n};\n#line 7 \"verify/union-find.yosupo-unionfind.test.cpp\"\
    \n\nint main() {\n\tint N, Q;\n  \tcin >> N >> Q;\n\tUnionFind dsu(N);\n  \twhile\
    \ (Q--) {\n    \tint t, u, v;\n    \tcin >> t >> u >> v;\n\t\tif (t == 0)\n\t\
    \      \tdsu.merge(u, v);\n    \telse\n      \t\tcout << (dsu.find(u) == dsu.find(v)\
    \ ? 1 : 0) << '\\n';\n  \t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/union-find.hpp\"\
    \n\nint main() {\n\tint N, Q;\n  \tcin >> N >> Q;\n\tUnionFind dsu(N);\n  \twhile\
    \ (Q--) {\n    \tint t, u, v;\n    \tcin >> t >> u >> v;\n\t\tif (t == 0)\n\t\
    \      \tdsu.merge(u, v);\n    \telse\n      \t\tcout << (dsu.find(u) == dsu.find(v)\
    \ ? 1 : 0) << '\\n';\n  \t}\n}\n"
  dependsOn:
  - data-structure/union-find.hpp
  isVerificationFile: true
  path: verify/union-find.yosupo-unionfind.test.cpp
  requiredBy: []
  timestamp: '2022-02-02 10:15:02-08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/union-find.yosupo-unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/union-find.yosupo-unionfind.test.cpp
- /verify/verify/union-find.yosupo-unionfind.test.cpp.html
title: verify/union-find.yosupo-unionfind.test.cpp
---
