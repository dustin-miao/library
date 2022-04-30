---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/fast-walsh-hadamard-transform.hpp
    title: Fast Walsh-Hadamard Transform
  - icon: ':heavy_check_mark:'
    path: convolution/inverse-fast-walsh-hadamard-transform.hpp
    title: Inverse Fast Walsh-Hadamard Transform
  - icon: ':heavy_check_mark:'
    path: convolution/xor-convolution.hpp
    title: Xor Convolution
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
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_xor_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_xor_convolution
  bundledCode: "#line 1 \"verify/xor-convolution.yosupo-bitwise-xor-convolution.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"convolution/fast-walsh-hadamard-transform.hpp\"\
    \n#pragma region fast_walsh_hadamard_transform\n\nnamespace conv {\n\ttemplate<typename\
    \ T>\n\tvoid fast_walsh_hadamard_transform(vector<T> &a) {\n\t\tint n = a.size();\n\
    \t\tfor (int i = 1; i < n; i <<= 1) {\n\t\t\tfor (int j = 0; j < n; j++) {\n\t\
    \t\t\tif ((j & i) == 0) {\n\t\t\t\t\tT x = a[j], y = a[j | i];\n\t\t\t\t\ta[j]\
    \ = x + y;\n\t\t\t\t\ta[j | i] = x - y;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n}\n\n\
    #pragma endregion fast_walsh_hadamard_transform\n#line 2 \"convolution/inverse-fast-walsh-hadamard-transform.hpp\"\
    \n\n#pragma region inverse_fast_walsh_hadamard_transform\n\nnamespace conv {\n\
    \ttemplate<typename T>\n\tvoid inverse_fast_walsh_hadamard_transform(vector<T>\
    \ &a) {\n\t\tfast_walsh_hadamard_transform<T>(a);\n\t\tif constexpr (is_integral<T>::value)\
    \ {\n\t\t\tint n = a.size();\n\t\t\tfor (auto &x : a)\n\t\t\t\tx /= n;\n\t\t}\
    \ else {\n\t\t\tT t = T(1) / T(a.size());\n\t\t\tfor (auto &x : a)\n\t\t\t\tx\
    \ *= t;\n\t\t}\n\t}\n}\n\n#pragma endregion inverse_fast_walsh_hadamard_transform\n\
    #line 2 \"convolution/xor-convolution.hpp\"\n\n#pragma region xor_convolution\n\
    \nnamespace conv {\n\ttemplate<typename T>\n\tvector<T> xor_convolution(const\
    \ vector<T> &a, const vector<T> &b) {\n\t\tvector<T> pa(a.begin(), a.end()), pb(b.begin(),\
    \ b.end());\n\t\tint n = 1;\n\t\twhile (n < a.size() + b.size()) \n\t\t\tn <<=\
    \ 1;\n\t\tpa.resize(n), pb.resize(n);\n\t\tfast_walsh_hadamard_transform(pa);\n\
    \t\tfast_walsh_hadamard_transform(pb);\n\t\tfor (int i = 0; i < n; i++)\n\t\t\t\
    pa[i] *= pb[i];\n\t\tinverse_fast_walsh_hadamard_transform(pa);\n\t\treturn pa;\n\
    \t}\n}\n\n#pragma endregion xor_convolution\n#line 1 \"math/inverse.hpp\"\n#pragma\
    \ region modular_inverse\n\nnamespace math {\n\ttemplate <typename T>\n\tT inverse(T\
    \ a, T p) {\n\t\tT b = p, x = 1, y = 0;\n\t\twhile (a) {\n\t\t\tT q = b / a;\n\
    \t\t\tswap(a, b %= a);\n\t\t\tswap(x, y -= q * x);\n\t\t}\n\t\tassert(b == 1);\n\
    \t\treturn y < 0 ? y + p : y;\n\t}\n}\n\n#pragma endregion modular_inverse\n#line\
    \ 2 \"utility/mint.hpp\"\n\n#pragma region mint\n\ntemplate<typename T>\nclass\
    \ Modular {\npublic:\n\tusing Type = typename decay<decltype(T::value)>::type;\n\
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
    \ MOD>>;\n*/\n\n#pragma endregion mint\n#line 8 \"verify/xor-convolution.yosupo-bitwise-xor-convolution.test.cpp\"\
    \n\nint main() {\n\tMOD = 998244353;\n\n\tint N;\n\tcin >> N;\n\tvector<mint>\
    \ A(1 << N), B(1 << N);\n\tfor (auto &a : A)\n\t\tcin >> a;\n\tfor (auto &b :\
    \ B)\n\t\tcin >> b;\n\tauto C = conv::xor_convolution(A, B);\n\tfor (int i = 0;\
    \ i < (1 << N); i++)\n\t\tcout << C[i] << ' ';\n\tcout << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"convolution/xor-convolution.hpp\"\
    \n#include \"utility/mint.hpp\"\n\nint main() {\n\tMOD = 998244353;\n\n\tint N;\n\
    \tcin >> N;\n\tvector<mint> A(1 << N), B(1 << N);\n\tfor (auto &a : A)\n\t\tcin\
    \ >> a;\n\tfor (auto &b : B)\n\t\tcin >> b;\n\tauto C = conv::xor_convolution(A,\
    \ B);\n\tfor (int i = 0; i < (1 << N); i++)\n\t\tcout << C[i] << ' ';\n\tcout\
    \ << '\\n';\n}"
  dependsOn:
  - convolution/xor-convolution.hpp
  - convolution/inverse-fast-walsh-hadamard-transform.hpp
  - convolution/fast-walsh-hadamard-transform.hpp
  - utility/mint.hpp
  - math/inverse.hpp
  isVerificationFile: true
  path: verify/xor-convolution.yosupo-bitwise-xor-convolution.test.cpp
  requiredBy: []
  timestamp: '2022-04-30 10:59:16-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/xor-convolution.yosupo-bitwise-xor-convolution.test.cpp
layout: document
redirect_from:
- /verify/verify/xor-convolution.yosupo-bitwise-xor-convolution.test.cpp
- /verify/verify/xor-convolution.yosupo-bitwise-xor-convolution.test.cpp.html
title: verify/xor-convolution.yosupo-bitwise-xor-convolution.test.cpp
---
