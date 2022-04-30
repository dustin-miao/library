---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/monotonic-dp-hull.hpp
    title: Monotonic DP Hull
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: Point
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/monotonic-dp-hull-minkowski-sum.yosupo-a+b.test.cpp
    title: verify/monotonic-dp-hull-minkowski-sum.yosupo-a+b.test.cpp
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
    \ return p * norm(q) + norm(p) * q; }\n}\n\n#pragma endregion point\n#line 2 \"\
    geometry/monotonic-dp-hull.hpp\"\n\n#pragma region monotonic_dp_hull\n\nstruct\
    \ monotonic_dp_hull {\n\tlong long prev_x = LLONG_MIN, prev_y = 1;\n\tdeque<geo::point<long\
    \ long>> points;\n \n\tvoid add(const geo::point<long long> &p) {\n\t\tassert(points.empty()\
    \ || p.x >= points.back().x);\n\t\tif (!points.empty() && p.x == points.back().x)\
    \ {\n\t\t\tif (p.y <= points.back().y)\n\t\t\t\treturn;\n\t\t\tpoints.pop_back();\n\
    \t\t}\n\t\twhile (size() >= 2 && ((points.back() - p) ^ (points[size() - 2] -\
    \ points.back())) <= 0)\n\t\t\tpoints.pop_back();\n\t\tpoints.push_back(p);\n\t\
    }\n\n\tvoid add(long long m, long long b) { add(geo::point(m, b)); }\n\n\tlong\
    \ long query(long long x, long long y = 1) {\n\t\tassert(size() > 0);\n\t\tassert(prev_x\
    \ == LLONG_MIN || x * prev_y >= prev_x * y);\n\t\tprev_x = x, prev_y = y;\n\t\t\
    while (size() >= 2 && x * (points[1].x - points[0].x) >= (points[0].y - points[1].y)\
    \ * y)\n\t\t\tpoints.pop_front();\n\t\treturn points[0].x * x + points[0].y *\
    \ y;\n\t}\n\n\tvoid clear() { points.clear(); prev_x = LLONG_MIN, prev_y = 1;\
    \ }\n\n\tint size() const { return points.size(); }\n};\n\n#pragma endregion monotonic_dp_hull\n\
    #line 2 \"geometry/monotonic-dp-hull-minkowski-sum.hpp\"\n\n#pragma region monotonic_dp_hull_minkowski_sum\n\
    \nmonotonic_dp_hull minkowski_sum(const monotonic_dp_hull &h1, const monotonic_dp_hull\
    \ &h2) {\n\tassert(h1.size() > 0 && h2.size() > 0);\n\tmonotonic_dp_hull sum;\n\
    \tfor (int i = 0, j = 0; i < h1.size() - 1 || j < h2.size() - 1;) {\n\t\tsum.add(h1.points[i]\
    \ + h2.points[j]);\n\t\tif (i == h1.size() - 1) {\n\t\t\tj++;\n\t\t\tcontinue;\n\
    \t\t}\n\t\tif (j == h2.size() - 1) {\n\t\t\ti++;\n\t\t\tcontinue;\n\t\t}\n \n\t\
    \tauto d1 = h1.points[i + 1] - h1.points[i];\n\t\tauto d2 = h2.points[j + 1] -\
    \ h2.points[j];\n\t\tif ((d2 ^ d1) > 0)\n\t\t\ti++;\n\t\telse\n\t\t\tj++;\n\t\
    }\n\tsum.add(h1.points.back() + h2.points.back());\n\treturn sum;\n}\n\n#pragma\
    \ endregion monotonic_dp_hull_minkowski_sum\n"
  code: "#include \"geometry/monotonic-dp-hull.hpp\"\n\n#pragma region monotonic_dp_hull_minkowski_sum\n\
    \nmonotonic_dp_hull minkowski_sum(const monotonic_dp_hull &h1, const monotonic_dp_hull\
    \ &h2) {\n\tassert(h1.size() > 0 && h2.size() > 0);\n\tmonotonic_dp_hull sum;\n\
    \tfor (int i = 0, j = 0; i < h1.size() - 1 || j < h2.size() - 1;) {\n\t\tsum.add(h1.points[i]\
    \ + h2.points[j]);\n\t\tif (i == h1.size() - 1) {\n\t\t\tj++;\n\t\t\tcontinue;\n\
    \t\t}\n\t\tif (j == h2.size() - 1) {\n\t\t\ti++;\n\t\t\tcontinue;\n\t\t}\n \n\t\
    \tauto d1 = h1.points[i + 1] - h1.points[i];\n\t\tauto d2 = h2.points[j + 1] -\
    \ h2.points[j];\n\t\tif ((d2 ^ d1) > 0)\n\t\t\ti++;\n\t\telse\n\t\t\tj++;\n\t\
    }\n\tsum.add(h1.points.back() + h2.points.back());\n\treturn sum;\n}\n\n#pragma\
    \ endregion monotonic_dp_hull_minkowski_sum"
  dependsOn:
  - geometry/monotonic-dp-hull.hpp
  - geometry/point.hpp
  isVerificationFile: false
  path: geometry/monotonic-dp-hull-minkowski-sum.hpp
  requiredBy: []
  timestamp: '2022-04-30 13:42:54-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/monotonic-dp-hull-minkowski-sum.yosupo-a+b.test.cpp
documentation_of: geometry/monotonic-dp-hull-minkowski-sum.hpp
layout: document
title: Minkowski Sum for Monotonic DP Hull
---

## Minkowski Sum for Monotonic DP Hull