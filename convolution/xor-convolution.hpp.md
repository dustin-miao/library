---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: convolution/fast-walsh-hadamard-transform.hpp
    title: Fast Walsh-Hadamard Transform
  - icon: ':x:'
    path: convolution/inverse-fast-walsh-hadamard-transform.hpp
    title: Inverse Fast Walsh-Hadamard Transform
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/xor-convolution.yosupo-bitwise-xor-convolution.test.cpp
    title: verify/xor-convolution.yosupo-bitwise-xor-convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convolution/fast-walsh-hadamard-transform.hpp\"\n#pragma\
    \ region fast_walsh_hadamard_transform\n\nnamespace conv {\n\ttemplate<typename\
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
    \t}\n}\n\n#pragma endregion xor_convolution\n"
  code: "#include \"convolution/inverse-fast-walsh-hadamard-transform.hpp\"\n\n#pragma\
    \ region xor_convolution\n\nnamespace conv {\n\ttemplate<typename T>\n\tvector<T>\
    \ xor_convolution(const vector<T> &a, const vector<T> &b) {\n\t\tvector<T> pa(a.begin(),\
    \ a.end()), pb(b.begin(), b.end());\n\t\tint n = 1;\n\t\twhile (n < a.size() +\
    \ b.size()) \n\t\t\tn <<= 1;\n\t\tpa.resize(n), pb.resize(n);\n\t\tfast_walsh_hadamard_transform(pa);\n\
    \t\tfast_walsh_hadamard_transform(pb);\n\t\tfor (int i = 0; i < n; i++)\n\t\t\t\
    pa[i] *= pb[i];\n\t\tinverse_fast_walsh_hadamard_transform(pa);\n\t\treturn pa;\n\
    \t}\n}\n\n#pragma endregion xor_convolution"
  dependsOn:
  - convolution/inverse-fast-walsh-hadamard-transform.hpp
  - convolution/fast-walsh-hadamard-transform.hpp
  isVerificationFile: false
  path: convolution/xor-convolution.hpp
  requiredBy: []
  timestamp: '2022-04-29 22:36:50-07:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/xor-convolution.yosupo-bitwise-xor-convolution.test.cpp
documentation_of: convolution/xor-convolution.hpp
layout: document
title: Xor Convolution
---

## Xor Convolution