---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: convolution/fast-fourier-transform.hpp
    title: Fast Fourier Transform
  - icon: ':question:'
    path: utility/pi.hpp
    title: Pi
  _extendedRequiredBy:
  - icon: ':warning:'
    path: convolution/cyclic-product.hpp
    title: Cyclic Product
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/convolution.yosupo-frequency-table-of-tree-distances.test.cpp
    title: verify/convolution.yosupo-frequency-table-of-tree-distances.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utility/pi.hpp\"\nconst double PI = acos(-1);\n#line 2 \"\
    convolution/fast-fourier-transform.hpp\"\n\nnamespace conv {\n\ttemplate<typename\
    \ T>\n\ttypename enable_if<is_floating_point<T>::value, void>::type\n\tfast_fourier_transform(vector<complex<T>>\
    \ &a) {\n\t\t \n\n\t\tvector<int> rev(n);\n\t\trev[0] = 0;\n\t\tfor (int i = 1;\
    \ i < n; i++) {\n\t\t\trev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (logn - 1));\n\
    \t\t\tif (i < rev[i])\n\t\t\t\tswap(a[i], a[rev[i]]);\n\t\t}\n\n\t\tvector<complex<T>>\
    \ root(n);\n\t\troot[1] = {1, 0};\n\t\tfor (int k = 1; k < logn; k++) {\n\t\t\t\
    T the = 2 * PI / (1 << (k + 1));\n\t\t\tcomplex<T> z = {cos(the), sin(the)};\n\
    \t\t\tfor (int i = (1 << (k - 1)); i < (1 << k); i++) {\n\t\t\t\troot[i << 1]\
    \ = root[i];\n\t\t\t\troot[i << 1 | 1] = root[i] * z;\n\t\t\t}\n\t\t}\n\n\t\t\
    for (int l = 1; l < n; l <<= 1) {\n\t\t\tfor (int i = 0; i < n; i += (l << 1))\
    \ {\n\t\t\t\tfor (int j = 0; j < l; j++) {\n\t\t\t\t\tauto z = root[j + l] * a[i\
    \ + j + l];\n\t\t\t\t\ta[i + j + l] = a[i + j] - z;\n\t\t\t\t\ta[i + j] += z;\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n}\n#line 2 \"convolution/convolution.hpp\"\n\n\
    namespace conv {\n\ttemplate<typename T, typename U = double>\n\tvector<T> convolution(const\
    \ vector<T> &a, const vector<T> &b) {\n\t\tint n = 1;\n\t\twhile (n < a.size()\
    \ + b.size()) \n\t\t\tn <<= 1;\n\t\tvector<complex<U>> c(n);\n\t\tfor (int i =\
    \ 0; i < a.size(); i++)\n\t\t\tc[i] = static_cast<U>(a[i]);\n\t\tfor (int i =\
    \ 0; i < b.size(); i++)\n\t\t\tc[i] = {c[i].real(), static_cast<U>(b[i])};\n\t\
    \tfast_fourier_transform(c);\n\n\t\tvector<complex<U>> d(n);\n\t\tfor (int i =\
    \ 0, j; i < n; i++) {\n\t\t\tj = (n - i) & (n - 1);\n\t\t\td[i] = (c[j] * c[j]\
    \ - conj(c[i] * c[i])) * complex<U>{0, -0.25 / n};\n\t\t}\n\t\tfast_fourier_transform(d);\n\
    \n\t\tn = a.size() + b.size() - 1;\n\t\tvector<T> ret(n);\n\t\tfor (int i = 0;\
    \ i < n; i++)\n\t\t\tret[i] = static_cast<T>(d[i].real() + 0.5);\n\t\treturn ret;\n\
    \t}\n}\n"
  code: "#include \"convolution/fast-fourier-transform.hpp\"\n\nnamespace conv {\n\
    \ttemplate<typename T, typename U = double>\n\tvector<T> convolution(const vector<T>\
    \ &a, const vector<T> &b) {\n\t\tint n = 1;\n\t\twhile (n < a.size() + b.size())\
    \ \n\t\t\tn <<= 1;\n\t\tvector<complex<U>> c(n);\n\t\tfor (int i = 0; i < a.size();\
    \ i++)\n\t\t\tc[i] = static_cast<U>(a[i]);\n\t\tfor (int i = 0; i < b.size();\
    \ i++)\n\t\t\tc[i] = {c[i].real(), static_cast<U>(b[i])};\n\t\tfast_fourier_transform(c);\n\
    \n\t\tvector<complex<U>> d(n);\n\t\tfor (int i = 0, j; i < n; i++) {\n\t\t\tj\
    \ = (n - i) & (n - 1);\n\t\t\td[i] = (c[j] * c[j] - conj(c[i] * c[i])) * complex<U>{0,\
    \ -0.25 / n};\n\t\t}\n\t\tfast_fourier_transform(d);\n\n\t\tn = a.size() + b.size()\
    \ - 1;\n\t\tvector<T> ret(n);\n\t\tfor (int i = 0; i < n; i++)\n\t\t\tret[i] =\
    \ static_cast<T>(d[i].real() + 0.5);\n\t\treturn ret;\n\t}\n}"
  dependsOn:
  - convolution/fast-fourier-transform.hpp
  - utility/pi.hpp
  isVerificationFile: false
  path: convolution/convolution.hpp
  requiredBy:
  - convolution/cyclic-product.hpp
  timestamp: '2022-04-21 20:14:03-07:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/convolution.yosupo-frequency-table-of-tree-distances.test.cpp
documentation_of: convolution/convolution.hpp
layout: document
title: Convolution
---

## Convolution