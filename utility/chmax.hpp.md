---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/chmax.aizu-min-max-sum.test.cpp
    title: verify/chmax.aizu-min-max-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/chmin.aizu-min-max-sum.test.cpp
    title: verify/chmin.aizu-min-max-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utility/chmax.hpp\"\ntemplate<typename T>\nbool chmax(T\
    \ &a, T b) {\n\tif (a < b) {\n\t\ta = b;\n\t\treturn true;\n\t}\n\treturn false;\n\
    }\n"
  code: "template<typename T>\nbool chmax(T &a, T b) {\n\tif (a < b) {\n\t\ta = b;\n\
    \t\treturn true;\n\t}\n\treturn false;\n}"
  dependsOn: []
  isVerificationFile: false
  path: utility/chmax.hpp
  requiredBy: []
  timestamp: '2022-02-04 21:19:28-08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/chmin.aizu-min-max-sum.test.cpp
  - verify/chmax.aizu-min-max-sum.test.cpp
documentation_of: utility/chmax.hpp
layout: document
title: Chmax
---

## Chmax