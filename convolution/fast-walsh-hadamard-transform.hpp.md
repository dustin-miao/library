---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/inverse-fast-walsh-hadamard-transform.hpp
    title: Inverse Fast Walsh-Hadamard Transform
  - icon: ':heavy_check_mark:'
    path: convolution/xor-convolution.hpp
    title: Xor Convolution
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/xor-convolution.yosupo-bitwise-xor-convolution.test.cpp
    title: verify/xor-convolution.yosupo-bitwise-xor-convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convolution/fast-walsh-hadamard-transform.hpp\"\n#pragma\
    \ region fast_walsh_hadamard_transform\n\nnamespace conv {\n\ttemplate<typename\
    \ T>\n\tvoid fast_walsh_hadamard_transform(vector<T> &a) {\n\t\tint n = a.size();\n\
    \t\tfor (int i = 1; i < n; i <<= 1) {\n\t\t\tfor (int j = 0; j < n; j++) {\n\t\
    \t\t\tif ((j & i) == 0) {\n\t\t\t\t\tT x = a[j], y = a[j | i];\n\t\t\t\t\ta[j]\
    \ = x + y;\n\t\t\t\t\ta[j | i] = x - y;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n}\n\n\
    #pragma endregion fast_walsh_hadamard_transform\n"
  code: "#pragma region fast_walsh_hadamard_transform\n\nnamespace conv {\n\ttemplate<typename\
    \ T>\n\tvoid fast_walsh_hadamard_transform(vector<T> &a) {\n\t\tint n = a.size();\n\
    \t\tfor (int i = 1; i < n; i <<= 1) {\n\t\t\tfor (int j = 0; j < n; j++) {\n\t\
    \t\t\tif ((j & i) == 0) {\n\t\t\t\t\tT x = a[j], y = a[j | i];\n\t\t\t\t\ta[j]\
    \ = x + y;\n\t\t\t\t\ta[j | i] = x - y;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n}\n\n\
    #pragma endregion fast_walsh_hadamard_transform"
  dependsOn: []
  isVerificationFile: false
  path: convolution/fast-walsh-hadamard-transform.hpp
  requiredBy:
  - convolution/xor-convolution.hpp
  - convolution/inverse-fast-walsh-hadamard-transform.hpp
  timestamp: '2022-04-29 22:36:50-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/xor-convolution.yosupo-bitwise-xor-convolution.test.cpp
documentation_of: convolution/fast-walsh-hadamard-transform.hpp
layout: document
title: Fast Walsh-Hadamard Transform
---

## Fast Walsh-Hadamard Transform