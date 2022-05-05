---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/prefix-sum.yosupo-static-range-sum.test.cpp
    title: verify/prefix-sum.yosupo-static-range-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utility/prefix-sum.hpp\"\n#pragma region prefix_sum\n\n\
    #ifndef PREFIX_SUM_HPP\n#define PREFIX_SUM_HPP\n\ntemplate<typename T>\nvector<T>\
    \ prefix_sum(vector<T> a) {\n\tint n = a.size();\n\tfor (int i = 1; i < n; i++)\n\
    \t\ta[i] += a[i - 1];\n\treturn a;\n}\n\n#endif\n\n#pragma endregion prefix_sum\n"
  code: "#pragma region prefix_sum\n\n#ifndef PREFIX_SUM_HPP\n#define PREFIX_SUM_HPP\n\
    \ntemplate<typename T>\nvector<T> prefix_sum(vector<T> a) {\n\tint n = a.size();\n\
    \tfor (int i = 1; i < n; i++)\n\t\ta[i] += a[i - 1];\n\treturn a;\n}\n\n#endif\n\
    \n#pragma endregion prefix_sum"
  dependsOn: []
  isVerificationFile: false
  path: utility/prefix-sum.hpp
  requiredBy: []
  timestamp: '2022-05-03 15:18:46-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/prefix-sum.yosupo-static-range-sum.test.cpp
documentation_of: utility/prefix-sum.hpp
layout: document
title: Prefix Sum
---

## Prefix Sum