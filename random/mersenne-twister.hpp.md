---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: random/random-float.hpp
    title: Random Float
  - icon: ':heavy_check_mark:'
    path: random/random-int-vector.hpp
    title: Random Integer Vector
  - icon: ':heavy_check_mark:'
    path: random/random-int.hpp
    title: Random Integer
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/cyclic-product.yosupo-a+b.test.cpp
    title: verify/cyclic-product.yosupo-a+b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/ext-gcd.yosupo-a+b.test.cpp
    title: verify/ext-gcd.yosupo-a+b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/monotonic-dp-hull-minkowski-sum.yosupo-a+b.test.cpp
    title: verify/monotonic-dp-hull-minkowski-sum.yosupo-a+b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/monotonic-dp-hull.yosupo-a+b.test.cpp
    title: verify/monotonic-dp-hull.yosupo-a+b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/wavelet-tree.yosupo-a+b.test.cpp
    title: verify/wavelet-tree.yosupo-a+b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/zip.yosupo-a+b.test.cpp
    title: verify/zip.yosupo-a+b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"random/mersenne-twister.hpp\"\n#pragma region mersenne_twister\n\
    \n#ifndef MERSENNE_TWISTER_HPP\n#define MERSENNE_TWISTER_HPP\n\nnamespace rng\
    \ {\n\tmt19937 mst(chrono::steady_clock::now().time_since_epoch().count());\n\
    }\n\n#endif\n\n#pragma endregion mersenne_twister\n"
  code: "#pragma region mersenne_twister\n\n#ifndef MERSENNE_TWISTER_HPP\n#define\
    \ MERSENNE_TWISTER_HPP\n\nnamespace rng {\n\tmt19937 mst(chrono::steady_clock::now().time_since_epoch().count());\n\
    }\n\n#endif\n\n#pragma endregion mersenne_twister"
  dependsOn: []
  isVerificationFile: false
  path: random/mersenne-twister.hpp
  requiredBy:
  - random/random-int.hpp
  - random/random-float.hpp
  - random/random-int-vector.hpp
  timestamp: '2022-05-18 09:09:46-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/zip.yosupo-a+b.test.cpp
  - verify/monotonic-dp-hull-minkowski-sum.yosupo-a+b.test.cpp
  - verify/ext-gcd.yosupo-a+b.test.cpp
  - verify/wavelet-tree.yosupo-a+b.test.cpp
  - verify/cyclic-product.yosupo-a+b.test.cpp
  - verify/monotonic-dp-hull.yosupo-a+b.test.cpp
documentation_of: random/mersenne-twister.hpp
layout: document
title: Mersenne Twister
---

## Mersenne Twister