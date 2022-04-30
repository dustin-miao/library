---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/prim.hpp
    title: Prim's Algorithm
  - icon: ':question:'
    path: utility/chmin.hpp
    title: Chmin
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
  bundledCode: "#line 1 \"verify/prim.aizu-minimum-spanning-tree.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"utility/chmin.hpp\"\
    \n#pragma region chmin\n\ntemplate<typename T>\nbool chmin(T &a, T b) {\n\tif\
    \ (a > b) {\n\t\ta = b;\n\t\treturn true;\n\t}\n\treturn false;\n}\n\n#pragma\
    \ endregion chmin\n#line 2 \"graph/prim.hpp\"\n\n#pragma region prim\n\ntemplate<class\
    \ T>\nvector<vector<pair<int, T>>> prim(const vector<vector<pair<int, T>>> &G)\
    \ {\n\tint n = G.size();\n\tvector<vector<pair<int, T>>> mst(n);\n\tif (n <= 1)\n\
    \t\treturn mst;\n\tpriority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T,\
    \ int>>> pq;\n\tvector<T> dis(n, numeric_limits<T>::max());\n\tvector<int> par(n,\
    \ -1);\n\tvector<bool> vis(n, false);\n\n\tpq.emplace(0, 0);\n\tdis[0] = 0;\n\t\
    par[0] = 0;\n\twhile (!pq.empty()) {\n\t\tauto [d, u] = pq.top(); pq.pop();\n\t\
    \tif (vis[u])\n\t\t\tcontinue;\n\t\tvis[u] = true;\n\t\tif (u != 0) {\n\t\t\t\
    mst[u].emplace_back(par[u], d);\n\t\t\tmst[par[u]].emplace_back(u, d);\n\t\t}\n\
    \t\tfor (auto [v, w] : G[u])\n\t\t\tif (!vis[v] && chmin(dis[v], w)) {\n\t\t\t\
    \tpar[v] = u;\n\t\t\t\tpq.emplace(dis[v], v);\n\t\t\t}\n\t}\n\treturn mst;\n}\n\
    \n#pragma endregion prim\n#line 7 \"verify/prim.aizu-minimum-spanning-tree.test.cpp\"\
    \n\nint main() {\n\tint N, M;\n\tcin >> N >> M;\n\tvector<vector<pair<int, long\
    \ long>>> G(N);\n\tfor (int i = 0; i < M; i++) {\n\t\tint u, v; long long w;\n\
    \t\tcin >> u >> v >> w;\n\t\tG[u].emplace_back(v, w);\n\t\tG[v].emplace_back(u,\
    \ w);\n\t}\n\tauto T = prim(G);\n\tlong long ans = 0;\n\tfor (int u = 0; u < N;\
    \ u++)\n\t\tfor (auto [v, w] : T[u])\n\t\t\tans += w;\n\tcout << ans / 2 << '\\\
    n';\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"graph/prim.hpp\"\
    \n\nint main() {\n\tint N, M;\n\tcin >> N >> M;\n\tvector<vector<pair<int, long\
    \ long>>> G(N);\n\tfor (int i = 0; i < M; i++) {\n\t\tint u, v; long long w;\n\
    \t\tcin >> u >> v >> w;\n\t\tG[u].emplace_back(v, w);\n\t\tG[v].emplace_back(u,\
    \ w);\n\t}\n\tauto T = prim(G);\n\tlong long ans = 0;\n\tfor (int u = 0; u < N;\
    \ u++)\n\t\tfor (auto [v, w] : T[u])\n\t\t\tans += w;\n\tcout << ans / 2 << '\\\
    n';\n}"
  dependsOn:
  - graph/prim.hpp
  - utility/chmin.hpp
  isVerificationFile: true
  path: verify/prim.aizu-minimum-spanning-tree.test.cpp
  requiredBy: []
  timestamp: '2022-04-29 22:36:50-07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/prim.aizu-minimum-spanning-tree.test.cpp
layout: document
redirect_from:
- /verify/verify/prim.aizu-minimum-spanning-tree.test.cpp
- /verify/verify/prim.aizu-minimum-spanning-tree.test.cpp.html
title: verify/prim.aizu-minimum-spanning-tree.test.cpp
---
