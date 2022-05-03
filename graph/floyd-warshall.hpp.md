---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/chmin.hpp
    title: Chmin
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/floyd-warshall.all-pairs-shortest-path.test.cpp
    title: verify/floyd-warshall.all-pairs-shortest-path.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utility/chmin.hpp\"\n#pragma region chmin\n\n#ifndef CHMIN_HPP\n\
    #define CHMIN_HPP\n\ntemplate<typename T>\nbool chmin(T &a, T b) {\n\tif (a >\
    \ b) {\n\t\ta = b;\n\t\treturn true;\n\t}\n\treturn false;\n}\n\n#endif\n\n#pragma\
    \ endregion chmin\n#line 2 \"graph/floyd-warshall.hpp\"\n\n#pragma region floyd_warshall\n\
    \ntemplate<typename T>\nvoid floyd_warshall(vector<vector<T>> &G, const T dval)\
    \ {\n\tint n = G.size();\n\tfor (int i = 0; i < n; i++)\n\t\tG[i][i] = 0;\n\t\
    for (int k = 0; k < n; k++) {\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\tfor (int\
    \ j = 0; j < n; j++) {\n\t\t\t\tif (G[i][k] != dval && G[k][j] != dval) {\n\t\t\
    \t\t\tif (G[i][j] == dval)\n\t\t\t\t\t\tG[i][j] = G[i][k] + G[k][j];\n\t\t\t\t\
    \telse \n\t\t\t\t\t\tchmin(G[i][j], G[i][k] + G[k][j]);\n\t\t\t\t}\n\t\t\t}\n\t\
    \t}\n\t}\n}\n\n#pragma endregion floyd_warshall\n"
  code: "#include \"utility/chmin.hpp\"\n\n#pragma region floyd_warshall\n\ntemplate<typename\
    \ T>\nvoid floyd_warshall(vector<vector<T>> &G, const T dval) {\n\tint n = G.size();\n\
    \tfor (int i = 0; i < n; i++)\n\t\tG[i][i] = 0;\n\tfor (int k = 0; k < n; k++)\
    \ {\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\tfor (int j = 0; j < n; j++) {\n\t\
    \t\t\tif (G[i][k] != dval && G[k][j] != dval) {\n\t\t\t\t\tif (G[i][j] == dval)\n\
    \t\t\t\t\t\tG[i][j] = G[i][k] + G[k][j];\n\t\t\t\t\telse \n\t\t\t\t\t\tchmin(G[i][j],\
    \ G[i][k] + G[k][j]);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n}\n\n#pragma endregion\
    \ floyd_warshall"
  dependsOn:
  - utility/chmin.hpp
  isVerificationFile: false
  path: graph/floyd-warshall.hpp
  requiredBy: []
  timestamp: '2022-05-03 13:27:25-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/floyd-warshall.all-pairs-shortest-path.test.cpp
documentation_of: graph/floyd-warshall.hpp
layout: document
title: Floyd-Warshall Algorithm
---

## Floyd-Warshall Algorithm