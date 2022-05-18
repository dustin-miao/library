---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: utility/floor-div.hpp
    title: Floor Division
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/many_aplusb
    links:
    - https://judge.yosupo.jp/problem/many_aplusb
  bundledCode: "#line 1 \"verify/floor-div.yosupo-many-a+b.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/many_aplusb\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"utility/floor-div.hpp\"\n#pragma region floor_div\n\
    \n#ifndef FLOOR_DIV_HPP\n#define FLOOR_DIV_HPP\n\ntemplate<typename T>\nT floor_div(T\
    \ a, T b) { \n\treturn a / b - ((a ^ b) < 0 && a % b); \n}\n\n#endif\n\n#pragma\
    \ endregion floor_div\n#line 7 \"verify/floor-div.yosupo-many-a+b.test.cpp\"\n\
    \nint main() {\n\tint TC;\n\tcin >> TC;\n\twhile (TC--) {\n\t\tlong long a, b;\n\
    \t\tcin >> a >> b;\n\t\tcout << a + b << '\\n';\n\t\tassert(b == 0 || floor_div(a,\
    \ b) == a / b);\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"utility/floor-div.hpp\"\n\
    \nint main() {\n\tint TC;\n\tcin >> TC;\n\twhile (TC--) {\n\t\tlong long a, b;\n\
    \t\tcin >> a >> b;\n\t\tcout << a + b << '\\n';\n\t\tassert(b == 0 || floor_div(a,\
    \ b) == a / b);\n\t}\n}"
  dependsOn:
  - utility/floor-div.hpp
  isVerificationFile: true
  path: verify/floor-div.yosupo-many-a+b.test.cpp
  requiredBy: []
  timestamp: '2022-05-03 13:27:25-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/floor-div.yosupo-many-a+b.test.cpp
layout: document
redirect_from:
- /verify/verify/floor-div.yosupo-many-a+b.test.cpp
- /verify/verify/floor-div.yosupo-many-a+b.test.cpp.html
title: verify/floor-div.yosupo-many-a+b.test.cpp
---
