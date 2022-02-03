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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/dijkstra.aizu-shortest-path.test.cpp
    title: verify/dijkstra.aizu-shortest-path.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/dijkstra.aizu-single-source-shortest-path.test.cpp
    title: verify/dijkstra.aizu-single-source-shortest-path.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/floyd-warshall.all-pairs-shortest-path.test.cpp
    title: verify/floyd-warshall.all-pairs-shortest-path.test.cpp
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
  - graph/floyd-warshall.hpp
  - graph/dijkstra.hpp
  timestamp: '2022-01-26 05:57:15-08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/dijkstra.aizu-shortest-path.test.cpp
  - verify/floyd-warshall.all-pairs-shortest-path.test.cpp
  - verify/dijkstra.aizu-single-source-shortest-path.test.cpp
documentation_of: utility/chmin.hpp
layout: document
title: Chmin
---

## Chmin

### Summary

Essentially to a `min=` operator. For some $a$ and $b$, assigns $a = \min(a, b)$. Returns `true` if the assignment is successful, and `false` otherwise. 

### Preconditions

- `T`'s comparison operators are defined

### Parameters
- `T &a`: A reference
- `T b`: A value