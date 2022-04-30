---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/union-find.hpp
    title: Union Find
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.hpp
    title: Kruskal's Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
  bundledCode: "#line 1 \"verify/kruskal.aizu-minimum-spanning-tree.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
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
    };\n\n#pragma endregion union_find\n#line 2 \"graph/kruskal.hpp\"\n\n#pragma region\
    \ kruskal\n\ntemplate<class T>\nvector<vector<pair<int, T>>> kruskal(int n, vector<tuple<int,\
    \ int, T>> E) {\n\tvector<vector<pair<int, T>>> mst(n);\n\tif (n <= 1)\n\t\treturn\
    \ mst;\n\tunion_find dsu(n);\n\tsort(E.begin(), E.end(), \n\t\t[](auto a, auto\
    \ b) { \n\t\t\treturn get<2>(a) < get<2>(b); \n\t\t}\n\t);\n\tfor (auto [u, v,\
    \ w] : E) {\n\t\tif (dsu.merge(u, v)) {\n\t\t\tmst[u].emplace_back(v, w);\n\t\t\
    \tmst[v].emplace_back(u, w);\n\t\t}\n\t\tif (dsu.size(0) == n)\n\t\t\tbreak;\n\
    \t}\n\treturn mst;\n}\n\n#pragma endregion kruskal\n#line 7 \"verify/kruskal.aizu-minimum-spanning-tree.test.cpp\"\
    \n\nint main() {\n\tint N, M;\n\tcin >> N >> M;\n\tvector<tuple<int, int, long\
    \ long>> E;\n\tfor (int i = 0; i < M; i++) {\n\t\tint u, v; long long w;\n\t\t\
    cin >> u >> v >> w;\n\t\tE.emplace_back(u, v, w);\n\t}\n\tauto T = kruskal(N,\
    \ E);\n\tlong long ans = 0;\n\tfor (int u = 0; u < N; u++)\n\t\tfor (auto [v,\
    \ w] : T[u])\n\t\t\tans += w;\n\tcout << ans / 2 << '\\n';\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"graph/kruskal.hpp\"\
    \n\nint main() {\n\tint N, M;\n\tcin >> N >> M;\n\tvector<tuple<int, int, long\
    \ long>> E;\n\tfor (int i = 0; i < M; i++) {\n\t\tint u, v; long long w;\n\t\t\
    cin >> u >> v >> w;\n\t\tE.emplace_back(u, v, w);\n\t}\n\tauto T = kruskal(N,\
    \ E);\n\tlong long ans = 0;\n\tfor (int u = 0; u < N; u++)\n\t\tfor (auto [v,\
    \ w] : T[u])\n\t\t\tans += w;\n\tcout << ans / 2 << '\\n';\n}"
  dependsOn:
  - graph/kruskal.hpp
  - data-structure/union-find.hpp
  isVerificationFile: true
  path: verify/kruskal.aizu-minimum-spanning-tree.test.cpp
  requiredBy: []
  timestamp: '2022-04-29 22:36:50-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/kruskal.aizu-minimum-spanning-tree.test.cpp
layout: document
redirect_from:
- /verify/verify/kruskal.aizu-minimum-spanning-tree.test.cpp
- /verify/verify/kruskal.aizu-minimum-spanning-tree.test.cpp.html
title: verify/kruskal.aizu-minimum-spanning-tree.test.cpp
---
