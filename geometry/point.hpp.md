---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/convex-hull.hpp
    title: Convex Hull
  - icon: ':heavy_check_mark:'
    path: geometry/monotonic-dp-hull-minkowski-sum.hpp
    title: Minkowski Sum for Monotonic DP Hull
  - icon: ':heavy_check_mark:'
    path: geometry/monotonic-dp-hull.hpp
    title: Monotonic DP Hull
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/monotonic-dp-hull-minkowski-sum.yosupo-a+b.test.cpp
    title: verify/monotonic-dp-hull-minkowski-sum.yosupo-a+b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/monotonic-dp-hull.yosupo-a+b.test.cpp
    title: verify/monotonic-dp-hull.yosupo-a+b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/point.aizu-counter-clockwise.test.cpp
    title: verify/point.aizu-counter-clockwise.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/point.aizu-parallel-orthagonal.test.cpp
    title: verify/point.aizu-parallel-orthagonal.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/point.aizu-projection.test.cpp
    title: verify/point.aizu-projection.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geometry/point.hpp\"\n#pragma region point\n\nnamespace\
    \ geo {\n\tconst double EPS = 1e-9;\n\n\ttemplate<typename T>\n\tclass point {\n\
    \t\tstatic_assert(is_arithmetic<T>::value, \"T must be an arithmetic type\");\n\
    \n\tpublic:\n\t\tT x, y;\n\n\t\tpoint() : x(T{}), y(T{}) {}\n\n\t\tpoint(const\
    \ T &_x, const T &_y) : x(_x), y(_y) {}\n\n\t\ttemplate<typename S> \n\t\toperator\
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
    \ return p * norm(q) + norm(p) * q; }\n}\n\n#pragma endregion point\n"
  code: "#pragma region point\n\nnamespace geo {\n\tconst double EPS = 1e-9;\n\n\t\
    template<typename T>\n\tclass point {\n\t\tstatic_assert(is_arithmetic<T>::value,\
    \ \"T must be an arithmetic type\");\n\n\tpublic:\n\t\tT x, y;\n\n\t\tpoint()\
    \ : x(T{}), y(T{}) {}\n\n\t\tpoint(const T &_x, const T &_y) : x(_x), y(_y) {}\n\
    \n\t\ttemplate<typename S> \n\t\toperator point<S>() const { return point<S>(static_cast<S>(x),\
    \ static_cast<S>(y)); }\n\n\t\ttemplate<typename S>\n\t\tpoint &operator=(const\
    \ point<S> &p) { x = p.x; y = p.y; return *this; }\n\n\t\tpoint &operator+=(const\
    \ point &p) { x += p.x; y += p.y; return *this; }\n\n\t\tpoint &operator-=(const\
    \ point &p) { x -= p.x; y -= p.y; return *this; }\n\n\t\tpoint &operator*=(const\
    \ T &s) { x *= s; y *= s; return *this; }\n\n\t\tpoint &operator/=(const T &s)\
    \ { x /= s; y /= s; return *this; }\n\n\t\tvoid swap(point &p) { swap(x, p.x);\
    \ swap(y, p.y); }\n\t};\n\n\ttemplate<typename T>\n\tpoint<T> make_point(const\
    \ T &x, const T &y) { return point<T>(x, y); }\n\n\ttemplate<typename T>\n\tvoid\
    \ swap(point<T> &p, point<T> &q) { p.swap(q); }\n\n\ttemplate<typename T>\n\t\
    point<T> operator-(const point<T> &p) { return point<T>(-p.x, -p.y); }\n\n\ttemplate<typename\
    \ T>\n\tpoint<T> operator+(point<T> p, const point<T> &q) { return p += q; }\n\
    \n\ttemplate<typename T>\n\tpoint<T> operator-(point<T> p, const point<T> &q)\
    \ { return p -= q; }\n\n\ttemplate<typename T>\n\tpoint<T> operator*(point<T>\
    \ p, const T &s) { return p *= s; }\n\n\ttemplate<typename T>\n\tpoint<T> operator*(const\
    \ T &s, point<T> p) { return p *= s; }\n\n\ttemplate<typename T>\n\tpoint<T> operator/(point<T>\
    \ p, const T &s) { return p /= s;}\n\n\ttemplate<typename T>\n\tT dot(const point<T>\
    \ &p, const point<T> &q) { return p.x * q.x + p.y * q.y; }\n\n\ttemplate<typename\
    \ T>\n\tT operator*(const point<T> &p, const point<T> &q) { return dot(p, q);\
    \ }\n\n\ttemplate<typename T>\n\tT cross(const point<T> &p, const point<T> &q)\
    \ { return p.x * q.y - p.y * q.x; }\n\n\ttemplate<typename T>\n\tT operator^(const\
    \ point<T> &p, const point<T> &q) { return cross(p, q); }\n\n\ttemplate<typename\
    \ T>\n\tbool operator==(const point<T> &p, const point<T> &q) { \n\t\tif constexpr\
    \ (is_integral<T>::value)\n\t\t\treturn p.x == q.x && p.y == q.y; \n\t\telse \n\
    \t\t\treturn abs(p.x - q.x) <= EPS && abs(p.y - q.y) <= EPS;\n\t} \n\n\ttemplate<typename\
    \ T>\n\tbool operator!=(const point<T> &p, const point<T> &q) { return !(p ==\
    \ q); }\n\n\ttemplate<typename T>\n\tbool operator<(const point<T> &p, const point<T>\
    \ &q) { return p.x < q.x || (p.x == q.x && p.y < q.y); }\n\n\ttemplate<typename\
    \ T>\n\tbool operator>(const point<T> &p, const point<T> &q) { return q < p; }\n\
    \n\ttemplate<typename T>\n\tbool operator<=(const point<T> &p, const point<T>\
    \ &q) { return !(p > q); }\n\n\ttemplate<typename T>\n\tbool operator>=(const\
    \ point<T> &p, const point<T> &q) { return !(p < q); }\n\n\ttemplate<typename\
    \ T>\n\tdouble angle(const point<T> &p) { return atan2(p.y, p.x); }\n\n\ttemplate<typename\
    \ T>\n\tdouble angle(const point<T> &p, const point<T> &q) { return static_cast<double>(p\
    \ ^ q) / (p * q); }\n\n\ttemplate<typename T, typename S>\n\tauto rotate(const\
    \ point<T> &p, const S &cos_a, const S &sin_a) { return make_point(cos_a * p.x\
    \ - sin_a * p.y, sin_a * p.x + cos_a * p.y); }\n\n\ttemplate<typename T, typename\
    \ S>\n\tauto rotate(const point<T> &p, const S &a) { return rotate(p, cos(a),\
    \ sin(a)); }\n\n\ttemplate<typename T, typename S>\n\tauto rotate(const point<T>\
    \ &p, const S &a, const point<T> &o) { return o + rotate(p - o, a); }\n\n\ttemplate<typename\
    \ T>\n\tT abs(const point<T> &p) { return p * p; }\n\n\ttemplate<typename T>\n\
    \tdouble norm(const point<T> &p) { return sqrt(abs(p)); }\n\n\ttemplate<typename\
    \ T>\n\tT dis2(const point<T> &p, const point<T> &q) { return abs(q - p); }\n\n\
    \ttemplate<typename T>\n\tdouble dis(const point<T> &p, const point<T> &q) { return\
    \ norm(q - p); }\n\n\ttemplate<typename T>\n\tauto bisector(const point<T> &p,\
    \ const point<T> &q) { return p * norm(q) + norm(p) * q; }\n}\n\n#pragma endregion\
    \ point"
  dependsOn: []
  isVerificationFile: false
  path: geometry/point.hpp
  requiredBy:
  - geometry/monotonic-dp-hull.hpp
  - geometry/convex-hull.hpp
  - geometry/monotonic-dp-hull-minkowski-sum.hpp
  timestamp: '2022-04-11 13:05:03-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/point.aizu-counter-clockwise.test.cpp
  - verify/monotonic-dp-hull.yosupo-a+b.test.cpp
  - verify/point.aizu-parallel-orthagonal.test.cpp
  - verify/monotonic-dp-hull-minkowski-sum.yosupo-a+b.test.cpp
  - verify/point.aizu-projection.test.cpp
documentation_of: geometry/point.hpp
layout: document
title: Point
---

## Point