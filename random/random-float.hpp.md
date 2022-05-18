---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: random/mersenne-twister.hpp
    title: Mersenne Twister
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"random/mersenne-twister.hpp\"\n#pragma region mersenne_twister\n\
    \n#ifndef MERSENNE_TWISTER_HPP\n#define MERSENNE_TWISTER_HPP\n\nnamespace rng\
    \ {\n\tmt19937 mst(chrono::steady_clock::now().time_since_epoch().count());\n\
    }\n\n#endif\n\n#pragma endregion mersenne_twister\n#line 2 \"random/random-float.hpp\"\
    \n\n#pragma region rng_float\n\n#ifndef RANDOM_FLOAT_HPP\n#define RANDOM_FLOAT_HPP\n\
    \nmt19937 _rng(chrono::steady_clock::now().time_since_epoch().count());\n\nnamespace\
    \ rng {\n\ttemplate<typename T = double>\n\ttypename enable_if<is_floating_point<T>::value,\
    \ T>::type \n\trflt(T l, T r) { return uniform_real_distribution<T>(l, r)(mst);\
    \ }\n}\n\n#endif\n\n#pragma endregion rng_float\n"
  code: "#include \"mersenne-twister.hpp\"\n\n#pragma region rng_float\n\n#ifndef\
    \ RANDOM_FLOAT_HPP\n#define RANDOM_FLOAT_HPP\n\nmt19937 _rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    \nnamespace rng {\n\ttemplate<typename T = double>\n\ttypename enable_if<is_floating_point<T>::value,\
    \ T>::type \n\trflt(T l, T r) { return uniform_real_distribution<T>(l, r)(mst);\
    \ }\n}\n\n#endif\n\n#pragma endregion rng_float"
  dependsOn:
  - random/mersenne-twister.hpp
  isVerificationFile: false
  path: random/random-float.hpp
  requiredBy: []
  timestamp: '2022-05-18 09:09:46-07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: random/random-float.hpp
layout: document
title: Random Float
---

## Random Float