---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/pi.aizu-string-search.test.cpp
    title: verify/pi.aizu-string-search.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/pi.hpp\"\n#pragma region str_pi\n\n#ifndef STR_PI_HPP\n\
    #define STR_PI_HPP\n\nnamespace str {\n\tvector<int> pi(const string &s) {\n\t\
    \tint n = (int)s.length();\n\t\tvector<int> _pi(n);\n\t\tfor (int i = 1, j; i\
    \ < n; i++) {\n\t\t\tfor (j = _pi[i - 1]; j > 0 && s[j] != s[i]; j = _pi[j - 1]);\n\
    \t\t\tif (s[i] == s[j])\n\t\t\t\tj++;\n\t\t\t_pi[i] = j;\n\t\t}\n\t\treturn _pi;\n\
    \t}\n}\n\n#endif\n\n#pragma endregion str_pi\n"
  code: "#pragma region str_pi\n\n#ifndef STR_PI_HPP\n#define STR_PI_HPP\n\nnamespace\
    \ str {\n\tvector<int> pi(const string &s) {\n\t\tint n = (int)s.length();\n\t\
    \tvector<int> _pi(n);\n\t\tfor (int i = 1, j; i < n; i++) {\n\t\t\tfor (j = _pi[i\
    \ - 1]; j > 0 && s[j] != s[i]; j = _pi[j - 1]);\n\t\t\tif (s[i] == s[j])\n\t\t\
    \t\tj++;\n\t\t\t_pi[i] = j;\n\t\t}\n\t\treturn _pi;\n\t}\n}\n\n#endif\n\n#pragma\
    \ endregion str_pi"
  dependsOn: []
  isVerificationFile: false
  path: string/pi.hpp
  requiredBy: []
  timestamp: '2022-05-18 09:19:50-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/pi.aizu-string-search.test.cpp
documentation_of: string/pi.hpp
layout: document
title: Pi Function
---

## Pi Function