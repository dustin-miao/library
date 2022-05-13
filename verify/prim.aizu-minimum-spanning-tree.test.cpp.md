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
    \n#pragma region chmin\n\n#ifndef CHMIN_HPP\n#define CHMIN_HPP\n\ntemplate<typename\
    \ T>\nbool chmin(T &a, T b) {\n\tif (a > b) {\n\t\ta = b;\n\t\treturn true;\n\t\
    }\n\treturn false;\n}\n\n#endif\n\n#pragma endregion chmin\n#line 2 \"graph/prim.hpp\"\
    \n\n#pragma region prim\n\n#ifndef PRIM_HPP\n#define PRIM_HPP\n\nnamespace graph\
    \ {\n\ttemplate<class T>\n\tvector<vector<pair<int, T>>> prim(const vector<vector<pair<int,\
    \ T>>> &G) {\n\t\tint n = G.size();\n\t\tvector<vector<pair<int, T>>> mst(n);\n\
    \t\tif (n <= 1)\n\t\t\treturn mst;\n\t\tpriority_queue<pair<T, int>, vector<pair<T,\
    \ int>>, greater<pair<T, int>>> pq;\n\t\tvector<T> dis(n, numeric_limits<T>::max());\n\
    \t\tvector<int> par(n, -1);\n\t\tvector<bool> vis(n, false);\n\n\t\tpq.emplace(0,\
    \ 0);\n\t\tdis[0] = 0;\n\t\tpar[0] = 0;\n\t\twhile (!pq.empty()) {\n\t\t\tauto\
    \ [d, u] = pq.top(); pq.pop();\n\t\t\tif (vis[u])\n\t\t\t\tcontinue;\n\t\t\tvis[u]\
    \ = true;\n\t\t\tif (u != 0) {\n\t\t\t\tmst[u].emplace_back(par[u], d);\n\t\t\t\
    \tmst[par[u]].emplace_back(u, d);\n\t\t\t}\n\t\t\tfor (auto [v, w] : G[u])\n\t\
    \t\t\tif (!vis[v] && chmin(dis[v], w)) {\n\t\t\t\t\tpar[v] = u;\n\t\t\t\t\tpq.emplace(dis[v],\
    \ v);\n\t\t\t\t}\n\t\t}\n\t\treturn mst;\n\t}\n}\n\n#endif\n\n#pragma endregion\
    \ prim\n#line 7 \"verify/prim.aizu-minimum-spanning-tree.test.cpp\"\n\nint main()\
    \ {\n\tint N, M;\n\tcin >> N >> M;\n\tvector<vector<pair<int, long long>>> G(N);\n\
    \tfor (int i = 0; i < M; i++) {\n\t\tint u, v; long long w;\n\t\tcin >> u >> v\
    \ >> w;\n\t\tG[u].emplace_back(v, w);\n\t\tG[v].emplace_back(u, w);\n\t}\n\tauto\
    \ T = prim(G);\n\tlong long ans = 0;\n\tfor (int u = 0; u < N; u++)\n\t\tfor (auto\
    \ [v, w] : T[u])\n\t\t\tans += w;\n\tcout << ans / 2 << '\\n';\n}\n"
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
  timestamp: '2022-05-13 08:14:05-07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/prim.aizu-minimum-spanning-tree.test.cpp
layout: document
redirect_from:
- /verify/verify/prim.aizu-minimum-spanning-tree.test.cpp
- /verify/verify/prim.aizu-minimum-spanning-tree.test.cpp.html
title: verify/prim.aizu-minimum-spanning-tree.test.cpp
---
