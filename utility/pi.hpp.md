---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: convolution/convolution-mod.hpp
    title: Convolution under Modulo
  - icon: ':heavy_check_mark:'
    path: convolution/convolution.hpp
    title: Convolution
  - icon: ':x:'
    path: convolution/fast-convolution.hpp
    title: Fast Convolution
  - icon: ':heavy_check_mark:'
    path: convolution/fast-fourier-transform.hpp
    title: Fast Fourier Transform
  - icon: ':x:'
    path: convolution/ultra-fast-fourier-transform.hpp
    title: Ultra Fast Fourier Transform
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/convolution-mod.yosupo-convolution-mod-1000000007.test.cpp
    title: verify/convolution-mod.yosupo-convolution-mod-1000000007.test.cpp
  - icon: ':x:'
    path: verify/convolution-mod.yosupo-convolution.test.cpp
    title: verify/convolution-mod.yosupo-convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/convolution.yosupo-frequency-table-of-tree-distances.test.cpp
    title: verify/convolution.yosupo-frequency-table-of-tree-distances.test.cpp
  - icon: ':x:'
    path: verify/fast-convolution.yosupo-frequency-table-of-tree-distances.test.cpp
    title: verify/fast-convolution.yosupo-frequency-table-of-tree-distances.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
  - convolution/fast-convolution.hpp
  - convolution/ultra-fast-fourier-transform.hpp
  - convolution/convolution.hpp
  - convolution/fast-fourier-transform.hpp
  timestamp: '2022-04-13 15:39:55-07:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/convolution.yosupo-frequency-table-of-tree-distances.test.cpp
  - verify/convolution-mod.yosupo-convolution-mod-1000000007.test.cpp
  - verify/fast-convolution.yosupo-frequency-table-of-tree-distances.test.cpp
  - verify/convolution-mod.yosupo-convolution.test.cpp
documentation_of: utility/pi.hpp
layout: document
title: Pi
---

## Pi