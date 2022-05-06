---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: random/mersenne-twister.hpp
    title: Mersenne Twister
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/cyclic-product.yosupo-a+b.test.cpp
    title: verify/cyclic-product.yosupo-a+b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/monotonic-dp-hull-minkowski-sum.yosupo-a+b.test.cpp
    title: verify/monotonic-dp-hull-minkowski-sum.yosupo-a+b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/monotonic-dp-hull.yosupo-a+b.test.cpp
    title: verify/monotonic-dp-hull.yosupo-a+b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/zip.yosupo-a+b.test.cpp
    title: verify/zip.yosupo-a+b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"random/mersenne-twister.hpp\"\n#pragma region rng\n\n#ifndef\
    \ MERSENNE_TWISTER_HPP\n#define MERSENNE_TWISTER_HPP\n\nmt19937 _rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    \ntemplate<typename T = int>\ntypename enable_if<is_integral<T>::value, T>::type\
    \ rng(T l, T r) { return uniform_int_distribution<T>(l, r)(_rng); }\n\n#endif\n\
    \n#pragma endregion rng\n#line 2 \"random/random-vector.hpp\"\n\n#pragma region\
    \ rng_vector\n\n#ifndef RNG_VECTOR_HPP\n#define RNG_VECTOR_HPP\n\ntemplate<typename\
    \ T>\ntypename enable_if<is_integral<T>::value, vector<T>>::type rng_vector(int\
    \ n, T l, T r) {\n\tvector<T> v(n);\n\tfor (auto &a : v)\n\t\ta = rng(l, r);\n\
    \treturn v;\n}\n\n#endif\n\n#pragma endregion rng_vector\n"
  code: "#include \"mersenne-twister.hpp\"\n\n#pragma region rng_vector\n\n#ifndef\
    \ RNG_VECTOR_HPP\n#define RNG_VECTOR_HPP\n\ntemplate<typename T>\ntypename enable_if<is_integral<T>::value,\
    \ vector<T>>::type rng_vector(int n, T l, T r) {\n\tvector<T> v(n);\n\tfor (auto\
    \ &a : v)\n\t\ta = rng(l, r);\n\treturn v;\n}\n\n#endif\n\n#pragma endregion rng_vector"
  dependsOn:
  - random/mersenne-twister.hpp
  isVerificationFile: false
  path: random/random-vector.hpp
  requiredBy: []
  timestamp: '2022-05-03 13:32:14-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/zip.yosupo-a+b.test.cpp
  - verify/monotonic-dp-hull.yosupo-a+b.test.cpp
  - verify/monotonic-dp-hull-minkowski-sum.yosupo-a+b.test.cpp
  - verify/cyclic-product.yosupo-a+b.test.cpp
documentation_of: random/random-vector.hpp
layout: document
title: Randomized Vector
---

## Randomized Vector