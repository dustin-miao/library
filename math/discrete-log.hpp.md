---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/mint.hpp
    title: Modular Int
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utility/mint.hpp\"\n#pragma region mint\n\ntemplate<typename\
    \ T>\nT inverse(T a, T m) {\n\tT u = 0, v = 1;\n\twhile (a != 0) {\n\t\tT t =\
    \ m / a;\n\t\tm -= t * a; swap(a, m);\n\t\tu -= t * v; swap(u, v);\n\t}\n\tassert(m\
    \ == 1);\n\treturn u;\n}\n\ntemplate<typename T>\nclass Modular {\npublic:\n\t\
    using Type = typename decay<decltype(T::value)>::type;\n\t\n\tconstexpr Modular()\
    \ : value() {}\n\n\ttemplate<typename U>\n\tModular(const U &x) { value = normalize(x);\
    \ }\n\n\ttemplate<typename U>\n\tstatic Type normalize(const U &x) {\n\t\tType\
    \ v;\n\t\tif (-mod() <= x && x < mod()) \n\t\t\tv = static_cast<Type>(x);\n\t\t\
    else \n\t\t\tv = static_cast<Type>(x % mod());\n\t\tif (v < 0) \n\t\t\tv += mod();\n\
    \t\treturn v;\n\t}\n\n\tconst Type &operator()() const { return value; }\n\n\t\
    template<typename U>\n\texplicit operator U() const { return static_cast<U>(value);\
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
    \tModular<T> x = a, res = 1;\n\tU p = b;\n\twhile (p > 0) {\n\t\tif (p & 1) \n\
    \t\t\tres *= x;\n\t\tx *= x;\n\t\tp /= 2;\n\t}\n\treturn res;\n}\n\ntemplate<typename\
    \ T>\nstring to_string(const Modular<T> &a) { return to_string(a()); }\n\ntemplate<typename\
    \ T>\nostream &operator<<(ostream &os, const Modular<T> &a) { return os << a();\
    \ }\n\ntemplate<typename T>\nistream &operator>>(istream &is, Modular<T> &a) {\n\
    \ttypename common_type<typename Modular<T>::Type, long long>::type x;\n\tis >>\
    \ x;\n\ta.value = Modular<T>::normalize(x);\n\treturn is;\n}\n\n// /*\nusing ModType\
    \ = int;\n\nstruct VarMod { static ModType value; };\n\nModType VarMod::value;\n\
    \nModType &MOD = VarMod::value;\n\nusing mint = Modular<VarMod>;\n// */\n\n/*\n\
    constexpr int MOD = @@HERE@@;\n\nusing mint = Modular<integral_constant<decay<decltype(MOD)>::type,\
    \ MOD>>;\n*/\n\n#pragma endregion mint\n#line 2 \"math/discrete-log.hpp\"\n\n\
    namespace math {\n\tint discrete_log(mint a, mint b) {\n\t\tint n = sqrt(MOD)\
    \ + 1;\n\n\t\tmint an = fast_pow(a, n);\n\t\tmap<mint, int> vals;\n\t\tmint cur\
    \ = b;\n\t\tfor (int q = 0; q <= n; q++) { \n\t\t\tvals[cur] = q;\n\t\t\tcur *=\
    \ a;\n\t\t}\n\t\tcur = 1;\n\t\tfor (int p = 1; p <= n; p++) {\n\t\t\tcur *= int(an);\n\
    \t\t\tif (vals.find(cur) != vals.end()) \n\t\t\t\treturn int(n * p - vals[cur]);\n\
    \t\t}\n\t\treturn -1;\n\t}\n}\n"
  code: "#include \"utility/mint.hpp\"\n\nnamespace math {\n\tint discrete_log(mint\
    \ a, mint b) {\n\t\tint n = sqrt(MOD) + 1;\n\n\t\tmint an = fast_pow(a, n);\n\t\
    \tmap<mint, int> vals;\n\t\tmint cur = b;\n\t\tfor (int q = 0; q <= n; q++) {\
    \ \n\t\t\tvals[cur] = q;\n\t\t\tcur *= a;\n\t\t}\n\t\tcur = 1;\n\t\tfor (int p\
    \ = 1; p <= n; p++) {\n\t\t\tcur *= int(an);\n\t\t\tif (vals.find(cur) != vals.end())\
    \ \n\t\t\t\treturn int(n * p - vals[cur]);\n\t\t}\n\t\treturn -1;\n\t}\n}"
  dependsOn:
  - utility/mint.hpp
  isVerificationFile: false
  path: math/discrete-log.hpp
  requiredBy: []
  timestamp: '2022-04-08 17:03:50-07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/discrete-log.hpp
layout: document
title: Discrete Logarithm
---

## Discrete Logarithm