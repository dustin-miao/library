---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/general-segment-tree.hpp
    title: General Segment Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"verify/general-segment-tree.yosupo-point-set-range-composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"utility/mint.hpp\"\
    \ntemplate<typename T>\nT inverse(T a, T m) {\n\tT u = 0, v = 1;\n\twhile (a !=\
    \ 0) {\n\t\tT t = m / a;\n\t\tm -= t * a; swap(a, m);\n\t\tu -= t * v; swap(u,\
    \ v);\n\t}\n\tassert(m == 1);\n\treturn u;\n}\n\ntemplate<typename T>\nclass Modular\
    \ {\npublic:\n\tusing Type = typename decay<decltype(T::value)>::type;\n\t\n\t\
    constexpr Modular() : value() {}\n\n\ttemplate<typename U>\n\tModular(const U\
    \ &x) { value = normalize(x); }\n\n\ttemplate<typename U>\n\tstatic Type normalize(const\
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
    \ Modular<U>::Type, int>::value, Modular>::type\n\t&operator*=(const Modular&\
    \ rhs) {\n#ifdef _WIN32\n\t\tuint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);\n\
    \t\tuint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x),\
    \ d, m;\n\t\tasm(\n\t\t\t\"divl %4; \\n\\t\"\n\t\t\t: \"=a\" (d), \"=d\" (m)\n\
    \t\t\t: \"d\" (xh), \"a\" (xl), \"r\" (mod())\n\t\t);\n\t\tvalue = m;\n#else\n\
    \t\tvalue = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));\n\
    #endif\n\t\treturn *this;\n\t}\n\t\n\ttemplate <typename U = T>\n\ttypename enable_if<is_same<typename\
    \ Modular<U>::Type, int64_t>::value, Modular>::type\n\t&operator*=(const Modular&\
    \ rhs) {\n\t\tint64_t q = static_cast<int64_t>(static_cast<long double>(value)\
    \ * rhs.value / mod());\n\t\tvalue = normalize(value * rhs.value - q * mod());\n\
    \t\treturn *this;\n\t}\n\n\ttemplate <typename U = T>\n\ttypename enable_if<!is_integral<typename\
    \ Modular<U>::Type>::value, Modular>::type \n\t&operator*=(const Modular& rhs)\
    \ {\n\t\tvalue = normalize(value * rhs.value);\n\t\treturn *this;\n\t}\n\n\tModular\
    \ &operator/=(const Modular &other) { return *this *= Modular(inverse(other.value,\
    \ mod())); }\n\n\ttemplate<typename U>\n\tfriend bool operator==(const Modular<U>&\
    \ a, const Modular<U>& b);\n\n\ttemplate<typename U>\n\tfriend bool operator<(const\
    \ Modular<U>& a, const Modular<U>& b);\n\n\ttemplate<typename U>\n\tfriend istream\
    \ &operator>>(istream &is, Modular<U> &a);\n\nprivate:\n\tType value;\n};\n\n\
    template<typename T> \nbool operator==(const Modular<T> &a, const Modular<T> &b)\
    \ { return a.value == b.value; }\n\ntemplate<typename T, typename U> \nbool operator==(const\
    \ Modular<T> &a, U b) { return a == Modular<T>(b); }\n\ntemplate<typename T, typename\
    \ U> \nbool operator==(U a, const Modular<T> &b) { return Modular<T>(a) == b;\
    \ }\n\ntemplate<typename T> \nbool operator!=(const Modular<T> &a, const Modular<T>\
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
    \ x;\n\ta.value = Modular<T>::normalize(x);\n\treturn is;\n}\n\nusing ModType\
    \ = int;\n\nstruct VarMod { static ModType value; };\n\nModType VarMod::value;\n\
    \nModType &MOD = VarMod::value;\n\nusing mint = Modular<VarMod>;\n\n/*\nconstexpr\
    \ int MOD = @@HERE@@;\n\nusing mint = Modular<integral_constant<decay<decltype(MOD)>::type,\
    \ md>>;\n*/\n#line 1 \"data-structure/general-segment-tree.hpp\"\ntemplate<class\
    \ Base>\nclass Segtree : public Base {\n\tusing T = typename Base::T;\n\tusing\
    \ Base::dval;\n\tusing Base::merge;\n\tusing Base::apply;\n\nprotected:\n\tsize_t\
    \ n;\n\tvector<T> tree;\n\npublic:\n\tSegtree() = default;\n\n\tSegtree(size_t\
    \ _n) { init(_n); }\n\n\tvoid init(size_t _n) {\n\t\tfor (n = 1; n < _n; n *=\
    \ 2);\n\t\ttree.assign(n * 2, dval);\n\t}\n\n\tvoid update(int i, T v) {\n\t\t\
    for (apply(tree[i += n], v); i >>= 1;)\n\t\t\ttree[i] = merge(tree[i << 1], tree[i\
    \ << 1 | 1]);\n\t}\n\n\tT query(int l, int r) {\n\t\tT lret = dval, rret = dval;\n\
    \t\tfor (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {\n\t\t\tif (l & 1) lret\
    \ = merge(lret, tree[l++]);\n\t\t\tif (r & 1) rret = merge(tree[--r], rret);\n\
    \t\t}\n\t\treturn merge(lret, rret);\n\t}\n\n\tT operator[](int i) { return tree[i\
    \ += n]; }\n};\n#line 8 \"verify/general-segment-tree.yosupo-point-set-range-composite.test.cpp\"\
    \n\nint main() {\n\tMOD = 998244353;\n\n\tint N, Q;\n\tcin >> N >> Q;\n\n\tstruct\
    \ stinfo {\n\t\tstruct node { mint a, b; };\n\t\tusing T = node;\n\t\tconst T\
    \ dval = {1, 0};\n\t\tvoid apply(T &a, T b) { a = b; }\n\t\tT merge(T a, T b)\
    \ { return {a.a * b.a, b.a * a.b + b.b}; }\n\t};\n\n\tSegtree<stinfo> sgt(N);\n\
    \tfor (int i = 0; i < N; i++) {\n\t\tlong long a, b; \n\t\tcin >> a >> b;\n\t\t\
    sgt.update(i, {a, b});\n\t}\n\n\twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t\
    \ == 0) {\n\t\t\tint p; long long c, d;\n\t\t\tcin >> p >> c >> d;\n\t\t\tsgt.update(p,\
    \ {c, d});\n\t\t} else {\n\t\t\tint l, r; long long x;\n\t\t\tcin >> l >> r >>\
    \ x;\n\t\t\tauto [a, b] = sgt.query(l, r - 1);\n\t\t\tcout << a * x + b << '\\\
    n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"utility/mint.hpp\"\
    \n#include \"data-structure/general-segment-tree.hpp\"\n\nint main() {\n\tMOD\
    \ = 998244353;\n\n\tint N, Q;\n\tcin >> N >> Q;\n\n\tstruct stinfo {\n\t\tstruct\
    \ node { mint a, b; };\n\t\tusing T = node;\n\t\tconst T dval = {1, 0};\n\t\t\
    void apply(T &a, T b) { a = b; }\n\t\tT merge(T a, T b) { return {a.a * b.a, b.a\
    \ * a.b + b.b}; }\n\t};\n\n\tSegtree<stinfo> sgt(N);\n\tfor (int i = 0; i < N;\
    \ i++) {\n\t\tlong long a, b; \n\t\tcin >> a >> b;\n\t\tsgt.update(i, {a, b});\n\
    \t}\n\n\twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\tint p;\
    \ long long c, d;\n\t\t\tcin >> p >> c >> d;\n\t\t\tsgt.update(p, {c, d});\n\t\
    \t} else {\n\t\t\tint l, r; long long x;\n\t\t\tcin >> l >> r >> x;\n\t\t\tauto\
    \ [a, b] = sgt.query(l, r - 1);\n\t\t\tcout << a * x + b << '\\n';\n\t\t}\n\t\
    }\n}"
  dependsOn:
  - utility/mint.hpp
  - data-structure/general-segment-tree.hpp
  isVerificationFile: true
  path: verify/general-segment-tree.yosupo-point-set-range-composite.test.cpp
  requiredBy: []
  timestamp: '2022-04-02 13:34:24-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/general-segment-tree.yosupo-point-set-range-composite.test.cpp
layout: document
redirect_from:
- /verify/verify/general-segment-tree.yosupo-point-set-range-composite.test.cpp
- /verify/verify/general-segment-tree.yosupo-point-set-range-composite.test.cpp.html
title: verify/general-segment-tree.yosupo-point-set-range-composite.test.cpp
---
