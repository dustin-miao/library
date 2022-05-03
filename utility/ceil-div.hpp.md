---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/ceil-div.yosupo-many-a+b.test.cpp
    title: verify/ceil-div.yosupo-many-a+b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utility/ceil-div.hpp\"\n#pragma region ceil_div\n\n#ifndef\
    \ CEIL_DIV_HPP\n#define CEIL_DIV_HPP\n\ntemplate<typename T>\nT ceil_div(T a,\
    \ T b) { \n\treturn a / b + ((a ^ b) > 0 && a % b); \n} \n\n#endif\n\n#pragma\
    \ endregion ceil_div\n"
  code: "#pragma region ceil_div\n\n#ifndef CEIL_DIV_HPP\n#define CEIL_DIV_HPP\n\n\
    template<typename T>\nT ceil_div(T a, T b) { \n\treturn a / b + ((a ^ b) > 0 &&\
    \ a % b); \n} \n\n#endif\n\n#pragma endregion ceil_div"
  dependsOn: []
  isVerificationFile: false
  path: utility/ceil-div.hpp
  requiredBy: []
  timestamp: '2022-05-03 13:27:25-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/ceil-div.yosupo-many-a+b.test.cpp
documentation_of: utility/ceil-div.hpp
layout: document
title: Ceil Division
---

## Ceil Division