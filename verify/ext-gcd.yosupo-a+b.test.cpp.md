---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/ext-gcd.hpp
    title: Extended GCD
  - icon: ':heavy_check_mark:'
    path: random/mersenne-twister.hpp
    title: Mersenne Twister
  - icon: ':heavy_check_mark:'
    path: random/random-int.hpp
    title: Random Integer
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/ext-gcd.yosupo-a+b.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#line 1 \"math/ext-gcd.hpp\"\n#pragma region extended_gcd\n\nnamespace\
    \ math {\n\ttemplate<typename T>\n\tT ext_gcd(T a, T b, T &x, T &y) {\n\t\tx =\
    \ 1, y = 0;\n\t\tT x1 = 0, y1 = 1, a1 = a, b1 = b;\n\t\twhile (b1) {\n\t\t\tT\
    \ q = a1 / b1;\n\t\t\ttie(x, x1) = make_tuple(x1, x - q * x1);\n\t\t\ttie(y, y1)\
    \ = make_tuple(y1, y - q * y1);\n\t\t\ttie(a1, b1) = make_tuple(b1, a1 - q * b1);\n\
    \t\t}\n\t\treturn a1;\n\t}\n}\n\n#pragma endregion extended_gcd\n#line 1 \"random/mersenne-twister.hpp\"\
    \n#pragma region mersenne_twister\n\n#ifndef MERSENNE_TWISTER_HPP\n#define MERSENNE_TWISTER_HPP\n\
    \nnamespace rng {\n\tmt19937 mst(chrono::steady_clock::now().time_since_epoch().count());\n\
    }\n\n#endif\n\n#pragma endregion mersenne_twister\n#line 2 \"random/random-int.hpp\"\
    \n\n#pragma region rng_int\n\n#ifndef RANDOM_INT_HPP\n#define RANDOM_INT_HPP\n\
    \nnamespace rng {\n\ttemplate<typename T = int>\n\ttypename enable_if<is_integral<T>::value,\
    \ T>::type \n\trint(T l, T r) { return uniform_int_distribution<T>(l, r)(mst);\
    \ }\n}\n\n#endif\n\n#pragma endregion rng_int\n#line 8 \"verify/ext-gcd.yosupo-a+b.test.cpp\"\
    \n\nint main() {\n\t{\n\t\tint T = 2e5;\n\t\twhile (T--) {\n\t\t\tlong long A\
    \ = rng::rint<long long>(1, 1e6);\n\t\t\tlong long B = rng::rint<long long>(1,\
    \ 1e6);\n\t\t\tlong long X, Y;\n\t\t\tauto G = math::ext_gcd(A, B, X, Y);\n\t\t\
    \tassert(G == __gcd(A, B));\n\t\t\tassert(A * X + B * Y == G);\n\t\t}\n\t}\n\n\
    \tlong long A, B;\n\tcin >> A >> B;\n\tcout << A + B << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"math/ext-gcd.hpp\"\n#include \"random/random-int.hpp\"\
    \n\nint main() {\n\t{\n\t\tint T = 2e5;\n\t\twhile (T--) {\n\t\t\tlong long A\
    \ = rng::rint<long long>(1, 1e6);\n\t\t\tlong long B = rng::rint<long long>(1,\
    \ 1e6);\n\t\t\tlong long X, Y;\n\t\t\tauto G = math::ext_gcd(A, B, X, Y);\n\t\t\
    \tassert(G == __gcd(A, B));\n\t\t\tassert(A * X + B * Y == G);\n\t\t}\n\t}\n\n\
    \tlong long A, B;\n\tcin >> A >> B;\n\tcout << A + B << '\\n';\n}"
  dependsOn:
  - math/ext-gcd.hpp
  - random/random-int.hpp
  - random/mersenne-twister.hpp
  isVerificationFile: true
  path: verify/ext-gcd.yosupo-a+b.test.cpp
  requiredBy: []
  timestamp: '2022-05-18 09:15:37-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/ext-gcd.yosupo-a+b.test.cpp
layout: document
redirect_from:
- /verify/verify/ext-gcd.yosupo-a+b.test.cpp
- /verify/verify/ext-gcd.yosupo-a+b.test.cpp.html
title: verify/ext-gcd.yosupo-a+b.test.cpp
---
