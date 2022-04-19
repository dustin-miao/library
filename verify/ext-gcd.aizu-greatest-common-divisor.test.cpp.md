---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/ext-gcd.hpp
    title: Extended GCD
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_B
  bundledCode: "#line 1 \"verify/ext-gcd.aizu-greatest-common-divisor.test.cpp\"\n\
    #define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"math/ext-gcd.hpp\"\
    \nnamespace math {\n\ttemplate<typename T>\n\tT ext_gcd(T a, T b, T &x, T &y)\
    \ {\n\t\tx = 1, y = 0;\n\t\tT x1 = 0, y1 = 1, a1 = a, b1 = b;\n\t\twhile (b1)\
    \ {\n\t\t\tT q = a1 / b1;\n\t\t\ttie(x, x1) = make_tuple(x1, x - q * x1);\n\t\t\
    \ttie(y, y1) = make_tuple(y1, y - q * y1);\n\t\t\ttie(a1, b1) = make_tuple(b1,\
    \ a1 - q * b1);\n\t\t}\n\t\treturn a1;\n\t}\n}\n#line 7 \"verify/ext-gcd.aizu-greatest-common-divisor.test.cpp\"\
    \n\nint main() {\n\tlong long A, B, X, Y;\n\tcin >> A >> B;\n\tcout << math::ext_gcd(A,\
    \ B, X, Y) << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"math/ext-gcd.hpp\"\
    \n\nint main() {\n\tlong long A, B, X, Y;\n\tcin >> A >> B;\n\tcout << math::ext_gcd(A,\
    \ B, X, Y) << '\\n';\n}"
  dependsOn:
  - math/ext-gcd.hpp
  isVerificationFile: true
  path: verify/ext-gcd.aizu-greatest-common-divisor.test.cpp
  requiredBy: []
  timestamp: '2022-04-19 13:04:18-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/ext-gcd.aizu-greatest-common-divisor.test.cpp
layout: document
redirect_from:
- /verify/verify/ext-gcd.aizu-greatest-common-divisor.test.cpp
- /verify/verify/ext-gcd.aizu-greatest-common-divisor.test.cpp.html
title: verify/ext-gcd.aizu-greatest-common-divisor.test.cpp
---
