---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/fast-fourier-transform.hpp
    title: Fast Fourier Transform
  - icon: ':heavy_check_mark:'
    path: utility/pi.hpp
    title: Pi
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/convolution.yosupo-frequency-table-of-tree-distances.test.cpp
    title: verify/convolution.yosupo-frequency-table-of-tree-distances.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utility/pi.hpp\"\nconst double PI = acos(-1);\n#line 2 \"\
    convolution/fast-fourier-transform.hpp\"\n\nnamespace conv {\n\ttemplate<typename\
    \ T>\n\tvoid reverse_bit_sort(vector<T> &a) {\n\t\tint n = a.size();\n\t\tfor\
    \ (int i = 1, j = 0; i < n; i++) {\n\t\t\tint t = n >> 1;\n\t\t\tfor (; t & j;\
    \ t >>= 1)\n\t\t\t\tj ^= t;\n\t\t\tj ^= t;\n\t\t\tif (i < j)\n\t\t\t\tswap(a[i],\
    \ a[j]);\n\t\t}\n\t}\n\n\ttemplate<typename T> \n\ttypename enable_if<is_floating_point<T>::value,\
    \ void>::type\n\tfast_fourier_transform(vector<complex<T>> &a) {\n\t\tint n =\
    \ a.size();\n\t\treverse_bit_sort(a);\n\t\tfor (int l = 2; l <= n; l <<= 1) {\n\
    \t\t\tT theta = 2 * PI / l;\n\t\t\tcomplex<T> dw(cos(theta), sin(theta));\n\t\t\
    \tfor (int i = 0; i < n; i += l) {\n\t\t\t\tcomplex<T> w = 1;\n\t\t\t\tfor (int\
    \ j = 0; j < l / 2; j++) {\n\t\t\t\t\tauto t1 = a[i + j], t2 = a[i + j + l / 2]\
    \ * w;\n\t\t\t\t\ta[i + j] = t1 + t2;\n\t\t\t\t\ta[i + j + l / 2] = t1 - t2;\n\
    \t\t\t\t\tw *= dw;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\n\ttemplate<typename T> \n\
    \ttypename enable_if<is_floating_point<T>::value, void>::type\n\tinverse_fast_fourier_transform(vector<complex<T>>\
    \ &a) {\n\t\tint n = a.size();\n\t\treverse_bit_sort(a);\n\t\tfor (int l = 2;\
    \ l <= n; l <<= 1) {\n\t\t\tT theta = -2 * PI / l;\n\t\t\tcomplex<T> dw(cos(theta),\
    \ sin(theta));\n\t\t\tfor (int i = 0; i < n; i += l) {\n\t\t\t\tcomplex<T> w =\
    \ 1;\n\t\t\t\tfor (int j = 0; j < l / 2; j++) {\n\t\t\t\t\tauto t1 = a[i + j],\
    \ t2 = a[i + j + l / 2] * w;\n\t\t\t\t\ta[i + j] = t1 + t2;\n\t\t\t\t\ta[i + j\
    \ + l / 2] = t1 - t2;\n\t\t\t\t\tw *= dw;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tfor\
    \ (int i = 0; i < n; i++)\n\t\t\ta[i] /= n;\n\t}\n}\n#line 2 \"convolution/convolution.hpp\"\
    \n\nnamespace conv {\n\ttemplate<typename T, typename U = double>\n\tvector<T>\
    \ convolution(const vector<T> &a, const vector<T> &b) {\n\t\tvector<complex<U>>\
    \ pa(a.begin(), a.end()), pb(b.begin(), b.end());\n\t\tint n = 1;\n\t\twhile (n\
    \ < a.size() + b.size()) \n\t\t\tn <<= 1;\n\t\tpa.resize(n), pb.resize(n);\n\n\
    \t\tfast_fourier_transform(pa);\n\t\tfast_fourier_transform(pb);\n\t\tfor (int\
    \ i = 0; i < n; i++)\n\t\t\tpa[i] *= pb[i];\n\t\tinverse_fast_fourier_transform(pa);\n\
    \n\t\tn = a.size() + b.size() - 1;\n\t\tvector<T> ret(n);\n\t\tfor (int i = 0;\
    \ i < n; i++)\n\t\t\tret[i] = round(pa[i].real());\n\t\treturn ret;\n\t}\n}\n"
  code: "#include \"convolution/fast-fourier-transform.hpp\"\n\nnamespace conv {\n\
    \ttemplate<typename T, typename U = double>\n\tvector<T> convolution(const vector<T>\
    \ &a, const vector<T> &b) {\n\t\tvector<complex<U>> pa(a.begin(), a.end()), pb(b.begin(),\
    \ b.end());\n\t\tint n = 1;\n\t\twhile (n < a.size() + b.size()) \n\t\t\tn <<=\
    \ 1;\n\t\tpa.resize(n), pb.resize(n);\n\n\t\tfast_fourier_transform(pa);\n\t\t\
    fast_fourier_transform(pb);\n\t\tfor (int i = 0; i < n; i++)\n\t\t\tpa[i] *= pb[i];\n\
    \t\tinverse_fast_fourier_transform(pa);\n\n\t\tn = a.size() + b.size() - 1;\n\t\
    \tvector<T> ret(n);\n\t\tfor (int i = 0; i < n; i++)\n\t\t\tret[i] = round(pa[i].real());\n\
    \t\treturn ret;\n\t}\n}"
  dependsOn:
  - convolution/fast-fourier-transform.hpp
  - utility/pi.hpp
  isVerificationFile: false
  path: convolution/convolution.hpp
  requiredBy: []
  timestamp: '2022-04-13 15:39:55-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/convolution.yosupo-frequency-table-of-tree-distances.test.cpp
documentation_of: convolution/convolution.hpp
layout: document
title: Convolution
---

## Convolution