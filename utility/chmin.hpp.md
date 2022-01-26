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
  bundledCode: "#line 1 \"utility/chmin.hpp\"\ntemplate<typename T>\nbool chmin(T\
    \ &a, T b) {\n\tif (a > b) {\n\t\ta = b;\n\t\treturn true;\n\t}\n\treturn false;\n\
    }\n"
  code: "template<typename T>\nbool chmin(T &a, T b) {\n\tif (a > b) {\n\t\ta = b;\n\
    \t\treturn true;\n\t}\n\treturn false;\n}"
  dependsOn: []
  isVerificationFile: false
  path: utility/chmin.hpp
  requiredBy: []
  timestamp: '2022-01-26 05:57:15-08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/chmin.hpp
layout: document
title: Chmin
---

## Chmin

### Summary

Essentially to a `min=` operator. For some $a$ and $b$, assigns $a = \min(a, b)$. Returns `true` if the assignment is successful, and `false` otherwise. 

### Preconditions

- `T`'s comparison operators are defined

### Parameters
- `T &a`: A reference
- `T b`: A value