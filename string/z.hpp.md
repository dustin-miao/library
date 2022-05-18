---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/z.aizu-string-search.test.cpp
    title: verify/z.aizu-string-search.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/z.yosupo-z-algorithm.test.cpp
    title: verify/z.yosupo-z-algorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/z.hpp\"\n#pragma region str_z\n\n#ifndef STR_Z_HPP\n\
    #define STR_Z_HPP\n\nnamespace str {\n\tvector<int> z(const string &s) {\n\t\t\
    int n = (int)s.size();\n\t\tvector<int> _z(n);\n\t\tfor (int i = 1, l = 0, r =\
    \ 0; i < n; i++) {\n\t\t\tif (i <= r)\n\t\t\t\t_z[i] = min(_z[i - l], r - i +\
    \ 1);\n\t\t\twhile (i + _z[i] < n && s[_z[i]] == s[i + _z[i]])\n\t\t\t\t_z[i]++;\n\
    \t\t\tif (i + _z[i] - 1 > r)\n\t\t\t\tl = i, r = i + _z[i] - 1;\n\t\t}\n\t\treturn\
    \ _z;\n\t}\n}\n\n#endif\n\n#pragma endregion str_z\n"
  code: "#pragma region str_z\n\n#ifndef STR_Z_HPP\n#define STR_Z_HPP\n\nnamespace\
    \ str {\n\tvector<int> z(const string &s) {\n\t\tint n = (int)s.size();\n\t\t\
    vector<int> _z(n);\n\t\tfor (int i = 1, l = 0, r = 0; i < n; i++) {\n\t\t\tif\
    \ (i <= r)\n\t\t\t\t_z[i] = min(_z[i - l], r - i + 1);\n\t\t\twhile (i + _z[i]\
    \ < n && s[_z[i]] == s[i + _z[i]])\n\t\t\t\t_z[i]++;\n\t\t\tif (i + _z[i] - 1\
    \ > r)\n\t\t\t\tl = i, r = i + _z[i] - 1;\n\t\t}\n\t\treturn _z;\n\t}\n}\n\n#endif\n\
    \n#pragma endregion str_z"
  dependsOn: []
  isVerificationFile: false
  path: string/z.hpp
  requiredBy: []
  timestamp: '2022-05-18 09:19:50-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/z.yosupo-z-algorithm.test.cpp
  - verify/z.aizu-string-search.test.cpp
documentation_of: string/z.hpp
layout: document
title: Z Function
---

## Z Function