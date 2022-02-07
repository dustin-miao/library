---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/line-container.hpp
    title: Line Container
  - icon: ':heavy_check_mark:'
    path: utility/floor-div.hpp
    title: Floor Division
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"verify/line-container.yosupo-line-add-get-min.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"utility/floor-div.hpp\"\n\
    template<typename T>\nT floor_div(T a, T b) { \n\treturn a / b - ((a ^ b) < 0\
    \ && a % b); \n}\n#line 2 \"data-structure/line-container.hpp\"\n\nbool __LINE_COMPARE__;\n\
    \nstruct Line {\n\tmutable long long m, b, p;\n\tbool operator<(const Line &l)\
    \ const { return __LINE_COMPARE__ ? p < l.p : m < l.m; }\n};\n\nclass LineContainer\
    \ : multiset<Line> {\n\tbool intersect(iterator x, iterator y) {\n\t\tif (y ==\
    \ end()) { \n\t\t\tx->p = LLONG_MAX; \n\t\t\treturn false; \n\t\t}\n\t\tif (x->m\
    \ == y->m) \n\t\t\tx->p = x->b > y->b ? LLONG_MAX : LLONG_MIN;\n\t\telse \n\t\t\
    \tx->p = floor_div(y->b - x->b, x->m - y->m);\n\t\treturn x->p >= y->p;\n\t}\n\
    \npublic:\n\tvoid add(long long m, long long b) {\n\t\tauto z = insert({m, b,\
    \ 0}), y = z++, x = y;\n\t\twhile (intersect(y, z)) \n\t\t\tz = erase(z);\n\t\t\
    if (x != begin() && intersect(--x, y)) \n\t\t\tintersect(x, y = erase(y));\n\t\
    \twhile ((y = x) != begin() && (--x)->p >= y->p)\n\t\t\tintersect(x, erase(y));\n\
    \t}\n\t\n\tlong long query(long long x) {\n\t\tassert(!empty());\n\t\t__LINE_COMPARE__\
    \ = true; \n\t\tauto l = *lower_bound({0, 0, x}); \n\t\t__LINE_COMPARE__ = false;\n\
    \t\treturn l.m * x + l.b;\n\t}\n};\n#line 7 \"verify/line-container.yosupo-line-add-get-min.test.cpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\tLineContainer lc;\n\tfor (int\
    \ i = 0; i < N; i++) {\n\t\tlong long m, b;\n\t\tcin >> m >> b;\n\t\tlc.add(-m,\
    \ -b);\n\t}\n\twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\t\
    long long m, b;\n\t\t\tcin >> m >> b;\n\t\t\tlc.add(-m, -b);\n\t\t} else if (t\
    \ == 1) {\n\t\t\tlong long x;\n\t\t\tcin >> x;\n\t\t\tcout << -lc.query(x) <<\
    \ '\\n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/line-container.hpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\tLineContainer lc;\n\tfor (int\
    \ i = 0; i < N; i++) {\n\t\tlong long m, b;\n\t\tcin >> m >> b;\n\t\tlc.add(-m,\
    \ -b);\n\t}\n\twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\t\
    long long m, b;\n\t\t\tcin >> m >> b;\n\t\t\tlc.add(-m, -b);\n\t\t} else if (t\
    \ == 1) {\n\t\t\tlong long x;\n\t\t\tcin >> x;\n\t\t\tcout << -lc.query(x) <<\
    \ '\\n';\n\t\t}\n\t}\n}"
  dependsOn:
  - data-structure/line-container.hpp
  - utility/floor-div.hpp
  isVerificationFile: true
  path: verify/line-container.yosupo-line-add-get-min.test.cpp
  requiredBy: []
  timestamp: '2022-02-06 21:17:29-08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/line-container.yosupo-line-add-get-min.test.cpp
layout: document
redirect_from:
- /verify/verify/line-container.yosupo-line-add-get-min.test.cpp
- /verify/verify/line-container.yosupo-line-add-get-min.test.cpp.html
title: verify/line-container.yosupo-line-add-get-min.test.cpp
---
