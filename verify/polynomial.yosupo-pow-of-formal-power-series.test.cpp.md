---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: poly/polynomial.hpp
    title: Polynomial
  - icon: ':question:'
    path: utility/pi.hpp
    title: Pi
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/pow_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/pow_of_formal_power_series
  bundledCode: "#line 1 \"verify/polynomial.yosupo-pow-of-formal-power-series.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/pow_of_formal_power_series\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"utility/pi.hpp\"\
    \n#pragma region Pi\n\n#ifndef PI_HPP\n#define PI_HPP\n\nconst double PI = acos(-1);\n\
    \n#endif\n\n#pragma endregion Pi\n#line 2 \"poly/polynomial.hpp\"\n\n#pragma region\
    \ polynomial\n\n#ifndef POLYNOMIAL_HPP\n#define POLYNOMIAL_HPP\n\nnamespace poly\
    \ {\n\tnamespace polynomial_internal {\n\t\tconst int MAX_N = 1 << 24; \t\t//\
    \ maximum size of polynomial, power of 2\n\t\tconst int MAX_B = 250; \t\t\t//\
    \ maximum size to run brute force\n\n\t\tmt19937 mst(chrono::steady_clock::now().time_since_epoch().count());\n\
    \n\t\ttemplate<typename T, typename U>\n\t\tT fast_pow(T a, U b) {\n\t\t\tT ret\
    \ = T(1);\n\t\t\tfor (; b; b /= 2) {\n\t\t\t\tif (b & 1)\n\t\t\t\t\tret = ret\
    \ * a;\n\t\t\t\ta = a * a;\n\t\t\t}\n\t\t\treturn ret;\n\t\t}\n\n\t\ttemplate<int\
    \ mod>\n\t\tclass Modular {\n\t\t\tint value;\n\n\t\tpublic:\n\t\t\tconstexpr\
    \ Modular(): value(0) {}\n\n\t\t\tconstexpr Modular(const long long &x): value(x\
    \ % mod) { if (value < 0) value += mod; }\n\n\t\t\tModular inv() const { return\
    \ fast_pow(*this, mod - 2); }\n\n\t\t\tModular operator-() const { return value\
    \ ? mod - value : 0; }\n\n\t\t\tModular operator*(const Modular &t) const { return\
    \ (long long)value * t.value % mod; }\n\n\t\t\tModular operator/(const Modular\
    \ &t) const { return *this * t.inv(); }\n\n\t\t\tModular operator+=(const Modular\
    \ &t) {\n\t\t\t\tvalue += t.value;\n\t\t\t\tif (value >= mod)\n\t\t\t\t\tvalue\
    \ -= mod;\n\t\t\t\treturn *this;\n\t\t\t}\n\n\t\t\tModular operator-=(const Modular\
    \ &t) {\n\t\t\t\tvalue -= t.value;\n\t\t\t\tif (value < 0)\n\t\t\t\t\tvalue +=\
    \ mod;\n\t\t\t\treturn *this;\n\t\t\t}\n\n\t\t\tModular operator+(const Modular\
    \ &t) const { return Modular(*this) += t; }\n\n\t\t\tModular operator-(const Modular\
    \ &t) const { return Modular(*this) -= t; }\n\n\t\t\tModular operator*=(const\
    \ Modular &t) { return *this = *this * t; }\n\n\t\t\tModular operator/=(const\
    \ Modular &t) { return *this = *this / t; }\n\n\t\t\tbool operator==(const Modular\
    \ &t) const { return value == t.value; }\n\n\t\t\tbool operator!=(const Modular\
    \ &t) const { return value != t.value; }\n\n\t\t\texplicit operator int() const\
    \ { return value; }\n\n\t\t\tlong long rem() const { return 2 * value > mod ?\
    \ value - mod : value; }\n\n\t\t\t/*\n\t\t\toptional<Modular> sqrt() const {\n\
    \t\t\t\tstatic Modular y;\n\n\t\t\t\ty = *this;\n\t\t\t\tif (value == 0)\n\t\t\
    \t\t\treturn 0;\n\t\t\t\telse if (fast_pow(y, (mod - 1) / 2) != Modular(1))\n\t\
    \t\t\t\treturn nullopt;\n\t\t\t\twhile (true) {\n\t\t\t\t\tModular z = mst();\n\
    \t\t\t\t\tif (z * z == *this)\n\t\t\t\t\t\treturn z;\n\n\t\t\t\t\tstruct lin {\n\
    \t\t\t\t\t\tModular a, b;\n\n\t\t\t\t\t\tlin(Modular a, Modular b = 0): a(a),\
    \ b(b) {}\n\n\t\t\t\t\t\tlin operator*(const lin& t) {\n\t\t\t\t\t\t\treturn {\n\
    \t\t\t\t\t\t\t\ta * t.a + b * t.b * y,\n\t\t\t\t\t\t\t\ta * t.b + b * t.a\n\t\t\
    \t\t\t\t\t};\n\t\t\t\t\t\t}\n\t\t\t\t\t} x(z, 1);\n\n\t\t\t\t\tx = fast_pow(x,\
    \ (mod - 1) / 2);\n\t\t\t\t\tif (x.b != Modular(0))\n\t\t\t\t\t\treturn x.b.inv();\n\
    \t\t\t\t}\n\t\t\t}*/\n\n\t\t\toptional<Modular> sqrt() const {\n\t\t\t\tassert(0\
    \ <= value && value < mod);\n\t\t\t\tif (value < 2) \n\t\t\t\t\treturn value;\n\
    \t\t\t\tif (fast_pow(Modular(value), (mod - 1) >> 1) != 1) \n\t\t\t\t\treturn\
    \ nullopt;\n\t\t\t\tModular b = 1;\n\t\t\t\tfor (; fast_pow(b, (mod - 1) >> 1)\
    \ == 1; b += 1);\n\t\t\t\tint m = mod - 1, e = 0;\n\t\t\t\tfor (; m % 2 == 0;\
    \ m >>= 1, e++);\n\t\t\t\tModular x = fast_pow(Modular(value), (m - 1) >> 1);\n\
    \t\t\t\tModular y = Modular(value) * x * x;\n\t\t\t\tModular z = fast_pow(Modular(b),\
    \ m);\n\t\t\t\tx *= value;\n\t\t\t\twhile (y != 1) {\n\t\t\t\t\tint j = 0;\n\t\
    \t\t\t\tModular t = y;\n\t\t\t\t\twhile (t != Modular(1)) {\n\t\t\t\t\t\tj +=\
    \ 1;\n\t\t\t\t\t\tt *= t;\n\t\t\t\t\t}\n\t\t\t\t\tz = fast_pow(z, 1 << (e - j\
    \ - 1));\n\t\t\t\t\tx *= z;\n\t\t\t\t\tz *= z;\n\t\t\t\t\ty *= z;\n\t\t\t\t\t\
    e = j;\n\t\t\t\t}\n\t\t\t\treturn int(x);\n\t\t\t}\n\n\t\t\ttemplate<int _mod>\n\
    \t\t\tfriend istream &operator>>(istream &is, Modular<_mod> &t);\n\t\t};\n\n\t\
    \ttemplate<int mod>\n\t\tistream &operator>>(istream &is, Modular<mod> &t) {\n\
    \t\t\tint x;\n\t\t\tis >> x;\n\t\t\tt.value = x % mod;\n\t\t\treturn is;\n\t\t\
    }\n\n\t\ttemplate<int mod>\n\t\tostream &operator<<(ostream &os, const Modular<mod>\
    \ &t) {\n\t\t\treturn os << int(t);\n\t\t}\n\n\t\ttemplate<typename T>\n\t\tT\
    \ fact(int n) {\n\t\t\tstatic array<T, MAX_N> F;\n\t\t\tstatic bool init = false;\n\
    \n\t\t\tif (!init) {\n\t\t\t\tF[0] = T(1);\n\t\t\t\tfor (int i = 1; i < MAX_N;\
    \ i++)\n\t\t\t\t\tF[i] = F[i - 1] * T(i);\n\t\t\t\tinit = true;\n\t\t\t}\n\t\t\
    \treturn F[n];\n\t\t}\n\n\t\ttemplate<typename T>\n\t\tT rfact(int n) {\n\t\t\t\
    static array<T, MAX_N> F;\n\t\t\tstatic bool init = false;\n\n\t\t\tif (!init)\
    \ {\n\t\t\t\tF[MAX_N - 1] = T(1) / fact<T>(MAX_N - 1);\n\t\t\t\tfor (int i = MAX_N\
    \ - 2; i >= 0; i--)\n\t\t\t\t\tF[i] = F[i + 1] * T(i + 1);\n\t\t\t\tinit = true;\n\
    \t\t\t}\n\t\t\treturn F[n];\n\t\t}\n\n\t\tnamespace fast_fourier_transform {\n\
    \t\t\tusing type = double;\n\n\t\t\tcomplex<double> w[MAX_N];\n\t\t\tint bitr[MAX_N];\n\
    \n\t\t\tvoid init_fast_fourier_transform() {\n\t\t\t\tstatic bool init = false;\n\
    \n\t\t\t\tif (!init) {\n\t\t\t\t\tfor (int i = 1; i < MAX_N; i *= 2) {\n\t\t\t\
    \t\t\tint ti = i / 2;\n\t\t\t\t\t\tfor (int j = 0; j < i; j++) {\n\t\t\t\t\t\t\
    \ttype ang = PI * j / i;\n\t\t\t\t\t\t\tw[i + j] = complex<type>(cos(ang), sin(ang));\n\
    \t\t\t\t\t\t\tif (ti)\n\t\t\t\t\t\t\t\tbitr[i + j] = 2 * bitr[ti + j % ti] + (j\
    \ >= ti);\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t\tinit = true;\n\t\t\t\t}\n\t\t\
    \t}\n\n\t\t\tvoid fast_fourier_transform(auto &a, int n) {\n\t\t\t\tinit_fast_fourier_transform();\n\
    \t\t\t\tif (n == 1)\n\t\t\t\t\treturn;\n\t\t\t\tint hn = n / 2;\n\t\t\t\tfor (int\
    \ i = 0; i < n; i++) {\n\t\t\t\t\tint ti = 2 * bitr[hn + i % hn] + (i > hn);\n\
    \t\t\t\t\tif (i < ti)\n\t\t\t\t\t\tswap(a[i], a[ti]);\n\t\t\t\t}\n\t\t\t\tfor\
    \ (int i = 1; i < n; i *= 2) {\n\t\t\t\t\tfor (int j = 0; j < n; j += 2 * i) {\n\
    \t\t\t\t\t\tfor (int k = j; k < j + i; k++) {\n\t\t\t\t\t\t\tauto t = a[k + i]\
    \ * w[i + k - j];\n\t\t\t\t\t\t\ta[k + i] = a[k] - t;\n\t\t\t\t\t\t\ta[k] += t;\n\
    \t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\n\t\t\tvoid slow_polynomial_multiply(vector<auto>\
    \ &a, const vector<auto> &b) {\n\t\t\t\tif (a.empty() || b.empty()) {\n\t\t\t\t\
    \ta.clear();\n\t\t\t\t} else {\n\t\t\t\t\tint n = a.size();\n\t\t\t\t\tint m =\
    \ b.size();\n\t\t\t\t\ta.resize(n + m - 1);\n\t\t\t\t\tfor (int k = n + m - 2;\
    \ k >= 0; k--) {\n\t\t\t\t\t\ta[k] *= b[0];\n\t\t\t\t\t\tfor (int j = max(k -\
    \ n + 1, 1); j < min(k + 1, m); j++)\n\t\t\t\t\t\t\ta[k] += a[k - j] * b[j];\n\
    \t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\n\t\t\ttemplate<int mod>\n\t\t\tclass discrete_fourier_transform\
    \ {\n\t\t\t\tstatic constexpr int split = 1 << 15;\n\t\t\t\tvector<complex<type>>\
    \ A;\n\n\t\t\tpublic:\n\t\t\t\tdiscrete_fourier_transform(vector<Modular<mod>>\
    \ const &a, int n): A(n) {\n\t\t\t\t\tfor (int i = 0; i < min(n, (int)a.size());\
    \ i++)\n\t\t\t\t\t\tA[i] = complex<type>(a[i].rem() % split, a[i].rem() / split);\n\
    \t\t\t\t\tif (n)\n\t\t\t\t\t\tfast_fourier_transform(A, n);\n\t\t\t\t}\n\n\t\t\
    \t\tauto operator*(discrete_fourier_transform const &B) {\n\t\t\t\t\tassert(A.size()\
    \ == B.A.size());\n\t\t\t\t\tint n = A.size();\n\t\t\t\t\tif (n == 0)\n\t\t\t\t\
    \t\treturn vector<Modular<mod>>();\n\n\t\t\t\t\tvector<complex<type>> C(n), D(n);\n\
    \t\t\t\t\tfor (int i = 0; i < n; i++) {\n\t\t\t\t\t\tC[i] = A[i] * (B[i] + conj(B[(n\
    \ - i) % n]));\n\t\t\t\t\t\tD[i] = A[i] * (B[i] - conj(B[(n - i) % n]));\n\t\t\
    \t\t\t}\n\n\t\t\t\t\tfast_fourier_transform(C, n);\n\t\t\t\t\tfast_fourier_transform(D,\
    \ n);\n\t\t\t\t\treverse(C.begin() + 1, C.end());\n\t\t\t\t\treverse(D.begin()\
    \ + 1, D.end());\n\n\t\t\t\t\tint t = 2 * n;\n\t\t\t\t\tvector<Modular<mod>> res(n);\n\
    \t\t\t\t\tfor (int i = 0; i < n; i++) {\n\t\t\t\t\t\tModular<mod> A0(llround(C[i].real()\
    \ / t));\n\t\t\t\t\t\tModular<mod> A1(llround(C[i].imag() / t + D[i].imag() /\
    \ t));\n\t\t\t\t\t\tModular<mod> A2(llround(D[i].real() / t));\n\t\t\t\t\t\tres[i]\
    \ = A0 + A1 * split - A2 * split * split;\n\t\t\t\t\t}\n\t\t\t\t\treturn res;\n\
    \t\t\t\t}\n\n\t\t\t\tcomplex<type>& operator[](int i) { return A[i]; }\n\n\t\t\
    \t\tcomplex<type> operator [](int i) const { return A[i]; }\n\t\t\t};\n\n\t\t\t\
    int common_size(int as, int bs) {\n\t\t\t\tif (as == 0 || bs == 0)\n\t\t\t\t\t\
    return 0;\n\t\t\t\tint n = as + bs - 1;\n\t\t\t\twhile (__builtin_popcount(n)\
    \ != 1)\n\t\t\t\t\tn++;\n\t\t\t\treturn n;\n\t\t\t}\n\n\t\t\ttemplate<int mod>\n\
    \t\t\tvoid polynomial_multiply(vector<Modular<mod>> &a, vector<Modular<mod>> b)\
    \ {\n\t\t\t\tif (min(a.size(), b.size()) < MAX_B) {\n\t\t\t\t\tslow_polynomial_multiply(a,\
    \ b);\n\t\t\t\t\treturn;\n\t\t\t\t}\n\n\t\t\t\tauto n = common_size(a.size(),\
    \ b.size());\n\t\t\t\tauto A = discrete_fourier_transform<mod>(a, n);\n\t\t\t\t\
    if (a == b)\n\t\t\t\t\ta = A * A;\n\t\t\t\telse\n\t\t\t\t\ta = A * discrete_fourier_transform<mod>(b,\
    \ n);\n\t\t\t}\n\t\t}\n\t}\n\n\tusing namespace polynomial_internal;\n\n\ttemplate<typename\
    \ T>\n\tclass polynomial {\n\t\tvector<T> coef;\n\n\t\tvoid normalize() {\n\t\t\
    \twhile (!coef.empty() && coef.back() == T())\n\t\t\t\tcoef.pop_back();\n\t\t\
    }\n\n\tpublic:\n\t\tpolynomial() {}\n\n\t\tpolynomial(T a0) : coef{a0} { normalize();\
    \ }\n\n\t\tpolynomial(const vector<T> &t) : coef(t) { normalize(); }\n\n\t\tpolynomial\
    \ operator-() const {\n\t\t\tauto t = *this;\n\t\t\tfor (auto &c : t.coef)\n\t\
    \t\t\tc = -c;\n\t\t\treturn t;\n\t\t}\n\n\t\tpolynomial operator+=(const polynomial\
    \ &t) {\n\t\t\tcoef.resize(max(coef.size(), t.coef.size()));\n\t\t\tfor (int i\
    \ = 0; i < t.coef.size(); i++)\n\t\t\t\tcoef[i] += t.coef[i];\n\t\t\tnormalize();\n\
    \t\t\treturn *this;\n\t\t}\n\n\t\tpolynomial operator+(const polynomial &t) const\
    \ { return polynomial(*this) += t; }\n\n\t\tpolynomial operator-=(const polynomial\
    \ &t) {\n\t\t\tcoef.resize(max(coef.size(), t.coef.size()));\n\t\t\tfor (int i\
    \ = 0; i < t.coef.size(); i++)\n\t\t\t\tcoef[i] -= t.coef[i];\n\t\t\tnormalize();\n\
    \t\t\treturn *this;\n\t\t}\n\t\tpolynomial operator-(const polynomial &t) const\
    \ { return polynomial(*this) -= t; }\n\n\t\tpolynomial modulo_k(int k) const {\
    \ return vector<T>(coef.begin(), coef.begin() + min(k, (int)coef.size())); }\n\
    \n\t\tpolynomial multiply_k(int k) const {\n\t\t\tauto res = coef;\n\t\t\tres.insert(res.begin(),\
    \ k, 0);\n\t\t\treturn res;\n\t\t}\n\n\t\tpolynomial divide_k(int k) const {\n\
    \t\t\tif (is_zero())\n\t\t\t\treturn polynomial();\n\t\t\treturn vector<T>(coef.begin()\
    \ + min(k, (int)coef.size()), coef.end());\n\t\t}\n\n\t\tpolynomial substr(int\
    \ l, int r) const {\n\t\t\treturn vector<T>(\n\t\t\t\tcoef.begin() + min(l, (int)coef.size()),\n\
    \t\t\t\tcoef.begin() + min(r, (int)coef.size())\n\t\t\t);\n\t\t}\n\n\t\tpolynomial\
    \ operator*=(const polynomial &t) {\n\t\t\tfast_fourier_transform::polynomial_multiply(coef,\
    \ t.coef);\n\t\t\tnormalize();\n\t\t\treturn *this;\n\t\t}\n\n\t\tpolynomial operator*(const\
    \ polynomial &t) const { return polynomial(*this) *= t; }\n\n\t\tpolynomial reverse(int\
    \ n) const {\n\t\t\tauto res = coef;\n\t\t\tres.resize(max(n, (int)res.size()));\n\
    \t\t\treturn vector<T>(res.rbegin(), res.rbegin() + n);\n\t\t}\n\n\t\tpolynomial\
    \ reverse() const { return reverse(deg() + 1); }\n\n\t\tint size() const { return\
    \ coef.size(); }\n\n\tprivate:\n\t\tpair<polynomial, polynomial> slow_division(const\
    \ polynomial &b) const {\n\t\t\tvector<T> A(coef);\n\t\t\tvector<T> res;\n\t\t\
    \twhile (A.size() >= b.coef.size()) {\n\t\t\t\tres.push_back(A.back() / b.coef.back());\n\
    \t\t\t\tif (res.back() != T(0))\n\t\t\t\t\tfor (int i = 0; i < b.coef.size();\
    \ i++)\n\t\t\t\t\t\tA[A.size() - i - 1] -= res.back() * b.coef[b.coef.size() -\
    \ i - 1];\n\t\t\t\tA.pop_back();\n\t\t\t}\n\t\t\tstd::reverse(res.begin(), res.end());\n\
    \t\t\treturn {res, A};\n\t\t}\n\n\tpublic:\n\t\tpair<polynomial, polynomial> hint_division(polynomial\
    \ const &b, polynomial const &binv) const {\n\t\t\tassert(!b.is_zero());\n\t\t\
    \tif (deg() < b.deg())\n\t\t\t\treturn {polynomial{0}, *this};\n\t\t\tint d =\
    \ deg() - b.deg();\n\t\t\tif (min(d, b.deg()) < MAX_B)\n\t\t\t\treturn slow_division(b);\n\
    \t\t\tpolynomial D = (reverse().modulo_k(d + 1) * binv.modulo_k(d + 1)).modulo_k(d\
    \ + 1).reverse(d + 1);\n\t\t\treturn {D, *this - D * b};\n\t\t}\n\n\t\tpair<polynomial,\
    \ polynomial> division(const polynomial &b) const {\n\t\t\tassert(!b.is_zero());\n\
    \t\t\tif (deg() < b.deg())\n\t\t\t\treturn {polynomial{0}, *this};\n\t\t\tint\
    \ d = deg() - b.deg();\n\t\t\tif (min(d, b.deg()) < MAX_B)\n\t\t\t\treturn slow_division(b);\n\
    \t\t\tpolynomial D = (reverse().modulo_k(d + 1) * b.reverse().inv(d + 1)).modulo_k(d\
    \ + 1).reverse(d + 1);\n\t\t\treturn {D, *this - D * b};\n\t\t}\n\n\tprivate:\n\
    \t\tstruct transform {\n\t\t\tpolynomial a, b, c, d;\n\n\t\t\ttransform(polynomial\
    \ a, polynomial b = T(1), polynomial c = T(1), polynomial d = T(0)): a(a), b(b),\
    \ c(c), d(d) {}\n\n\t\t\ttransform operator *(transform const &t) { return { a*t.a\
    \ + b*t.c, a*t.b + b*t.d, c*t.a + d*t.c, c*t.b + d*t.d}; }\n\n\t\t\ttransform\
    \ adj() { return transform(d, -b, -c, a); }\n\n\t\t\tauto apply(polynomial A,\
    \ polynomial B) { return make_pair(a * A + b * B, c * A + d * B); }\n\t\t};\n\n\
    \t\ttemplate<typename Q>\n\t\tstatic void attatch(vector<Q> &a, vector<Q> const\
    \ &b) {\n\t\t\tfor (auto c : b)\n\t\t\t\ta.push_back(c);\n\t\t}\n\n\t\tstatic\
    \ pair<vector<polynomial>, transform> half_gcd(polynomial A, polynomial B) {\n\
    \t\t\tassert(A.deg() >= B.deg());\n\t\t\tint m = (A.deg() + 1) / 2;\n\t\t\tif\
    \ (B.deg() < m)\n\t\t\t\treturn {{}, {T(1), T(0), T(0), T(1)}};\n\t\t\tauto [ar,\
    \ Tr] = half_gcd(A.divide_k(m), B.divide_k(m));\n\t\t\ttie(A, B) = Tr.adj().apply(A,\
    \ B);\n\t\t\tif (B.deg() < m)\n\t\t\t\treturn {ar, Tr};\n\t\t\tauto [ai, R] =\
    \ A.division(B);\n\t\t\ttie(A, B) = make_pair(B, R);\n\t\t\tint k = 2 * m - B.deg();\n\
    \t\t\tauto [as, Ts] = half_gcd(A.divide_k(k), B.divide_k(k));\n\t\t\tattatch(ar,\
    \ {ai});\n\t\t\tattatch(ar, as);\n\t\t\treturn {ar, Tr * transform(ai) * Ts};\n\
    \t\t}\n\n\t\tstatic pair<vector<polynomial>, transform> full_gcd(polynomial A,\
    \ polynomial B) {\n\t\t\tvector<polynomial> ak;\n\t\t\tvector<transform> trs;\n\
    \t\t\twhile (!B.is_zero()) {\n\t\t\t\tif (2 * B.deg() > A.deg()) {\n\t\t\t\t\t\
    auto [a, Tr] = half_gcd(A, B);\n\t\t\t\t\tattatch(ak, a);\n\t\t\t\t\ttrs.push_back(Tr);\n\
    \t\t\t\t\ttie(A, B) = trs.back().adj().apply(A, B);\n\t\t\t\t} else {\n\t\t\t\t\
    \tauto [a, R] = A.division(B);\n\t\t\t\t\tak.push_back(a);\n\t\t\t\t\ttrs.emplace_back(a);\n\
    \t\t\t\t\ttie(A, B) = make_pair(B, R);\n\t\t\t\t}\n\t\t\t}\n\t\t\ttrs.emplace_back(T(1),\
    \ T(0), T(0), T(1));\n\t\t\twhile (trs.size() >= 2) {\n\t\t\t\ttrs[trs.size()\
    \ - 2] = trs[trs.size() - 2] * trs[trs.size() - 1];\n\t\t\t\ttrs.pop_back();\n\
    \t\t\t}\n\t\t\treturn {ak, trs.back()};\n\t\t}\n\n\tpublic:\n\t\tstatic polynomial\
    \ gcd(polynomial A, polynomial B) {\n\t\t\tif (A.deg() < B.deg())\n\t\t\t\treturn\
    \ full_gcd(B, A);\n\t\t\tauto Tr = fraction(A, B);\n\t\t\treturn Tr.d * A - Tr.b\
    \ * B;\n\t\t}\n\n\tprivate:\n\t\tpolynomial slow_linear_recurrence(int d) const\
    \ {\n\t\t\tauto R1 = modulo_k(d + 1).reverse(d + 1), R2 = init_xk(d + 1);\n\t\t\
    \tauto Q1 = polynomial(T(1)), Q2 = polynomial(T(0));\n\t\t\twhile (!R2.is_zero())\
    \ {\n\t\t\t\tauto [a, nR] = R1.division(R2);\n\t\t\t\ttie(R1, R2) = make_tuple(R2,\
    \ nR);\n\t\t\t\ttie(Q1, Q2) = make_tuple(Q2, Q1 + a * Q2);\n\t\t\t\tif (R2.deg()\
    \ < Q2.deg())\n\t\t\t\t\treturn Q2 / Q2.lead();\n\t\t\t}\n\t\t\tassert(false);\n\
    \t\t}\n\n\t\tstatic transform convergent(auto L, auto R) {\n\t\t\tif (R - L ==\
    \ 1)\n\t\t\t\treturn transform(*L);\n\t\t\tint s = 0;\n\t\t\tfor (int i = 0; i\
    \ < R - L; i++)\n\t\t\t\ts += L[i].coef.size();\n\t\t\tint c = 0;\n\t\t\tfor (int\
    \ i = 0; i < R - L; i++) {\n\t\t\t\tc += L[i].coef.size();\n\t\t\t\tif (2 * c\
    \ > s)\n\t\t\t\t\treturn convergent(L, L + i) * convergent(L + i, R);\n\t\t\t\
    }\n\t\t\tassert(false);\n\t\t}\n\n\tpublic:\n\t\tpolynomial linear_recurrence(int\
    \ d) const {\n\t\t\tif (d < MAX_B)\n\t\t\t\treturn slow_linear_recurrence(d);\n\
    \t\t\tauto R2 = modulo_k(d + 1).reverse(d + 1), R1 = init_xk(d + 1);\n\t\t\tif\
    \ (R2.is_zero())\n\t\t\t\treturn polynomial(1);\n\t\t\tauto [a, Tr] = full_gcd(R1,\
    \ R2);\n\t\t\tint dr = (d + 1) - a[0].deg(), dp = 0;\n\t\t\tfor (int i = 0; i\
    \ + 1 < a.size(); i++) {\n\t\t\t\tdr -= a[i + 1].deg();\n\t\t\t\tdp += a[i].deg();\n\
    \t\t\t\tif (dr < dp) {\n\t\t\t\t\tauto ans = convergent(begin(a), begin(a) + i\
    \ + 1);\n\t\t\t\t\treturn ans.a / ans.a.lead();\n\t\t\t\t}\n\t\t\t}\n\t\t\tauto\
    \ ans = convergent(begin(a), end(a));\n\t\t\treturn ans.a / ans.a.lead();\n\t\t\
    }\n\n\tprivate:\n\t\toptional<polynomial> slow_modulo_inverse(polynomial const\
    \ &t) const {\n\t\t\tauto R1 = *this, R2 = t;\n\t\t\tauto Q1 = polynomial(T(1)),\
    \ Q2 = polynomial(T(0));\n\t\t\tint k = 0;\n\t\t\twhile (!R2.is_zero()) {\n\t\t\
    \t\tk ^= 1;\n\t\t\t\tauto [a, nR] = R1.division(R2);\n\t\t\t\ttie(R1, R2) = make_tuple(R2,\
    \ nR);\n\t\t\t\ttie(Q1, Q2) = make_tuple(Q2, Q1 + a * Q2);\n\t\t\t}\n\t\t\tif\
    \ (R1.deg() > 0)\n\t\t\t\treturn nullopt;\n\t\t\telse\n\t\t\t\treturn (k ? -Q1\
    \ : Q1) / R1[0];\n\t\t}\n\n\tpublic:\n\t\toptional<polynomial> modulo_inverse(polynomial\
    \ const &t) const {\n\t\t\tassert(!t.is_zero());\n\t\t\tif (false && min(deg(),\
    \ t.deg()) < MAX_B)\n\t\t\t\treturn slow_modulo_inverse(t);\n\t\t\tauto A = t,\
    \ B = *this % t;\n\t\t\tauto [a, Tr] = full_gcd(A, B);\n\t\t\tauto g = Tr.d *\
    \ A - Tr.b * B;\n\t\t\tif (g.deg() != 0)\n\t\t\t\treturn nullopt;\n\t\t\treturn\
    \ -Tr.b / g[0];\n\t\t};\n\n\t\tpolynomial operator/(const polynomial &t) const\
    \ { return division(t).first; }\n\n\t\tpolynomial operator%(const polynomial &t)\
    \ const { return division(t).second; }\n\n\t\tpolynomial operator/=(const polynomial\
    \ &t) { return *this = division(t).first; }\n\n\t\tpolynomial operator%=(const\
    \ polynomial &t) { return *this = division(t).second; }\n\n\t\tpolynomial operator*=(const\
    \ T &x) {\n\t\t\tfor (auto &c : coef)\n\t\t\t\tc *= x;\n\t\t\tnormalize();\n\t\
    \t\treturn *this;\n\t\t}\n\n\t\tpolynomial operator/=(const T &x) {\n\t\t\tfor\
    \ (auto &c : coef)\n\t\t\t\tc /= x;\n\t\t\tnormalize();\n\t\t\treturn *this;\n\
    \t\t}\n\n\t\tpolynomial operator*(const T &x) const { return polynomial(*this)\
    \ *= x; }\n\n\t\tpolynomial operator/(const T &x) const { return polynomial(*this)\
    \ /= x; }\n\n\t\tpolynomial conjugate() const {\n\t\t\tauto res = *this;\n\t\t\
    \tfor (int i = 1; i <= deg(); i += 2)\n\t\t\t\tres[i] = -res[i];\n\t\t\treturn\
    \ res;\n\t\t}\n\n\t\tT eval(T x) const {\n\t\t\tT res(0);\n\t\t\tfor (int i =\
    \ deg(); i >= 0; i--) {\n\t\t\t\tres *= x;\n\t\t\t\tres += coef[i];\n\t\t\t}\n\
    \t\t\treturn res;\n\t\t}\n\n\t\tT operator()(T x) { return eval(x); }\n\n\t\t\
    T lead() const {\n\t\t\tassert(!is_zero());\n\t\t\treturn coef.back();\n\t\t}\n\
    \n\t\tint deg() const { return (int)coef.size() - 1; }\n\n\t\tbool is_zero() const\
    \ { return coef.empty(); }\n\n\t\tT operator[](int i) const { return i < 0 ||\
    \ i > deg() ? T(0) : coef[i]; }\n\n\t\tT &operator[](int i) { return coef[i];\
    \ }\n\n\t\tbool operator==(const polynomial &t) const { return coef == t.coef;\
    \ }\n\n\t\tbool operator!=(const polynomial &t) const { return coef != t.coef;\
    \ }\n\n\t\tpolynomial derivative(int k = 1) {\n\t\t\tif (deg() + 1 < k)\n\t\t\t\
    \treturn polynomial(T(0));\n\t\t\tvector<T> res(deg() + 1 - k);\n\t\t\tfor (int\
    \ i = k; i <= deg(); i++)\n\t\t\t\tres[i - k] = fact<T>(i) * rfact<T>(i - k) *\
    \ coef[i];\n\t\t\treturn res;\n\t\t}\n\n\t\tpolynomial integral() {\n\t\t\tvector<T>\
    \ res(deg() + 2);\n\t\t\tfor (int i = 0; i <= deg(); i++)\n\t\t\t\tres[i + 1]\
    \ = coef[i] / T(i + 1);\n\t\t\treturn res;\n\t\t}\n\n\t\tint trailing_k() const\
    \ {\n\t\t\tif (is_zero())\n\t\t\t\treturn -1;\n\t\t\tint res = 0;\n\t\t\twhile\
    \ (coef[res] == T(0))\n\t\t\t\tres++;\n\t\t\treturn res;\n\t\t}\n\n\t\tpolynomial\
    \ log(int n) {\n\t\t\tassert(coef[0] == T(1));\n\t\t\treturn (derivative().modulo_k(n)\
    \ * inv(n)).integral().modulo_k(n);\n\t\t}\n\n\t\tpolynomial exp(int n) {\n\t\t\
    \tif (is_zero())\n\t\t\t\treturn T(1);\n\t\t\tassert(coef[0] == T(0));\n\t\t\t\
    polynomial ans = T(1);\n\t\t\tint a = 1;\n\t\t\twhile (a < n) {\n\t\t\t\tpolynomial\
    \ C = ans.log(2 * a).divide_k(a) - substr(a, 2 * a);\n\t\t\t\tans -= (ans * C).modulo_k(a).multiply_k(a);\n\
    \t\t\t\ta *= 2;\n\t\t\t}\n\t\t\treturn ans.modulo_k(n);\n\t\t}\n\n\tprivate:\n\
    \t\tpolynomial pow_bin(long long k, int n) {\n\t\t\tif (k == 0) {\n\t\t\t\treturn\
    \ polynomial(1).modulo_k(n);\n\t\t\t} else {\n\t\t\t\tauto t = pow(k / 2, n);\n\
    \t\t\t\tt *= t;\n\t\t\t\treturn (k % 2 ? *this * t : t).modulo_k(n);\n\t\t\t}\n\
    \t\t}\n\n\t\tpolynomial hint_pow(long long k, polynomial const &mod, polynomial\
    \ const &mod_inv) {\n\t\t\tif (k == 0) {\n\t\t\t\treturn polynomial(1);\n\t\t\t\
    } else {\n\t\t\t\tauto t = hint_pow(k / 2, mod, mod_inv);\n\t\t\t\tt = (t * t).hint_division(mod,\
    \ mod_inv).second;\n\t\t\t\tif (k % 2) {\n\t\t\t\t\tt = (t * *this).hint_division(mod,\
    \ mod_inv).second;\n\t\t\t\t}\n\t\t\t\treturn t;\n\t\t\t}\n\t\t}\n\n\tpublic:\n\
    \n\t\tpolynomial pow(long long k, polynomial const &mod) {\n\t\t\tauto mod_inv\
    \ = mod.reverse().inv(mod.deg() + 1);\n\t\t\treturn hint_pow(k, mod, mod_inv);\n\
    \t\t}\n\n\tprivate:\n\t\tpolynomial pow_dn(long long k, int n) {\n\t\t\tif (n\
    \ == 0) {\n\t\t\t\treturn polynomial(T(0));\n\t\t\t}\n\t\t\tassert((*this)[0]\
    \ != T(0));\n\t\t\tvector<T> Q(n);\n\t\t\tQ[0] = fast_pow(coef[0], k);\n\t\t\t\
    for (int i = 1; i < (int)n; i++) {\n\t\t\t\tfor (int j = 1; j <= min(deg(), i);\
    \ j++) {\n\t\t\t\t\tQ[i] += coef[j] * Q[i - j] * (T(k) * T(j) - T(i - j));\n\t\
    \t\t\t}\n\t\t\t\tQ[i] /= T(i) * coef[0];\n\t\t\t}\n\t\t\treturn Q;\n\t\t}\n\n\t\
    public:\n\t\tpolynomial pow(long long k, int n) {\n\t\t\tif (is_zero())\n\t\t\t\
    \treturn k ? *this : polynomial(1);\n\t\t\tint i = trailing_k();\n\t\t\tif (i\
    \ > 0)\n\t\t\t\treturn i * k >= (long long)n ? polynomial(T(0)) : divide_k(i).pow(k,\
    \ n - i * k).multiply_k(i * k);\n\t\t\tif (min(deg(), (int)n) <= MAX_B)\n\t\t\t\
    \treturn pow_dn(k, n);\n\t\t\tif (k <= MAX_B)\n\t\t\t\treturn pow_bin(k, n);\n\
    \t\t\tT j = coef[i];\n\t\t\tpolynomial t = *this / j;\n\t\t\treturn fast_pow(j,\
    \ k) * (t.log(n) * T(k)).exp(n).modulo_k(n);\n\t\t}\n\n\tpublic:\n\t\toptional<polynomial>\
    \ sqrt(int n) const {\n\t\t\tif (is_zero())\n\t\t\t\treturn *this;\n\t\t\tint\
    \ i = trailing_k();\n\t\t\tif (i % 2) {\n\t\t\t\treturn nullopt;\n\t\t\t} else\
    \ if (i > 0) {\n\t\t\t\tauto ans = divide_k(i).sqrt(n - i / 2);\n\t\t\t\treturn\
    \ ans ? ans->multiply_k(i / 2) : ans;\n\t\t\t}\n\t\t\tauto st = (*this)[0].sqrt();\n\
    \t\t\tif (st) {\n\t\t\t\tpolynomial ans = *st;\n\t\t\t\tint a = 1;\n\t\t\t\twhile\
    \ (a < n) {\n\t\t\t\t\ta *= 2;\n\t\t\t\t\tans -= (ans - modulo_k(a) * ans.inv(a)).modulo_k(a)\
    \ / 2;\n\t\t\t\t}\n\t\t\t\treturn ans.modulo_k(n);\n\t\t\t}\n\t\t\treturn nullopt;\n\
    \t\t}\n\n\tprivate:\n\t\tpolynomial mulx(T a) const {\n\t\t\tT cur = 1;\n\t\t\t\
    polynomial res(*this);\n\t\t\tfor (int i = 0; i <= deg(); i++) {\n\t\t\t\tres.coef[i]\
    \ *= cur;\n\t\t\t\tcur *= a;\n\t\t\t}\n\t\t\treturn res;\n\t\t}\n\n\t\tpolynomial\
    \ mulx_sq(T a) const {\n\t\t\tT cur = a;\n\t\t\tT total = 1;\n\t\t\tT aa = a *\
    \ a;\n\t\t\tpolynomial res(*this);\n\t\t\tfor (int i = 0; i <= deg(); i++) {\n\
    \t\t\t\tres.coef[i] *= total;\n\t\t\t\ttotal *= cur;\n\t\t\t\tcur *= aa;\n\t\t\
    \t}\n\t\t\treturn res;\n\t\t}\n\n\t\tvector<T> chirpz_even(T z, int n) const {\n\
    \t\t\tint m = deg();\n\t\t\tif (is_zero())\n\t\t\t\treturn vector<T>(n, 0);\n\t\
    \t\tvector<T> vv(m + n);\n\t\t\tT zi = T(1) / z;\n\t\t\tT zz = zi * zi;\n\t\t\t\
    T cur = zi;\n\t\t\tT total = 1;\n\t\t\tfor (int i = 0; i <= max(n - 1, m); i++)\
    \ {\n\t\t\t\tif (i <= m) {vv[m - i] = total; }\n\t\t\t\tif (i < n) {vv[m + i]\
    \ = total; }\n\t\t\t\ttotal *= cur;\n\t\t\t\tcur *= zz;\n\t\t\t}\n\t\t\tpolynomial\
    \ w = (mulx_sq(z) * vv).substr(m, m + n).mulx_sq(z);\n\t\t\tvector<T> res(n);\n\
    \t\t\tfor (int i = 0; i < n; i++) {\n\t\t\t\tres[i] = w[i];\n\t\t\t}\n\t\t\treturn\
    \ res;\n\t\t}\n\n\tpublic:\n\t\tvector<T> chirpz(T z, int n) const {\n\t\t\tauto\
    \ even = chirpz_even(z, (n + 1) / 2);\n\t\t\tauto odd = mulx(z).chirpz_even(z,\
    \ n / 2);\n\t\t\tvector<T> ans(n);\n\t\t\tfor (int i = 0; i < n / 2; i++) {\n\t\
    \t\t\tans[2 * i] = even[i];\n\t\t\t\tans[2 * i + 1] = odd[i];\n\t\t\t}\n\t\t\t\
    if (n % 2 == 1) {\n\t\t\t\tans[n - 1] = even.back();\n\t\t\t}\n\t\t\treturn ans;\n\
    \t\t}\n\n\tprivate:\n\t\tvector<T> eval(vector<polynomial> &tree, int v, auto\
    \ l, auto r) {\n\t\t\tif (r - l == 1) {\n\t\t\t\treturn {eval(*l)};\n\t\t\t} else\
    \ {\n\t\t\t\tauto m = l + (r - l) / 2;\n\t\t\t\tauto A = (*this % tree[2 * v]).eval(tree,\
    \ 2 * v, l, m);\n\t\t\t\tauto B = (*this % tree[2 * v + 1]).eval(tree, 2 * v +\
    \ 1, m, r);\n\t\t\t\tA.insert(end(A), begin(B), end(B));\n\t\t\t\treturn A;\n\t\
    \t\t}\n\t\t}\n\n\tpublic:\n\t\tvector<T> eval(vector<T> x) {\n\t\t\tint n = x.size();\n\
    \t\t\tif (is_zero()) \n\t\t\t\treturn vector<T>(n, T(0));\n\t\t\tvector<polynomial>\
    \ tree(4 * n);\n\t\t\tbuild(tree, 1, begin(x), end(x));\n\t\t\treturn eval(tree,\
    \ 1, begin(x), end(x));\n\t\t}\n\n\tprivate:\n\t\tpolynomial interpolate(vector<polynomial>\
    \ &tree, int v, auto l, auto r, auto ly, auto ry) {\n\t\t\tif (r - l == 1) {\n\
    \t\t\t\treturn {*ly / coef[0]};\n\t\t\t} else {\n\t\t\t\tauto m = l + (r - l)\
    \ / 2;\n\t\t\t\tauto my = ly + (ry - ly) / 2;\n\t\t\t\tauto A = (*this % tree[2\
    \ * v]).interpolate(tree, 2 * v, l, m, ly, my);\n\t\t\t\tauto B = (*this % tree[2\
    \ * v + 1]).interpolate(tree, 2 * v + 1, m, r, my, ry);\n\t\t\t\treturn A * tree[2\
    \ * v + 1] + B * tree[2 * v];\n\t\t\t}\n\t\t}\n\n\t\tstatic auto resultant(polynomial\
    \ a, polynomial b) {\n\t\t\tif (b.is_zero()) {\n\t\t\t\treturn 0;\n\t\t\t} else\
    \ if (b.deg() == 0) {\n\t\t\t\treturn bpow(b.lead(), a.deg());\n\t\t\t} else {\n\
    \t\t\t\tint pw = a.deg();\n\t\t\t\ta %= b;\n\t\t\t\tpw -= a.deg();\n\t\t\t\tauto\
    \ mul = bpow(b.lead(), pw) * T((b.deg() & a.deg() & 1) ? -1 : 1);\n\t\t\t\tauto\
    \ ans = resultant(b, a);\n\t\t\t\treturn ans * mul;\n\t\t\t}\n\t\t}\n\n\t\tstatic\
    \ polynomial build(vector<polynomial> &res, int v, auto L, auto R) {\n\t\t\tif\
    \ (R - L == 1) {\n\t\t\t\treturn res[v] = vector<T>{-*L, 1};\n\t\t\t} else {\n\
    \t\t\t\tauto M = L + (R - L) / 2;\n\t\t\t\treturn res[v] = build(res, 2 * v, L,\
    \ M) * build(res, 2 * v + 1, M, R);\n\t\t\t}\n\t\t}\n\n\tpublic:\n\t\tstatic auto\
    \ interpolate(vector<T> x, vector<T> y) {\n\t\t\tint n = x.size();\n\t\t\tvector<polynomial>\
    \ tree(4 * n);\n\t\t\treturn build(tree, 1, begin(x), end(x)).derivative().interpolate(tree,\
    \ 1, begin(x), end(x), begin(y), end(y));\n\t\t}\n\n\n\t\tstatic polynomial init_xk(int\
    \ n) { return polynomial(T(1)).multiply_k(n); }\n\n\t\tstatic polynomial init_unit(int\
    \ n) { return polynomial(vector<T>(n, 1)); }\n\n\t\tstatic polynomial init_exp(int\
    \ n) { return init_unit(n).borel(); }\n\n\t\tstatic polynomial cross_correlation(polynomial\
    \ a, polynomial b) { return a * b.reverse(); }\n\n\t\tpolynomial invborel() const\
    \ {\n\t\t\tauto res = *this;\n\t\t\tfor (int i = 0; i <= deg(); i++)\n\t\t\t\t\
    res.coef[i] *= fact<T>(i);\n\t\t\treturn res;\n\t\t}\n\n\t\tpolynomial borel()\
    \ const {\n\t\t\tauto res = *this;\n\t\t\tfor (int i = 0; i <= deg(); i++)\n\t\
    \t\t\tres.coef[i] *= rfact<T>(i);\n\t\t\treturn res;\n\t\t}\n\n\t\tpolynomial\
    \ shift(T a) const { return (init_exp(deg() + 1).mulx(a).reverse() * invborel()).divide_k(deg()).borel();\
    \ }\n\n\tprivate:\n\t\tpolynomial eval_x2() {\n\t\t\tvector<T> res(2 * coef.size());\n\
    \t\t\tfor (int i = 0; i < coef.size(); i++)\n\t\t\t\tres[2 * i] = coef[i];\n\t\
    \t\treturn res;\n\t\t}\n\n\t\tpair<polynomial, polynomial> bisect() const {\n\t\
    \t\tvector<T> res[2];\n\t\t\tres[0].reserve(deg() / 2 + 1);\n\t\t\tres[1].reserve(deg()\
    \ / 2 + 1);\n\t\t\tfor (int i = 0; i <= deg(); i++) {\n\t\t\t\tres[i % 2].push_back(coef[i]);\n\
    \t\t\t}\n\t\t\treturn {res[0], res[1]};\n\t\t}\n\n\tpublic:\n\t\tstatic T kth_recurrence(polynomial\
    \ P, polynomial Q, long long k) {\n\t\t\twhile (k > Q.deg()) {\n\t\t\t\tint n\
    \ = Q.coef.size();\n\t\t\t\tauto [Q0, Q1] = Q.mulx(-1).bisect();\n\t\t\t\tauto\
    \ [P0, P1] = P.bisect();\n\n\t\t\t\tint N = fast_fourier_transform::common_size((n\
    \ + 1) / 2, (n + 1) / 2);\n\n\t\t\t\tauto Q0f = fast_fourier_transform::discrete_fourier_transform(Q0.coef,\
    \ N);\n\t\t\t\tauto Q1f = fast_fourier_transform::discrete_fourier_transform(Q1.coef,\
    \ N);\n\t\t\t\tauto P0f = fast_fourier_transform::discrete_fourier_transform(P0.coef,\
    \ N);\n\t\t\t\tauto P1f = fast_fourier_transform::discrete_fourier_transform(P1.coef,\
    \ N);\n\n\t\t\t\tif (k % 2)\n\t\t\t\t\tP = polynomial(Q0f * P1f) + polynomial(Q1f\
    \ * P0f);\n\t\t\t\telse\n\t\t\t\t\tP = polynomial(Q0f * P0f) + polynomial(Q1f\
    \ * P1f).multiply_k(1);\n\t\t\t\tQ = polynomial(Q0f * Q0f) - polynomial(Q1f *\
    \ Q1f).multiply_k(1);\n\t\t\t\tk /= 2;\n\t\t\t}\n\t\t\treturn (P * Q.inv(Q.deg()\
    \ + 1))[k];\n\t\t}\n\n\t\tpolynomial inv(int n) const {\n\t\t\tauto Q = modulo_k(n);\n\
    \t\t\tif (n == 1)\n\t\t\t\treturn Q.is_zero() ? 0 : Q[0].inv();\n\t\t\tauto [P0,\
    \ P1] = Q.mulx(-1).bisect();\n\t\t\tint N = fast_fourier_transform::common_size((n\
    \ + 1) / 2, (n + 1) / 2);\n\n\t\t\tauto P0f = fast_fourier_transform::discrete_fourier_transform(P0.coef,\
    \ N);\n\t\t\tauto P1f = fast_fourier_transform::discrete_fourier_transform(P1.coef,\
    \ N);\n\n\t\t\tauto TTf = fast_fourier_transform::discrete_fourier_transform((\n\
    \t\t\t\tpolynomial(P0f * P0f) - polynomial(P1f * P1f).multiply_k(1)\n\t\t\t).inv((n\
    \ + 1) / 2).coef, N);\n\n\t\t\treturn (\n\t\t\t\tpolynomial(P0f * TTf).eval_x2()\
    \ + polynomial(P1f * TTf).eval_x2().multiply_k(1)\n\t\t\t).modulo_k(n);\n\t\t\
    }\n\n\t\tstatic polynomial compose(polynomial A, polynomial B, int n) {\n\t\t\t\
    int q = std::sqrt(n);\n\t\t\tvector<polynomial> Bk(q);\n\t\t\tauto Bq = B.pow(q,\
    \ n);\n\t\t\tBk[0] = polynomial(T(1));\n\t\t\tfor (int i = 1; i < q; i++)\n\t\t\
    \t\tBk[i] = (Bk[i - 1] * B).modulo_k(n);\n\t\t\tpolynomial Bqk(1);\n\t\t\tpolynomial\
    \ ans;\n\t\t\tfor (int i = 0; i <= n / q; i++) {\n\t\t\t\tpolynomial cur;\n\t\t\
    \t\tfor (int j = 0; j < q; j++)\n\t\t\t\t\tcur += Bk[j] * A[i * q + j];\n\t\t\t\
    \tans += (Bqk * cur).modulo_k(n);\n\t\t\t\tBqk = (Bqk * Bq).modulo_k(n);\n\t\t\
    \t}\n\t\t\treturn ans;\n\t\t}\n\n\t\tstatic polynomial compose_large(polynomial\
    \ A, polynomial B, int n) {\n\t\t\tif (B[0] != T(0))\n\t\t\t\treturn compose_large(A.shift(B[0]),\
    \ B - B[0], n);\n\t\t\tint q = std::sqrt(n);\n\t\t\tauto [B0, B1] = make_pair(B.modulo_k(q),\
    \ B.divide_k(q));\n\t\t\tB0 = B0.divide_k(1);\n\t\t\tvector<polynomial> pw(A.deg()\
    \ + 1);\n\t\t\tauto getpow = [&](int k) { return pw[k].is_zero() ? pw[k] = B0.pow(k,\
    \ n - k) : pw[k]; };\n\n\t\t\tfunction<polynomial(polynomial const&, int, int)>\
    \ compose_dac = [&getpow, &compose_dac](polynomial const &f, int m, int N) {\n\
    \t\t\t\tif (f.deg() <= 0)\n\t\t\t\t\treturn f;\n\t\t\t\tint k = m / 2;\n\t\t\t\
    \tauto [f0, f1] = make_pair(f.modulo_k(k), f.divide_k(k));\n\t\t\t\tauto [A, B]\
    \ = make_pair(compose_dac(f0, k, N), compose_dac(f1, m - k, N - k));\n\t\t\t\t\
    return (A + (B.modulo_k(N - k) * getpow(k).modulo_k(N - k)).multiply_k(k)).modulo_k(N);\n\
    \t\t\t};\n\n\t\t\tint r = n / q;\n\t\t\tauto Ar = A.derivative(r);\n\t\t\tauto\
    \ AB0 = compose_dac(Ar, Ar.deg() + 1, n);\n\t\t\tauto Bd = B0.multiply_k(1).derivative();\n\
    \n\t\t\tpolynomial ans = T(0);\n\n\t\t\tvector<polynomial> B1p(r + 1);\n\t\t\t\
    B1p[0] = polynomial(T(1));\n\t\t\tfor (int i = 1; i <= r; i++)\n\t\t\t\tB1p[i]\
    \ = (B1p[i - 1] * B1.modulo_k(n - i * q)).modulo_k(n - i * q);\n\t\t\twhile (r\
    \ >= 0) {\n\t\t\t\tans += (AB0.modulo_k(n - r * q) * rfact<T>(r) * B1p[r]).multiply_k(r\
    \ * q).modulo_k(n);\n\t\t\t\tr--;\n\t\t\t\tif (r >= 0)\n\t\t\t\t\tAB0 = ((AB0\
    \ * Bd).integral() + A[r] * fact<T>(r)).modulo_k(n);\n\t\t\t}\n\t\t\treturn ans;\n\
    \t\t}\n\t};\n\n\tstatic auto operator*(const auto &a, const polynomial<auto> &b)\
    \ { return b * a; }\n\n\tostream &operator<<(ostream &os, const polynomial<auto>\
    \ &p) {\n\t\tos << '[';\n\t\tif (p.size()) {\n\t\t\tos << p[0];\n\t\t\tfor (int\
    \ i = 1; i < p.size(); i++)\n\t\t\t\tos << \", \" << p[i];\n\t\t}\n\t\treturn\
    \ os << ']';\n\t}\n}\n\n#endif\n\n#pragma endregion polynomial\n#line 7 \"verify/polynomial.yosupo-pow-of-formal-power-series.test.cpp\"\
    \n\nusing namespace poly;\n\nconst int MOD = 998244353;\nusing mint = polynomial_internal::Modular<MOD>;\n\
    \nint main() {\n\tint N, M;\n\tcin >> N >> M;\n\tvector<mint> A(N);\n\tfor (auto\
    \ &a : A)\n\t\tcin >> a;\n\t\n\tpolynomial<mint> P(A);\n\tauto Q = P.pow(M, N);\n\
    \tfor (int i = 0; i < N; i++)\n\t\tcout << (i < Q.size() ? Q[i] : 0) << ' ';\n\
    \tcout << '\\n';\n} \n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/pow_of_formal_power_series\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"poly/polynomial.hpp\"\
    \n\nusing namespace poly;\n\nconst int MOD = 998244353;\nusing mint = polynomial_internal::Modular<MOD>;\n\
    \nint main() {\n\tint N, M;\n\tcin >> N >> M;\n\tvector<mint> A(N);\n\tfor (auto\
    \ &a : A)\n\t\tcin >> a;\n\t\n\tpolynomial<mint> P(A);\n\tauto Q = P.pow(M, N);\n\
    \tfor (int i = 0; i < N; i++)\n\t\tcout << (i < Q.size() ? Q[i] : 0) << ' ';\n\
    \tcout << '\\n';\n} "
  dependsOn:
  - poly/polynomial.hpp
  - utility/pi.hpp
  isVerificationFile: true
  path: verify/polynomial.yosupo-pow-of-formal-power-series.test.cpp
  requiredBy: []
  timestamp: '2022-06-01 15:52:51-07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/polynomial.yosupo-pow-of-formal-power-series.test.cpp
layout: document
redirect_from:
- /verify/verify/polynomial.yosupo-pow-of-formal-power-series.test.cpp
- /verify/verify/polynomial.yosupo-pow-of-formal-power-series.test.cpp.html
title: verify/polynomial.yosupo-pow-of-formal-power-series.test.cpp
---
