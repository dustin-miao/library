---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/convolution-mod.hpp
    title: Convolution under Modulo
  - icon: ':heavy_check_mark:'
    path: convolution/convolution.hpp
    title: Convolution
  - icon: ':heavy_check_mark:'
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
    path: verify/convolution-mod.yosupo-convolution-mod-1000000007.test.cpp
    title: verify/convolution-mod.yosupo-convolution-mod-1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/convolution-mod.yosupo-convolution.test.cpp
    title: verify/convolution-mod.yosupo-convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/convolution.yosupo-frequency-table-of-tree-distances.test.cpp
    title: verify/convolution.yosupo-frequency-table-of-tree-distances.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/slow-convolution.yosupo-frequency-table-of-tree-distances.test.cpp
    title: verify/slow-convolution.yosupo-frequency-table-of-tree-distances.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 1 "utility/pi.hpp"

    const double PI = acos(-1);

    '
  code: const double PI = acos(-1);
  dependsOn: []
  isVerificationFile: false
  path: utility/pi.hpp
  requiredBy:
  - convolution/convolution-mod.hpp
  - convolution/convolution.hpp
  - convolution/fast-fourier-transform.hpp
  - convolution/slow-fast-fourier-transform.hpp
  - convolution/slow-convolution.hpp
  timestamp: '2022-04-13 15:39:55-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/convolution.yosupo-frequency-table-of-tree-distances.test.cpp
  - verify/slow-convolution.yosupo-frequency-table-of-tree-distances.test.cpp
  - verify/convolution-mod.yosupo-convolution-mod-1000000007.test.cpp
  - verify/convolution-mod.yosupo-convolution.test.cpp
documentation_of: utility/pi.hpp
layout: document
title: Pi
---

## Pi