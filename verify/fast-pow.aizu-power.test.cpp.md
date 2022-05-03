---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/fast-pow.hpp
    title: Binary Exponentiation
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
  bundledCode: "#line 1 \"verify/fast-pow.aizu-power.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"utility/fast-pow.hpp\"\n\
    #pragma region fast_pow\n\n#ifndef FAST_POW_HPP\n#define FAST_POW_HPP\n\ntemplate<typename\
    \ T, typename U>\nT fast_pow(T a, U b) { \n\tT ret = 1; \n\tfor (; b; b /= 2)\
    \ { \n\t\tif (b & 1) \n\t\t\tret = ret * a; \n\t\ta = a * a; \n\t} \n\treturn\
    \ ret; \n}\n\ntemplate<typename T, typename U, typename S>\nT fast_pow(T a, U\
    \ b, const S &mod) { \n\tT ret = 1; \n\tfor (a % mod; b; b /= 2) { \n\t\tif (b\
    \ & 1) \n\t\t\tret = ret * a % mod; \n\t\ta = a * a % mod; \n\t} \n\treturn ret;\
    \ \n}\n\n#endif\n\n#pragma endregion fast_pow\n#line 7 \"verify/fast-pow.aizu-power.test.cpp\"\
    \n\nconst long long MOD = 1e9 + 7;\n\nint main() {\n\tlong long M, N;\n\tcin >>\
    \ M >> N;\n\tcout << fast_pow(M, N, MOD) << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"utility/fast-pow.hpp\"\
    \n\nconst long long MOD = 1e9 + 7;\n\nint main() {\n\tlong long M, N;\n\tcin >>\
    \ M >> N;\n\tcout << fast_pow(M, N, MOD) << '\\n';\n}"
  dependsOn:
  - utility/fast-pow.hpp
  isVerificationFile: true
  path: verify/fast-pow.aizu-power.test.cpp
  requiredBy: []
  timestamp: '2022-05-03 13:27:25-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/fast-pow.aizu-power.test.cpp
layout: document
redirect_from:
- /verify/verify/fast-pow.aizu-power.test.cpp
- /verify/verify/fast-pow.aizu-power.test.cpp.html
title: verify/fast-pow.aizu-power.test.cpp
---
