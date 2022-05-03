---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/chmax.hpp
    title: Chmax
  - icon: ':heavy_check_mark:'
    path: utility/chmin.hpp
    title: Chmin
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_4_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_4_D
  bundledCode: "#line 1 \"verify/chmin.aizu-min-max-sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_4_D\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"utility/chmax.hpp\"\n#pragma\
    \ region chmax\n\n#ifndef CHMAX_HPP\n#define CHMAX_HPP\n\ntemplate<typename T>\n\
    bool chmax(T &a, T b) {\n\tif (a < b) {\n\t\ta = b;\n\t\treturn true;\n\t}\n\t\
    return false;\n}\n\n#endif\n\n#pragma endregion chmax\n#line 1 \"utility/chmin.hpp\"\
    \n#pragma region chmin\n\n#ifndef CHMIN_HPP\n#define CHMIN_HPP\n\ntemplate<typename\
    \ T>\nbool chmin(T &a, T b) {\n\tif (a > b) {\n\t\ta = b;\n\t\treturn true;\n\t\
    }\n\treturn false;\n}\n\n#endif\n\n#pragma endregion chmin\n#line 8 \"verify/chmin.aizu-min-max-sum.test.cpp\"\
    \n\nint main() {\n\tint N;\n\tcin >> N;\n\tlong long mn = LLONG_MAX, mx = LLONG_MIN,\
    \ sum = 0;\n\tfor (int i = 0; i < N; i++) {\n\t\tlong long a;\n\t\tcin >> a;\n\
    \t\tchmin(mn, a);\n\t\tchmax(mx, a);\n\t\tsum += a;\n\t}\n\tcout << mn << ' '\
    \ << mx << ' ' << sum << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_4_D\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"utility/chmax.hpp\"\
    \n#include \"utility/chmin.hpp\"\n\nint main() {\n\tint N;\n\tcin >> N;\n\tlong\
    \ long mn = LLONG_MAX, mx = LLONG_MIN, sum = 0;\n\tfor (int i = 0; i < N; i++)\
    \ {\n\t\tlong long a;\n\t\tcin >> a;\n\t\tchmin(mn, a);\n\t\tchmax(mx, a);\n\t\
    \tsum += a;\n\t}\n\tcout << mn << ' ' << mx << ' ' << sum << '\\n';\n}"
  dependsOn:
  - utility/chmax.hpp
  - utility/chmin.hpp
  isVerificationFile: true
  path: verify/chmin.aizu-min-max-sum.test.cpp
  requiredBy: []
  timestamp: '2022-05-03 13:27:25-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/chmin.aizu-min-max-sum.test.cpp
layout: document
redirect_from:
- /verify/verify/chmin.aizu-min-max-sum.test.cpp
- /verify/verify/chmin.aizu-min-max-sum.test.cpp.html
title: verify/chmin.aizu-min-max-sum.test.cpp
---
