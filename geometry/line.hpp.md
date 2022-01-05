---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/data-structure/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp
    title: verify/data-structure/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geometry/line.hpp\"\ntemplate<typename T>\nstruct line {\n\
    \    T m, b;\n\n    line() = default;\n\n    line(T _m, T _b) : m(_m), b(_b) {};\n\
    \n    T operator()(T x) { return m * x + b; }\n\n    friend double intersect(const\
    \ line &l1, const line &l2) { \n        return (double)(l1.b - l2.b) / (double)(l2.m\
    \ - l1.m); \n    }\n\n    friend ostream &operator<<(ostream &os, const line &l)\
    \ { \n        return os << \"y = \" << l.m << \"x + \" << l.b; \n    }\n};\n"
  code: "template<typename T>\nstruct line {\n    T m, b;\n\n    line() = default;\n\
    \n    line(T _m, T _b) : m(_m), b(_b) {};\n\n    T operator()(T x) { return m\
    \ * x + b; }\n\n    friend double intersect(const line &l1, const line &l2) {\
    \ \n        return (double)(l1.b - l2.b) / (double)(l2.m - l1.m); \n    }\n\n\
    \    friend ostream &operator<<(ostream &os, const line &l) { \n        return\
    \ os << \"y = \" << l.m << \"x + \" << l.b; \n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/line.hpp
  requiredBy: []
  timestamp: '2021-12-31 10:27:42-08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/data-structure/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp
documentation_of: geometry/line.hpp
layout: document
title: Line
---

## Line

### Summary

A line object represents a linear function on a euclidian plane, which is described by two variables $m$ and $b$, corresponding respectively to slope and y-intercept. Useful for convex hull trick when combined with Line Container or Li-Chao Tree. 

### Documentation

- `m`: The slope.
- `b`: The y-intercept.
- `line()`: Constructs a line object with default values.
- `line(T m, T b)`: Constructs a line object with given parameters. 
- `T operator(T x)`: Evaluates the linear function at position $x$. 
- `double intersect(line l1, line l2)`: Determines the $x$ position of intersection between two lines. Will throw a runtime error if lines do not intersect. 
