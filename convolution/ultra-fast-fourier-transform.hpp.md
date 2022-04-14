---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/pi.hpp
    title: Pi
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/fast-convolution.hpp
    title: convolution/fast-convolution.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/fast-convolution.yosupo-frequency-table-of-tree-distances.test.cpp
    title: verify/fast-convolution.yosupo-frequency-table-of-tree-distances.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utility/pi.hpp\"\nconst double PI = acos(-1);\n#line 2 \"\
    convolution/ultra-fast-fourier-transform.hpp\"\n\ntemplate<typename T>\nvoid ultra_fast_fourier_transform(vector<complex<T>>\
    \ &a) {\n\tint n = a.size(), logn = 31 - __builtin_clz(n);\n\n\tvector<int> rev(n);\n\
    \trev[0] = 0;\n\tfor (int i = 1; i < n; i++) {\n\t\trev[i] = (rev[i >> 1] >> 1)\
    \ + ((i & 1) << (logn - 1));\n\t\tif (i < rev[i])\n\t\t\tswap(a[i], a[rev[i]]);\n\
    \t}\n\n\tvector<complex<T>> root(n);\n\troot[1] = {1, 0};\n\tfor (int k = 1; k\
    \ < logn; k++) {\n\t\tT the = 2 * PI / (1 << (k + 1));\n\t\tcomplex<T> z = {cos(the),\
    \ sin(the)};\n\t\tfor (int i = (1 << (k - 1)); i < (1 << k); i++) {\n\t\t\troot[i\
    \ << 1] = root[i];\n\t\t\troot[i << 1 | 1] = root[i] * z;\n\t\t}\n\t}\n\n\tfor\
    \ (int l = 1; l < n; l <<= 1) {\n\t\tfor (int i = 0; i < n; i += (l << 1)) {\n\
    \t\t\tfor (int j = 0; j < l; j++) {\n\t\t\t\tauto z = root[j + l] * a[i + j +\
    \ l];\n\t\t\t\ta[i + j + l] = a[i + j] - z;\n\t\t\t\ta[i + j] += z;\n\t\t\t}\n\
    \t\t}\n\t}\n}\n"
  code: "#include \"utility/pi.hpp\"\n\ntemplate<typename T>\nvoid ultra_fast_fourier_transform(vector<complex<T>>\
    \ &a) {\n\tint n = a.size(), logn = 31 - __builtin_clz(n);\n\n\tvector<int> rev(n);\n\
    \trev[0] = 0;\n\tfor (int i = 1; i < n; i++) {\n\t\trev[i] = (rev[i >> 1] >> 1)\
    \ + ((i & 1) << (logn - 1));\n\t\tif (i < rev[i])\n\t\t\tswap(a[i], a[rev[i]]);\n\
    \t}\n\n\tvector<complex<T>> root(n);\n\troot[1] = {1, 0};\n\tfor (int k = 1; k\
    \ < logn; k++) {\n\t\tT the = 2 * PI / (1 << (k + 1));\n\t\tcomplex<T> z = {cos(the),\
    \ sin(the)};\n\t\tfor (int i = (1 << (k - 1)); i < (1 << k); i++) {\n\t\t\troot[i\
    \ << 1] = root[i];\n\t\t\troot[i << 1 | 1] = root[i] * z;\n\t\t}\n\t}\n\n\tfor\
    \ (int l = 1; l < n; l <<= 1) {\n\t\tfor (int i = 0; i < n; i += (l << 1)) {\n\
    \t\t\tfor (int j = 0; j < l; j++) {\n\t\t\t\tauto z = root[j + l] * a[i + j +\
    \ l];\n\t\t\t\ta[i + j + l] = a[i + j] - z;\n\t\t\t\ta[i + j] += z;\n\t\t\t}\n\
    \t\t}\n\t}\n}"
  dependsOn:
  - utility/pi.hpp
  isVerificationFile: false
  path: convolution/ultra-fast-fourier-transform.hpp
  requiredBy:
  - convolution/fast-convolution.hpp
  timestamp: '2022-04-14 13:16:36-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/fast-convolution.yosupo-frequency-table-of-tree-distances.test.cpp
documentation_of: convolution/ultra-fast-fourier-transform.hpp
layout: document
title: Ultra Fast Fourier Transform
---

## Ultra Fast Fourier Transform

Run between $50%$ and $100%$ faster than fast fourier transform.