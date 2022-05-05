---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/monotonic-dp-hull-minkowski-sum.hpp
    title: Minkowski Sum for Monotonic DP Hull
  - icon: ':heavy_check_mark:'
    path: geometry/monotonic-dp-hull.hpp
    title: Monotonic DP Hull
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: Point
  - icon: ':heavy_check_mark:'
    path: random/mersenne-twister.hpp
    title: Mersenne Twister
  - icon: ':heavy_check_mark:'
    path: random/random-vector.hpp
    title: Randomized Vector
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/monotonic-dp-hull-minkowski-sum.yosupo-a+b.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"geometry/point.hpp\"\n#pragma region point\n\
    \n#ifndef POINT_HPP\n#define POINT_HPP\n\nnamespace geo {\n\tconst double EPS\
    \ = 1e-9;\n\n\ttemplate<typename T>\n\tclass point {\n\t\tstatic_assert(is_arithmetic<T>::value,\
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
    \ const point<T> &q) { return p * norm(q) + norm(p) * q; }\n}\n\n#endif\n\n#pragma\
    \ endregion point\n#line 2 \"geometry/monotonic-dp-hull.hpp\"\n\n#pragma region\
    \ monotonic_dp_hull\n\n#ifndef MONOTONIC_DP_HULL_HPP\n#define MONOTONIC_DP_HULL_HPP\n\
    \nstruct monotonic_dp_hull {\n\tlong long prev_x = LLONG_MIN, prev_y = 1;\n\t\
    deque<geo::point<long long>> points;\n \n\tvoid add(const geo::point<long long>\
    \ &p) {\n\t\tassert(points.empty() || p.x >= points.back().x);\n\t\tif (!points.empty()\
    \ && p.x == points.back().x) {\n\t\t\tif (p.y <= points.back().y)\n\t\t\t\treturn;\n\
    \t\t\tpoints.pop_back();\n\t\t}\n\t\twhile (size() >= 2 && ((points.back() - p)\
    \ ^ (points[size() - 2] - points.back())) <= 0)\n\t\t\tpoints.pop_back();\n\t\t\
    points.push_back(p);\n\t}\n\n\tvoid add(long long m, long long b) { add(geo::point(m,\
    \ b)); }\n\n\tlong long query(long long x, long long y = 1) {\n\t\tassert(size()\
    \ > 0);\n\t\tassert(prev_x == LLONG_MIN || x * prev_y >= prev_x * y);\n\t\tprev_x\
    \ = x, prev_y = y;\n\t\twhile (size() >= 2 && x * (points[1].x - points[0].x)\
    \ >= (points[0].y - points[1].y) * y)\n\t\t\tpoints.pop_front();\n\t\treturn points[0].x\
    \ * x + points[0].y * y;\n\t}\n\n\tvoid clear() { points.clear(); prev_x = LLONG_MIN,\
    \ prev_y = 1; }\n\n\tint size() const { return points.size(); }\n};\n\n#endif\n\
    \n#pragma endregion monotonic_dp_hull\n#line 1 \"geometry/point.hpp\"\n#pragma\
    \ region point\n\n#ifndef POINT_HPP\n#define POINT_HPP\n\nnamespace geo {\n\t\
    const double EPS = 1e-9;\n\n\ttemplate<typename T>\n\tclass point {\n\t\tstatic_assert(is_arithmetic<T>::value,\
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
    \ const point<T> &q) { return p * norm(q) + norm(p) * q; }\n}\n\n#endif\n\n#pragma\
    \ endregion point\n#line 2 \"geometry/monotonic-dp-hull.hpp\"\n\n#pragma region\
    \ monotonic_dp_hull\n\n#ifndef MONOTONIC_DP_HULL_HPP\n#define MONOTONIC_DP_HULL_HPP\n\
    \nstruct monotonic_dp_hull {\n\tlong long prev_x = LLONG_MIN, prev_y = 1;\n\t\
    deque<geo::point<long long>> points;\n \n\tvoid add(const geo::point<long long>\
    \ &p) {\n\t\tassert(points.empty() || p.x >= points.back().x);\n\t\tif (!points.empty()\
    \ && p.x == points.back().x) {\n\t\t\tif (p.y <= points.back().y)\n\t\t\t\treturn;\n\
    \t\t\tpoints.pop_back();\n\t\t}\n\t\twhile (size() >= 2 && ((points.back() - p)\
    \ ^ (points[size() - 2] - points.back())) <= 0)\n\t\t\tpoints.pop_back();\n\t\t\
    points.push_back(p);\n\t}\n\n\tvoid add(long long m, long long b) { add(geo::point(m,\
    \ b)); }\n\n\tlong long query(long long x, long long y = 1) {\n\t\tassert(size()\
    \ > 0);\n\t\tassert(prev_x == LLONG_MIN || x * prev_y >= prev_x * y);\n\t\tprev_x\
    \ = x, prev_y = y;\n\t\twhile (size() >= 2 && x * (points[1].x - points[0].x)\
    \ >= (points[0].y - points[1].y) * y)\n\t\t\tpoints.pop_front();\n\t\treturn points[0].x\
    \ * x + points[0].y * y;\n\t}\n\n\tvoid clear() { points.clear(); prev_x = LLONG_MIN,\
    \ prev_y = 1; }\n\n\tint size() const { return points.size(); }\n};\n\n#endif\n\
    \n#pragma endregion monotonic_dp_hull\n#line 2 \"geometry/monotonic-dp-hull-minkowski-sum.hpp\"\
    \n\n#pragma region monotonic_dp_hull_minkowski_sum\n\n#ifndef MONOTONIC_DP_HULL_MINKOWSKI_SUM_HPP\n\
    #define MONOTONIC_DP_HULL_MINKOWSKI_SUM_HPP\n\nmonotonic_dp_hull minkowski_sum(const\
    \ monotonic_dp_hull &h1, const monotonic_dp_hull &h2) {\n\tassert(h1.size() >\
    \ 0 && h2.size() > 0);\n\tmonotonic_dp_hull sum;\n\tfor (int i = 0, j = 0; i <\
    \ h1.size() - 1 || j < h2.size() - 1;) {\n\t\tsum.add(h1.points[i] + h2.points[j]);\n\
    \t\tif (i == h1.size() - 1) {\n\t\t\tj++;\n\t\t\tcontinue;\n\t\t}\n\t\tif (j ==\
    \ h2.size() - 1) {\n\t\t\ti++;\n\t\t\tcontinue;\n\t\t}\n \n\t\tauto d1 = h1.points[i\
    \ + 1] - h1.points[i];\n\t\tauto d2 = h2.points[j + 1] - h2.points[j];\n\t\tif\
    \ ((d2 ^ d1) > 0)\n\t\t\ti++;\n\t\telse\n\t\t\tj++;\n\t}\n\tsum.add(h1.points.back()\
    \ + h2.points.back());\n\treturn sum;\n}\n\n#endif\n\n#pragma endregion monotonic_dp_hull_minkowski_sum\n\
    #line 1 \"random/mersenne-twister.hpp\"\n#pragma region rng\n\n#ifndef MERSENNE_TWISTER_HPP\n\
    #define MERSENNE_TWISTER_HPP\n\nmt19937 _rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    \ntemplate<typename T = int>\ntypename enable_if<is_integral<T>::value, T>::type\
    \ rng(T l, T r) { return uniform_int_distribution<T>(l, r)(_rng); }\n\n#endif\n\
    \n#pragma endregion rng\n#line 2 \"random/random-vector.hpp\"\n\n#pragma region\
    \ rng_vector\n\n#ifndef RNG_VECTOR_HPP\n#define RNG_VECTOR_HPP\n\ntemplate<typename\
    \ T>\ntypename enable_if<is_integral<T>::value, vector<T>>::type rng_vector(int\
    \ n, T l, T r) {\n\tvector<T> v(n);\n\tfor (auto &a : v)\n\t\ta = rng(l, r);\n\
    \treturn v;\n}\n\n#endif\n\n#pragma endregion rng_vector\n#line 9 \"verify/monotonic-dp-hull-minkowski-sum.yosupo-a+b.test.cpp\"\
    \n\nint main() {\n\t{\n\t\tint T = 1e6;\n\t\tauto slope1 = rng_vector<long long>(T,\
    \ -1e6, 1e6), intercept1 = rng_vector<long long>(T, -1e9, 1e9);\n\t\tauto slope2\
    \ = rng_vector<long long>(T, -1e6, 1e6), intercept2 = rng_vector<long long>(T,\
    \ -1e9, 1e9);\n\t\tsort(slope1.begin(), slope1.end());\n\t\tsort(slope2.begin(),\
    \ slope2.end());\n\t\tmonotonic_dp_hull a, b;\n\t\tfor (int i = 0; i < T; i++)\n\
    \t\t\ta.add(slope1[i], intercept1[i]);\n\t\tfor (int i = 0; i < T; i++)\n\t\t\t\
    b.add(slope2[i], intercept2[i]);\n\t\tmonotonic_dp_hull c = minkowski_sum(a, b);\n\
    \n\t\tauto x_coord = rng_vector<long long>(T, -1e6, 1e6);\n\t\tsort(x_coord.begin(),\
    \ x_coord.end());\n\n\t\tfor (int x : x_coord)\n\t\t\tassert(c.query(x) == a.query(x)\
    \ + b.query(x));\n\t}\n\n\tint A, B;\n\tcin >> A >> B;\n\tcout << A + B << '\\\
    n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"geometry/monotonic-dp-hull.hpp\"\n#include\
    \ \"geometry/monotonic-dp-hull-minkowski-sum.hpp\"\n#include \"random/random-vector.hpp\"\
    \n\nint main() {\n\t{\n\t\tint T = 1e6;\n\t\tauto slope1 = rng_vector<long long>(T,\
    \ -1e6, 1e6), intercept1 = rng_vector<long long>(T, -1e9, 1e9);\n\t\tauto slope2\
    \ = rng_vector<long long>(T, -1e6, 1e6), intercept2 = rng_vector<long long>(T,\
    \ -1e9, 1e9);\n\t\tsort(slope1.begin(), slope1.end());\n\t\tsort(slope2.begin(),\
    \ slope2.end());\n\t\tmonotonic_dp_hull a, b;\n\t\tfor (int i = 0; i < T; i++)\n\
    \t\t\ta.add(slope1[i], intercept1[i]);\n\t\tfor (int i = 0; i < T; i++)\n\t\t\t\
    b.add(slope2[i], intercept2[i]);\n\t\tmonotonic_dp_hull c = minkowski_sum(a, b);\n\
    \n\t\tauto x_coord = rng_vector<long long>(T, -1e6, 1e6);\n\t\tsort(x_coord.begin(),\
    \ x_coord.end());\n\n\t\tfor (int x : x_coord)\n\t\t\tassert(c.query(x) == a.query(x)\
    \ + b.query(x));\n\t}\n\n\tint A, B;\n\tcin >> A >> B;\n\tcout << A + B << '\\\
    n';\n}"
  dependsOn:
  - geometry/monotonic-dp-hull.hpp
  - geometry/point.hpp
  - geometry/monotonic-dp-hull-minkowski-sum.hpp
  - random/random-vector.hpp
  - random/mersenne-twister.hpp
  isVerificationFile: true
  path: verify/monotonic-dp-hull-minkowski-sum.yosupo-a+b.test.cpp
  requiredBy: []
  timestamp: '2022-05-05 15:11:34-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/monotonic-dp-hull-minkowski-sum.yosupo-a+b.test.cpp
layout: document
redirect_from:
- /verify/verify/monotonic-dp-hull-minkowski-sum.yosupo-a+b.test.cpp
- /verify/verify/monotonic-dp-hull-minkowski-sum.yosupo-a+b.test.cpp.html
title: verify/monotonic-dp-hull-minkowski-sum.yosupo-a+b.test.cpp
---
