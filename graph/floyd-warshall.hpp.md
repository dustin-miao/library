---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: utility/chmin.hpp
    title: Chmin
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/floyd-warshall.all-pairs-shortest-path.test.cpp
    title: verify/floyd-warshall.all-pairs-shortest-path.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utility/chmin.hpp\"\ntemplate<typename T>\nbool chmin(T\
    \ &a, T b) {\n\tif (a > b) {\n\t\ta = b;\n\t\treturn true;\n\t}\n\treturn false;\n\
    }\n#line 2 \"graph/floyd-warshall.hpp\"\n\ntemplate<typename T>\nvoid floyd_warshall(vector<T>\
    \ &G, const T dval) {\n\tint n = G.size();\n\tfor (int i = 0; i < n; i++)\n\t\t\
    G[i][i] = 0;\n\tfor (int k = 0; k < n; k++) {\n\t\tfor (int i = 0; i < n; i++)\
    \ {\n\t\t\tfor (int j = 0; j < n; j++) {\n\t\t\t\tif (G[i][k] != dval && G[k][j]\
    \ != dval) {\n\t\t\t\t\tif (G[i][j] == dval)\n\t\t\t\t\t\tG[i][j] = G[i][k] +\
    \ G[k][j];\n\t\t\t\t\telse \n\t\t\t\t\t\tchmin(G[i][j], G[i][k] + G[k][j]);\n\t\
    \t\t\t}\n\t\t\t}\n\t\t}\n\t}\n}\n"
  code: "#include \"utility/chmin.hpp\"\n\ntemplate<typename T>\nvoid floyd_warshall(vector<T>\
    \ &G, const T dval) {\n\tint n = G.size();\n\tfor (int i = 0; i < n; i++)\n\t\t\
    G[i][i] = 0;\n\tfor (int k = 0; k < n; k++) {\n\t\tfor (int i = 0; i < n; i++)\
    \ {\n\t\t\tfor (int j = 0; j < n; j++) {\n\t\t\t\tif (G[i][k] != dval && G[k][j]\
    \ != dval) {\n\t\t\t\t\tif (G[i][j] == dval)\n\t\t\t\t\t\tG[i][j] = G[i][k] +\
    \ G[k][j];\n\t\t\t\t\telse \n\t\t\t\t\t\tchmin(G[i][j], G[i][k] + G[k][j]);\n\t\
    \t\t\t}\n\t\t\t}\n\t\t}\n\t}\n}"
  dependsOn:
  - utility/chmin.hpp
  isVerificationFile: false
  path: graph/floyd-warshall.hpp
  requiredBy: []
  timestamp: '2022-03-29 12:51:37-07:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/floyd-warshall.all-pairs-shortest-path.test.cpp
documentation_of: graph/floyd-warshall.hpp
layout: document
title: Floyd-Warshall Algorithm
---

## Floyd-Warshall Algorithm