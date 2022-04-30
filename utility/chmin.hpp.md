---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: Dijkstra's Algorithm
  - icon: ':heavy_check_mark:'
    path: graph/floyd-warshall.hpp
    title: Floyd-Warshall Algorithm
  - icon: ':heavy_check_mark:'
    path: graph/prim.hpp
    title: Prim's Algorithm
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/chmax.aizu-min-max-sum.test.cpp
    title: verify/chmax.aizu-min-max-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/chmin.aizu-min-max-sum.test.cpp
    title: verify/chmin.aizu-min-max-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/dijkstra.aizu-shortest-path.test.cpp
    title: verify/dijkstra.aizu-shortest-path.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/dijkstra.aizu-single-source-shortest-path.test.cpp
    title: verify/dijkstra.aizu-single-source-shortest-path.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/floyd-warshall.all-pairs-shortest-path.test.cpp
    title: verify/floyd-warshall.all-pairs-shortest-path.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/prim.aizu-minimum-spanning-tree.test.cpp
    title: verify/prim.aizu-minimum-spanning-tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  - graph/prim.hpp
  - graph/dijkstra.hpp
  - graph/floyd-warshall.hpp
  timestamp: '2022-02-04 21:19:28-08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/prim.aizu-minimum-spanning-tree.test.cpp
  - verify/chmin.aizu-min-max-sum.test.cpp
  - verify/chmax.aizu-min-max-sum.test.cpp
  - verify/dijkstra.aizu-shortest-path.test.cpp
  - verify/floyd-warshall.all-pairs-shortest-path.test.cpp
  - verify/dijkstra.aizu-single-source-shortest-path.test.cpp
documentation_of: utility/chmin.hpp
layout: document
title: Chmin
---

## Chmin