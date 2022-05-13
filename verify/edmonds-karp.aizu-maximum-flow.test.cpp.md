---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/edmonds-karp.hpp
    title: Edmonds-Karp Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
  bundledCode: "#line 1 \"verify/edmonds-karp.aizu-maximum-flow.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"graph/edmonds-karp.hpp\"\
    \n#pragma region graph_flow_edmonds_karp\n\n#ifndef EDMONDS_KARP_HPP\n#define\
    \ EDMONDS_KARP_HPP\n\nnamespace graph {\n\tnamespace flow {\n\t\ttemplate<typename\
    \ T>\n\t\tT edmonds_karp(const vector<vector<pair<int, T>>> &G, int s, int t)\
    \ {\n\t\t\tint n = G.size();\n\t\t\tT flow = 0, mx = numeric_limits<T>::max();\n\
    \t\t\tvector<vector<T>> cap(n, vector<T>(n, T{}));\n\t\t\tvector<int> par(n);\n\
    \n\t\t\tvector<vector<int>> U(n);\n\t\t\tfor (int u = 0; u < n; u++) {\n\t\t\t\
    \tfor (auto [v, w] : G[u]) {\n\t\t\t\t\tcap[u][v] += w;\n\t\t\t\t\tU[u].push_back(v);\n\
    \t\t\t\t\tU[v].push_back(u);\n\t\t\t\t}\n\t\t\t}\n\n\t\t\twhile (true) {\n\t\t\
    \t\tqueue<pair<int, T>> q;\n\t\t\t\tfill(par.begin(), par.end(), -1);\n\t\t\t\t\
    T nflow = 0;\n\n\t\t\t\tq.emplace(s, mx);\n\t\t\t\tpar[s] = s;\n\t\t\t\twhile\
    \ (!q.empty()) {\n\t\t\t\t\tauto [u, f] = q.front(); q.pop();\n\t\t\t\t\tfor (auto\
    \ v : U[u]) {\n\t\t\t\t\t\tif (par[v] == -1 && cap[u][v]) {\n\t\t\t\t\t\t\tpar[v]\
    \ = u;\n\t\t\t\t\t\t\tif (v == t) {\n\t\t\t\t\t\t\t\tnflow = min(f, cap[u][v]);\n\
    \t\t\t\t\t\t\t\tgoto bfs_end;\n\t\t\t\t\t\t\t} else {\n\t\t\t\t\t\t\t\tq.emplace(v,\
    \ min(f, cap[u][v]));\n\t\t\t\t\t\t\t}\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t}\n\
    \t\t\t\t\n\t\t\t\tbfs_end:\n\n\t\t\t\tif (nflow == 0)\n\t\t\t\t\tbreak;\n\t\t\t\
    \tflow += nflow;\n\t\t\t\tfor (int u = t; u != s; u = par[u]) {\n\t\t\t\t\tcap[par[u]][u]\
    \ -= nflow;\n\t\t\t\t\tcap[u][par[u]] += nflow;\n\t\t\t\t}\n\t\t\t}\n\t\t\t\n\t\
    \t\treturn flow;\n\t\t}\n\t}\n}\n\n\n#endif \n\n#pragma endregion graph_flow_edmonds_karp\n\
    #line 7 \"verify/edmonds-karp.aizu-maximum-flow.test.cpp\"\n\nint main() {\n\t\
    int N, M;\n\tcin >> N >> M;\n\tvector<vector<pair<int, long long>>> G(N);\n\t\
    for (int i = 0; i < M; i++) {\n\t\tint u, v;\n\t\tlong long w;\n\t\tcin >> u >>\
    \ v >> w;\n\t\tG[u].emplace_back(v, w);\n\t}\n\tcout << graph::flow::edmonds_karp(G,\
    \ 0, N - 1) << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"graph/edmonds-karp.hpp\"\
    \n\nint main() {\n\tint N, M;\n\tcin >> N >> M;\n\tvector<vector<pair<int, long\
    \ long>>> G(N);\n\tfor (int i = 0; i < M; i++) {\n\t\tint u, v;\n\t\tlong long\
    \ w;\n\t\tcin >> u >> v >> w;\n\t\tG[u].emplace_back(v, w);\n\t}\n\tcout << graph::flow::edmonds_karp(G,\
    \ 0, N - 1) << '\\n';\n}"
  dependsOn:
  - graph/edmonds-karp.hpp
  isVerificationFile: true
  path: verify/edmonds-karp.aizu-maximum-flow.test.cpp
  requiredBy: []
  timestamp: '2022-05-13 08:53:25-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/edmonds-karp.aizu-maximum-flow.test.cpp
layout: document
redirect_from:
- /verify/verify/edmonds-karp.aizu-maximum-flow.test.cpp
- /verify/verify/edmonds-karp.aizu-maximum-flow.test.cpp.html
title: verify/edmonds-karp.aizu-maximum-flow.test.cpp
---
