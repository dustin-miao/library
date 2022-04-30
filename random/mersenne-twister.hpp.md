---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: random/random-vector.hpp
    title: Randomized Vector
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/ext-gcd.yosupo-a+b.test.cpp
    title: verify/ext-gcd.yosupo-a+b.test.cpp
  - icon: ':x:'
    path: verify/monotonic-dp-hull.yosupo-a+b.test.cpp
    title: verify/monotonic-dp-hull.yosupo-a+b.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: '#line 1 "random/mersenne-twister.hpp"

    #pragma region rng


    mt19937 _rng(chrono::steady_clock::now().time_since_epoch().count());


    template<typename T = int>

    typename enable_if<is_integral<T>::value, T>::type rng(T l, T r) { return uniform_int_distribution<T>(l,
    r)(_rng); }


    #pragma endregion rng

    '
  code: '#pragma region rng


    mt19937 _rng(chrono::steady_clock::now().time_since_epoch().count());


    template<typename T = int>

    typename enable_if<is_integral<T>::value, T>::type rng(T l, T r) { return uniform_int_distribution<T>(l,
    r)(_rng); }


    #pragma endregion rng'
  dependsOn: []
  isVerificationFile: false
  path: random/mersenne-twister.hpp
  requiredBy:
  - random/random-vector.hpp
  timestamp: '2022-04-29 22:36:50-07:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/monotonic-dp-hull.yosupo-a+b.test.cpp
  - verify/ext-gcd.yosupo-a+b.test.cpp
documentation_of: random/mersenne-twister.hpp
layout: document
title: Mersenne Twister
---

## Mersenne Twister