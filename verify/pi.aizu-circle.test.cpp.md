---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: utility/pi.hpp
    title: Pi
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_4_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_4_B
  bundledCode: "#line 1 \"verify/pi.aizu-circle.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_4_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"utility/pi.hpp\"\
    \n#pragma region Pi\n\nconst double PI = acos(-1);\n\n#pragma endregion Pi\n#line\
    \ 7 \"verify/pi.aizu-circle.test.cpp\"\n\nint main() {\n\tlong double r;\n\tcin\
    \ >> r;\n\tcout << fixed << setprecision(10) << PI * r * r << ' ' << 2 * PI *\
    \ r << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_4_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"utility/pi.hpp\"\
    \n\nint main() {\n\tlong double r;\n\tcin >> r;\n\tcout << fixed << setprecision(10)\
    \ << PI * r * r << ' ' << 2 * PI * r << '\\n';\n}"
  dependsOn:
  - utility/pi.hpp
  isVerificationFile: true
  path: verify/pi.aizu-circle.test.cpp
  requiredBy: []
  timestamp: '2022-04-30 13:13:46-07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/pi.aizu-circle.test.cpp
layout: document
redirect_from:
- /verify/verify/pi.aizu-circle.test.cpp
- /verify/verify/pi.aizu-circle.test.cpp.html
title: verify/pi.aizu-circle.test.cpp
---
