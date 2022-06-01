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
  bundledCode: "#line 1 \"utility/chmax.hpp\"\n#pragma region chmax\n\n#ifndef CHMAX_HPP\n\
    #define CHMAX_HPP\n\ntemplate<typename T>\nbool chmax(T &a, T b) {\n\tif (a <\
    \ b) {\n\t\ta = b;\n\t\treturn true;\n\t}\n\treturn false;\n}\n\n#endif\n\n#pragma\
    \ endregion chmax\n"
  code: "#pragma region chmax\n\n#ifndef CHMAX_HPP\n#define CHMAX_HPP\n\ntemplate<typename\
    \ T>\nbool chmax(T &a, T b) {\n\tif (a < b) {\n\t\ta = b;\n\t\treturn true;\n\t\
    }\n\treturn false;\n}\n\n#endif\n\n#pragma endregion chmax"
  dependsOn: []
  isVerificationFile: false
  path: utility/chmax.hpp
  requiredBy: []
  timestamp: '2022-05-03 13:27:25-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/chmin.aizu-min-max-sum.test.cpp
  - verify/chmax.aizu-min-max-sum.test.cpp
documentation_of: utility/chmax.hpp
layout: document
title: Chmax
---

## Chmax