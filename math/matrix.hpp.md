---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/matrix.aizu-fibonacci-number.test.cpp
    title: verify/matrix.aizu-fibonacci-number.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/matrix.hpp\"\n#pragma region matrix\n\ntemplate<typename\
    \ T>\nclass matrix {\n\tint n;\n\tvector<vector<T>> mat;\n\npublic:\n\tmatrix()\
    \ = default;\n\n\tmatrix(int _n) {\n\t\tn = _n;\n\t\tmat.assign(n, vector<T>(n));\n\
    \t\tfor (int i = 0; i < n; i++)\n\t\t\tfor (int j = 0; j < n; j++)\n\t\t\t\tmat[i][j]\
    \ = int(i == j);\n\t}\n\n\tmatrix(int _n, T v) { \n\t\tn = _n;\n\t\tmat.assign(n,\
    \ vector<T>(n, v)); \n\t}\n\n\tvector<T> &operator[](int i) { return mat[i]; }\n\
    \n\tconst vector<T> &operator[](int i) const { return mat[i]; }\n\n\tconst int\
    \ size() const { return n; }\n\n\tvoid fill(T v = T{}) {\n\t\tfor (int i = 0;\
    \ i < n; i++)\n\t\t\tfill(mat[i].begin(), mat[i].end(), v);\n\t}\n\n\tvoid resize(int\
    \ _n, T v = T{}) { \n\t\tn = _n;\n\t\tmat.resize(n);\n\t\tfor (int i = 0; i <\
    \ n; i++)\n\t\t\tmat[i].resize(n, v);\n\t}\n\n\tmatrix<T> operator+=(const matrix<T>\
    \ &m) {\n\t\tassert(size() == m.size());\n\t\tfor (int i = 0; i < n; i++)\n\t\t\
    \tfor (int j = 0; j < n; j++)\n\t\t\t\tmat[i][j] += m[i][j];\n\t\treturn *this;\n\
    \t}\n\n\tmatrix<T> operator-=(const matrix<T> &m) {\n\t\tassert(size() == m.size());\n\
    \t\tfor (int i = 0; i < n; i++)\n\t\t\tfor (int j = 0; j < n; j++)\n\t\t\t\tmat[i][j]\
    \ -= m[i][j];\n\t\treturn *this;\n\t}\n\n\tmatrix<T> operator *=(const matrix<T>\
    \ &m) {\n\t\tassert(size() == m.size());\n\t\tmatrix<T> ret(n, T{});\n\t\tfor\
    \ (int i = 0; i < n; i++)\n\t\t\tfor (int k = 0; k < n; k++)\n\t\t\t\tfor (int\
    \ j = 0; j < n; j++)\n\t\t\t\t\tret[i][j] += mat[i][k] * m[k][j];\n\t\treturn\
    \ *this = move(ret);\n\t}\n};\n\ntemplate<typename T>\nmatrix<T> operator+(matrix<T>\
    \ m, const matrix<T> &n) { return m += n; }\n\ntemplate<typename T>\nmatrix<T>\
    \ operator-(matrix<T> m, const matrix<T> &n) { return m -= n; }\n\ntemplate<typename\
    \ T>\nmatrix<T> operator*(matrix<T> m, const matrix<T> &n) { return m *= n; }\n\
    \ntemplate<typename T>\nvector<T> operator*(const matrix<T> &m, const vector<T>\
    \ &n) {\n\tassert(m.size() == n.size());\n\tint s = m.size();\n\tvector<T> ret(s);\n\
    \tfor (int i = 0; i < s; i++)\n\t\tfor (int j = 0; j < s; j++)\n\t\t\tret[i] +=\
    \ m[i][j] * n[j];\n\treturn ret;\n}\n\ntemplate<typename T>\nbool operator==(const\
    \ matrix<T> &m, const matrix<T> &n) {\n\tif (m.size() != n.size())\n\t\treturn\
    \ false;\n\tint s = m.size();\n\tfor (int i = 0; i < s; i++)\n\t\tfor (int j =\
    \ 0; j < s; j++)\n\t\t\tif (m[i][j] != n[i][j])\n\t\t\t\treturn false;\n\treturn\
    \ true;\n}\n\ntemplate<typename T>\nbool operator!=(const matrix<T> &m, const\
    \ matrix<T> &n) { return !(m == n); }\n\ntemplate<typename T>\nostream &operator<<(ostream\
    \ &os, const matrix<T> &m) {\n\tint s = m.size();\n\tfor (int i = 0; i < s; i++)\
    \ {\n\t\tos << '[';\n\t\tfor (int j = 0; j < s; j++) {\n\t\t\tos << m[i][j];\n\
    \t\t\tif (j != s - 1)\n\t\t\t\tos << \", \";\n\t\t}\n\t\tos << \"]\\n\";\n\t}\n\
    \treturn os;\n}\n\ntemplate<typename T, typename U>\nmatrix<T> fast_pow(matrix<T>\
    \ a, U b) {\n\tint n = a.size();\n\tmatrix<T> ret(n);\n\tfor (; b; b /= 2) {\n\
    \t\tif (b & 1)\n\t\t\tret *= a;\n\t\ta *= a;\n\t}\n\treturn ret;\n}\n\n#pragma\
    \ endregion matrix\n"
  code: "#pragma region matrix\n\ntemplate<typename T>\nclass matrix {\n\tint n;\n\
    \tvector<vector<T>> mat;\n\npublic:\n\tmatrix() = default;\n\n\tmatrix(int _n)\
    \ {\n\t\tn = _n;\n\t\tmat.assign(n, vector<T>(n));\n\t\tfor (int i = 0; i < n;\
    \ i++)\n\t\t\tfor (int j = 0; j < n; j++)\n\t\t\t\tmat[i][j] = int(i == j);\n\t\
    }\n\n\tmatrix(int _n, T v) { \n\t\tn = _n;\n\t\tmat.assign(n, vector<T>(n, v));\
    \ \n\t}\n\n\tvector<T> &operator[](int i) { return mat[i]; }\n\n\tconst vector<T>\
    \ &operator[](int i) const { return mat[i]; }\n\n\tconst int size() const { return\
    \ n; }\n\n\tvoid fill(T v = T{}) {\n\t\tfor (int i = 0; i < n; i++)\n\t\t\tfill(mat[i].begin(),\
    \ mat[i].end(), v);\n\t}\n\n\tvoid resize(int _n, T v = T{}) { \n\t\tn = _n;\n\
    \t\tmat.resize(n);\n\t\tfor (int i = 0; i < n; i++)\n\t\t\tmat[i].resize(n, v);\n\
    \t}\n\n\tmatrix<T> operator+=(const matrix<T> &m) {\n\t\tassert(size() == m.size());\n\
    \t\tfor (int i = 0; i < n; i++)\n\t\t\tfor (int j = 0; j < n; j++)\n\t\t\t\tmat[i][j]\
    \ += m[i][j];\n\t\treturn *this;\n\t}\n\n\tmatrix<T> operator-=(const matrix<T>\
    \ &m) {\n\t\tassert(size() == m.size());\n\t\tfor (int i = 0; i < n; i++)\n\t\t\
    \tfor (int j = 0; j < n; j++)\n\t\t\t\tmat[i][j] -= m[i][j];\n\t\treturn *this;\n\
    \t}\n\n\tmatrix<T> operator *=(const matrix<T> &m) {\n\t\tassert(size() == m.size());\n\
    \t\tmatrix<T> ret(n, T{});\n\t\tfor (int i = 0; i < n; i++)\n\t\t\tfor (int k\
    \ = 0; k < n; k++)\n\t\t\t\tfor (int j = 0; j < n; j++)\n\t\t\t\t\tret[i][j] +=\
    \ mat[i][k] * m[k][j];\n\t\treturn *this = move(ret);\n\t}\n};\n\ntemplate<typename\
    \ T>\nmatrix<T> operator+(matrix<T> m, const matrix<T> &n) { return m += n; }\n\
    \ntemplate<typename T>\nmatrix<T> operator-(matrix<T> m, const matrix<T> &n) {\
    \ return m -= n; }\n\ntemplate<typename T>\nmatrix<T> operator*(matrix<T> m, const\
    \ matrix<T> &n) { return m *= n; }\n\ntemplate<typename T>\nvector<T> operator*(const\
    \ matrix<T> &m, const vector<T> &n) {\n\tassert(m.size() == n.size());\n\tint\
    \ s = m.size();\n\tvector<T> ret(s);\n\tfor (int i = 0; i < s; i++)\n\t\tfor (int\
    \ j = 0; j < s; j++)\n\t\t\tret[i] += m[i][j] * n[j];\n\treturn ret;\n}\n\ntemplate<typename\
    \ T>\nbool operator==(const matrix<T> &m, const matrix<T> &n) {\n\tif (m.size()\
    \ != n.size())\n\t\treturn false;\n\tint s = m.size();\n\tfor (int i = 0; i <\
    \ s; i++)\n\t\tfor (int j = 0; j < s; j++)\n\t\t\tif (m[i][j] != n[i][j])\n\t\t\
    \t\treturn false;\n\treturn true;\n}\n\ntemplate<typename T>\nbool operator!=(const\
    \ matrix<T> &m, const matrix<T> &n) { return !(m == n); }\n\ntemplate<typename\
    \ T>\nostream &operator<<(ostream &os, const matrix<T> &m) {\n\tint s = m.size();\n\
    \tfor (int i = 0; i < s; i++) {\n\t\tos << '[';\n\t\tfor (int j = 0; j < s; j++)\
    \ {\n\t\t\tos << m[i][j];\n\t\t\tif (j != s - 1)\n\t\t\t\tos << \", \";\n\t\t\
    }\n\t\tos << \"]\\n\";\n\t}\n\treturn os;\n}\n\ntemplate<typename T, typename\
    \ U>\nmatrix<T> fast_pow(matrix<T> a, U b) {\n\tint n = a.size();\n\tmatrix<T>\
    \ ret(n);\n\tfor (; b; b /= 2) {\n\t\tif (b & 1)\n\t\t\tret *= a;\n\t\ta *= a;\n\
    \t}\n\treturn ret;\n}\n\n#pragma endregion matrix\n"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix.hpp
  requiredBy: []
  timestamp: '2022-04-17 17:41:50-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/matrix.aizu-fibonacci-number.test.cpp
documentation_of: math/matrix.hpp
layout: document
title: Matrix
---

## Matrix