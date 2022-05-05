---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: Point
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C
  bundledCode: "#line 1 \"verify/point.aizu-counter-clockwise.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"geometry/point.hpp\"\
    \n#pragma region point\n\n#ifndef POINT_HPP\n#define POINT_HPP\n\nnamespace geo\
    \ {\n\tconst double EPS = 1e-9;\n\n\ttemplate<typename T>\n\tclass point {\n\t\
    \tstatic_assert(is_arithmetic<T>::value, \"T must be an arithmetic type\");\n\n\
    \tpublic:\n\t\tT x, y;\n\n\t\tpoint() : x(T{}), y(T{}) {}\n\n\t\tpoint(const T\
    \ &_x, const T &_y) : x(_x), y(_y) {}\n\n\t\ttemplate<typename S> \n\t\toperator\
    \ point<S>() const { return point<S>(static_cast<S>(x), static_cast<S>(y)); }\n\
    \n\t\ttemplate<typename S>\n\t\tpoint &operator=(const point<S> &p) { x = p.x;\
    \ y = p.y; return *this; }\n\n\t\tpoint &operator+=(const point &p) { x += p.x;\
    \ y += p.y; return *this; }\n\n\t\tpoint &operator-=(const point &p) { x -= p.x;\
    \ y -= p.y; return *this; }\n\n\t\tpoint &operator*=(const T &s) { x *= s; y *=\
    \ s; return *this; }\n\n\t\tpoint &operator/=(const T &s) { x /= s; y /= s; return\
    \ *this; }\n\n\t\tvoid swap(point &p) { swap(x, p.x); swap(y, p.y); }\n\t};\n\n\
    \ttemplate<typename T>\n\tpoint<T> make_point(const T &x, const T &y) { return\
    \ point<T>(x, y); }\n\n\ttemplate<typename T>\n\tvoid swap(point<T> &p, point<T>\
    \ &q) { p.swap(q); }\n\n\ttemplate<typename T>\n\tpoint<T> operator-(const point<T>\
    \ &p) { return point<T>(-p.x, -p.y); }\n\n\ttemplate<typename T>\n\tpoint<T> operator+(point<T>\
    \ p, const point<T> &q) { return p += q; }\n\n\ttemplate<typename T>\n\tpoint<T>\
    \ operator-(point<T> p, const point<T> &q) { return p -= q; }\n\n\ttemplate<typename\
    \ T>\n\tpoint<T> operator*(point<T> p, const T &s) { return p *= s; }\n\n\ttemplate<typename\
    \ T>\n\tpoint<T> operator*(const T &s, point<T> p) { return p *= s; }\n\n\ttemplate<typename\
    \ T>\n\tpoint<T> operator/(point<T> p, const T &s) { return p /= s;}\n\n\ttemplate<typename\
    \ T>\n\tT dot(const point<T> &p, const point<T> &q) { return p.x * q.x + p.y *\
    \ q.y; }\n\n\ttemplate<typename T>\n\tT operator*(const point<T> &p, const point<T>\
    \ &q) { return dot(p, q); }\n\n\ttemplate<typename T>\n\tT cross(const point<T>\
    \ &p, const point<T> &q) { return p.x * q.y - p.y * q.x; }\n\n\ttemplate<typename\
    \ T>\n\tT operator^(const point<T> &p, const point<T> &q) { return cross(p, q);\
    \ }\n\n\ttemplate<typename T>\n\tbool operator==(const point<T> &p, const point<T>\
    \ &q) { \n\t\tif constexpr (is_integral<T>::value)\n\t\t\treturn p.x == q.x &&\
    \ p.y == q.y; \n\t\telse \n\t\t\treturn abs(p.x - q.x) <= EPS && abs(p.y - q.y)\
    \ <= EPS;\n\t} \n\n\ttemplate<typename T>\n\tbool operator!=(const point<T> &p,\
    \ const point<T> &q) { return !(p == q); }\n\n\ttemplate<typename T>\n\tbool operator<(const\
    \ point<T> &p, const point<T> &q) { return p.x < q.x || (p.x == q.x && p.y < q.y);\
    \ }\n\n\ttemplate<typename T>\n\tbool operator>(const point<T> &p, const point<T>\
    \ &q) { return q < p; }\n\n\ttemplate<typename T>\n\tbool operator<=(const point<T>\
    \ &p, const point<T> &q) { return !(p > q); }\n\n\ttemplate<typename T>\n\tbool\
    \ operator>=(const point<T> &p, const point<T> &q) { return !(p < q); }\n\n\t\
    template<typename T>\n\tdouble angle(const point<T> &p) { return atan2(p.y, p.x);\
    \ }\n\n\ttemplate<typename T>\n\tdouble angle(const point<T> &p, const point<T>\
    \ &q) { return static_cast<double>(p ^ q) / (p * q); }\n\n\ttemplate<typename\
    \ T, typename S>\n\tauto rotate(const point<T> &p, const S &cos_a, const S &sin_a)\
    \ { return make_point(cos_a * p.x - sin_a * p.y, sin_a * p.x + cos_a * p.y); }\n\
    \n\ttemplate<typename T, typename S>\n\tauto rotate(const point<T> &p, const S\
    \ &a) { return rotate(p, cos(a), sin(a)); }\n\n\ttemplate<typename T, typename\
    \ S>\n\tauto rotate(const point<T> &p, const S &a, const point<T> &o) { return\
    \ o + rotate(p - o, a); }\n\n\ttemplate<typename T>\n\tT abs(const point<T> &p)\
    \ { return p * p; }\n\n\ttemplate<typename T>\n\tdouble norm(const point<T> &p)\
    \ { return sqrt(abs(p)); }\n\n\ttemplate<typename T>\n\tT dis2(const point<T>\
    \ &p, const point<T> &q) { return abs(q - p); }\n\n\ttemplate<typename T>\n\t\
    double dis(const point<T> &p, const point<T> &q) { return norm(q - p); }\n\n\t\
    template<typename T>\n\tauto bisector(const point<T> &p, const point<T> &q) {\
    \ return p * norm(q) + norm(p) * q; }\n}\n\n#endif\n\n#pragma endregion point\n\
    #line 7 \"verify/point.aizu-counter-clockwise.test.cpp\"\n\nusing namespace geo;\n\
    \nint main() {\n\tcout << fixed << setprecision(10);\n\tpoint<double> p0, p1;\
    \ \n\tcin >> p0.x >> p0.y >> p1.x >> p1.y;\n\n\tint Q;\n\tcin >> Q;\n\twhile (Q--)\
    \ {\n\t\tpoint<double> p2;\n\t\tcin >> p2.x >> p2.y;\n\t\tauto p = p1 - p0, q\
    \ = p2 - p0;\n\t\tauto c = p ^ q;\n\t\tif (c > 0) {\n\t\t\tcout << \"COUNTER_CLOCKWISE\\\
    n\";\n\t\t} else if (c < 0) {\n\t\t\tcout << \"CLOCKWISE\\n\";\n\t\t} else {\n\
    \t\t\tif (p * q >= 0) {\n\t\t\t\tif (abs(p) < abs(q)) \n\t\t\t\t\tcout << \"ONLINE_FRONT\\\
    n\";\n\t\t\t\telse \n\t\t\t\t\tcout << \"ON_SEGMENT\\n\";\n\t\t\t} else {\n\t\t\
    \t\tcout << \"ONLINE_BACK\\n\";\n\t\t\t}\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"geometry/point.hpp\"\
    \n\nusing namespace geo;\n\nint main() {\n\tcout << fixed << setprecision(10);\n\
    \tpoint<double> p0, p1; \n\tcin >> p0.x >> p0.y >> p1.x >> p1.y;\n\n\tint Q;\n\
    \tcin >> Q;\n\twhile (Q--) {\n\t\tpoint<double> p2;\n\t\tcin >> p2.x >> p2.y;\n\
    \t\tauto p = p1 - p0, q = p2 - p0;\n\t\tauto c = p ^ q;\n\t\tif (c > 0) {\n\t\t\
    \tcout << \"COUNTER_CLOCKWISE\\n\";\n\t\t} else if (c < 0) {\n\t\t\tcout << \"\
    CLOCKWISE\\n\";\n\t\t} else {\n\t\t\tif (p * q >= 0) {\n\t\t\t\tif (abs(p) < abs(q))\
    \ \n\t\t\t\t\tcout << \"ONLINE_FRONT\\n\";\n\t\t\t\telse \n\t\t\t\t\tcout << \"\
    ON_SEGMENT\\n\";\n\t\t\t} else {\n\t\t\t\tcout << \"ONLINE_BACK\\n\";\n\t\t\t\
    }\n\t\t}\n\t}\n}"
  dependsOn:
  - geometry/point.hpp
  isVerificationFile: true
  path: verify/point.aizu-counter-clockwise.test.cpp
  requiredBy: []
  timestamp: '2022-05-05 15:11:34-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/point.aizu-counter-clockwise.test.cpp
layout: document
redirect_from:
- /verify/verify/point.aizu-counter-clockwise.test.cpp
- /verify/verify/point.aizu-counter-clockwise.test.cpp.html
title: verify/point.aizu-counter-clockwise.test.cpp
---
