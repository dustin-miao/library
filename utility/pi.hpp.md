---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: convolution/convolution-mod.hpp
    title: Convolution under Modulo
  - icon: ':x:'
    path: convolution/convolution.hpp
    title: Convolution
  - icon: ':x:'
    path: convolution/fast-fourier-transform.hpp
    title: Fast Fourier Transform
  - icon: ':warning:'
    path: convolution/slow-convolution.hpp
    title: convolution/slow-convolution.hpp
  - icon: ':warning:'
    path: convolution/slow-fast-fourier-transform.hpp
    title: convolution/slow-fast-fourier-transform.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/convolution-mod.yosupo-convolution-mod-1000000007.test.cpp
    title: verify/convolution-mod.yosupo-convolution-mod-1000000007.test.cpp
  - icon: ':x:'
    path: verify/convolution-mod.yosupo-convolution.test.cpp
    title: verify/convolution-mod.yosupo-convolution.test.cpp
  - icon: ':x:'
    path: verify/convolution.yosupo-frequency-table-of-tree-distances.test.cpp
    title: verify/convolution.yosupo-frequency-table-of-tree-distances.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/convolution.yosupo-frequency-table-of-tree-distances.test.cpp
  - verify/convolution-mod.yosupo-convolution-mod-1000000007.test.cpp
  - verify/convolution-mod.yosupo-convolution.test.cpp
documentation_of: utility/pi.hpp
layout: document
title: Pi
---

## Pi