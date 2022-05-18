---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/z.hpp
    title: Z Function
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"verify/z.yosupo-z-algorithm.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"string/z.hpp\"\n#pragma region str_z\n\n#ifndef\
    \ STR_Z_HPP\n#define STR_Z_HPP\n\nnamespace str {\n\tvector<int> z(const string\
    \ &s) {\n\t\tint n = (int)s.size();\n\t\tvector<int> _z(n);\n\t\tfor (int i =\
    \ 1, l = 0, r = 0; i < n; i++) {\n\t\t\tif (i <= r)\n\t\t\t\t_z[i] = min(_z[i\
    \ - l], r - i + 1);\n\t\t\twhile (i + _z[i] < n && s[_z[i]] == s[i + _z[i]])\n\
    \t\t\t\t_z[i]++;\n\t\t\tif (i + _z[i] - 1 > r)\n\t\t\t\tl = i, r = i + _z[i] -\
    \ 1;\n\t\t}\n\t\treturn _z;\n\t}\n}\n\n#endif\n\n#pragma endregion str_z\n#line\
    \ 7 \"verify/z.yosupo-z-algorithm.test.cpp\"\n\nint main() {\n\tstring S;\n\t\
    cin >> S;\n\tauto z = str::z(S);\n\tz[0] = S.size();\n\tfor (int x : z)\n\t\t\
    cout << x << ' ';\n\tcout << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"string/z.hpp\"\n\nint main()\
    \ {\n\tstring S;\n\tcin >> S;\n\tauto z = str::z(S);\n\tz[0] = S.size();\n\tfor\
    \ (int x : z)\n\t\tcout << x << ' ';\n\tcout << '\\n';\n}"
  dependsOn:
  - string/z.hpp
  isVerificationFile: true
  path: verify/z.yosupo-z-algorithm.test.cpp
  requiredBy: []
  timestamp: '2022-05-18 09:24:47-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/z.yosupo-z-algorithm.test.cpp
layout: document
redirect_from:
- /verify/verify/z.yosupo-z-algorithm.test.cpp
- /verify/verify/z.yosupo-z-algorithm.test.cpp.html
title: verify/z.yosupo-z-algorithm.test.cpp
---
