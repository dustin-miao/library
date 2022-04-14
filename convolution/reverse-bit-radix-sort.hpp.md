---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: convolution/convolution-mod.hpp
    title: Convolution under Modulo
  - icon: ':heavy_check_mark:'
    path: convolution/convolution.hpp
    title: Convolution
  - icon: ':heavy_check_mark:'
    path: convolution/fast-fourier-transform.hpp
    title: Fast Fourier Transform
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/convolution.yosupo-frequency-table-of-tree-distances.test.cpp
    title: verify/convolution.yosupo-frequency-table-of-tree-distances.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convolution/reverse-bit-radix-sort.hpp\"\ntemplate<typename\
    \ T>\nvoid reverse_bit_radix_sort(vector<T> &a) {\n\tint n = a.size();\n\tfor\
    \ (int i = 1, j = 0; i < n; i++) {\n\t\tint t = n >> 1;\n\t\tfor (; t & j; t >>=\
    \ 1)\n\t\t\tj ^= t;\n\t\tj ^= t;\n\t\tif (i < j)\n\t\t\tswap(a[i], a[j]);\n\t\
    }\n}\n"
  code: "template<typename T>\nvoid reverse_bit_radix_sort(vector<T> &a) {\n\tint\
    \ n = a.size();\n\tfor (int i = 1, j = 0; i < n; i++) {\n\t\tint t = n >> 1;\n\
    \t\tfor (; t & j; t >>= 1)\n\t\t\tj ^= t;\n\t\tj ^= t;\n\t\tif (i < j)\n\t\t\t\
    swap(a[i], a[j]);\n\t}\n}"
  dependsOn: []
  isVerificationFile: false
  path: convolution/reverse-bit-radix-sort.hpp
  requiredBy:
  - convolution/convolution-mod.hpp
  - convolution/convolution.hpp
  - convolution/fast-fourier-transform.hpp
  timestamp: '2022-04-14 09:16:54-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/convolution.yosupo-frequency-table-of-tree-distances.test.cpp
documentation_of: convolution/reverse-bit-radix-sort.hpp
layout: document
redirect_from:
- /library/convolution/reverse-bit-radix-sort.hpp
- /library/convolution/reverse-bit-radix-sort.hpp.html
title: convolution/reverse-bit-radix-sort.hpp
---
