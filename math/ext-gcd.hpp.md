---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/ext-gcd.aizu-extended-euclid-algorithm.test.cpp
    title: verify/ext-gcd.aizu-extended-euclid-algorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/ext-gcd.hpp\"\nnamespace math {\n\ttemplate<typename\
    \ T>\n\tT ext_gcd(T a, T b, T &x, T &y) {\n\t\tx = 1, y = 0;\n\t\tint x1 = 0,\
    \ y1 = 1, a1 = a, b1 = b;\n\t\twhile (b1) {\n\t\t\tint q = a1 / b1;\n\t\t\ttie(x,\
    \ x1) = make_tuple(x1, x - q * x1);\n\t\t\ttie(y, y1) = make_tuple(y1, y - q *\
    \ y1);\n\t\t\ttie(a1, b1) = make_tuple(b1, a1 - q * b1);\n\t\t}\n\t\treturn a1;\n\
    \t}\n}\n"
  code: "namespace math {\n\ttemplate<typename T>\n\tT ext_gcd(T a, T b, T &x, T &y)\
    \ {\n\t\tx = 1, y = 0;\n\t\tint x1 = 0, y1 = 1, a1 = a, b1 = b;\n\t\twhile (b1)\
    \ {\n\t\t\tint q = a1 / b1;\n\t\t\ttie(x, x1) = make_tuple(x1, x - q * x1);\n\t\
    \t\ttie(y, y1) = make_tuple(y1, y - q * y1);\n\t\t\ttie(a1, b1) = make_tuple(b1,\
    \ a1 - q * b1);\n\t\t}\n\t\treturn a1;\n\t}\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/ext-gcd.hpp
  requiredBy: []
  timestamp: '2022-04-08 16:00:08-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/ext-gcd.aizu-extended-euclid-algorithm.test.cpp
documentation_of: math/ext-gcd.hpp
layout: document
title: Extended GCD
---

## Extended GCD