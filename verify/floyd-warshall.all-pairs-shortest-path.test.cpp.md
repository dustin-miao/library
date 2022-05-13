---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/floyd-warshall.hpp
    title: Floyd-Warshall Algorithm
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
  bundledCode: "#line 1 \"verify/floyd-warshall.all-pairs-shortest-path.test.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"utility/chmin.hpp\"\
    \n#pragma region chmin\n\n#ifndef CHMIN_HPP\n#define CHMIN_HPP\n\ntemplate<typename\
    \ T>\nbool chmin(T &a, T b) {\n\tif (a > b) {\n\t\ta = b;\n\t\treturn true;\n\t\
    }\n\treturn false;\n}\n\n#endif\n\n#pragma endregion chmin\n#line 2 \"graph/floyd-warshall.hpp\"\
    \n\n#pragma region floyd_warshall\n\n#ifndef FLOYD_WARSHALL_HPP\n#define FLOYD_WARSHALL_HPP\n\
    \nnamespace graph {\n\ttemplate<typename T>\n\tvoid floyd_warshall(vector<vector<T>>\
    \ &G, const T dval) {\n\t\tint n = G.size();\n\t\tfor (int i = 0; i < n; i++)\n\
    \t\t\tG[i][i] = 0;\n\t\tfor (int k = 0; k < n; k++) {\n\t\t\tfor (int i = 0; i\
    \ < n; i++) {\n\t\t\t\tfor (int j = 0; j < n; j++) {\n\t\t\t\t\tif (G[i][k] !=\
    \ dval && G[k][j] != dval) {\n\t\t\t\t\t\tif (G[i][j] == dval)\n\t\t\t\t\t\t\t\
    G[i][j] = G[i][k] + G[k][j];\n\t\t\t\t\t\telse \n\t\t\t\t\t\t\tchmin(G[i][j],\
    \ G[i][k] + G[k][j]);\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n}\n\n#endif\n\
    \n#pragma endregion floyd_warshall\n#line 7 \"verify/floyd-warshall.all-pairs-shortest-path.test.cpp\"\
    \n\nint main() {\n\tint N, M;\n\tcin >> N >> M;\n\tvector<vector<long long>> G(N,\
    \ vector<long long>(N, LLONG_MAX));\n\tfor (int i = 0; i < M; i++) {\n\t\tint\
    \ u, v; long long w;\n\t\tcin >> u >> v >> w;\n\t\tG[u][v] = w;\n\t}\n\n\tfloyd_warshall(G,\
    \ LLONG_MAX); \n\n\tbool cycle = false;\n\tfor (int i = 0; i < N; i++)\n\t\tif\
    \ (G[i][i] < 0)\n\t\t\tcycle = true;\n\t\n\tif (cycle) {\n\t\tcout << \"NEGATIVE\
    \ CYCLE\\n\";\n\t} else {\n\t\tfor (int i = 0; i < N; i++) {\n\t\t\tfor (int j\
    \ = 0; j < N; j++) {\n\t\t\t\tif (G[i][j] == LLONG_MAX)\n\t\t\t\t\tcout << \"\
    INF\";\n\t\t\t\telse \n\t\t\t\t\tcout << G[i][j];\n\t\t\t\tcout << \" \\n\"[j\
    \ == N - 1];\n\t\t\t}\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"graph/floyd-warshall.hpp\"\
    \n\nint main() {\n\tint N, M;\n\tcin >> N >> M;\n\tvector<vector<long long>> G(N,\
    \ vector<long long>(N, LLONG_MAX));\n\tfor (int i = 0; i < M; i++) {\n\t\tint\
    \ u, v; long long w;\n\t\tcin >> u >> v >> w;\n\t\tG[u][v] = w;\n\t}\n\n\tfloyd_warshall(G,\
    \ LLONG_MAX); \n\n\tbool cycle = false;\n\tfor (int i = 0; i < N; i++)\n\t\tif\
    \ (G[i][i] < 0)\n\t\t\tcycle = true;\n\t\n\tif (cycle) {\n\t\tcout << \"NEGATIVE\
    \ CYCLE\\n\";\n\t} else {\n\t\tfor (int i = 0; i < N; i++) {\n\t\t\tfor (int j\
    \ = 0; j < N; j++) {\n\t\t\t\tif (G[i][j] == LLONG_MAX)\n\t\t\t\t\tcout << \"\
    INF\";\n\t\t\t\telse \n\t\t\t\t\tcout << G[i][j];\n\t\t\t\tcout << \" \\n\"[j\
    \ == N - 1];\n\t\t\t}\n\t\t}\n\t}\n}"
  dependsOn:
  - graph/floyd-warshall.hpp
  - utility/chmin.hpp
  isVerificationFile: true
  path: verify/floyd-warshall.all-pairs-shortest-path.test.cpp
  requiredBy: []
  timestamp: '2022-05-13 08:14:05-07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/floyd-warshall.all-pairs-shortest-path.test.cpp
layout: document
redirect_from:
- /verify/verify/floyd-warshall.all-pairs-shortest-path.test.cpp
- /verify/verify/floyd-warshall.all-pairs-shortest-path.test.cpp.html
title: verify/floyd-warshall.all-pairs-shortest-path.test.cpp
---
