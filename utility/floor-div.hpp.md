---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data-structure/line-container.hpp
    title: Line Container
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/floor_div.yosupo-many-a+b.test.cpp
    title: verify/floor_div.yosupo-many-a+b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/line-container.yosupo-line-add-get-min.test.cpp
    title: verify/line-container.yosupo-line-add-get-min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utility/floor-div.hpp\"\ntemplate<typename T>\nT floor_div(T\
    \ a, T b) { \n\treturn a / b - ((a ^ b) < 0 && a % b); \n}\n"
  code: "template<typename T>\nT floor_div(T a, T b) { \n\treturn a / b - ((a ^ b)\
    \ < 0 && a % b); \n}"
  dependsOn: []
  isVerificationFile: false
  path: utility/floor-div.hpp
  requiredBy:
  - data-structure/line-container.hpp
  timestamp: '2022-02-06 21:17:29-08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/floor_div.yosupo-many-a+b.test.cpp
  - verify/line-container.yosupo-line-add-get-min.test.cpp
documentation_of: utility/floor-div.hpp
layout: document
title: Floor Division
---

## Floor Division