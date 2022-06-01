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
  - icon: ':heavy_check_mark:'
    path: convolution/convolution.hpp
    title: Convolution
  - icon: ':heavy_check_mark:'
    path: convolution/cyclic-product.hpp
    title: Cyclic Product
  - icon: ':heavy_check_mark:'
    path: convolution/fast-fourier-transform.hpp
    title: Fast Fourier Transform
  - icon: ':heavy_check_mark:'
    path: convolution/slow-convolution.hpp
    title: Slow Convolution
  - icon: ':heavy_check_mark:'
    path: convolution/slow-fast-fourier-transform.hpp
    title: Slow Fast Fourier Transform
  - icon: ':question:'
    path: poly/polynomial.hpp
    title: Polynomial
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
  - icon: ':heavy_check_mark:'
    path: verify/cyclic-product.yosupo-a+b.test.cpp
    title: verify/cyclic-product.yosupo-a+b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/polynomial-yosupo-division-of-polynomials.test.cpp
    title: verify/polynomial-yosupo-division-of-polynomials.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/polynomial.yosupo-composition-of-formal-power-series.test.cpp
    title: verify/polynomial.yosupo-composition-of-formal-power-series.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/polynomial.yosupo-convolution-mod-1000000007.test.cpp
    title: verify/polynomial.yosupo-convolution-mod-1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/polynomial.yosupo-convolution.test.cpp
    title: verify/polynomial.yosupo-convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/polynomial.yosupo-exp-of-formal-power-series.test.cpp
    title: verify/polynomial.yosupo-exp-of-formal-power-series.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/polynomial.yosupo-find-linear-recurrence.test.cpp
    title: verify/polynomial.yosupo-find-linear-recurrence.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/polynomial.yosupo-inv-of-formal-power-series.test.cpp
    title: verify/polynomial.yosupo-inv-of-formal-power-series.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/polynomial.yosupo-inv-of-polynomials.test.cpp
    title: verify/polynomial.yosupo-inv-of-polynomials.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/polynomial.yosupo-kth-term-of-linearly-recurrent-sequence.test.cpp
    title: verify/polynomial.yosupo-kth-term-of-linearly-recurrent-sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/polynomial.yosupo-log-of-formal-power-series.test.cpp
    title: verify/polynomial.yosupo-log-of-formal-power-series.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/polynomial.yosupo-multipoint-evaluation.test.cpp
    title: verify/polynomial.yosupo-multipoint-evaluation.test.cpp
  - icon: ':x:'
    path: verify/polynomial.yosupo-polynomial-interpolation.test.cpp
    title: verify/polynomial.yosupo-polynomial-interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/polynomial.yosupo-polynomial-taylor-shift.test.cpp
    title: verify/polynomial.yosupo-polynomial-taylor-shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/polynomial.yosupo-pow-of-formal-power-series.test.cpp
    title: verify/polynomial.yosupo-pow-of-formal-power-series.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/polynomial.yosupo-sqrt-of-formal-power-series.test.cpp
    title: verify/polynomial.yosupo-sqrt-of-formal-power-series.test.cpp
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


    #ifndef PI_HPP

    #define PI_HPP


    const double PI = acos(-1);


    #endif


    #pragma endregion Pi

    '
  code: '#pragma region Pi


    #ifndef PI_HPP

    #define PI_HPP


    const double PI = acos(-1);


    #endif


    #pragma endregion Pi'
  dependsOn: []
  isVerificationFile: false
  path: utility/pi.hpp
  requiredBy:
  - poly/polynomial.hpp
  - convolution/slow-convolution.hpp
  - convolution/complex-convolution.hpp
  - convolution/convolution-mod.hpp
  - convolution/cyclic-product.hpp
  - convolution/slow-fast-fourier-transform.hpp
  - convolution/convolution.hpp
  - convolution/fast-fourier-transform.hpp
  timestamp: '2022-05-03 13:27:25-07:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/cyclic-product.yosupo-a+b.test.cpp
  - verify/polynomial.yosupo-inv-of-formal-power-series.test.cpp
  - verify/polynomial.yosupo-sqrt-of-formal-power-series.test.cpp
  - verify/polynomial.yosupo-pow-of-formal-power-series.test.cpp
  - verify/polynomial.yosupo-polynomial-interpolation.test.cpp
  - verify/complex-convolution.aizu-string-search.test.cpp
  - verify/polynomial-yosupo-division-of-polynomials.test.cpp
  - verify/slow-convolution.yosupo-frequency-table-of-tree-distances.test.cpp
  - verify/polynomial.yosupo-multipoint-evaluation.test.cpp
  - verify/polynomial.yosupo-convolution.test.cpp
  - verify/convolution-mod.yosupo-convolution-mod-1000000007.test.cpp
  - verify/complex-convolution.aizu-naive-string-search.test.cpp
  - verify/convolution-mod.yosupo-convolution.test.cpp
  - verify/convolution.yosupo-frequency-table-of-tree-distances.test.cpp
  - verify/polynomial.yosupo-kth-term-of-linearly-recurrent-sequence.test.cpp
  - verify/polynomial.yosupo-find-linear-recurrence.test.cpp
  - verify/polynomial.yosupo-inv-of-polynomials.test.cpp
  - verify/polynomial.yosupo-composition-of-formal-power-series.test.cpp
  - verify/polynomial.yosupo-log-of-formal-power-series.test.cpp
  - verify/polynomial.yosupo-polynomial-taylor-shift.test.cpp
  - verify/polynomial.yosupo-convolution-mod-1000000007.test.cpp
  - verify/polynomial.yosupo-exp-of-formal-power-series.test.cpp
documentation_of: utility/pi.hpp
layout: document
title: Pi
---

## Pi