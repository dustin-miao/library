---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/fast-pow.aizu-power.test.cpp
    title: verify/fast-pow.aizu-power.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utility/fast-pow.hpp\"\n#pragma region fast_pow\n\n#ifndef\
    \ FAST_POW_HPP\n#define FAST_POW_HPP\n\ntemplate<typename T, typename U>\nT fast_pow(T\
    \ a, U b) { \n\tT ret = 1; \n\tfor (; b; b /= 2) { \n\t\tif (b & 1) \n\t\t\tret\
    \ = ret * a; \n\t\ta = a * a; \n\t} \n\treturn ret; \n}\n\ntemplate<typename T,\
    \ typename U, typename S>\nT fast_pow(T a, U b, const S &mod) { \n\tT ret = 1;\
    \ \n\tfor (a % mod; b; b /= 2) { \n\t\tif (b & 1) \n\t\t\tret = ret * a % mod;\
    \ \n\t\ta = a * a % mod; \n\t} \n\treturn ret; \n}\n\n#endif\n\n#pragma endregion\
    \ fast_pow\n"
  code: "#pragma region fast_pow\n\n#ifndef FAST_POW_HPP\n#define FAST_POW_HPP\n\n\
    template<typename T, typename U>\nT fast_pow(T a, U b) { \n\tT ret = 1; \n\tfor\
    \ (; b; b /= 2) { \n\t\tif (b & 1) \n\t\t\tret = ret * a; \n\t\ta = a * a; \n\t\
    } \n\treturn ret; \n}\n\ntemplate<typename T, typename U, typename S>\nT fast_pow(T\
    \ a, U b, const S &mod) { \n\tT ret = 1; \n\tfor (a % mod; b; b /= 2) { \n\t\t\
    if (b & 1) \n\t\t\tret = ret * a % mod; \n\t\ta = a * a % mod; \n\t} \n\treturn\
    \ ret; \n}\n\n#endif\n\n#pragma endregion fast_pow"
  dependsOn: []
  isVerificationFile: false
  path: utility/fast-pow.hpp
  requiredBy: []
  timestamp: '2022-05-03 13:27:25-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/fast-pow.aizu-power.test.cpp
documentation_of: utility/fast-pow.hpp
layout: document
title: Binary Exponentiation
---

## Binary Exponentiation