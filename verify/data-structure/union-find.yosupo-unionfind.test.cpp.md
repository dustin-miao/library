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
  bundledCode: "#line 1 \"verify/data-structure/union-find.yosupo-unionfind.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"data-structure/union-find.hpp\"\nstruct UnionFind\
    \ {\n    vector<int> parent, setsize;\n\n    UnionFind() = default;\n\n    UnionFind(int\
    \ n) { init(n); }\n\n    void init(int n) {\n        parent.resize(n);\n     \
    \   setsize.resize(n);\n        iota(parent.begin(), parent.end(), 0);\n     \
    \   fill(setsize.begin(), setsize.end(), 1);\n    }\n\n    int find(int u) {\n\
    \        if (u == parent[u])\n            return u;\n        return parent[u]\
    \ = find(parent[u]);\n    }\n\n    bool merge(int u, int v) {\n        u = find(u),\
    \ v = find(v);\n        if (u == v)\n            return false;\n        if (setsize[u]\
    \ > setsize[v]) {\n            parent[v] = u;\n            setsize[u] += setsize[v];\n\
    \        } else {\n            parent[u] = v;\n            setsize[v] += setsize[u];\n\
    \        }\n        return true;\n    }\n\n    int size(int u) {\n        return\
    \ setsize[find(u)];\n    }\n};\n#line 7 \"verify/data-structure/union-find.yosupo-unionfind.test.cpp\"\
    \n\nconst int MAX = 2e5 + 5;\n\nint N, Q;\nUnionFind dsu(MAX);\n\nint main() {\n\
    \  cin >> N >> Q;\n  while (Q--) {\n    int t, u, v;\n    cin >> t >> u >> v;\n\
    \    if (t == 0)\n      dsu.merge(u, v);\n    else\n      cout << (dsu.find(u)\
    \ == dsu.find(v) ? 1 : 0) << '\\n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/union-find.hpp\"\
    \n\nconst int MAX = 2e5 + 5;\n\nint N, Q;\nUnionFind dsu(MAX);\n\nint main() {\n\
    \  cin >> N >> Q;\n  while (Q--) {\n    int t, u, v;\n    cin >> t >> u >> v;\n\
    \    if (t == 0)\n      dsu.merge(u, v);\n    else\n      cout << (dsu.find(u)\
    \ == dsu.find(v) ? 1 : 0) << '\\n';\n  }\n}\n"
  dependsOn:
  - data-structure/union-find.hpp
  isVerificationFile: true
  path: verify/data-structure/union-find.yosupo-unionfind.test.cpp
  requiredBy: []
  timestamp: '2021-12-31 09:10:59-08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data-structure/union-find.yosupo-unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/data-structure/union-find.yosupo-unionfind.test.cpp
- /verify/verify/data-structure/union-find.yosupo-unionfind.test.cpp.html
title: verify/data-structure/union-find.yosupo-unionfind.test.cpp
---
