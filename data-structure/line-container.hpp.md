---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/floor-div.hpp
    title: Floor Division
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/line-container.yosupo-line-add-get-min.test.cpp
    title: verify/line-container.yosupo-line-add-get-min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utility/floor-div.hpp\"\ntemplate<typename T>\nT floor_div(T\
    \ a, T b) { \n\treturn a / b - ((a ^ b) < 0 && a % b); \n}\n#line 2 \"data-structure/line-container.hpp\"\
    \n\nbool __LINE_COMPARE__;\n\nstruct Line {\n\tmutable long long m, b, p;\n\t\
    bool operator<(const Line &l) const { return __LINE_COMPARE__ ? p < l.p : m <\
    \ l.m; }\n};\n\nclass LineContainer : multiset<Line> {\n\tbool intersect(iterator\
    \ x, iterator y) {\n\t\tif (y == end()) { \n\t\t\tx->p = LLONG_MAX; \n\t\t\treturn\
    \ false; \n\t\t}\n\t\tif (x->m == y->m) \n\t\t\tx->p = x->b > y->b ? LLONG_MAX\
    \ : LLONG_MIN;\n\t\telse \n\t\t\tx->p = floor_div(y->b - x->b, x->m - y->m);\n\
    \t\treturn x->p >= y->p;\n\t}\n\npublic:\n\tvoid add(long long m, long long b)\
    \ {\n\t\tauto z = insert({m, b, 0}), y = z++, x = y;\n\t\twhile (intersect(y,\
    \ z)) \n\t\t\tz = erase(z);\n\t\tif (x != begin() && intersect(--x, y)) \n\t\t\
    \tintersect(x, y = erase(y));\n\t\twhile ((y = x) != begin() && (--x)->p >= y->p)\n\
    \t\t\tintersect(x, erase(y));\n\t}\n\t\n\tlong long query(long long x) {\n\t\t\
    assert(!empty());\n\t\t__LINE_COMPARE__ = true; \n\t\tauto l = *lower_bound({0,\
    \ 0, x}); \n\t\t__LINE_COMPARE__ = false;\n\t\treturn l.m * x + l.b;\n\t}\n};\n"
  code: "#include \"utility/floor-div.hpp\"\n\nbool __LINE_COMPARE__;\n\nstruct Line\
    \ {\n\tmutable long long m, b, p;\n\tbool operator<(const Line &l) const { return\
    \ __LINE_COMPARE__ ? p < l.p : m < l.m; }\n};\n\nclass LineContainer : multiset<Line>\
    \ {\n\tbool intersect(iterator x, iterator y) {\n\t\tif (y == end()) { \n\t\t\t\
    x->p = LLONG_MAX; \n\t\t\treturn false; \n\t\t}\n\t\tif (x->m == y->m) \n\t\t\t\
    x->p = x->b > y->b ? LLONG_MAX : LLONG_MIN;\n\t\telse \n\t\t\tx->p = floor_div(y->b\
    \ - x->b, x->m - y->m);\n\t\treturn x->p >= y->p;\n\t}\n\npublic:\n\tvoid add(long\
    \ long m, long long b) {\n\t\tauto z = insert({m, b, 0}), y = z++, x = y;\n\t\t\
    while (intersect(y, z)) \n\t\t\tz = erase(z);\n\t\tif (x != begin() && intersect(--x,\
    \ y)) \n\t\t\tintersect(x, y = erase(y));\n\t\twhile ((y = x) != begin() && (--x)->p\
    \ >= y->p)\n\t\t\tintersect(x, erase(y));\n\t}\n\t\n\tlong long query(long long\
    \ x) {\n\t\tassert(!empty());\n\t\t__LINE_COMPARE__ = true; \n\t\tauto l = *lower_bound({0,\
    \ 0, x}); \n\t\t__LINE_COMPARE__ = false;\n\t\treturn l.m * x + l.b;\n\t}\n};"
  dependsOn:
  - utility/floor-div.hpp
  isVerificationFile: false
  path: data-structure/line-container.hpp
  requiredBy: []
  timestamp: '2022-02-06 21:17:29-08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/line-container.yosupo-line-add-get-min.test.cpp
documentation_of: data-structure/line-container.hpp
layout: document
title: Line Container
---

## Line Container

[Placeholder]