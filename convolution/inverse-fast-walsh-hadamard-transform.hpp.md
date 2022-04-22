---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/fast-walsh-hadamard-transform.hpp
    title: Fast Walsh-Hadamard Transform
  _extendedRequiredBy:
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
    \ region fast walsh hadamard transform\n\nnamespace conv {\n\ttemplate<typename\
    \ T>\n\tvoid fast_walsh_hadamard_transform(vector<T> &a) {\n\t\tint n = a.size();\n\
    \t\tfor (int i = 1; i < n; i <<= 1) {\n\t\t\tfor (int j = 0; j < n; j++) {\n\t\
    \t\t\tif ((j & i) == 0) {\n\t\t\t\t\tT x = a[j], y = a[j | i];\n\t\t\t\t\ta[j]\
    \ = x + y;\n\t\t\t\t\ta[j | i] = x - y;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n}\n\n\
    #pragma endregion fast walsh hadamard transform\n#line 2 \"convolution/inverse-fast-walsh-hadamard-transform.hpp\"\
    \n\n#pragma region inverse fast walsh hadamard transform\n\nnamespace conv {\n\
    \ttemplate<typename T>\n\tvoid inverse_fast_walsh_hadamard_transform(vector<T>\
    \ &a) {\n\t\tfast_walsh_hadamard_transform<T>(a);\n\t\tif constexpr (is_integral<T>::value)\
    \ {\n\t\t\tint n = a.size();\n\t\t\tfor (auto &x : a)\n\t\t\t\tx /= n;\n\t\t}\
    \ else {\n\t\t\tT t = T(1) / T(a.size());\n\t\t\tfor (auto &x : a)\n\t\t\t\tx\
    \ *= t;\n\t\t}\n\t}\n}\n\n#pragma endregion inverse fast walsh hadamard transform\n"
  code: "#include \"convolution/fast-walsh-hadamard-transform.hpp\"\n\n#pragma region\
    \ inverse fast walsh hadamard transform\n\nnamespace conv {\n\ttemplate<typename\
    \ T>\n\tvoid inverse_fast_walsh_hadamard_transform(vector<T> &a) {\n\t\tfast_walsh_hadamard_transform<T>(a);\n\
    \t\tif constexpr (is_integral<T>::value) {\n\t\t\tint n = a.size();\n\t\t\tfor\
    \ (auto &x : a)\n\t\t\t\tx /= n;\n\t\t} else {\n\t\t\tT t = T(1) / T(a.size());\n\
    \t\t\tfor (auto &x : a)\n\t\t\t\tx *= t;\n\t\t}\n\t}\n}\n\n#pragma endregion inverse\
    \ fast walsh hadamard transform"
  dependsOn:
  - convolution/fast-walsh-hadamard-transform.hpp
  isVerificationFile: false
  path: convolution/inverse-fast-walsh-hadamard-transform.hpp
  requiredBy:
  - convolution/xor-convolution.hpp
  timestamp: '2022-04-21 20:28:30-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/xor-convolution.yosupo-bitwise-xor-convolution.test.cpp
documentation_of: convolution/inverse-fast-walsh-hadamard-transform.hpp
layout: document
title: Inverse Fast Walsh-Hadamard Transform
---

## Inverse Fast Walsh-Hadamard Transform