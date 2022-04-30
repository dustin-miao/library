---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/complex-convolution.hpp
    title: Complex Convolution
  - icon: ':heavy_check_mark:'
    path: convolution/convolution-mod.hpp
    title: Convolution under Modulo
  - icon: ':question:'
    path: convolution/convolution.hpp
    title: Convolution
  - icon: ':x:'
    path: convolution/cyclic-product.hpp
    title: Cyclic Product
  - icon: ':question:'
    path: convolution/fast-fourier-transform.hpp
    title: Fast Fourier Transform
  - icon: ':heavy_check_mark:'
    path: convolution/slow-convolution.hpp
    title: Slow Convolution
  - icon: ':heavy_check_mark:'
    path: convolution/slow-fast-fourier-transform.hpp
    title: Slow Fast Fourier Transform
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/complex-convolution.aizu-naive-string-search.test.cpp
    title: verify/complex-convolution.aizu-naive-string-search.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/complex-convolution.aizu-string-search.test.cpp
    title: verify/complex-convolution.aizu-string-search.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/convolution-mod.yosupo-convolution-mod-1000000007.test.cpp
    title: verify/convolution-mod.yosupo-convolution-mod-1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/convolution-mod.yosupo-convolution.test.cpp
    title: verify/convolution-mod.yosupo-convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/convolution.yosupo-frequency-table-of-tree-distances.test.cpp
    title: verify/convolution.yosupo-frequency-table-of-tree-distances.test.cpp
  - icon: ':x:'
    path: verify/cyclic-product.yosupo-a+b.test.cpp
    title: verify/cyclic-product.yosupo-a+b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/slow-convolution.yosupo-frequency-table-of-tree-distances.test.cpp
    title: verify/slow-convolution.yosupo-frequency-table-of-tree-distances.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: '#line 1 "utility/pi.hpp"

    #pragma region Pi


    const double PI = acos(-1);


    #pragma endregion Pi

    '
  code: '#pragma region Pi


    const double PI = acos(-1);


    #pragma endregion Pi'
  dependsOn: []
  isVerificationFile: false
  path: utility/pi.hpp
  requiredBy:
  - convolution/slow-convolution.hpp
  - convolution/complex-convolution.hpp
  - convolution/fast-fourier-transform.hpp
  - convolution/convolution.hpp
  - convolution/slow-fast-fourier-transform.hpp
  - convolution/cyclic-product.hpp
  - convolution/convolution-mod.hpp
  timestamp: '2022-04-29 22:36:50-07:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/convolution.yosupo-frequency-table-of-tree-distances.test.cpp
  - verify/complex-convolution.aizu-naive-string-search.test.cpp
  - verify/convolution-mod.yosupo-convolution.test.cpp
  - verify/convolution-mod.yosupo-convolution-mod-1000000007.test.cpp
  - verify/slow-convolution.yosupo-frequency-table-of-tree-distances.test.cpp
  - verify/cyclic-product.yosupo-a+b.test.cpp
  - verify/complex-convolution.aizu-string-search.test.cpp
documentation_of: utility/pi.hpp
layout: document
title: Pi
---

## Pi