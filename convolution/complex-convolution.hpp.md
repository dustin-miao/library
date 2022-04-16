---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: convolution/fast-fourier-transform.hpp
    title: Fast Fourier Transform
  - icon: ':question:'
    path: utility/pi.hpp
    title: Pi
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/complex-convolution.aizu-naive-string-search.test.cpp
    title: verify/complex-convolution.aizu-naive-string-search.test.cpp
  - icon: ':x:'
    path: verify/complex-convolution.aizu-string-search.test.cpp
    title: verify/complex-convolution.aizu-string-search.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/complex-convolution.yosupo-frequency-table-of-tree-distances.test.cpp
    title: verify/complex-convolution.yosupo-frequency-table-of-tree-distances.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utility/pi.hpp\"\nconst double PI = acos(-1);\n#line 2 \"\
    convolution/fast-fourier-transform.hpp\"\n\nnamespace conv {\n\ttemplate<typename\
    \ T>\n\ttypename enable_if<is_floating_point<T>::value, void>::type\n\tfast_fourier_transform(vector<complex<T>>\
    \ &a) {\n\t\tint n = a.size(), logn = 31 - __builtin_clz(n);\n\n\t\tvector<int>\
    \ rev(n);\n\t\trev[0] = 0;\n\t\tfor (int i = 1; i < n; i++) {\n\t\t\trev[i] =\
    \ (rev[i >> 1] >> 1) + ((i & 1) << (logn - 1));\n\t\t\tif (i < rev[i])\n\t\t\t\
    \tswap(a[i], a[rev[i]]);\n\t\t}\n\n\t\tvector<complex<T>> root(n);\n\t\troot[1]\
    \ = {1, 0};\n\t\tfor (int k = 1; k < logn; k++) {\n\t\t\tT the = 2 * PI / (1 <<\
    \ (k + 1));\n\t\t\tcomplex<T> z = {cos(the), sin(the)};\n\t\t\tfor (int i = (1\
    \ << (k - 1)); i < (1 << k); i++) {\n\t\t\t\troot[i << 1] = root[i];\n\t\t\t\t\
    root[i << 1 | 1] = root[i] * z;\n\t\t\t}\n\t\t}\n\n\t\tfor (int l = 1; l < n;\
    \ l <<= 1) {\n\t\t\tfor (int i = 0; i < n; i += (l << 1)) {\n\t\t\t\tfor (int\
    \ j = 0; j < l; j++) {\n\t\t\t\t\tauto z = root[j + l] * a[i + j + l];\n\t\t\t\
    \t\ta[i + j + l] = a[i + j] - z;\n\t\t\t\t\ta[i + j] += z;\n\t\t\t\t}\n\t\t\t\
    }\n\t\t}\n\t}\n}\n#line 2 \"convolution/complex-convolution.hpp\"\n\nnamespace\
    \ conv {\n\ttemplate<typename T, typename U = double>\n\tvector<complex<T>> complex_convolution(const\
    \ vector<complex<T>> &a, const vector<complex<T>> &b) {\n\t\tint n = 1;\n\t\t\
    while (n < a.size() + b.size()) \n\t\t\tn <<= 1;\n\t\tvector<complex<U>> pa(n),\
    \ pb(n);\n\t\tfor (int i = 0; i < a.size(); i++)\n\t\t\tpa[i] = complex<U>(a[i].real(),\
    \ a[i].imag());\n\t\tfor (int i = 0; i < b.size(); i++)\n\t\t\tpb[i] = complex<U>(b[i].real(),\
    \ b[i].imag());\n\n\t\tfast_fourier_transform(pa);\n\t\tfast_fourier_transform(pb);\n\
    \t\tvector<complex<U>> c(n);\n\t\tfor (int i = 0; i < n; i++) \n\t\t\tc[i] = pa[i]\
    \ * pb[i] / static_cast<U>(n);\n\t\treverse(c.begin() + 1, c.end());\n\t\tfast_fourier_transform(c);\n\
    \n\t\tn = a.size() + b.size() - 1;\n\t\tvector<complex<T>> ret(n);\n\t\tfor (int\
    \ i = 0; i < n; i++)\n\t\t\tret[i] = complex<T>(static_cast<T>(c[i].real() + 0.5),\
    \ static_cast<T>(c[i].imag() + 0.5));\n\t\treturn ret;\n\t}\n}\n"
  code: "#include \"convolution/fast-fourier-transform.hpp\"\n\nnamespace conv {\n\
    \ttemplate<typename T, typename U = double>\n\tvector<complex<T>> complex_convolution(const\
    \ vector<complex<T>> &a, const vector<complex<T>> &b) {\n\t\tint n = 1;\n\t\t\
    while (n < a.size() + b.size()) \n\t\t\tn <<= 1;\n\t\tvector<complex<U>> pa(n),\
    \ pb(n);\n\t\tfor (int i = 0; i < a.size(); i++)\n\t\t\tpa[i] = complex<U>(a[i].real(),\
    \ a[i].imag());\n\t\tfor (int i = 0; i < b.size(); i++)\n\t\t\tpb[i] = complex<U>(b[i].real(),\
    \ b[i].imag());\n\n\t\tfast_fourier_transform(pa);\n\t\tfast_fourier_transform(pb);\n\
    \t\tvector<complex<U>> c(n);\n\t\tfor (int i = 0; i < n; i++) \n\t\t\tc[i] = pa[i]\
    \ * pb[i] / static_cast<U>(n);\n\t\treverse(c.begin() + 1, c.end());\n\t\tfast_fourier_transform(c);\n\
    \n\t\tn = a.size() + b.size() - 1;\n\t\tvector<complex<T>> ret(n);\n\t\tfor (int\
    \ i = 0; i < n; i++)\n\t\t\tret[i] = complex<T>(static_cast<T>(c[i].real() + 0.5),\
    \ static_cast<T>(c[i].imag() + 0.5));\n\t\treturn ret;\n\t}\n}"
  dependsOn:
  - convolution/fast-fourier-transform.hpp
  - utility/pi.hpp
  isVerificationFile: false
  path: convolution/complex-convolution.hpp
  requiredBy: []
  timestamp: '2022-04-16 10:42:05-07:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/complex-convolution.aizu-naive-string-search.test.cpp
  - verify/complex-convolution.yosupo-frequency-table-of-tree-distances.test.cpp
  - verify/complex-convolution.aizu-string-search.test.cpp
documentation_of: convolution/complex-convolution.hpp
layout: document
title: Complex Convolution
---

## Complex Convolution