---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/ext-gcd.hpp\"\ntemplate<typename T>\nT gcd(T a, T b,\
    \ T &x, T &y) {\n    x = 1, y = 0;\n    int x1 = 0, y1 = 1, a1 = a, b1 = b;\n\
    \    while (b1) {\n        int q = a1 / b1;\n        tie(x, x1) = make_tuple(x1,\
    \ x - q * x1);\n        tie(y, y1) = make_tuple(y1, y - q * y1);\n        tie(a1,\
    \ b1) = make_tuple(b1, a1 - q * b1);\n    }\n    return a1;\n}\n"
  code: "template<typename T>\nT gcd(T a, T b, T &x, T &y) {\n    x = 1, y = 0;\n\
    \    int x1 = 0, y1 = 1, a1 = a, b1 = b;\n    while (b1) {\n        int q = a1\
    \ / b1;\n        tie(x, x1) = make_tuple(x1, x - q * x1);\n        tie(y, y1)\
    \ = make_tuple(y1, y - q * y1);\n        tie(a1, b1) = make_tuple(b1, a1 - q *\
    \ b1);\n    }\n    return a1;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/ext-gcd.hpp
  requiredBy: []
  timestamp: '2022-04-03 13:56:35-07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/ext-gcd.hpp
layout: document
redirect_from:
- /library/math/ext-gcd.hpp
- /library/math/ext-gcd.hpp.html
title: math/ext-gcd.hpp
---
