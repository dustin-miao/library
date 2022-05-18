---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/line-container.hpp
    title: Line Container
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
    path: random/random-int-vector.hpp
    title: Random Integer Vector
  - icon: ':heavy_check_mark:'
    path: random/random-int.hpp
    title: Random Integer
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/monotonic-dp-hull.yosupo-a+b.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"utility/floor-div.hpp\"\n#pragma region floor_div\n\
    \n#ifndef FLOOR_DIV_HPP\n#define FLOOR_DIV_HPP\n\ntemplate<typename T>\nT floor_div(T\
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
    \      return l.m * x + l.b;\n    }\n};\n\n#endif\n\n#pragma endregion line_container\n\
    #line 1 \"geometry/point.hpp\"\n#pragma region point\n\n#ifndef POINT_HPP\n#define\
    \ POINT_HPP\n\nnamespace geo {\n\tconst double EPS = 1e-9;\n\n\ttemplate<typename\
    \ T>\n\tclass point {\n\t\tstatic_assert(is_arithmetic<T>::value, \"T must be\
    \ an arithmetic type\");\n\n\tpublic:\n\t\tT x, y;\n\n\t\tpoint() : x(T{}), y(T{})\
    \ {}\n\n\t\tpoint(const T &_x, const T &_y) : x(_x), y(_y) {}\n\n\t\ttemplate<typename\
    \ S> \n\t\toperator point<S>() const { return point<S>(static_cast<S>(x), static_cast<S>(y));\
    \ }\n\n\t\ttemplate<typename S>\n\t\tpoint &operator=(const point<S> &p) { x =\
    \ p.x; y = p.y; return *this; }\n\n\t\tpoint &operator+=(const point &p) { x +=\
    \ p.x; y += p.y; return *this; }\n\n\t\tpoint &operator-=(const point &p) { x\
    \ -= p.x; y -= p.y; return *this; }\n\n\t\tpoint &operator*=(const T &s) { x *=\
    \ s; y *= s; return *this; }\n\n\t\tpoint &operator/=(const T &s) { x /= s; y\
    \ /= s; return *this; }\n\n\t\tvoid swap(point &p) { swap(x, p.x); swap(y, p.y);\
    \ }\n\t};\n\n\ttemplate<typename T>\n\tpoint<T> make_point(const T &x, const T\
    \ &y) { return point<T>(x, y); }\n\n\ttemplate<typename T>\n\tvoid swap(point<T>\
    \ &p, point<T> &q) { p.swap(q); }\n\n\ttemplate<typename T>\n\tpoint<T> operator-(const\
    \ point<T> &p) { return point<T>(-p.x, -p.y); }\n\n\ttemplate<typename T>\n\t\
    point<T> operator+(point<T> p, const point<T> &q) { return p += q; }\n\n\ttemplate<typename\
    \ T>\n\tpoint<T> operator-(point<T> p, const point<T> &q) { return p -= q; }\n\
    \n\ttemplate<typename T>\n\tpoint<T> operator*(point<T> p, const T &s) { return\
    \ p *= s; }\n\n\ttemplate<typename T>\n\tpoint<T> operator*(const T &s, point<T>\
    \ p) { return p *= s; }\n\n\ttemplate<typename T>\n\tpoint<T> operator/(point<T>\
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
    \n#pragma endregion monotonic_dp_hull\n#line 1 \"random/mersenne-twister.hpp\"\
    \n#pragma region mersenne_twister\n\n#ifndef MERSENNE_TWISTER_HPP\n#define MERSENNE_TWISTER_HPP\n\
    \nnamespace rng {\n\tmt19937 mst(chrono::steady_clock::now().time_since_epoch().count());\n\
    }\n\n#endif\n\n#pragma endregion mersenne_twister\n#line 2 \"random/random-int.hpp\"\
    \n\n#pragma region rng_int\n\n#ifndef RANDOM_INT_HPP\n#define RANDOM_INT_HPP\n\
    \nnamespace rng {\n\ttemplate<typename T = int>\n\ttypename enable_if<is_integral<T>::value,\
    \ T>::type \n\trint(T l, T r) { return uniform_int_distribution<T>(l, r)(mst);\
    \ }\n}\n\n#endif\n\n#pragma endregion rng_int\n#line 2 \"random/random-int-vector.hpp\"\
    \n\n#pragma region rng_int_vector\n\n#ifndef RNG_VECTOR_HPP\n#define RNG_VECTOR_HPP\n\
    \nnamespace rng {\n\ttemplate<typename T>\n\ttypename enable_if<is_integral<T>::value,\
    \ vector<T>>::type \n\trivec(int n, T l, T r) {\n\t\tvector<T> v(n);\n\t\tfor\
    \ (auto &a : v)\n\t\t\ta = rint(l, r);\n\t\treturn v;\n\t}\n}\n\n#endif\n\n#pragma\
    \ endregion rng_int_vector\n#line 9 \"verify/monotonic-dp-hull.yosupo-a+b.test.cpp\"\
    \n\nint main() {\n\t{\n\t\tint T = 2e5;\n\t\tauto slope = rng::rivec<long long>(T,\
    \ -1e6, 1e6), intercept = rng::rivec<long long>(T, -1e9, 1e9);\n\t\tauto x_coord\
    \ = rng::rivec<long long>(5 * T, -1e6, 1e6);\n\n\t\tsort(slope.begin(), slope.end());\n\
    \t\tsort(x_coord.begin(), x_coord.end());\n\n\t\tline_container lc;\n\t\tmonotonic_dp_hull\
    \ mdh;\n\t\tfor (int tc = 0; tc < T; tc++) {\n\t\t\tlc.add(slope[tc], intercept[tc]);\n\
    \t\t\tmdh.add(slope[tc], intercept[tc]);\n\t\t\tfor (int i = tc * 5; i < (tc +\
    \ 1) * 5; i++) \n\t\t\t\tassert(lc.query(x_coord[i]) == mdh.query(x_coord[i]));\n\
    \t\t}\n\t}\n\n\tlong long A, B;\n\tcin >> A >> B;\n\tcout << A + B << '\\n';\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"geometry/line-container.hpp\"\n#include \"\
    geometry/monotonic-dp-hull.hpp\"\n#include \"random/random-int-vector.hpp\"\n\n\
    int main() {\n\t{\n\t\tint T = 2e5;\n\t\tauto slope = rng::rivec<long long>(T,\
    \ -1e6, 1e6), intercept = rng::rivec<long long>(T, -1e9, 1e9);\n\t\tauto x_coord\
    \ = rng::rivec<long long>(5 * T, -1e6, 1e6);\n\n\t\tsort(slope.begin(), slope.end());\n\
    \t\tsort(x_coord.begin(), x_coord.end());\n\n\t\tline_container lc;\n\t\tmonotonic_dp_hull\
    \ mdh;\n\t\tfor (int tc = 0; tc < T; tc++) {\n\t\t\tlc.add(slope[tc], intercept[tc]);\n\
    \t\t\tmdh.add(slope[tc], intercept[tc]);\n\t\t\tfor (int i = tc * 5; i < (tc +\
    \ 1) * 5; i++) \n\t\t\t\tassert(lc.query(x_coord[i]) == mdh.query(x_coord[i]));\n\
    \t\t}\n\t}\n\n\tlong long A, B;\n\tcin >> A >> B;\n\tcout << A + B << '\\n';\n\
    }"
  dependsOn:
  - geometry/line-container.hpp
  - utility/floor-div.hpp
  - geometry/monotonic-dp-hull.hpp
  - geometry/point.hpp
  - random/random-int-vector.hpp
  - random/random-int.hpp
  - random/mersenne-twister.hpp
  isVerificationFile: true
  path: verify/monotonic-dp-hull.yosupo-a+b.test.cpp
  requiredBy: []
  timestamp: '2022-05-18 09:19:50-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/monotonic-dp-hull.yosupo-a+b.test.cpp
layout: document
redirect_from:
- /verify/verify/monotonic-dp-hull.yosupo-a+b.test.cpp
- /verify/verify/monotonic-dp-hull.yosupo-a+b.test.cpp.html
title: verify/monotonic-dp-hull.yosupo-a+b.test.cpp
---
