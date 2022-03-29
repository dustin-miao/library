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
  bundledCode: "#line 1 \"utility/fast-pow.hpp\"\ntemplate<typename T>\nT fast_pow(T\
    \ a, T b) { \n\tT ret = 1; \n\tfor (; b; b >>= 1) { \n\t\tif (b & 1) \n\t\t\t\
    ret = ret * a; \n\t\ta = a * a; \n\t} \n\treturn ret; \n}\n\ntemplate<typename\
    \ T>\nT fast_pow(T a, T b, T mod) { \n\tT ret = 1; \n\tfor (a %= mod; b; b >>=\
    \ 1) { \n\t\tif (b & 1) \n\t\t\tret = ret * a % mod; \n\t\ta = a * a % mod; \n\
    \t} \n\treturn ret; \n}\n"
  code: "template<typename T>\nT fast_pow(T a, T b) { \n\tT ret = 1; \n\tfor (; b;\
    \ b >>= 1) { \n\t\tif (b & 1) \n\t\t\tret = ret * a; \n\t\ta = a * a; \n\t} \n\
    \treturn ret; \n}\n\ntemplate<typename T>\nT fast_pow(T a, T b, T mod) { \n\t\
    T ret = 1; \n\tfor (a %= mod; b; b >>= 1) { \n\t\tif (b & 1) \n\t\t\tret = ret\
    \ * a % mod; \n\t\ta = a * a % mod; \n\t} \n\treturn ret; \n}"
  dependsOn: []
  isVerificationFile: false
  path: utility/fast-pow.hpp
  requiredBy: []
  timestamp: '2022-02-18 14:02:10-08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/fast-pow.hpp
layout: document
title: Binary Exponentiation
---

## Binary Exponentiation