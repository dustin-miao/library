---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/pi.hpp
    title: Pi Function
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
  bundledCode: "#line 1 \"verify/pi.aizu-string-search.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"string/pi.hpp\"\n\
    #pragma region str_pi\n\n#ifndef STR_PI_HPP\n#define STR_PI_HPP\n\nnamespace str\
    \ {\n\tvector<int> pi(const string &s) {\n\t\tint n = (int)s.length();\n\t\tvector<int>\
    \ _pi(n);\n\t\tfor (int i = 1, j; i < n; i++) {\n\t\t\tfor (j = _pi[i - 1]; j\
    \ > 0 && s[j] != s[i]; j = _pi[j - 1]);\n\t\t\tif (s[i] == s[j])\n\t\t\t\tj++;\n\
    \t\t\t_pi[i] = j;\n\t\t}\n\t\treturn _pi;\n\t}\n}\n\n#endif\n\n#pragma endregion\
    \ str_pi\n#line 7 \"verify/pi.aizu-string-search.test.cpp\"\n\nint main() {\n\t\
    string T, P;\n\tcin >> T >> P;\n\tstring S = P + '#' + T;\n\tauto pi = str::pi(S);\n\
    \tfor (int i = 0; i + 2 * P.size() < S.size(); i++)\n\t\tif (pi[i + 2 * P.size()]\
    \ == P.size())\n\t\t\tcout << i << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"string/pi.hpp\"\
    \n\nint main() {\n\tstring T, P;\n\tcin >> T >> P;\n\tstring S = P + '#' + T;\n\
    \tauto pi = str::pi(S);\n\tfor (int i = 0; i + 2 * P.size() < S.size(); i++)\n\
    \t\tif (pi[i + 2 * P.size()] == P.size())\n\t\t\tcout << i << '\\n';\n}"
  dependsOn:
  - string/pi.hpp
  isVerificationFile: true
  path: verify/pi.aizu-string-search.test.cpp
  requiredBy: []
  timestamp: '2022-05-18 11:50:13-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/pi.aizu-string-search.test.cpp
layout: document
redirect_from:
- /verify/verify/pi.aizu-string-search.test.cpp
- /verify/verify/pi.aizu-string-search.test.cpp.html
title: verify/pi.aizu-string-search.test.cpp
---
