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
  bundledCode: "#line 1 \"utility/fast-pow.hpp\"\ntemplate<typename T, typename U>\n\
    T fast_pow(T a, U b) { \n\tT ret = 1; \n\tfor (; b; b /= 2) { \n\t\tif (b & 1)\
    \ \n\t\t\tret = ret * a; \n\t\ta = a * a; \n\t} \n\treturn ret; \n}\n"
  code: "template<typename T, typename U>\nT fast_pow(T a, U b) { \n\tT ret = 1; \n\
    \tfor (; b; b /= 2) { \n\t\tif (b & 1) \n\t\t\tret = ret * a; \n\t\ta = a * a;\
    \ \n\t} \n\treturn ret; \n}"
  dependsOn: []
  isVerificationFile: false
  path: utility/fast-pow.hpp
  requiredBy: []
  timestamp: '2022-04-08 16:00:08-07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/fast-pow.hpp
layout: document
title: Binary Exponentiation
---

## Binary Exponentiation