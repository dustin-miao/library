---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/slow-convolution.hpp
    title: Slow Convolution
  - icon: ':heavy_check_mark:'
    path: convolution/slow-fast-fourier-transform.hpp
    title: Slow Fast Fourier Transform
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/slow-convolution.yosupo-frequency-table-of-tree-distances.test.cpp
    title: verify/slow-convolution.yosupo-frequency-table-of-tree-distances.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convolution/reverse-bit-radix-sort.hpp\"\n#pragma region\
    \ reverse_bit_radix_sort\n\ntemplate<typename T>\nvoid reverse_bit_radix_sort(vector<T>\
    \ &a) {\n\tint n = a.size();\n\tfor (int i = 1, j = 0; i < n; i++) {\n\t\tint\
    \ t = n >> 1;\n\t\tfor (; t & j; t >>= 1)\n\t\t\tj ^= t;\n\t\tj ^= t;\n\t\tif\
    \ (i < j)\n\t\t\tswap(a[i], a[j]);\n\t}\n}\n\n#pragma endregion reverse_bit_radix_sort\n"
  code: "#pragma region reverse_bit_radix_sort\n\ntemplate<typename T>\nvoid reverse_bit_radix_sort(vector<T>\
    \ &a) {\n\tint n = a.size();\n\tfor (int i = 1, j = 0; i < n; i++) {\n\t\tint\
    \ t = n >> 1;\n\t\tfor (; t & j; t >>= 1)\n\t\t\tj ^= t;\n\t\tj ^= t;\n\t\tif\
    \ (i < j)\n\t\t\tswap(a[i], a[j]);\n\t}\n}\n\n#pragma endregion reverse_bit_radix_sort"
  dependsOn: []
  isVerificationFile: false
  path: convolution/reverse-bit-radix-sort.hpp
  requiredBy:
  - convolution/slow-convolution.hpp
  - convolution/slow-fast-fourier-transform.hpp
  timestamp: '2022-04-29 22:36:50-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/slow-convolution.yosupo-frequency-table-of-tree-distances.test.cpp
documentation_of: convolution/reverse-bit-radix-sort.hpp
layout: document
title: Reverse Bit Radix Sort
---

## Reverse Bit Radix Sort