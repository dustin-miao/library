---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/ext-gcd.hpp
    title: Extended GCD
  - icon: ':x:'
    path: random/mersenne_twister.hpp
    title: Mersenne Twister
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_B
  bundledCode: "#line 1 \"verify/ext-gcd.yosupo-a+b.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_B\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"math/ext-gcd.hpp\"\nnamespace\
    \ math {\n\ttemplate<typename T>\n\tT ext_gcd(T a, T b, T &x, T &y) {\n\t\tx =\
    \ 1, y = 0;\n\t\tT x1 = 0, y1 = 1, a1 = a, b1 = b;\n\t\twhile (b1) {\n\t\t\tT\
    \ q = a1 / b1;\n\t\t\ttie(x, x1) = make_tuple(x1, x - q * x1);\n\t\t\ttie(y, y1)\
    \ = make_tuple(y1, y - q * y1);\n\t\t\ttie(a1, b1) = make_tuple(b1, a1 - q * b1);\n\
    \t\t}\n\t\treturn a1;\n\t}\n}\n#line 1 \"random/mersenne_twister.hpp\"\nmt19937\
    \ _rng(chrono::steady_clock::now().time_since_epoch().count());\n\ntemplate<typename\
    \ T = int>\nT rng(T l, T r) { return uniform_int_distribution<T>(l, r)(_rng);\
    \ }\n#line 8 \"verify/ext-gcd.yosupo-a+b.test.cpp\"\n\nint main() {\n\tint T =\
    \ 2e5;\n\twhile (T--) {\n\t\tlong long A = rng<long long>(1, 1e9);\n\t\tlong long\
    \ B = rng<long long>(1, 1e9);\n\t\tlong long X, Y;\n\t\tauto G = math::ext_gcd(A,\
    \ B, X, Y);\n\t\tassert(G == __gcd(A, B));\n\t\tassert(A * X + B * Y == G);\n\t\
    }\n\n\tlong long A, B;\n\tcin >> A >> B;\n\tcout << A + B << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"math/ext-gcd.hpp\"\
    \n#include \"random/mersenne_twister.hpp\"\n\nint main() {\n\tint T = 2e5;\n\t\
    while (T--) {\n\t\tlong long A = rng<long long>(1, 1e9);\n\t\tlong long B = rng<long\
    \ long>(1, 1e9);\n\t\tlong long X, Y;\n\t\tauto G = math::ext_gcd(A, B, X, Y);\n\
    \t\tassert(G == __gcd(A, B));\n\t\tassert(A * X + B * Y == G);\n\t}\n\n\tlong\
    \ long A, B;\n\tcin >> A >> B;\n\tcout << A + B << '\\n';\n}"
  dependsOn:
  - math/ext-gcd.hpp
  - random/mersenne_twister.hpp
  isVerificationFile: true
  path: verify/ext-gcd.yosupo-a+b.test.cpp
  requiredBy: []
  timestamp: '2022-04-19 13:05:12-07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/ext-gcd.yosupo-a+b.test.cpp
layout: document
redirect_from:
- /verify/verify/ext-gcd.yosupo-a+b.test.cpp
- /verify/verify/ext-gcd.yosupo-a+b.test.cpp.html
title: verify/ext-gcd.yosupo-a+b.test.cpp
---
