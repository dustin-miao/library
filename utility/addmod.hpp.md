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
  bundledCode: "#line 1 \"utility/addmod.hpp\"\ntemplate<typename T>\nT addmod(T a,\
    \ T b, long long MOD) {\n\tT t = a + b;\n\treturn t >= MOD ? t - MOD : t;\n}\n"
  code: "template<typename T>\nT addmod(T a, T b, long long MOD) {\n\tT t = a + b;\n\
    \treturn t >= MOD ? t - MOD : t;\n}"
  dependsOn: []
  isVerificationFile: false
  path: utility/addmod.hpp
  requiredBy: []
  timestamp: '2022-02-04 21:19:28-08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/addmod.hpp
layout: document
title: Addmod
---

## Addmod