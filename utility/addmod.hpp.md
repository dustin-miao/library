---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/general-segment-tree.yosupo-point-set-range-composite.test.cpp
    title: verify/general-segment-tree.yosupo-point-set-range-composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/lazy-segment-tree.yosupo-range-affine-range-sum.test.cpp
    title: verify/lazy-segment-tree.yosupo-range-affine-range-sum.test.cpp
  - icon: ':x:'
    path: verify/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp
    title: verify/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utility/addmod.hpp\"\ntemplate<typename T>\nT addmod(T a,\
    \ T b, long long MOD) {\n\tT t = a + b;\n\treturn t >= MOD ? t - MOD : t;\n}\n"
  code: "template<typename T>\nT addmod(T a, T b, long long MOD) {\n\tT t = a + b;\n\
    \treturn t >= MOD ? t - MOD : t;\n}"
  dependsOn: []
  isVerificationFile: false
  path: utility/addmod.hpp
  requiredBy: []
  timestamp: '2022-01-26 05:45:04-08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp
  - verify/lazy-segment-tree.yosupo-range-affine-range-sum.test.cpp
  - verify/general-segment-tree.yosupo-point-set-range-composite.test.cpp
documentation_of: utility/addmod.hpp
layout: document
title: Addmod
---

## Addmod

### Summary

An addition operator under modulo. 

### Preconditions

- `T`'s addition, subtraction, and comparison operators are defined

### Parameters
- `T a`: A non-negative value less than `MOD`
- `T b`: A non-negative value less than `MOD`
- `T MOD`: : A positive value