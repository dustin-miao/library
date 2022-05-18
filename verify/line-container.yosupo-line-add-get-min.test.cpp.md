---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/line-container.hpp
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
    #pragma region floor_div\n\n#ifndef FLOOR_DIV_HPP\n#define FLOOR_DIV_HPP\n\ntemplate<typename\
    \ T>\nT floor_div(T a, T b) { \n\treturn a / b - ((a ^ b) < 0 && a % b); \n}\n\
    \n#endif\n\n#pragma endregion floor_div\n#line 2 \"geometry/line-container.hpp\"\
    \n\n#pragma region line_container\n\n#ifndef LINE_CONTAINER_HPP\n#define LINE_CONTAINER_HPP\n\
    \nstruct line_container_line {\n    mutable long long m, b, p;\n    bool operator<(const\
    \ line_container_line &o) const { return m < o.m; }\n    bool operator<(long long\
    \ x) const { return p < x; }\n};\n\nclass line_container : multiset<line_container_line,\
    \ less<>> {\n    bool isect(iterator x, iterator y) {\n        if (y == end())\
    \ {\n\t\t\tx->p = LLONG_MAX;\n\t\t\treturn false;\n\t\t}\n        if (x->m ==\
    \ y->m)\n            x->p = x->b > y->b ? LLONG_MAX : LLONG_MIN;\n        else\n\
    \            x->p = floor_div(y->b - x->b, x->m - y->m);\n        return x->p\
    \ >= y->p;\n    }\n\npublic:\n    void add(long long m, long long b) {\n     \
    \   auto z = insert({m, b, 0}), y = z++, x = y;\n        while (isect(y, z)) \n\
    \            z = erase(z);\n        if (x != begin() && isect(--x, y)) \n    \
    \        isect(x, y = erase(y));\n        while ((y = x) != begin() && (--x)->p\
    \ >= y->p) \n            isect(x, erase(y));\n    }\n\n    long long query(long\
    \ long x) {\n        assert(!empty());\n        auto l = *lower_bound(x);\n  \
    \      return l.m * x + l.b;\n    }\n};\n\n#endif\n\n#pragma endregion line_container\n\
    #line 7 \"verify/line-container.yosupo-line-add-get-min.test.cpp\"\n\nint main()\
    \ {\n\tint N, Q;\n\tcin >> N >> Q;\n\tline_container lc;\n\tfor (int i = 0; i\
    \ < N; i++) {\n\t\tlong long m, b;\n\t\tcin >> m >> b;\n\t\tlc.add(-m, -b);\n\t\
    }\n\twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\tlong long m,\
    \ b;\n\t\t\tcin >> m >> b;\n\t\t\tlc.add(-m, -b);\n\t\t} else if (t == 1) {\n\t\
    \t\tlong long x;\n\t\t\tcin >> x;\n\t\t\tcout << -lc.query(x) << '\\n';\n\t\t\
    }\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"geometry/line-container.hpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\tline_container lc;\n\tfor (int\
    \ i = 0; i < N; i++) {\n\t\tlong long m, b;\n\t\tcin >> m >> b;\n\t\tlc.add(-m,\
    \ -b);\n\t}\n\twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\t\
    long long m, b;\n\t\t\tcin >> m >> b;\n\t\t\tlc.add(-m, -b);\n\t\t} else if (t\
    \ == 1) {\n\t\t\tlong long x;\n\t\t\tcin >> x;\n\t\t\tcout << -lc.query(x) <<\
    \ '\\n';\n\t\t}\n\t}\n}"
  dependsOn:
  - geometry/line-container.hpp
  - utility/floor-div.hpp
  isVerificationFile: true
  path: verify/line-container.yosupo-line-add-get-min.test.cpp
  requiredBy: []
  timestamp: '2022-05-05 15:11:34-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/line-container.yosupo-line-add-get-min.test.cpp
layout: document
redirect_from:
- /verify/verify/line-container.yosupo-line-add-get-min.test.cpp
- /verify/verify/line-container.yosupo-line-add-get-min.test.cpp.html
title: verify/line-container.yosupo-line-add-get-min.test.cpp
---
