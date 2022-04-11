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
  bundledCode: "#line 1 \"utility/fast-pow.hpp\"\ntemplate<typename T, typename U>\n\
    T fast_pow(T a, U b) { \n\tT ret = 1; \n\tfor (; b; b /= 2) { \n\t\tif (b & 1)\
    \ \n\t\t\tret = ret * a; \n\t\ta = a * a; \n\t} \n\treturn ret; \n}\n\ntemplate<typename\
    \ T, typename U, typename S>\nT fast_pow(T a, U b, const S &mod) { \n\tT ret =\
    \ 1; \n\tfor (a % mod; b; b /= 2) { \n\t\tif (b & 1) \n\t\t\tret = ret * a % mod;\
    \ \n\t\ta = a * a % mod; \n\t} \n\treturn ret; \n}\n"
  code: "template<typename T, typename U>\nT fast_pow(T a, U b) { \n\tT ret = 1; \n\
    \tfor (; b; b /= 2) { \n\t\tif (b & 1) \n\t\t\tret = ret * a; \n\t\ta = a * a;\
    \ \n\t} \n\treturn ret; \n}\n\ntemplate<typename T, typename U, typename S>\n\
    T fast_pow(T a, U b, const S &mod) { \n\tT ret = 1; \n\tfor (a % mod; b; b /=\
    \ 2) { \n\t\tif (b & 1) \n\t\t\tret = ret * a % mod; \n\t\ta = a * a % mod; \n\
    \t} \n\treturn ret; \n}"
  dependsOn: []
  isVerificationFile: false
  path: utility/fast-pow.hpp
  requiredBy: []
  timestamp: '2022-04-11 09:09:09-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/fast-pow.aizu-power.test.cpp
documentation_of: utility/fast-pow.hpp
layout: document
title: Binary Exponentiation
---

## Binary Exponentiation