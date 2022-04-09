---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/union-find.hpp
    title: Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
  bundledCode: "#line 1 \"verify/union-find.aizu-disjoint-union.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/union-find.hpp\"\
    \nstruct union_find {\n    vector<int> par, siz;\n\n    union_find() = default;\n\
    \n    union_find(int n) { init(n); }\n\n    void init(int n) {\n        par.resize(n);\n\
    \        siz.resize(n);\n        iota(par.begin(), par.end(), 0);\n        fill(siz.begin(),\
    \ siz.end(), 1);\n    }\n\n    int find(int u) {\n        if (u == par[u])\n \
    \           return u;\n        return par[u] = find(par[u]);\n    }\n\n    bool\
    \ merge(int u, int v) {\n        u = find(u), v = find(v);\n        if (u == v)\n\
    \            return false;\n        if (siz[u] > siz[v]) {\n            par[v]\
    \ = u;\n            siz[u] += siz[v];\n        } else {\n            par[u] =\
    \ v;\n            siz[v] += siz[u];\n        }\n        return true;\n    }\n\n\
    \    int size(int u) { return siz[find(u)]; }\n};\n#line 7 \"verify/union-find.aizu-disjoint-union.test.cpp\"\
    \n\nint main() {\n\tint N, Q;\n  \tcin >> N >> Q;\n\tunion_find dsu(N);\n  \t\
    while (Q--) {\n    \tint t, u, v;\n    \tcin >> t >> u >> v;\n\t\tif (t == 0)\n\
    \t      \tdsu.merge(u, v);\n    \telse\n      \t\tcout << (dsu.find(u) == dsu.find(v)\
    \ ? 1 : 0) << '\\n';\n  \t}\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/union-find.hpp\"\
    \n\nint main() {\n\tint N, Q;\n  \tcin >> N >> Q;\n\tunion_find dsu(N);\n  \t\
    while (Q--) {\n    \tint t, u, v;\n    \tcin >> t >> u >> v;\n\t\tif (t == 0)\n\
    \t      \tdsu.merge(u, v);\n    \telse\n      \t\tcout << (dsu.find(u) == dsu.find(v)\
    \ ? 1 : 0) << '\\n';\n  \t}\n}\n"
  dependsOn:
  - data-structure/union-find.hpp
  isVerificationFile: true
  path: verify/union-find.aizu-disjoint-union.test.cpp
  requiredBy: []
  timestamp: '2022-04-09 15:55:38-07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/union-find.aizu-disjoint-union.test.cpp
layout: document
redirect_from:
- /verify/verify/union-find.aizu-disjoint-union.test.cpp
- /verify/verify/union-find.aizu-disjoint-union.test.cpp.html
title: verify/union-find.aizu-disjoint-union.test.cpp
---
