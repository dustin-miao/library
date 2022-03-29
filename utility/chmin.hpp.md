---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: Dijkstra's Algorithm
  - icon: ':x:'
    path: graph/floyd-warshall.hpp
    title: Floyd-Warshall Algorithm
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/dijkstra.aizu-shortest-path.test.cpp
    title: verify/dijkstra.aizu-shortest-path.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/dijkstra.aizu-single-source-shortest-path.test.cpp
    title: verify/dijkstra.aizu-single-source-shortest-path.test.cpp
  - icon: ':x:'
    path: verify/floyd-warshall.all-pairs-shortest-path.test.cpp
    title: verify/floyd-warshall.all-pairs-shortest-path.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utility/chmin.hpp\"\ntemplate<typename T>\nbool chmin(T\
    \ &a, T b) {\n\tif (a > b) {\n\t\ta = b;\n\t\treturn true;\n\t}\n\treturn false;\n\
    }\n"
  code: "template<typename T>\nbool chmin(T &a, T b) {\n\tif (a > b) {\n\t\ta = b;\n\
    \t\treturn true;\n\t}\n\treturn false;\n}"
  dependsOn: []
  isVerificationFile: false
  path: utility/chmin.hpp
  requiredBy:
  - graph/floyd-warshall.hpp
  - graph/dijkstra.hpp
  timestamp: '2022-02-04 21:19:28-08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/dijkstra.aizu-shortest-path.test.cpp
  - verify/floyd-warshall.all-pairs-shortest-path.test.cpp
  - verify/dijkstra.aizu-single-source-shortest-path.test.cpp
documentation_of: utility/chmin.hpp
layout: document
title: Chmin
---

## Chmin