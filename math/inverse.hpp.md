---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/binomial-coefficients.hpp
    title: Binomial Coefficients
  - icon: ':heavy_check_mark:'
    path: math/discrete-log.hpp
    title: Discrete Logarithm
  - icon: ':heavy_check_mark:'
    path: math/discrete-sqrt.hpp
    title: Discrete Square Root
  - icon: ':heavy_check_mark:'
    path: utility/mint.hpp
    title: Modular Int
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/discrete-log.yosupo-discrete-logarithm.test.cpp
    title: verify/discrete-log.yosupo-discrete-logarithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/discrete-sqrt.yosupo-sqrt-mod.test.cpp
    title: verify/discrete-sqrt.yosupo-sqrt-mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/general-segment-tree.yosupo-point-set-range-composite.test.cpp
    title: verify/general-segment-tree.yosupo-point-set-range-composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/lazy-segment-tree.yosupo-range-affine-range-sum.test.cpp
    title: verify/lazy-segment-tree.yosupo-range-affine-range-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/mint.power.test.cpp
    title: verify/mint.power.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/mint.yosupo-A+B.test.cpp
    title: verify/mint.yosupo-A+B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp
    title: verify/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/sparse-segment-tree.yosupo-point-set-range-composite.test.cpp
    title: verify/sparse-segment-tree.yosupo-point-set-range-composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/inverse.hpp\"\n#pragma region modulo inverse\n\nnamespace\
    \ math {\n\ttemplate <typename T>\n\tT inverse(T a, T p) {\n\t\tT b = p, x = 1,\
    \ y = 0;\n\t\twhile (a) {\n\t\t\tT q = b / a;\n\t\t\tswap(a, b %= a);\n\t\t\t\
    swap(x, y -= q * x);\n\t\t}\n\t\tassert(b == 1);\n\t\treturn y < 0 ? y + p : y;\n\
    \t}\n}\n\n#pragma endregion modulo inverse\n"
  code: "#pragma region modulo inverse\n\nnamespace math {\n\ttemplate <typename T>\n\
    \tT inverse(T a, T p) {\n\t\tT b = p, x = 1, y = 0;\n\t\twhile (a) {\n\t\t\tT\
    \ q = b / a;\n\t\t\tswap(a, b %= a);\n\t\t\tswap(x, y -= q * x);\n\t\t}\n\t\t\
    assert(b == 1);\n\t\treturn y < 0 ? y + p : y;\n\t}\n}\n\n#pragma endregion modulo\
    \ inverse"
  dependsOn: []
  isVerificationFile: false
  path: math/inverse.hpp
  requiredBy:
  - math/discrete-log.hpp
  - math/binomial-coefficients.hpp
  - math/discrete-sqrt.hpp
  - utility/mint.hpp
  timestamp: '2022-04-20 11:24:42-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/mint.power.test.cpp
  - verify/mint.yosupo-A+B.test.cpp
  - verify/lazy-segment-tree.yosupo-range-affine-range-sum.test.cpp
  - verify/discrete-log.yosupo-discrete-logarithm.test.cpp
  - verify/sparse-segment-tree.yosupo-point-set-range-composite.test.cpp
  - verify/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp
  - verify/discrete-sqrt.yosupo-sqrt-mod.test.cpp
  - verify/general-segment-tree.yosupo-point-set-range-composite.test.cpp
documentation_of: math/inverse.hpp
layout: document
title: Modulo Inverse
---

## Modulo Inverse