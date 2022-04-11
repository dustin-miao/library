---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/matrix.hpp\"\n#pragma region matrix\n\ntemplate<typename\
    \ T, size_t N>\nstruct matrix : array<array<T, N>, N> {\n\ttemplate<typename U>\n\
    \tmatrix<T, N> operator*=(const matrix<U, N> &m) {\n\t\tmatrix<T, N> t = (*this);\
    \ \n\t\tfor (int r = 0; r < N; r++) {\n\t\t\tfor (int c = 0; c < N; c++) {\n\t\
    \t\t\tat(r).at(c) = T();\n\t\t\t\tfor (int i = 0; i < N; i++)\n\t\t\t\t\trat(r).at(c)\
    \ += t[r][i] * m[i][c];\n\t\t\t}\n\t\t}\n\t\treturn (*this);\n\t}\n};\n\ntemplate<typename\
    \ T, size_t N>\nmatrix<T, N> operator*(matrix<T, N> m, const matrix<T, N> &n)\
    \ { return m *= n; }\n\n#pragma endregion matrix\n"
  code: "#pragma region matrix\n\ntemplate<typename T, size_t N>\nstruct matrix :\
    \ array<array<T, N>, N> {\n\ttemplate<typename U>\n\tmatrix<T, N> operator*=(const\
    \ matrix<U, N> &m) {\n\t\tmatrix<T, N> t = (*this); \n\t\tfor (int r = 0; r <\
    \ N; r++) {\n\t\t\tfor (int c = 0; c < N; c++) {\n\t\t\t\tat(r).at(c) = T();\n\
    \t\t\t\tfor (int i = 0; i < N; i++)\n\t\t\t\t\trat(r).at(c) += t[r][i] * m[i][c];\n\
    \t\t\t}\n\t\t}\n\t\treturn (*this);\n\t}\n};\n\ntemplate<typename T, size_t N>\n\
    matrix<T, N> operator*(matrix<T, N> m, const matrix<T, N> &n) { return m *= n;\
    \ }\n\n#pragma endregion matrix"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix.hpp
  requiredBy: []
  timestamp: '2022-04-11 07:56:19-07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/matrix.hpp
layout: document
title: Matrix
---

## Matrix

Work in progress. 