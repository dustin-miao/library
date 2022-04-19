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
  bundledCode: '#line 1 "random/mersenne_twister.hpp"

    mt19937 _rng(chrono::steady_clock::now().time_since_epoch().count());


    template<typename T = int>

    T rng(T l, T r) { return uniform_int_distribution<T>(l, r)(_rng); }

    '
  code: 'mt19937 _rng(chrono::steady_clock::now().time_since_epoch().count());


    template<typename T = int>

    T rng(T l, T r) { return uniform_int_distribution<T>(l, r)(_rng); }'
  dependsOn: []
  isVerificationFile: false
  path: random/mersenne_twister.hpp
  requiredBy: []
  timestamp: '2022-04-19 13:01:20-07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: random/mersenne_twister.hpp
layout: document
title: Mersenne Twister
---

## Mersenne Twister