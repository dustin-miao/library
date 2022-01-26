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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
  bundledCode: "#line 1 \"verify/union-find.aizu-disjoint-union.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/union-find.hpp\"\
    \nstruct UnionFind {\n    vector<int> parent, setsize;\n\n    UnionFind() = default;\n\
    \n    UnionFind(int n) { init(n); }\n\n    void init(int n) {\n        parent.resize(n);\n\
    \        setsize.resize(n);\n        iota(parent.begin(), parent.end(), 0);\n\
    \        fill(setsize.begin(), setsize.end(), 1);\n    }\n\n    int find(int u)\
    \ {\n        if (u == parent[u])\n            return u;\n        return parent[u]\
    \ = find(parent[u]);\n    }\n\n    bool merge(int u, int v) {\n        u = find(u),\
    \ v = find(v);\n        if (u == v)\n            return false;\n        if (setsize[u]\
    \ > setsize[v]) {\n            parent[v] = u;\n            setsize[u] += setsize[v];\n\
    \        } else {\n            parent[u] = v;\n            setsize[v] += setsize[u];\n\
    \        }\n        return true;\n    }\n\n    int size(int u) {\n        return\
    \ setsize[find(u)];\n    }\n};\n#line 7 \"verify/union-find.aizu-disjoint-union.test.cpp\"\
    \n\nint main() {\n\tint N, Q;\n  \tcin >> N >> Q;\n\tUnionFind dsu(N);\n  \twhile\
    \ (Q--) {\n    \tint t, u, v;\n    \tcin >> t >> u >> v;\n\t\tif (t == 0)\n\t\
    \      \tdsu.merge(u, v);\n    \telse\n      \t\tcout << (dsu.find(u) == dsu.find(v)\
    \ ? 1 : 0) << '\\n';\n  \t}\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/union-find.hpp\"\
    \n\nint main() {\n\tint N, Q;\n  \tcin >> N >> Q;\n\tUnionFind dsu(N);\n  \twhile\
    \ (Q--) {\n    \tint t, u, v;\n    \tcin >> t >> u >> v;\n\t\tif (t == 0)\n\t\
    \      \tdsu.merge(u, v);\n    \telse\n      \t\tcout << (dsu.find(u) == dsu.find(v)\
    \ ? 1 : 0) << '\\n';\n  \t}\n}\n"
  dependsOn:
  - data-structure/union-find.hpp
  isVerificationFile: true
  path: verify/union-find.aizu-disjoint-union.test.cpp
  requiredBy: []
  timestamp: '2022-01-26 05:49:00-08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/union-find.aizu-disjoint-union.test.cpp
layout: document
redirect_from:
- /verify/verify/union-find.aizu-disjoint-union.test.cpp
- /verify/verify/union-find.aizu-disjoint-union.test.cpp.html
title: verify/union-find.aizu-disjoint-union.test.cpp
---
