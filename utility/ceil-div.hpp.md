---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utility/ceil-div.hpp\"\ntemplate<typename T>\nT ceil_div(T\
    \ a, T b) { \n\treturn a / b + ((a ^ b) > 0 && a % b); \n} \n"
  code: "template<typename T>\nT ceil_div(T a, T b) { \n\treturn a / b + ((a ^ b)\
    \ > 0 && a % b); \n} "
  dependsOn: []
  isVerificationFile: false
  path: utility/ceil-div.hpp
  requiredBy: []
  timestamp: '2022-02-06 21:17:29-08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/ceil-div.hpp
layout: document
title: Ceil Division
---

## Ceil Division