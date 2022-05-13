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
  - icon: ':heavy_check_mark:'
    path: verify/monotonic-dp-hull.yosupo-a+b.test.cpp
    title: verify/monotonic-dp-hull.yosupo-a+b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utility/floor-div.hpp\"\n#pragma region floor_div\n\n#ifndef\
    \ FLOOR_DIV_HPP\n#define FLOOR_DIV_HPP\n\ntemplate<typename T>\nT floor_div(T\
    \ a, T b) { \n\treturn a / b - ((a ^ b) < 0 && a % b); \n}\n\n#endif\n\n#pragma\
    \ endregion floor_div\n#line 2 \"geometry/line-container.hpp\"\n\n#pragma region\
    \ line_container\n\n#ifndef LINE_CONTAINER_HPP\n#define LINE_CONTAINER_HPP\n\n\
    struct line_container_line {\n    mutable long long m, b, p;\n    bool operator<(const\
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
    \      return l.m * x + l.b;\n    }\n};\n\n#endif\n\n#pragma endregion line_container\n"
  code: "#include \"utility/floor-div.hpp\"\n\n#pragma region line_container\n\n#ifndef\
    \ LINE_CONTAINER_HPP\n#define LINE_CONTAINER_HPP\n\nstruct line_container_line\
    \ {\n    mutable long long m, b, p;\n    bool operator<(const line_container_line\
    \ &o) const { return m < o.m; }\n    bool operator<(long long x) const { return\
    \ p < x; }\n};\n\nclass line_container : multiset<line_container_line, less<>>\
    \ {\n    bool isect(iterator x, iterator y) {\n        if (y == end()) {\n\t\t\
    \tx->p = LLONG_MAX;\n\t\t\treturn false;\n\t\t}\n        if (x->m == y->m)\n \
    \           x->p = x->b > y->b ? LLONG_MAX : LLONG_MIN;\n        else\n      \
    \      x->p = floor_div(y->b - x->b, x->m - y->m);\n        return x->p >= y->p;\n\
    \    }\n\npublic:\n    void add(long long m, long long b) {\n        auto z =\
    \ insert({m, b, 0}), y = z++, x = y;\n        while (isect(y, z)) \n         \
    \   z = erase(z);\n        if (x != begin() && isect(--x, y)) \n            isect(x,\
    \ y = erase(y));\n        while ((y = x) != begin() && (--x)->p >= y->p) \n  \
    \          isect(x, erase(y));\n    }\n\n    long long query(long long x) {\n\
    \        assert(!empty());\n        auto l = *lower_bound(x);\n        return\
    \ l.m * x + l.b;\n    }\n};\n\n#endif\n\n#pragma endregion line_container"
  dependsOn:
  - utility/floor-div.hpp
  isVerificationFile: false
  path: geometry/line-container.hpp
  requiredBy: []
  timestamp: '2022-05-05 15:11:34-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/line-container.yosupo-line-add-get-min.test.cpp
  - verify/monotonic-dp-hull.yosupo-a+b.test.cpp
documentation_of: geometry/line-container.hpp
layout: document
title: Line Container
---

## Line Container

## Summary
The line container is an online set of lines that supports the following operations:
- Given some linear function $f(x) = mx + b$, inserts it into the set.
- Given some location $x$, returns the maximum of $f(x)$ for all functions $f$ in the set. 

Both these operations are performed in $\mathcal{O}(\log n)$ time, and the data structure has space complexity proportional to $O(q)$, where $q$ is the number of update operations performed. Note that deleting and random access is not possible. 