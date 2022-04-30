---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/union-find-2d.hpp
    title: Union Find 2d
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
  bundledCode: "#line 1 \"verify/union-find-2d.aizu-disjoint-union.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/union-find.hpp\"\
    \n#pragma region union_find\n\nstruct union_find {\n    vector<int> par, siz;\n\
    \n    union_find() = default;\n\n    union_find(int n) { init(n); }\n\n    void\
    \ init(int n) {\n        par.resize(n);\n        siz.resize(n);\n        iota(par.begin(),\
    \ par.end(), 0);\n        fill(siz.begin(), siz.end(), 1);\n    }\n\n    int find(int\
    \ u) {\n        if (u == par[u])\n            return u;\n        return par[u]\
    \ = find(par[u]);\n    }\n\n    bool merge(int u, int v) {\n        u = find(u),\
    \ v = find(v);\n        if (u == v)\n            return false;\n        if (siz[u]\
    \ > siz[v]) {\n            par[v] = u;\n            siz[u] += siz[v];\n      \
    \  } else {\n            par[u] = v;\n            siz[v] += siz[u];\n        }\n\
    \        return true;\n    }\n\n    int size(int u) { return siz[find(u)]; }\n\
    };\n\n#pragma endregion union_find\n#line 2 \"data-structure/union-find-2d.hpp\"\
    \n\n#pragma region union_find_2d\n\nstruct union_find_2d {\n\tint n, m;\n\tunion_find\
    \ dsu;\n\n\tunion_find_2d() = default;\n\n\tunion_find_2d(int _n, int _m) { init(_n,\
    \ _m); }\n\n\tvoid init(int _n, int _m) { \n\t\tn = _n, m = _m;\n\t\tdsu.init(n\
    \ * m); \n\t}\n\n\tint find(int ui, int uj) { return dsu.find(ui * m + uj); }\n\
    \n\tbool merge(int ui, int uj, int vi, int vj) { return dsu.merge(ui * m + uj,\
    \ vi * m + vj); }\n};\n\n#pragma endregion union_find_2d\n#line 7 \"verify/union-find-2d.aizu-disjoint-union.test.cpp\"\
    \n\nint main() {\n\tint N, Q;\n  \tcin >> N >> Q;\n\tunion_find_2d dsu(1, N);\n\
    \  \twhile (Q--) {\n    \tint t, u, v;\n    \tcin >> t >> u >> v;\n\t\tif (t ==\
    \ 0)\n\t      \tdsu.merge(0, u, 0, v);\n    \telse\n      \t\tcout << (dsu.find(0,\
    \ u) == dsu.find(0, v) ? 1 : 0) << '\\n';\n  \t}\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/union-find-2d.hpp\"\
    \n\nint main() {\n\tint N, Q;\n  \tcin >> N >> Q;\n\tunion_find_2d dsu(1, N);\n\
    \  \twhile (Q--) {\n    \tint t, u, v;\n    \tcin >> t >> u >> v;\n\t\tif (t ==\
    \ 0)\n\t      \tdsu.merge(0, u, 0, v);\n    \telse\n      \t\tcout << (dsu.find(0,\
    \ u) == dsu.find(0, v) ? 1 : 0) << '\\n';\n  \t}\n}\n"
  dependsOn:
  - data-structure/union-find-2d.hpp
  - data-structure/union-find.hpp
  isVerificationFile: true
  path: verify/union-find-2d.aizu-disjoint-union.test.cpp
  requiredBy: []
  timestamp: '2022-04-29 22:36:50-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/union-find-2d.aizu-disjoint-union.test.cpp
layout: document
redirect_from:
- /verify/verify/union-find-2d.aizu-disjoint-union.test.cpp
- /verify/verify/union-find-2d.aizu-disjoint-union.test.cpp.html
title: verify/union-find-2d.aizu-disjoint-union.test.cpp
---
