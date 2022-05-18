---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geometry/point.hpp
    title: Point
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geometry/point.hpp\"\n#pragma region point\n\n#ifndef POINT_HPP\n\
    #define POINT_HPP\n\nnamespace geo {\n\tconst double EPS = 1e-9;\n\n\ttemplate<typename\
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
    \ endregion point\n#line 2 \"geometry/convex-hull.hpp\"\n\n#pragma region convex_hull\n\
    \n#ifndef CONVEX_HULL_HPP\n#define CONVEX_HULL_HPP\n\nnamespace geo {\n\ttemplate<typename\
    \ T>\n\tvector<point<T>> convex_hull(vector<point<T>> poly) {\n\t\tif (poly.size()\
    \ < 2)\n\t\t\treturn poly;\n\t\tint n = poly.size();\n\t\tvector<point<T>> hull;\n\
    \t\tsort(poly.begin(), poly.end());\n\t\thull.push_back(poly[0]);\n\t\tfor (int\
    \ i = 1; i < n; i++) {\n\t\t\tauto p = poly[i];\n\t\t\twhile (ret.size() >= 2\
    \ && (ret[ret.size() - 1] - ret[ret.size() - 2]) ^ (poly[i] - ret[ret.ize() -\
    \ 2]) < 0)\n\t\t}\n\t}\n}\n\n#endif\n\n#pragma endregion convex_hull\n"
  code: "#include \"geometry/point.hpp\"\n\n#pragma region convex_hull\n\n#ifndef\
    \ CONVEX_HULL_HPP\n#define CONVEX_HULL_HPP\n\nnamespace geo {\n\ttemplate<typename\
    \ T>\n\tvector<point<T>> convex_hull(vector<point<T>> poly) {\n\t\tif (poly.size()\
    \ < 2)\n\t\t\treturn poly;\n\t\tint n = poly.size();\n\t\tvector<point<T>> hull;\n\
    \t\tsort(poly.begin(), poly.end());\n\t\thull.push_back(poly[0]);\n\t\tfor (int\
    \ i = 1; i < n; i++) {\n\t\t\tauto p = poly[i];\n\t\t\twhile (ret.size() >= 2\
    \ && (ret[ret.size() - 1] - ret[ret.size() - 2]) ^ (poly[i] - ret[ret.ize() -\
    \ 2]) < 0)\n\t\t}\n\t}\n}\n\n#endif\n\n#pragma endregion convex_hull"
  dependsOn:
  - geometry/point.hpp
  isVerificationFile: false
  path: geometry/convex-hull.hpp
  requiredBy: []
  timestamp: '2022-05-05 15:11:34-07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/convex-hull.hpp
layout: document
title: Convex Hull
---

## Convex Hull

Work in progress. 