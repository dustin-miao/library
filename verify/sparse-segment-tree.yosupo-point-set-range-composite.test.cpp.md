---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/sparse-segment-tree.hpp
    title: Sparse Segment Tree
  - icon: ':question:'
    path: math/inverse.hpp
    title: Modulo Inverse
  - icon: ':question:'
    path: utility/mint.hpp
    title: Modular Int
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"verify/sparse-segment-tree.yosupo-point-set-range-composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"math/inverse.hpp\"\
    \n#pragma region modular_inverse\n\nnamespace math {\n\ttemplate <typename T>\n\
    \tT inverse(T a, T p) {\n\t\tT b = p, x = 1, y = 0;\n\t\twhile (a) {\n\t\t\tT\
    \ q = b / a;\n\t\t\tswap(a, b %= a);\n\t\t\tswap(x, y -= q * x);\n\t\t}\n\t\t\
    assert(b == 1);\n\t\treturn y < 0 ? y + p : y;\n\t}\n}\n\n#pragma endregion modular_inverse\n\
    #line 2 \"utility/mint.hpp\"\n\n#pragma region mint\n\n#ifndef MINT_HPP\n#define\
    \ MINT_HPP\n\ntemplate<typename T>\nclass Modular {\npublic:\n\tusing Type = typename\
    \ decay<decltype(T::value)>::type;\n\t\n\tconstexpr Modular() : value() {}\n\n\
    \ttemplate<typename U>\n\tModular(const U &x) { value = normalize(x); }\n\n\t\
    template<typename U>\n\tstatic Type normalize(const U &x) {\n\t\tType v;\n\t\t\
    if (-mod() <= x && x < mod()) \n\t\t\tv = static_cast<Type>(x);\n\t\telse \n\t\
    \t\tv = static_cast<Type>(x % mod());\n\t\tif (v < 0) \n\t\t\tv += mod();\n\t\t\
    return v;\n\t}\n\n\tconst Type &operator()() const { return value; }\n\n\ttemplate<typename\
    \ U>\n\texplicit operator U() const { return static_cast<U>(value); }\n\n\tconstexpr\
    \ static Type mod() { return T::value; }\n\n\tModular &operator+=(const Modular\
    \ &a) { \n\t\tif ((value += a.value) >= mod()) \n\t\t\tvalue -= mod(); \n\t\t\
    return *this; \n\t}\n\n\tModular &operator-=(const Modular &a) { \n\t\tif ((value\
    \ -= a.value) < 0) \n\t\t\tvalue += mod(); \n\t\treturn *this; \n\t}\n\n\ttemplate<typename\
    \ U> \n\tModular &operator+=(const U &other) { return *this += Modular(other);\
    \ }\n\n\ttemplate<typename U> \n\tModular &operator-=(const U &other) { return\
    \ *this -= Modular(other); }\n\n\tModular &operator++() { return *this += 1; }\n\
    \n\tModular &operator--() { return *this -= 1; }\n\n\tModular operator++(int)\
    \ { \n\t\tModular result(*this); \n\t\t*this += 1; \n\t\treturn result; \n\t}\n\
    \n\tModular operator--(int) { \n\t\tModular result(*this);\n\t\t*this -= 1; \n\
    \t\treturn result; \n\t}\n\n\tModular operator-() const { return Modular(-value);\
    \ }\n\n\ttemplate<typename U = T>\n\ttypename enable_if<is_same<typename Modular<U>::Type,\
    \ int>::value, Modular>::type\n\t&operator*=(const Modular &a) {\n#ifdef _WIN32\n\
    \t\tuint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(a.value);\n\
    \t\tuint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x),\
    \ d, m;\n\t\tasm(\n\t\t\t\"divl %4; \\n\\t\"\n\t\t\t: \"=a\" (d), \"=d\" (m)\n\
    \t\t\t: \"d\" (xh), \"a\" (xl), \"r\" (mod())\n\t\t);\n\t\tvalue = m;\n#else\n\
    \t\tvalue = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(a.value));\n\
    #endif\n\t\treturn *this;\n\t}\n\t\n\ttemplate <typename U = T>\n\ttypename enable_if<is_same<typename\
    \ Modular<U>::Type, int64_t>::value, Modular>::type\n\t&operator*=(const Modular\
    \ &a) {\n\t\tint64_t q = static_cast<int64_t>(static_cast<long double>(value)\
    \ * a.value / mod());\n\t\tvalue = normalize(value * a.value - q * mod());\n\t\
    \treturn *this;\n\t}\n\n\ttemplate <typename U = T>\n\ttypename enable_if<!is_integral<typename\
    \ Modular<U>::Type>::value, Modular>::type \n\t&operator*=(const Modular &a) {\n\
    \t\tvalue = normalize(value * a.value);\n\t\treturn *this;\n\t}\n\n\tModular &operator/=(const\
    \ Modular &other) { return *this *= Modular(math::inverse(other.value, mod()));\
    \ }\n\n\ttemplate<typename U>\n\tfriend bool operator==(const Modular<U>& a, const\
    \ Modular<U>& b);\n\n\ttemplate<typename U>\n\tfriend bool operator<(const Modular<U>&\
    \ a, const Modular<U>& b);\n\n\ttemplate<typename U>\n\tfriend istream &operator>>(istream\
    \ &is, Modular<U> &a);\n\nprivate:\n\tType value;\n};\n\ntemplate<typename T>\
    \ \nbool operator==(const Modular<T> &a, const Modular<T> &b) { return a.value\
    \ == b.value; }\n\ntemplate<typename T, typename U> \nbool operator==(const Modular<T>\
    \ &a, U b) { return a == Modular<T>(b); }\n\ntemplate<typename T, typename U>\
    \ \nbool operator==(U a, const Modular<T> &b) { return Modular<T>(a) == b; }\n\
    \ntemplate<typename T> \nbool operator!=(const Modular<T> &a, const Modular<T>\
    \ &b) { return !(a == b); }\n\ntemplate<typename T, typename U> \nbool operator!=(const\
    \ Modular<T> &a, U b) { return !(a == b); }\n\ntemplate<typename T, typename U>\
    \ \nbool operator!=(U a, const Modular<T> &b) { return !(a == b); }\n\ntemplate<typename\
    \ T> \nbool operator<(const Modular<T> &a, const Modular<T> &b) { return a.value\
    \ < b.value; }\n\ntemplate<typename T> \nModular<T> operator+(const Modular<T>\
    \ &a, const Modular<T> &b) { return Modular<T>(a) += b; }\n\ntemplate<typename\
    \ T, typename U> \nModular<T> operator+(const Modular<T> &a, U b) { return Modular<T>(a)\
    \ += b; }\n\ntemplate<typename T, typename U> \nModular<T> operator+(U a, const\
    \ Modular<T> &b) { return Modular<T>(a) += b; }\n\ntemplate<typename T> \nModular<T>\
    \ operator-(const Modular<T> &a, const Modular<T> &b) { return Modular<T>(a) -=\
    \ b; }\n\ntemplate<typename T, typename U> \nModular<T> operator-(const Modular<T>\
    \ &a, U b) { return Modular<T>(a) -= b; }\n\ntemplate<typename T, typename U>\
    \ \nModular<T> operator-(U a, const Modular<T> &b) { return Modular<T>(a) -= b;\
    \ }\n\ntemplate<typename T> Modular<T> \noperator*(const Modular<T> &a, const\
    \ Modular<T> &b) { return Modular<T>(a) *= b; }\n\ntemplate<typename T, typename\
    \ U> \nModular<T> operator*(const Modular<T> &a, U b) { return Modular<T>(a) *=\
    \ b; }\n\ntemplate<typename T, typename U> \nModular<T> operator*(U a, const Modular<T>\
    \ &b) { return Modular<T>(a) *= b; }\n\ntemplate<typename T> Modular<T> \noperator/(const\
    \ Modular<T> &a, const Modular<T> &b) { return Modular<T>(a) /= b; }\n\ntemplate<typename\
    \ T, typename U> \nModular<T> operator/(const Modular<T> &a, U b) { return Modular<T>(a)\
    \ /= b; }\n\ntemplate<typename T, typename U> \nModular<T> operator/(U a, const\
    \ Modular<T> &b) { return Modular<T>(a) /= b; }\n\ntemplate<typename T, typename\
    \ U>\nModular<T> fast_pow(const Modular<T> &a, const U &b) {\n\tassert(b >= 0);\n\
    \tModular<T> x = a, res = 1;\n\tU p = b;\n\twhile (p > 0) {\n\t\tif (p & 1) \n\
    \t\t\tres *= x;\n\t\tx *= x;\n\t\tp /= 2;\n\t}\n\treturn res;\n}\n\ntemplate<typename\
    \ T>\nstring to_string(const Modular<T> &a) { return to_string(a()); }\n\ntemplate<typename\
    \ T>\nostream &operator<<(ostream &os, const Modular<T> &a) { return os << a();\
    \ }\n\ntemplate<typename T>\nistream &operator>>(istream &is, Modular<T> &a) {\n\
    \ttypename common_type<typename Modular<T>::Type, long long>::type x;\n\tis >>\
    \ x;\n\ta.value = Modular<T>::normalize(x);\n\treturn is;\n}\n\n// /*\nusing ModType\
    \ = int;\n\nstruct VarMod { static ModType value; };\n\nModType VarMod::value;\n\
    \nModType &MOD = VarMod::value;\n\nusing mint = Modular<VarMod>;\n// */\n\n/*\n\
    constexpr int MOD = HERE;\n\nusing mint = Modular<integral_constant<decay<decltype(MOD)>::type,\
    \ MOD>>;\n*/\n\n#endif\n\n#pragma endregion mint\n#line 1 \"data-structure/sparse-segment-tree.hpp\"\
    \n#pragma region sparse_segment_tree\n\ntemplate<class segment_tree_template>\n\
    class sparse_segment_tree : public segment_tree_template {\n\tusing T = typename\
    \ segment_tree_template::type;\n\tusing segment_tree_template::default_value;\n\
    \tusing segment_tree_template::merge;\n\tusing segment_tree_template::apply;\n\
    \nprotected:\n\tlong long n;\n\n\tstruct node {\n\t\tT v;\n\t\tint l, r;\n\t\t\
    node() = default;\n\t\tnode(T _v, int  _l, int _r) : v(_v), l(_l), r(_r) {}\n\t\
    };\n\n\tint root;\n\tvector<node> tree;\n\n\tint new_node() {\n\t\ttree.emplace_back(default_value,\
    \ -1, -1);\n\t\treturn tree.size() - 1;\n\t}\n\nprivate:\n\tvoid update(long long\
    \ i, T v, int t, long long tl, long long tr) {\n\t\tif (tl == tr) {\n\t\t\tapply(tree[t].v,\
    \ v);\n\t\t\treturn;\n\t\t}\n\t\tlong long tm = (tl + tr) / 2;\n\t\tif (i <= tm)\
    \ {\n\t\t\tif (tree[t].l == -1)\n\t\t\t\ttree[t].l = new_node();\n\t\t\tupdate(i,\
    \ v, tree[t].l, tl, tm);\n\t\t} else {\n\t\t\tif (tree[t].r == -1)\n\t\t\t\ttree[t].r\
    \ = new_node();\n\t\t\tupdate(i, v, tree[t].r, tm + 1, tr);\n\t\t}\n\t\ttree[t].v\
    \ = merge(tree[t].l == -1 ? default_value : tree[tree[t].l].v, \n\t\t\ttree[t].r\
    \ == -1 ? default_value : tree[tree[t].r].v);\n\t}\n\n\tT query(long long l, long\
    \ long r, int t, long long tl, long long tr) {\n\t\tif (r < tl || tr < l)\n\t\t\
    \treturn default_value;\n\t\tif (l <= tl && tr <= r)\n\t\t\treturn tree[t].v;\n\
    \t\tlong long tm = (tl + tr) / 2;\n\t\treturn merge(tree[t].l == -1 ? default_value\
    \ : query(l, r, tree[t].l, tl, tm), \n\t\t\ttree[t].r == -1 ? default_value :\
    \ query(l, r, tree[t].r, tm + 1, tr));\n\t}\n\npublic:\n\tsparse_segment_tree()\
    \ = default;\n\n\tsparse_segment_tree(long long _n) { init(_n); }\n\n\tvoid init(int\
    \ _n) {\n\t\tn = _n;\n\t\troot = new_node();\n\t}\n\n\tvoid reserve(int _n) {\
    \ tree.reserve(_n); }\n\n\tvoid clear() { tree.clear(); }\n\n\tvoid update(long\
    \ long i, T v) { update(i, v, root, 0, n - 1); }\n\n\tT query(long long l, long\
    \ long r) { return query(l, r, root, 0, n - 1); }\n};\n\n#pragma endregion sparse_segment_tree\n\
    #line 8 \"verify/sparse-segment-tree.yosupo-point-set-range-composite.test.cpp\"\
    \n\nint main() {\n\tMOD = 998244353;\n\n\tint N, Q;\n\tcin >> N >> Q;\n\n\tstruct\
    \ segment_tree_template {\n\t\tstruct node { mint a, b; };\n\t\tusing type = node;\n\
    \t\tconst type default_value = {1, 0};\n\t\tvoid apply(type &a, type b) { a =\
    \ b; }\n\t\ttype merge(type a, type b) { return {a.a * b.a, b.a * a.b + b.b};\
    \ }\n\t};\n\n\tsparse_segment_tree<segment_tree_template> sgt(N);\n\tsgt.reserve(N\
    \ * 4);\n\tfor (int i = 0; i < N; i++) {\n\t\tlong long a, b; \n\t\tcin >> a >>\
    \ b;\n\t\tsgt.update(i, {a, b});\n\t}\n\twhile (Q--) {\n\t\tint t; cin >> t;\n\
    \t\tif (t == 0) {\n\t\t\tint p; long long c, d;\n\t\t\tcin >> p >> c >> d;\n\t\
    \t\tsgt.update(p, {c, d});\n\t\t} else {\n\t\t\tint l, r; long long x;\n\t\t\t\
    cin >> l >> r >> x;\n\t\t\tauto [a, b] = sgt.query(l, r - 1);\n\t\t\tcout << a\
    \ * x + b << '\\n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"utility/mint.hpp\"\
    \n#include \"data-structure/sparse-segment-tree.hpp\"\n\nint main() {\n\tMOD =\
    \ 998244353;\n\n\tint N, Q;\n\tcin >> N >> Q;\n\n\tstruct segment_tree_template\
    \ {\n\t\tstruct node { mint a, b; };\n\t\tusing type = node;\n\t\tconst type default_value\
    \ = {1, 0};\n\t\tvoid apply(type &a, type b) { a = b; }\n\t\ttype merge(type a,\
    \ type b) { return {a.a * b.a, b.a * a.b + b.b}; }\n\t};\n\n\tsparse_segment_tree<segment_tree_template>\
    \ sgt(N);\n\tsgt.reserve(N * 4);\n\tfor (int i = 0; i < N; i++) {\n\t\tlong long\
    \ a, b; \n\t\tcin >> a >> b;\n\t\tsgt.update(i, {a, b});\n\t}\n\twhile (Q--) {\n\
    \t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\tint p; long long c, d;\n\t\t\t\
    cin >> p >> c >> d;\n\t\t\tsgt.update(p, {c, d});\n\t\t} else {\n\t\t\tint l,\
    \ r; long long x;\n\t\t\tcin >> l >> r >> x;\n\t\t\tauto [a, b] = sgt.query(l,\
    \ r - 1);\n\t\t\tcout << a * x + b << '\\n';\n\t\t}\n\t}\n}\n"
  dependsOn:
  - utility/mint.hpp
  - math/inverse.hpp
  - data-structure/sparse-segment-tree.hpp
  isVerificationFile: true
  path: verify/sparse-segment-tree.yosupo-point-set-range-composite.test.cpp
  requiredBy: []
  timestamp: '2022-05-03 13:27:25-07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/sparse-segment-tree.yosupo-point-set-range-composite.test.cpp
layout: document
redirect_from:
- /verify/verify/sparse-segment-tree.yosupo-point-set-range-composite.test.cpp
- /verify/verify/sparse-segment-tree.yosupo-point-set-range-composite.test.cpp.html
title: verify/sparse-segment-tree.yosupo-point-set-range-composite.test.cpp
---
