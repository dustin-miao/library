---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/convolution.hpp
    title: Convolution
  - icon: ':heavy_check_mark:'
    path: convolution/cyclic-product.hpp
    title: Cyclic Product
  - icon: ':heavy_check_mark:'
    path: convolution/fast-fourier-transform.hpp
    title: Fast Fourier Transform
  - icon: ':heavy_check_mark:'
    path: random/mersenne-twister.hpp
    title: Mersenne Twister
  - icon: ':heavy_check_mark:'
    path: random/random-vector.hpp
    title: Randomized Vector
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/cyclic-product.yosupo-a+b.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n#line 1 \"utility/pi.hpp\"\n#pragma region Pi\n\nconst double\
    \ PI = acos(-1);\n\n#pragma endregion Pi\n#line 2 \"convolution/fast-fourier-transform.hpp\"\
    \n\n#pragma region fast_fourier_transform\n\nnamespace conv {\n\ttemplate<typename\
    \ T>\n\ttypename enable_if<is_floating_point<T>::value, void>::type\n\tfast_fourier_transform(vector<complex<T>>\
    \ &a) {\n\t\tint n = a.size(), logn = 31 - __builtin_clz(n);\n\t\t\n\t\tvector<int>\
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
    }\n\t\t}\n\t}\n}\n\n#pragma endregion fast_fourier_transform\n#line 2 \"convolution/convolution.hpp\"\
    \n\n#pragma region convolution\n\nnamespace conv {\n\ttemplate<typename T, typename\
    \ U = double>\n\tvector<T> convolution(const vector<T> &a, const vector<T> &b)\
    \ {\n\t\tint n = 1;\n\t\twhile (n < a.size() + b.size()) \n\t\t\tn <<= 1;\n\t\t\
    vector<complex<U>> c(n);\n\t\tfor (int i = 0; i < a.size(); i++)\n\t\t\tc[i] =\
    \ static_cast<U>(a[i]);\n\t\tfor (int i = 0; i < b.size(); i++)\n\t\t\tc[i] =\
    \ {c[i].real(), static_cast<U>(b[i])};\n\t\tfast_fourier_transform(c);\n\n\t\t\
    vector<complex<U>> d(n);\n\t\tfor (int i = 0, j; i < n; i++) {\n\t\t\tj = (n -\
    \ i) & (n - 1);\n\t\t\td[i] = (c[j] * c[j] - conj(c[i] * c[i])) * complex<U>{0,\
    \ -0.25 / n};\n\t\t}\n\t\tfast_fourier_transform(d);\n\n\t\tn = a.size() + b.size()\
    \ - 1;\n\t\tvector<T> ret(n);\n\t\tfor (int i = 0; i < n; i++)\n\t\t\tret[i] =\
    \ static_cast<T>(d[i].real() + 0.5);\n\t\treturn ret;\n\t}\n}\n\n#pragma endregion\
    \ convolution\n#line 2 \"convolution/cyclic-product.hpp\"\n\n#pragma region cyclic_product\n\
    \nnamespace conv {\n\ttemplate<typename T, typename U = double>\n\tvector<T> cyclic_product(vector<T>\
    \ a, vector<T> b) {\n\t\tassert(a.size() == b.size());\n\t\tint n = a.size();\n\
    \t\treverse(a.begin(), a.end());\n\t\ta.resize(2 * n);\n\t\tb.insert(b.end(),\
    \ b.begin(), b.end());\n\t\tauto c = convolution<T, U>(a, b);\n\t\tvector<T> ret(n);\n\
    \t\tfor (int i = 0; i < n; i++)\n\t\t\tret[i] = c[i + n - 1];\n\t\treturn ret;\n\
    \t}\n}\n\n#pragma endregion cyclic_product\n#line 1 \"random/mersenne-twister.hpp\"\
    \n#pragma region rng\n\nmt19937 _rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    \ntemplate<typename T = int>\ntypename enable_if<is_integral<T>::value, T>::type\
    \ rng(T l, T r) { return uniform_int_distribution<T>(l, r)(_rng); }\n\n#pragma\
    \ endregion rng\n#line 2 \"random/random-vector.hpp\"\n\n#pragma region rng_vector\n\
    \ntemplate<typename T>\ntypename enable_if<is_integral<T>::value, vector<T>>::type\
    \ rng_vector(int n, T l, T r) {\n\tvector<T> v(n);\n\tfor (auto &a : v)\n\t\t\
    a = rng(l, r);\n\treturn v;\n}\n\n#pragma endregion rng_vector\n#line 8 \"verify/cyclic-product.yosupo-a+b.test.cpp\"\
    \n\nconst int N = 5e4;\n\nint main() { \n\t{\n\t\tvector<long long> A = rng_vector<long\
    \ long>(N, 1, 1e5);\n\t\tvector<long long> B = rng_vector<long long>(N, 1, 1e5);\n\
    \t\tauto C = conv::cyclic_product(A, B);\n\t\tB.insert(B.end(), B.begin(), B.end());\n\
    \t\tfor (int i = 0; i < N; i++) {\n\t\t\tlong long cur = 0;\n\t\t\tfor (int j\
    \ = 0; j < N; j++)\n\t\t\t\tcur += A[j] * B[i + j];\n\t\t\tassert(cur == C[i]);\n\
    \t\t}\n\t}\n\n\tint A, B;\n\tcin >> A >> B;\n\tcout << A + B << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"convolution/cyclic-product.hpp\"\n#include\
    \ \"random/random-vector.hpp\"\n\nconst int N = 5e4;\n\nint main() { \n\t{\n\t\
    \tvector<long long> A = rng_vector<long long>(N, 1, 1e5);\n\t\tvector<long long>\
    \ B = rng_vector<long long>(N, 1, 1e5);\n\t\tauto C = conv::cyclic_product(A,\
    \ B);\n\t\tB.insert(B.end(), B.begin(), B.end());\n\t\tfor (int i = 0; i < N;\
    \ i++) {\n\t\t\tlong long cur = 0;\n\t\t\tfor (int j = 0; j < N; j++)\n\t\t\t\t\
    cur += A[j] * B[i + j];\n\t\t\tassert(cur == C[i]);\n\t\t}\n\t}\n\n\tint A, B;\n\
    \tcin >> A >> B;\n\tcout << A + B << '\\n';\n}"
  dependsOn:
  - convolution/cyclic-product.hpp
  - convolution/convolution.hpp
  - convolution/fast-fourier-transform.hpp
  - utility/pi.hpp
  - random/random-vector.hpp
  - random/mersenne-twister.hpp
  isVerificationFile: true
  path: verify/cyclic-product.yosupo-a+b.test.cpp
  requiredBy: []
  timestamp: '2022-04-30 13:05:31-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/cyclic-product.yosupo-a+b.test.cpp
layout: document
redirect_from:
- /verify/verify/cyclic-product.yosupo-a+b.test.cpp
- /verify/verify/cyclic-product.yosupo-a+b.test.cpp.html
title: verify/cyclic-product.yosupo-a+b.test.cpp
---
