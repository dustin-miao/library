---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/lazy-segment-tree.hpp
    title: Lazy Segment Tree
  - icon: ':heavy_check_mark:'
    path: utility/mint.hpp
    title: Modular Int
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"verify/lazy-segment-tree.yosupo-range-affine-range-sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"utility/mint.hpp\"\
    \n#pragma region mint\n\ntemplate<typename T>\nT inverse(T a, T m) {\n\tT u =\
    \ 0, v = 1;\n\twhile (a != 0) {\n\t\tT t = m / a;\n\t\tm -= t * a; swap(a, m);\n\
    \t\tu -= t * v; swap(u, v);\n\t}\n\tassert(m == 1);\n\treturn u;\n}\n\ntemplate<typename\
    \ T>\nclass Modular {\npublic:\n\tusing Type = typename decay<decltype(T::value)>::type;\n\
    \t\n\tconstexpr Modular() : value() {}\n\n\ttemplate<typename U>\n\tModular(const\
    \ U &x) { value = normalize(x); }\n\n\ttemplate<typename U>\n\tstatic Type normalize(const\
    \ U &x) {\n\t\tType v;\n\t\tif (-mod() <= x && x < mod()) \n\t\t\tv = static_cast<Type>(x);\n\
    \t\telse \n\t\t\tv = static_cast<Type>(x % mod());\n\t\tif (v < 0) \n\t\t\tv +=\
    \ mod();\n\t\treturn v;\n\t}\n\n\tconst Type &operator()() const { return value;\
    \ }\n\n\ttemplate<typename U>\n\texplicit operator U() const { return static_cast<U>(value);\
    \ }\n\n\tconstexpr static Type mod() { return T::value; }\n\n\tModular &operator+=(const\
    \ Modular &a) { \n\t\tif ((value += a.value) >= mod()) \n\t\t\tvalue -= mod();\
    \ \n\t\treturn *this; \n\t}\n\n\tModular &operator-=(const Modular &a) { \n\t\t\
    if ((value -= a.value) < 0) \n\t\t\tvalue += mod(); \n\t\treturn *this; \n\t}\n\
    \n\ttemplate<typename U> \n\tModular &operator+=(const U &other) { return *this\
    \ += Modular(other); }\n\n\ttemplate<typename U> \n\tModular &operator-=(const\
    \ U &other) { return *this -= Modular(other); }\n\n\tModular &operator++() { return\
    \ *this += 1; }\n\n\tModular &operator--() { return *this -= 1; }\n\n\tModular\
    \ operator++(int) { \n\t\tModular result(*this); \n\t\t*this += 1; \n\t\treturn\
    \ result; \n\t}\n\n\tModular operator--(int) { \n\t\tModular result(*this);\n\t\
    \t*this -= 1; \n\t\treturn result; \n\t}\n\n\tModular operator-() const { return\
    \ Modular(-value); }\n\n\ttemplate<typename U = T>\n\ttypename enable_if<is_same<typename\
    \ Modular<U>::Type, int>::value, Modular>::type\n\t&operator*=(const Modular &a)\
    \ {\n#ifdef _WIN32\n\t\tuint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(a.value);\n\
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
    \ Modular &other) { return *this *= Modular(inverse(other.value, mod())); }\n\n\
    \ttemplate<typename U>\n\tfriend bool operator==(const Modular<U>& a, const Modular<U>&\
    \ b);\n\n\ttemplate<typename U>\n\tfriend bool operator<(const Modular<U>& a,\
    \ const Modular<U>& b);\n\n\ttemplate<typename U>\n\tfriend istream &operator>>(istream\
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
    \tModular<T> x = a, res = 1;\n\tU p = b;\n\twhile (p > 0) {\n\t\tif (p & 1) res\
    \ *= x;\n\t\tx *= x;\n\t\tp >>= 1;\n\t}\n\treturn res;\n}\n\ntemplate<typename\
    \ T>\nstring to_string(const Modular<T> &a) { return to_string(a()); }\n\ntemplate<typename\
    \ T>\nostream &operator<<(ostream &os, const Modular<T> &a) { return os << a();\
    \ }\n\ntemplate<typename T>\nistream &operator>>(istream &is, Modular<T> &a) {\n\
    \ttypename common_type<typename Modular<T>::Type, long long>::type x;\n\tis >>\
    \ x;\n\ta.value = Modular<T>::normalize(x);\n\treturn is;\n}\n\n// /*\nusing ModType\
    \ = int;\n\nstruct VarMod { static ModType value; };\n\nModType VarMod::value;\n\
    \nModType &MOD = VarMod::value;\n\nusing mint = Modular<VarMod>;\n// */\n\n/*\n\
    constexpr int MOD = @@HERE@@;\n\nusing mint = Modular<integral_constant<decay<decltype(MOD)>::type,\
    \ MOD>>;\n*/\n\n#pragma endregion mint\n#line 1 \"data-structure/lazy-segment-tree.hpp\"\
    \ntemplate<class Base>\nclass Segtree : public Base {\n\tusing T = typename Base::T;\n\
    \tusing L = typename Base::L;\n\tusing Base::Tdval;\n\tusing Base::Ldval;\n\t\
    using Base::merge;\n\tusing Base::apply;\n\nprotected:\n\tsize_t n;\n\tvector<T>\
    \ tree;\n\tvector<L> lazy;\n\nprivate:\n\tvoid pushdown(int t, int tl, int tr)\
    \ {\n\t\tif (lazy[t] == Ldval)\n\t\t\treturn;\n\t\tint tm = (tl + tr) / 2;\n\t\
    \tapply(tree[t * 2], lazy[t * 2], lazy[t], tl, tm);\n\t\tapply(tree[t * 2 + 1],\
    \ lazy[t * 2 + 1], lazy[t], tm + 1, tr);\n\t\tlazy[t] = Ldval;\n\t}\n\n\tvoid\
    \ update(int l, int r, L v, int t, int tl, int tr) {\n\t\tif (r < tl || tr < l)\n\
    \t\t\treturn;\n\t\tif (l <= tl && tr <= r) {\n\t\t\tapply(tree[t], lazy[t], v,\
    \ tl, tr);\n\t\t\treturn;\n\t\t}\n\t\tpushdown(t, tl, tr);\n\t\tint tm = (tl +\
    \ tr) / 2;\n\t\tupdate(l, r, v, t * 2, tl, tm);\n\t\tupdate(l, r, v, t * 2 + 1,\
    \ tm + 1, tr);\n\t\ttree[t] = merge(tree[t * 2], tree[t * 2 + 1]);\n\t}\n\n\t\
    T query(int l, int r, int t, int tl, int tr) {\n\t\tif (r < tl || tr < l)\n\t\t\
    \treturn Tdval;\n\t\tif (l <= tl && tr <= r)\n\t\t\treturn tree[t];\n\t\tpushdown(t,\
    \ tl, tr);\n\t\tint tm = (tl + tr) / 2;\n\t\treturn merge(query(l, r, t * 2, tl,\
    \ tm), query(l, r, t * 2 + 1, tm + 1, tr));\n\t}\n\npublic:\n\tSegtree() = default;\n\
    \n\tSegtree(size_t _n) { init(_n); }\n\n\tvoid init(size_t _n) {\n\t\tn = _n;\n\
    \t\ttree.assign(4 * n, Tdval);\n\t\tlazy.assign(4 * n, Ldval);\n\t}\n\n\tvoid\
    \ update(int l, int r, L v) { update(l, r, v, 1, 0, n - 1); }\n\n\tT query(int\
    \ l, int r) { return query(l, r, 1, 0, n - 1); }\n};\n#line 8 \"verify/lazy-segment-tree.yosupo-range-affine-range-sum.test.cpp\"\
    \n\nint main() {\n\tMOD = 998244353;\n\n\tint N, Q; \n\tcin >> N >> Q;\n\t\n\t\
    struct stinfo {\n\t\tusing T = mint;\n\t\tusing L = pair<mint, mint>;\n\n\t\t\
    const T Tdval = 0;\n\t\tconst L Ldval = {1, 0};\n\n\t\tvoid apply(T &a, L &b,\
    \ L c, int l, int r) {\n\t\t\ta = c.first * a + c.second * (r - l + 1);\n\t\t\t\
    b = {c.first * b.first, c.first * b.second + c.second};\n\t\t}\t\n\n\t\tT merge(T\
    \ a, T b) { return a + b; }\n\t};\n\t\n\tSegtree<stinfo> sgt(N);\n\tfor (int i\
    \ = 0; i < N; i++) {\n\t\tlong long a; cin >> a;\n\t\tsgt.update(i, i, {1, a});\n\
    \t}\n\twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\tint l, r;\
    \ long long b, c;\n\t\t\tcin >> l >> r >> b >> c;\n\t\t\tsgt.update(l, r - 1,\
    \ {b, c});\n\t\t} else {\n\t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\t\t\tcout <<\
    \ sgt.query(l, r - 1) << '\\n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"utility/mint.hpp\"\
    \n#include \"data-structure/lazy-segment-tree.hpp\"\n\nint main() {\n\tMOD = 998244353;\n\
    \n\tint N, Q; \n\tcin >> N >> Q;\n\t\n\tstruct stinfo {\n\t\tusing T = mint;\n\
    \t\tusing L = pair<mint, mint>;\n\n\t\tconst T Tdval = 0;\n\t\tconst L Ldval =\
    \ {1, 0};\n\n\t\tvoid apply(T &a, L &b, L c, int l, int r) {\n\t\t\ta = c.first\
    \ * a + c.second * (r - l + 1);\n\t\t\tb = {c.first * b.first, c.first * b.second\
    \ + c.second};\n\t\t}\t\n\n\t\tT merge(T a, T b) { return a + b; }\n\t};\n\t\n\
    \tSegtree<stinfo> sgt(N);\n\tfor (int i = 0; i < N; i++) {\n\t\tlong long a; cin\
    \ >> a;\n\t\tsgt.update(i, i, {1, a});\n\t}\n\twhile (Q--) {\n\t\tint t; cin >>\
    \ t;\n\t\tif (t == 0) {\n\t\t\tint l, r; long long b, c;\n\t\t\tcin >> l >> r\
    \ >> b >> c;\n\t\t\tsgt.update(l, r - 1, {b, c});\n\t\t} else {\n\t\t\tint l,\
    \ r;\n\t\t\tcin >> l >> r;\n\t\t\tcout << sgt.query(l, r - 1) << '\\n';\n\t\t\
    }\n\t}\n}"
  dependsOn:
  - utility/mint.hpp
  - data-structure/lazy-segment-tree.hpp
  isVerificationFile: true
  path: verify/lazy-segment-tree.yosupo-range-affine-range-sum.test.cpp
  requiredBy: []
  timestamp: '2022-04-08 11:14:33-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/lazy-segment-tree.yosupo-range-affine-range-sum.test.cpp
layout: document
redirect_from:
- /verify/verify/lazy-segment-tree.yosupo-range-affine-range-sum.test.cpp
- /verify/verify/lazy-segment-tree.yosupo-range-affine-range-sum.test.cpp.html
title: verify/lazy-segment-tree.yosupo-range-affine-range-sum.test.cpp
---
