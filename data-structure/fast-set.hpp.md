---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/discrete-log.hpp
    title: Discrete Logarithm
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/cycle-finding.yosupo-cycle-detection.test.cpp
    title: verify/cycle-finding.yosupo-cycle-detection.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/discrete-log.yosupo-discrete-logarithm.test.cpp
    title: verify/discrete-log.yosupo-discrete-logarithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/fast-set.hpp\"\n#pragma region fast_set\n\
    \nstruct custom_hash {\n    static uint64_t splitmix64(uint64_t x) {\n       \
    \ x += 0x9e3779b97f4a7c15;\n        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n\
    \        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n        return x ^ (x >> 31);\n\
    \    }\n\n    size_t operator()(uint64_t x) const {\n        static const uint64_t\
    \ FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();\n   \
    \     return splitmix64(x + FIXED_RANDOM);\n    }\n\n\ttemplate<typename T>\n\
    \    size_t operator()(const pair<T, T> &x) const { \n\t\treturn (*this)(x.first)\
    \ ^ __builtin_bswap64((*this)(x.second)); \n\t}\n\n\ttemplate<typename T>\n  \
    \  size_t operator()(const tuple<T, T, T> &x) const { \n\t\treturn (*this)(get<0>(x))\
    \ + __builtin_bswap64((*this)(make_pair(get<1>(x), get<2>(x)))); \n\t}\n\n\ttemplate<typename\
    \ T>\n    size_t operator()(const tuple<T, T, T, T> &x) const { \n\t\treturn (*this)(get<0>(x))\
    \ + __builtin_bswap64((*this)(make_tuple(get<1>(x), get<2>(x), get<3>(x)))); \n\
    \t}\n};\n\n#include <ext/pb_ds/assoc_container.hpp>\nusing namespace __gnu_pbds;\n\
    \ntemplate <class K, class V>\nusing fast_map = gp_hash_table<K, V, custom_hash>;\n\
    \ntemplate <class K>\nusing fast_set = gp_hash_table<K, null_type, custom_hash>;\n\
    \n#pragma endregion fast_set\n"
  code: "#pragma region fast_set\n\nstruct custom_hash {\n    static uint64_t splitmix64(uint64_t\
    \ x) {\n        x += 0x9e3779b97f4a7c15;\n        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n\
    \        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n        return x ^ (x >> 31);\n\
    \    }\n\n    size_t operator()(uint64_t x) const {\n        static const uint64_t\
    \ FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();\n   \
    \     return splitmix64(x + FIXED_RANDOM);\n    }\n\n\ttemplate<typename T>\n\
    \    size_t operator()(const pair<T, T> &x) const { \n\t\treturn (*this)(x.first)\
    \ ^ __builtin_bswap64((*this)(x.second)); \n\t}\n\n\ttemplate<typename T>\n  \
    \  size_t operator()(const tuple<T, T, T> &x) const { \n\t\treturn (*this)(get<0>(x))\
    \ + __builtin_bswap64((*this)(make_pair(get<1>(x), get<2>(x)))); \n\t}\n\n\ttemplate<typename\
    \ T>\n    size_t operator()(const tuple<T, T, T, T> &x) const { \n\t\treturn (*this)(get<0>(x))\
    \ + __builtin_bswap64((*this)(make_tuple(get<1>(x), get<2>(x), get<3>(x)))); \n\
    \t}\n};\n\n#include <ext/pb_ds/assoc_container.hpp>\nusing namespace __gnu_pbds;\n\
    \ntemplate <class K, class V>\nusing fast_map = gp_hash_table<K, V, custom_hash>;\n\
    \ntemplate <class K>\nusing fast_set = gp_hash_table<K, null_type, custom_hash>;\n\
    \n#pragma endregion fast_set\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/fast-set.hpp
  requiredBy:
  - math/discrete-log.hpp
  timestamp: '2022-04-29 22:36:50-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/cycle-finding.yosupo-cycle-detection.test.cpp
  - verify/discrete-log.yosupo-discrete-logarithm.test.cpp
documentation_of: data-structure/fast-set.hpp
layout: document
title: Fast Set
---

## Fast Set