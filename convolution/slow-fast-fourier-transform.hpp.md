---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/reverse-bit-radix-sort.hpp
    title: Reverse Bit Radix Sort
  - icon: ':heavy_check_mark:'
    path: utility/pi.hpp
    title: Pi
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/slow-convolution.hpp
    title: Slow Convolution
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/slow-convolution.yosupo-frequency-table-of-tree-distances.test.cpp
    title: verify/slow-convolution.yosupo-frequency-table-of-tree-distances.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utility/pi.hpp\"\n#pragma region Pi\n\n#ifndef PI_HPP\n\
    #define PI_HPP\n\nconst double PI = acos(-1);\n\n#endif\n\n#pragma endregion Pi\n\
    #line 1 \"convolution/reverse-bit-radix-sort.hpp\"\n#pragma region reverse_bit_radix_sort\n\
    \ntemplate<typename T>\nvoid reverse_bit_radix_sort(vector<T> &a) {\n\tint n =\
    \ a.size();\n\tfor (int i = 1, j = 0; i < n; i++) {\n\t\tint t = n >> 1;\n\t\t\
    for (; t & j; t >>= 1)\n\t\t\tj ^= t;\n\t\tj ^= t;\n\t\tif (i < j)\n\t\t\tswap(a[i],\
    \ a[j]);\n\t}\n}\n\n#pragma endregion reverse_bit_radix_sort\n#line 3 \"convolution/slow-fast-fourier-transform.hpp\"\
    \n\n#pragma region slow_fast_fourier_transform\n\nnamespace conv {\n\ttemplate<typename\
    \ T> \n\ttypename enable_if<is_floating_point<T>::value, void>::type\n\tslow_fast_fourier_transform(vector<complex<T>>\
    \ &a) {\n\t\tint n = a.size();\n\t\treverse_bit_radix_sort(a);\n\t\tfor (int l\
    \ = 2; l <= n; l <<= 1) {\n\t\t\tT theta = 2 * PI / l;\n\t\t\tcomplex<T> dw(cos(theta),\
    \ sin(theta));\n\t\t\tfor (int i = 0; i < n; i += l) {\n\t\t\t\tcomplex<T> w =\
    \ 1;\n\t\t\t\tfor (int j = 0; j < l / 2; j++) {\n\t\t\t\t\tauto t1 = a[i + j],\
    \ t2 = a[i + j + l / 2] * w;\n\t\t\t\t\ta[i + j] = t1 + t2;\n\t\t\t\t\ta[i + j\
    \ + l / 2] = t1 - t2;\n\t\t\t\t\tw *= dw;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\n\t\
    template<typename T> \n\ttypename enable_if<is_floating_point<T>::value, void>::type\n\
    \tslow_inverse_fast_fourier_transform(vector<complex<T>> &a) {\n\t\tint n = a.size();\n\
    \t\treverse_bit_radix_sort(a);\n\t\tfor (int l = 2; l <= n; l <<= 1) {\n\t\t\t\
    T theta = -2 * PI / l;\n\t\t\tcomplex<T> dw(cos(theta), sin(theta));\n\t\t\tfor\
    \ (int i = 0; i < n; i += l) {\n\t\t\t\tcomplex<T> w = 1;\n\t\t\t\tfor (int j\
    \ = 0; j < l / 2; j++) {\n\t\t\t\t\tauto t1 = a[i + j], t2 = a[i + j + l / 2]\
    \ * w;\n\t\t\t\t\ta[i + j] = t1 + t2;\n\t\t\t\t\ta[i + j + l / 2] = t1 - t2;\n\
    \t\t\t\t\tw *= dw;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tfor (int i = 0; i < n; i++)\n\
    \t\t\ta[i] /= n;\n\t}\n}\n\n#pragma endregion slow_fast_fourier_transform\n"
  code: "#include \"utility/pi.hpp\"\n#include \"convolution/reverse-bit-radix-sort.hpp\"\
    \n\n#pragma region slow_fast_fourier_transform\n\nnamespace conv {\n\ttemplate<typename\
    \ T> \n\ttypename enable_if<is_floating_point<T>::value, void>::type\n\tslow_fast_fourier_transform(vector<complex<T>>\
    \ &a) {\n\t\tint n = a.size();\n\t\treverse_bit_radix_sort(a);\n\t\tfor (int l\
    \ = 2; l <= n; l <<= 1) {\n\t\t\tT theta = 2 * PI / l;\n\t\t\tcomplex<T> dw(cos(theta),\
    \ sin(theta));\n\t\t\tfor (int i = 0; i < n; i += l) {\n\t\t\t\tcomplex<T> w =\
    \ 1;\n\t\t\t\tfor (int j = 0; j < l / 2; j++) {\n\t\t\t\t\tauto t1 = a[i + j],\
    \ t2 = a[i + j + l / 2] * w;\n\t\t\t\t\ta[i + j] = t1 + t2;\n\t\t\t\t\ta[i + j\
    \ + l / 2] = t1 - t2;\n\t\t\t\t\tw *= dw;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\n\t\
    template<typename T> \n\ttypename enable_if<is_floating_point<T>::value, void>::type\n\
    \tslow_inverse_fast_fourier_transform(vector<complex<T>> &a) {\n\t\tint n = a.size();\n\
    \t\treverse_bit_radix_sort(a);\n\t\tfor (int l = 2; l <= n; l <<= 1) {\n\t\t\t\
    T theta = -2 * PI / l;\n\t\t\tcomplex<T> dw(cos(theta), sin(theta));\n\t\t\tfor\
    \ (int i = 0; i < n; i += l) {\n\t\t\t\tcomplex<T> w = 1;\n\t\t\t\tfor (int j\
    \ = 0; j < l / 2; j++) {\n\t\t\t\t\tauto t1 = a[i + j], t2 = a[i + j + l / 2]\
    \ * w;\n\t\t\t\t\ta[i + j] = t1 + t2;\n\t\t\t\t\ta[i + j + l / 2] = t1 - t2;\n\
    \t\t\t\t\tw *= dw;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tfor (int i = 0; i < n; i++)\n\
    \t\t\ta[i] /= n;\n\t}\n}\n\n#pragma endregion slow_fast_fourier_transform"
  dependsOn:
  - utility/pi.hpp
  - convolution/reverse-bit-radix-sort.hpp
  isVerificationFile: false
  path: convolution/slow-fast-fourier-transform.hpp
  requiredBy:
  - convolution/slow-convolution.hpp
  timestamp: '2022-05-03 13:27:25-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/slow-convolution.yosupo-frequency-table-of-tree-distances.test.cpp
documentation_of: convolution/slow-fast-fourier-transform.hpp
layout: document
title: Slow Fast Fourier Transform
---

## Slow Fast Fourier Transform