---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/dijkstra.hpp
    title: Dijkstra's Algorithm
  - icon: ':x:'
    path: graph/floyd-warshall.hpp
    title: Floyd-Warshall Algorithm
  - icon: ':x:'
    path: graph/prim.hpp
    title: Prim's Algorithm
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/chmax.aizu-min-max-sum.test.cpp
    title: verify/chmax.aizu-min-max-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/chmin.aizu-min-max-sum.test.cpp
    title: verify/chmin.aizu-min-max-sum.test.cpp
  - icon: ':x:'
    path: verify/dijkstra.aizu-shortest-path.test.cpp
    title: verify/dijkstra.aizu-shortest-path.test.cpp
  - icon: ':x:'
    path: verify/dijkstra.aizu-single-source-shortest-path.test.cpp
    title: verify/dijkstra.aizu-single-source-shortest-path.test.cpp
  - icon: ':x:'
    path: verify/floyd-warshall.all-pairs-shortest-path.test.cpp
    title: verify/floyd-warshall.all-pairs-shortest-path.test.cpp
  - icon: ':x:'
    path: verify/prim.aizu-minimum-spanning-tree.test.cpp
    title: verify/prim.aizu-minimum-spanning-tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utility/chmin.hpp\"\n#pragma region chmin\n\n#ifndef CHMIN_HPP\n\
    #define CHMIN_HPP\n\ntemplate<typename T>\nbool chmin(T &a, T b) {\n\tif (a >\
    \ b) {\n\t\ta = b;\n\t\treturn true;\n\t}\n\treturn false;\n}\n\n#endif\n\n#pragma\
    \ endregion chmin\n"
  code: "#pragma region chmin\n\n#ifndef CHMIN_HPP\n#define CHMIN_HPP\n\ntemplate<typename\
    \ T>\nbool chmin(T &a, T b) {\n\tif (a > b) {\n\t\ta = b;\n\t\treturn true;\n\t\
    }\n\treturn false;\n}\n\n#endif\n\n#pragma endregion chmin"
  dependsOn: []
  isVerificationFile: false
  path: utility/chmin.hpp
  requiredBy:
  - graph/prim.hpp
  - graph/floyd-warshall.hpp
  - graph/dijkstra.hpp
  timestamp: '2022-05-03 13:27:25-07:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/dijkstra.aizu-shortest-path.test.cpp
  - verify/chmax.aizu-min-max-sum.test.cpp
  - verify/dijkstra.aizu-single-source-shortest-path.test.cpp
  - verify/chmin.aizu-min-max-sum.test.cpp
  - verify/floyd-warshall.all-pairs-shortest-path.test.cpp
  - verify/prim.aizu-minimum-spanning-tree.test.cpp
documentation_of: utility/chmin.hpp
layout: document
title: Chmin
---

## Chmin