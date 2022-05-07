---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/sliding-window-aggregate.hpp
    title: Sliding Window Aggregate
  - icon: ':heavy_check_mark:'
    path: math/inverse.hpp
    title: Modulo Inverse
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
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"verify/sliding-window-aggregate.yosupo-queue-operate-all-composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/sliding-window-aggregate.hpp\"\
    \n#pragma region sliding_window_aggregate\n\n#ifndef SLIDING_WINDOX_AGGREGATE_HPP\n\
    #define SLIDING_WINDOX_AGGREGATE_HPP\n\ntemplate<class sliding_window_aggregate_template>\n\
    class sliding_window_aggregate : public sliding_window_aggregate_template {\n\t\
    using T = typename sliding_window_aggregate_template::type;\n\tusing sliding_window_aggregate_template::default_value;\n\
    \tusing sliding_window_aggregate_template::merge;\n\n\tstack<pair<T, T>> s1, s2;\n\
    \tT ret1, ret2;\n\npublic:\n\tsliding_window_aggregate() { init(); };\n\n\tvoid\
    \ init() { \n\t\twhile (!s1.empty())\n\t\t\ts1.pop();\n\t\twhile (!s2.empty())\n\
    \t\t\ts2.pop();\n\t\tret1 = ret2 = default_value; \n\t}\n\n\tT query() { return\
    \ merge(ret2, ret1); }\n\n\tvoid push(T x) {\n\t\tif (s2.empty()) {\n\t\t\ts2.emplace(x,\
    \ ret2 = merge(x, ret2));\n\t\t\twhile (!s1.empty()) {\n\t\t\t\tT y = s1.top().first;\
    \ s1.pop();\n\t\t\t\ts2.emplace(y, ret2 = merge(y, ret2));\n\t\t\t}\n\t\t\tret1\
    \ = default_value;\n\t\t} else {\n\t\t\ts1.emplace(x, ret1 = merge(ret1, x));\n\
    \t\t}\n\t}\n\n\tvoid pop() {\n\t\tif (s2.empty()) {\n\t\t\twhile (!s1.empty())\
    \ {\n\t\t\t\tT x = s1.top().first; s1.pop();\n\t\t\t\ts2.emplace(x, ret2 = merge(x,\
    \ ret2));\n\t\t\t}\n\t\t\tret1 = default_value;\n\t\t}\n\t\ts2.pop();\n\t\tret2\
    \ = s2.empty() ? default_value : s2.top().second;\n\t}\n\n\tint size() { return\
    \ s1.size() + s2.size(); }\t\n\n\tbool empty() { return size() == 0; }\n};\n\n\
    #endif\n\n#pragma endregion sliding_window_aggregate\n#line 1 \"math/inverse.hpp\"\
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
    \ MOD>>;\n*/\n\n#endif\n\n#pragma endregion mint\n#line 8 \"verify/sliding-window-aggregate.yosupo-queue-operate-all-composite.test.cpp\"\
    \n\nint main() {\n\tMOD = 998244353;\n\n\tint Q;\n\tcin >> Q;\n\n\tstruct sliding_window_aggregate_template\
    \ {\n\t\tusing type = pair<mint, mint>;\n\t\tconst type default_value = {1, 0};\n\
    \t\ttype merge(type a, type b) { return type{a.first * b.first, a.second * b.first\
    \ + b.second}; }\n\t};\n\n\tsliding_window_aggregate<sliding_window_aggregate_template>\
    \ swa;\n\twhile (Q--) {\n\t\tint t;\n\t\tcin >> t;\n\t\tif (t == 0) {\n\t\t\t\
    mint a, b;\n\t\t\tcin >> a >> b;\n\t\t\tswa.push(make_pair(a, b));\n\t\t} else\
    \ if (t == 1) {\n\t\t\tassert(!swa.empty());\n\t\t\tswa.pop();\n\t\t} else if\
    \ (t == 2) {\n\t\t\tmint x;\n\t\t\tcin >> x;\n\t\t\tauto [a, b] = swa.query();\n\
    \t\t\tcout << a * x + b << '\\n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/sliding-window-aggregate.hpp\"\
    \n#include \"utility/mint.hpp\"\n\nint main() {\n\tMOD = 998244353;\n\n\tint Q;\n\
    \tcin >> Q;\n\n\tstruct sliding_window_aggregate_template {\n\t\tusing type =\
    \ pair<mint, mint>;\n\t\tconst type default_value = {1, 0};\n\t\ttype merge(type\
    \ a, type b) { return type{a.first * b.first, a.second * b.first + b.second};\
    \ }\n\t};\n\n\tsliding_window_aggregate<sliding_window_aggregate_template> swa;\n\
    \twhile (Q--) {\n\t\tint t;\n\t\tcin >> t;\n\t\tif (t == 0) {\n\t\t\tmint a, b;\n\
    \t\t\tcin >> a >> b;\n\t\t\tswa.push(make_pair(a, b));\n\t\t} else if (t == 1)\
    \ {\n\t\t\tassert(!swa.empty());\n\t\t\tswa.pop();\n\t\t} else if (t == 2) {\n\
    \t\t\tmint x;\n\t\t\tcin >> x;\n\t\t\tauto [a, b] = swa.query();\n\t\t\tcout <<\
    \ a * x + b << '\\n';\n\t\t}\n\t}\n}"
  dependsOn:
  - data-structure/sliding-window-aggregate.hpp
  - utility/mint.hpp
  - math/inverse.hpp
  isVerificationFile: true
  path: verify/sliding-window-aggregate.yosupo-queue-operate-all-composite.test.cpp
  requiredBy: []
  timestamp: '2022-05-06 22:55:08-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/sliding-window-aggregate.yosupo-queue-operate-all-composite.test.cpp
layout: document
redirect_from:
- /verify/verify/sliding-window-aggregate.yosupo-queue-operate-all-composite.test.cpp
- /verify/verify/sliding-window-aggregate.yosupo-queue-operate-all-composite.test.cpp.html
title: verify/sliding-window-aggregate.yosupo-queue-operate-all-composite.test.cpp
---
