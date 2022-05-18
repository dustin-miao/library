---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: geometry/line-container.hpp
    title: Line Container
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/floor-div.yosupo-many-a+b.test.cpp
    title: verify/floor-div.yosupo-many-a+b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/line-container.yosupo-line-add-get-min.test.cpp
    title: verify/line-container.yosupo-line-add-get-min.test.cpp
  - icon: ':x:'
    path: verify/monotonic-dp-hull.yosupo-a+b.test.cpp
    title: verify/monotonic-dp-hull.yosupo-a+b.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utility/floor-div.hpp\"\n#pragma region floor_div\n\n#ifndef\
    \ FLOOR_DIV_HPP\n#define FLOOR_DIV_HPP\n\ntemplate<typename T>\nT floor_div(T\
    \ a, T b) { \n\treturn a / b - ((a ^ b) < 0 && a % b); \n}\n\n#endif\n\n#pragma\
    \ endregion floor_div\n"
  code: "#pragma region floor_div\n\n#ifndef FLOOR_DIV_HPP\n#define FLOOR_DIV_HPP\n\
    \ntemplate<typename T>\nT floor_div(T a, T b) { \n\treturn a / b - ((a ^ b) <\
    \ 0 && a % b); \n}\n\n#endif\n\n#pragma endregion floor_div"
  dependsOn: []
  isVerificationFile: false
  path: utility/floor-div.hpp
  requiredBy:
  - geometry/line-container.hpp
  timestamp: '2022-05-03 13:27:25-07:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/floor-div.yosupo-many-a+b.test.cpp
  - verify/line-container.yosupo-line-add-get-min.test.cpp
  - verify/monotonic-dp-hull.yosupo-a+b.test.cpp
documentation_of: utility/floor-div.hpp
layout: document
title: Floor Division
---

## Floor Division