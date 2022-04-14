---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: convolution/reverse-bit-radix-sort.hpp
    title: Reverse Bit Radix Sort
  - icon: ':x:'
    path: utility/pi.hpp
    title: Pi
  _extendedRequiredBy:
  - icon: ':warning:'
    path: convolution/slow-convolution.hpp
    title: convolution/slow-convolution.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utility/pi.hpp\"\nconst double PI = acos(-1);\n#line 1 \"\
    convolution/reverse-bit-radix-sort.hpp\"\ntemplate<typename T>\nvoid reverse_bit_radix_sort(vector<T>\
    \ &a) {\n\tint n = a.size();\n\tfor (int i = 1, j = 0; i < n; i++) {\n\t\tint\
    \ t = n >> 1;\n\t\tfor (; t & j; t >>= 1)\n\t\t\tj ^= t;\n\t\tj ^= t;\n\t\tif\
    \ (i < j)\n\t\t\tswap(a[i], a[j]);\n\t}\n}\n#line 3 \"convolution/slow-fast-fourier-transform.hpp\"\
    \n\nnamespace conv {\n\ttemplate<typename T> \n\ttypename enable_if<is_floating_point<T>::value,\
    \ void>::type\n\tslow_fast_fourier_transform(vector<complex<T>> &a) {\n\t\tint\
    \ n = a.size();\n\t\treverse_bit_radix_sort(a);\n\t\tfor (int l = 2; l <= n; l\
    \ <<= 1) {\n\t\t\tT theta = 2 * PI / l;\n\t\t\tcomplex<T> dw(cos(theta), sin(theta));\n\
    \t\t\tfor (int i = 0; i < n; i += l) {\n\t\t\t\tcomplex<T> w = 1;\n\t\t\t\tfor\
    \ (int j = 0; j < l / 2; j++) {\n\t\t\t\t\tauto t1 = a[i + j], t2 = a[i + j +\
    \ l / 2] * w;\n\t\t\t\t\ta[i + j] = t1 + t2;\n\t\t\t\t\ta[i + j + l / 2] = t1\
    \ - t2;\n\t\t\t\t\tw *= dw;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\n\ttemplate<typename\
    \ T> \n\ttypename enable_if<is_floating_point<T>::value, void>::type\n\tslow_inverse_fast_fourier_transform(vector<complex<T>>\
    \ &a) {\n\t\tint n = a.size();\n\t\treverse_bit_radix_sort(a);\n\t\tfor (int l\
    \ = 2; l <= n; l <<= 1) {\n\t\t\tT theta = -2 * PI / l;\n\t\t\tcomplex<T> dw(cos(theta),\
    \ sin(theta));\n\t\t\tfor (int i = 0; i < n; i += l) {\n\t\t\t\tcomplex<T> w =\
    \ 1;\n\t\t\t\tfor (int j = 0; j < l / 2; j++) {\n\t\t\t\t\tauto t1 = a[i + j],\
    \ t2 = a[i + j + l / 2] * w;\n\t\t\t\t\ta[i + j] = t1 + t2;\n\t\t\t\t\ta[i + j\
    \ + l / 2] = t1 - t2;\n\t\t\t\t\tw *= dw;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tfor\
    \ (int i = 0; i < n; i++)\n\t\t\ta[i] /= n;\n\t}\n}\n"
  code: "#include \"utility/pi.hpp\"\n#include \"convolution/reverse-bit-radix-sort.hpp\"\
    \n\nnamespace conv {\n\ttemplate<typename T> \n\ttypename enable_if<is_floating_point<T>::value,\
    \ void>::type\n\tslow_fast_fourier_transform(vector<complex<T>> &a) {\n\t\tint\
    \ n = a.size();\n\t\treverse_bit_radix_sort(a);\n\t\tfor (int l = 2; l <= n; l\
    \ <<= 1) {\n\t\t\tT theta = 2 * PI / l;\n\t\t\tcomplex<T> dw(cos(theta), sin(theta));\n\
    \t\t\tfor (int i = 0; i < n; i += l) {\n\t\t\t\tcomplex<T> w = 1;\n\t\t\t\tfor\
    \ (int j = 0; j < l / 2; j++) {\n\t\t\t\t\tauto t1 = a[i + j], t2 = a[i + j +\
    \ l / 2] * w;\n\t\t\t\t\ta[i + j] = t1 + t2;\n\t\t\t\t\ta[i + j + l / 2] = t1\
    \ - t2;\n\t\t\t\t\tw *= dw;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\n\ttemplate<typename\
    \ T> \n\ttypename enable_if<is_floating_point<T>::value, void>::type\n\tslow_inverse_fast_fourier_transform(vector<complex<T>>\
    \ &a) {\n\t\tint n = a.size();\n\t\treverse_bit_radix_sort(a);\n\t\tfor (int l\
    \ = 2; l <= n; l <<= 1) {\n\t\t\tT theta = -2 * PI / l;\n\t\t\tcomplex<T> dw(cos(theta),\
    \ sin(theta));\n\t\t\tfor (int i = 0; i < n; i += l) {\n\t\t\t\tcomplex<T> w =\
    \ 1;\n\t\t\t\tfor (int j = 0; j < l / 2; j++) {\n\t\t\t\t\tauto t1 = a[i + j],\
    \ t2 = a[i + j + l / 2] * w;\n\t\t\t\t\ta[i + j] = t1 + t2;\n\t\t\t\t\ta[i + j\
    \ + l / 2] = t1 - t2;\n\t\t\t\t\tw *= dw;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tfor\
    \ (int i = 0; i < n; i++)\n\t\t\ta[i] /= n;\n\t}\n}"
  dependsOn:
  - utility/pi.hpp
  - convolution/reverse-bit-radix-sort.hpp
  isVerificationFile: false
  path: convolution/slow-fast-fourier-transform.hpp
  requiredBy:
  - convolution/slow-convolution.hpp
  timestamp: '2022-04-14 13:47:28-07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convolution/slow-fast-fourier-transform.hpp
layout: document
redirect_from:
- /library/convolution/slow-fast-fourier-transform.hpp
- /library/convolution/slow-fast-fourier-transform.hpp.html
title: convolution/slow-fast-fourier-transform.hpp
---
