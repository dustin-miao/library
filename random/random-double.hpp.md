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
  bundledCode: '#line 1 "random/random-double.hpp"

    #pragma region rng


    #ifndef RANDOM_DOUBLE

    #define RANDOM_DOUBLE


    mt19937 _rng(chrono::steady_clock::now().time_since_epoch().count());


    template<typename T = double>

    typename enable_if<is_floating_point<T>::value, T>::type rng(T l, T r) { return
    uniform_real_distribution<T>(l, r)(_rng); }


    #endif


    #pragma endregion rng

    '
  code: '#pragma region rng


    #ifndef RANDOM_DOUBLE

    #define RANDOM_DOUBLE


    mt19937 _rng(chrono::steady_clock::now().time_since_epoch().count());


    template<typename T = double>

    typename enable_if<is_floating_point<T>::value, T>::type rng(T l, T r) { return
    uniform_real_distribution<T>(l, r)(_rng); }


    #endif


    #pragma endregion rng'
  dependsOn: []
  isVerificationFile: false
  path: random/random-double.hpp
  requiredBy: []
  timestamp: '2022-05-14 19:13:35-07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: random/random-double.hpp
layout: document
title: Random Double
---

## Random Double

TODO: Move MT to seperate file inclued by random-double and random-int