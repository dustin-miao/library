---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/y-combinator.hpp
    title: Y-Combinator
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
  bundledCode: "#line 1 \"verify/y-combinator.aizu-greatest-common-denominator.test.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"utility/y-combinator.hpp\"\
    \nnamespace std {\n\t// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html\n\
    \ttemplate<class Fun>\n\tclass y_combinator_result {\n\t\tFun fun_;\n\tpublic:\n\
    \t\ttemplate<class T>\n\t\texplicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun))\
    \ {}\n\n\t\ttemplate<class ...Args>\n\t\tdecltype(auto) operator()(Args &&...args)\
    \ {\n\t\t\treturn fun_(std::ref(*this), std::forward<Args>(args)...);\n\t\t}\n\
    \t};\n\n\ttemplate<class Fun>\n\tdecltype(auto) y_combinator(Fun &&fun) {\n\t\t\
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));\n\t}\n\
    }\n#line 7 \"verify/y-combinator.aizu-greatest-common-denominator.test.cpp\"\n\
    \nint main() {\n\tlong long A, B;\n\tcin >> A >> B;\n\n\tauto gcd_test = y_combinator([](auto\
    \ gcd_test, long long a, long long b) -> long long { \n\t\treturn b == 0 ? a :\
    \ gcd_test(b, a % b); \n\t});\n\t\n\tcout << gcd_test(A, B) << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"utility/y-combinator.hpp\"\
    \n\nint main() {\n\tlong long A, B;\n\tcin >> A >> B;\n\n\tauto gcd_test = y_combinator([](auto\
    \ gcd_test, long long a, long long b) -> long long { \n\t\treturn b == 0 ? a :\
    \ gcd_test(b, a % b); \n\t});\n\t\n\tcout << gcd_test(A, B) << endl;\n}"
  dependsOn:
  - utility/y-combinator.hpp
  isVerificationFile: true
  path: verify/y-combinator.aizu-greatest-common-denominator.test.cpp
  requiredBy: []
  timestamp: '2022-04-19 13:38:39-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/y-combinator.aizu-greatest-common-denominator.test.cpp
layout: document
redirect_from:
- /verify/verify/y-combinator.aizu-greatest-common-denominator.test.cpp
- /verify/verify/y-combinator.aizu-greatest-common-denominator.test.cpp.html
title: verify/y-combinator.aizu-greatest-common-denominator.test.cpp
---
