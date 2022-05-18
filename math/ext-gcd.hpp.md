---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/crt.hpp
    title: Chinese Remainder Theorem
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/ext-gcd.aizu-extended-euclid-algorithm.test.cpp
    title: verify/ext-gcd.aizu-extended-euclid-algorithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/ext-gcd.aizu-greatest-common-divisor.test.cpp
    title: verify/ext-gcd.aizu-greatest-common-divisor.test.cpp
  - icon: ':x:'
    path: verify/ext-gcd.yosupo-a+b.test.cpp
    title: verify/ext-gcd.yosupo-a+b.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/ext-gcd.hpp\"\n#pragma region extended_gcd\n\nnamespace\
    \ math {\n\ttemplate<typename T>\n\tT ext_gcd(T a, T b, T &x, T &y) {\n\t\tx =\
    \ 1, y = 0;\n\t\tT x1 = 0, y1 = 1, a1 = a, b1 = b;\n\t\twhile (b1) {\n\t\t\tT\
    \ q = a1 / b1;\n\t\t\ttie(x, x1) = make_tuple(x1, x - q * x1);\n\t\t\ttie(y, y1)\
    \ = make_tuple(y1, y - q * y1);\n\t\t\ttie(a1, b1) = make_tuple(b1, a1 - q * b1);\n\
    \t\t}\n\t\treturn a1;\n\t}\n}\n\n#pragma endregion extended_gcd\n"
  code: "#pragma region extended_gcd\n\nnamespace math {\n\ttemplate<typename T>\n\
    \tT ext_gcd(T a, T b, T &x, T &y) {\n\t\tx = 1, y = 0;\n\t\tT x1 = 0, y1 = 1,\
    \ a1 = a, b1 = b;\n\t\twhile (b1) {\n\t\t\tT q = a1 / b1;\n\t\t\ttie(x, x1) =\
    \ make_tuple(x1, x - q * x1);\n\t\t\ttie(y, y1) = make_tuple(y1, y - q * y1);\n\
    \t\t\ttie(a1, b1) = make_tuple(b1, a1 - q * b1);\n\t\t}\n\t\treturn a1;\n\t}\n\
    }\n\n#pragma endregion extended_gcd"
  dependsOn: []
  isVerificationFile: false
  path: math/ext-gcd.hpp
  requiredBy:
  - math/crt.hpp
  timestamp: '2022-04-29 22:36:50-07:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/ext-gcd.aizu-extended-euclid-algorithm.test.cpp
  - verify/ext-gcd.yosupo-a+b.test.cpp
  - verify/ext-gcd.aizu-greatest-common-divisor.test.cpp
documentation_of: math/ext-gcd.hpp
layout: document
title: Extended GCD
---

## Extended GCD