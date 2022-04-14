---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: convolution/slow-convolution.hpp
    title: convolution/slow-convolution.hpp
  - icon: ':warning:'
    path: convolution/slow-fast-fourier-transform.hpp
    title: convolution/slow-fast-fourier-transform.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
  - convolution/slow-fast-fourier-transform.hpp
  - convolution/slow-convolution.hpp
  timestamp: '2022-04-14 09:16:54-07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convolution/reverse-bit-radix-sort.hpp
layout: document
title: Reverse Bit Radix Sort
---

## Reverse Bit Radix Sort