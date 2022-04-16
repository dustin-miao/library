---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/complex-convolution.hpp
    title: Complex Convolution
  - icon: ':heavy_check_mark:'
    path: convolution/fast-fourier-transform.hpp
    title: Fast Fourier Transform
  - icon: ':heavy_check_mark:'
    path: utility/pi.hpp
    title: Pi
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"verify/complex-convolution.aizu-string-search.test.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"utility/pi.hpp\"\
    \nconst double PI = acos(-1);\n#line 2 \"convolution/fast-fourier-transform.hpp\"\
    \n\nnamespace conv {\n\ttemplate<typename T>\n\ttypename enable_if<is_floating_point<T>::value,\
    \ void>::type\n\tfast_fourier_transform(vector<complex<T>> &a) {\n\t\tint n =\
    \ a.size(), logn = 31 - __builtin_clz(n);\n\n\t\tvector<int> rev(n);\n\t\trev[0]\
    \ = 0;\n\t\tfor (int i = 1; i < n; i++) {\n\t\t\trev[i] = (rev[i >> 1] >> 1) +\
    \ ((i & 1) << (logn - 1));\n\t\t\tif (i < rev[i])\n\t\t\t\tswap(a[i], a[rev[i]]);\n\
    \t\t}\n\n\t\tvector<complex<T>> root(n);\n\t\troot[1] = {1, 0};\n\t\tfor (int\
    \ k = 1; k < logn; k++) {\n\t\t\tT the = 2 * PI / (1 << (k + 1));\n\t\t\tcomplex<T>\
    \ z = {cos(the), sin(the)};\n\t\t\tfor (int i = (1 << (k - 1)); i < (1 << k);\
    \ i++) {\n\t\t\t\troot[i << 1] = root[i];\n\t\t\t\troot[i << 1 | 1] = root[i]\
    \ * z;\n\t\t\t}\n\t\t}\n\n\t\tfor (int l = 1; l < n; l <<= 1) {\n\t\t\tfor (int\
    \ i = 0; i < n; i += (l << 1)) {\n\t\t\t\tfor (int j = 0; j < l; j++) {\n\t\t\t\
    \t\tauto z = root[j + l] * a[i + j + l];\n\t\t\t\t\ta[i + j + l] = a[i + j] -\
    \ z;\n\t\t\t\t\ta[i + j] += z;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n}\n#line 2 \"\
    convolution/complex-convolution.hpp\"\n\nnamespace conv {\n\ttemplate<typename\
    \ T, typename U = double>\n\ttypename enable_if<is_floating_point<T>::value, vector<complex<T>>>::type\n\
    \tcomplex_convolution(const vector<complex<T>> &a, const vector<complex<T>> &b)\
    \ {\n\t\tint n = 1;\n\t\twhile (n < a.size() + b.size()) \n\t\t\tn <<= 1;\n\t\t\
    vector<complex<U>> pa(n), pb(n);\n\t\tfor (int i = 0; i < a.size(); i++)\n\t\t\
    \tpa[i] = complex<U>(a[i].real(), a[i].imag());\n\t\tfor (int i = 0; i < b.size();\
    \ i++)\n\t\t\tpb[i] = complex<U>(b[i].real(), b[i].imag());\n\n\t\tfast_fourier_transform(pa);\n\
    \t\tfast_fourier_transform(pb);\n\t\tvector<complex<U>> c(n);\n\t\tfor (int i\
    \ = 0; i < n; i++) \n\t\t\tc[i] = pa[i] * pb[i] / static_cast<U>(n);\n\t\treverse(c.begin()\
    \ + 1, c.end());\n\t\tfast_fourier_transform(c);\n\n\t\tn = a.size() + b.size()\
    \ - 1;\n\t\tvector<complex<T>> ret(n);\n\t\tfor (int i = 0; i < n; i++)\n\t\t\t\
    ret[i] = complex<T>(static_cast<T>(c[i].real()), static_cast<T>(c[i].imag()));\n\
    \t\treturn ret;\n\t}\n}\n#line 7 \"verify/complex-convolution.aizu-string-search.test.cpp\"\
    \n\nconst double EPS = 0.005;\n\nint main() {\n\tstring P, T;\n\tcin >> T >> P;\n\
    \tint n = T.size(), m = P.size();\n\tvector<complex<double>> a(n), b(m);\n\tfor\
    \ (int i = 0; i < n; i++) {\n\t\tchar c = T[i];\n\t\tdouble the = 2 * PI * ('0'\
    \ <= c <= '9' ? c - '0' : c - 'a' + 10) / 36;\n\t\ta[i] = complex<double>(cos(the),\
    \ sin(the));\n\t}\n\tfor (int i = 0; i < m; i++) {\n\t\tchar c = P[m - i - 1];\n\
    \t\tdouble the = 2 * PI * ('0' <= c <= '9' ? c - '0' : c - 'a' + 10) / 36;\n\t\
    \tb[i] = complex<double>(cos(the), -sin(the));\n\t}\n\tauto c = conv::complex_convolution(a,\
    \ b);\n\tfor (int i = 0; i < n; i++)  {\n\t\tif (abs(c[m - 1 + i].real() - m)\
    \ <= EPS && abs(c[m - 1 + i].imag()) <= EPS) {\n\t\t\tcout << i << '\\n';\n\t\t\
    }\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"convolution/complex-convolution.hpp\"\
    \n\nconst double EPS = 0.005;\n\nint main() {\n\tstring P, T;\n\tcin >> T >> P;\n\
    \tint n = T.size(), m = P.size();\n\tvector<complex<double>> a(n), b(m);\n\tfor\
    \ (int i = 0; i < n; i++) {\n\t\tchar c = T[i];\n\t\tdouble the = 2 * PI * ('0'\
    \ <= c <= '9' ? c - '0' : c - 'a' + 10) / 36;\n\t\ta[i] = complex<double>(cos(the),\
    \ sin(the));\n\t}\n\tfor (int i = 0; i < m; i++) {\n\t\tchar c = P[m - i - 1];\n\
    \t\tdouble the = 2 * PI * ('0' <= c <= '9' ? c - '0' : c - 'a' + 10) / 36;\n\t\
    \tb[i] = complex<double>(cos(the), -sin(the));\n\t}\n\tauto c = conv::complex_convolution(a,\
    \ b);\n\tfor (int i = 0; i < n; i++)  {\n\t\tif (abs(c[m - 1 + i].real() - m)\
    \ <= EPS && abs(c[m - 1 + i].imag()) <= EPS) {\n\t\t\tcout << i << '\\n';\n\t\t\
    }\n\t}\n}"
  dependsOn:
  - convolution/complex-convolution.hpp
  - convolution/fast-fourier-transform.hpp
  - utility/pi.hpp
  isVerificationFile: true
  path: verify/complex-convolution.aizu-string-search.test.cpp
  requiredBy: []
  timestamp: '2022-04-16 15:04:12-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/complex-convolution.aizu-string-search.test.cpp
layout: document
redirect_from:
- /verify/verify/complex-convolution.aizu-string-search.test.cpp
- /verify/verify/complex-convolution.aizu-string-search.test.cpp.html
title: verify/complex-convolution.aizu-string-search.test.cpp
---
