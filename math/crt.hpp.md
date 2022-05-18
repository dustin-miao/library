---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/ext-gcd.hpp
    title: Extended GCD
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/ext-gcd.hpp\"\n#pragma region extended_gcd\n\nnamespace\
    \ math {\n\ttemplate<typename T>\n\tT ext_gcd(T a, T b, T &x, T &y) {\n\t\tx =\
    \ 1, y = 0;\n\t\tT x1 = 0, y1 = 1, a1 = a, b1 = b;\n\t\twhile (b1) {\n\t\t\tT\
    \ q = a1 / b1;\n\t\t\ttie(x, x1) = make_tuple(x1, x - q * x1);\n\t\t\ttie(y, y1)\
    \ = make_tuple(y1, y - q * y1);\n\t\t\ttie(a1, b1) = make_tuple(b1, a1 - q * b1);\n\
    \t\t}\n\t\treturn a1;\n\t}\n}\n\n#pragma endregion extended_gcd\n#line 2 \"math/crt.hpp\"\
    \n\n#pragma region chinese_remainder_theorem\n\nnamespace math {\n\ttemplate<typename\
    \ T>\n\tT crt(const pair<T, T> &p1, const pair<T, T> &p2) {\n\t\tauto [a1, m1]\
    \ = p1;\n\t\tauto [a2, m2] = p2;\n\t\tif (a2 < a1) {\n\t\t\tswap(a1, a2);\n\t\t\
    \tswap(m1, m2);\n\t\t}\n\t\tT n1, n2;\n\t\tT g = ext_gcd(m1, m2, n1, n2), l =\
    \ m1 / g * m2; \n\t\tif ((a2 - a1) % g != 0)\n\t\t\treturn -1;\n\t\treturn (n1\
    \ * (a2 - a1) / g % (m2 / g) * m1 + a1 + l) % l;\n\t}\n}\n\n#pragma endregion\
    \ chinese_remainder_theorem\n"
  code: "#include \"math/ext-gcd.hpp\"\n\n#pragma region chinese_remainder_theorem\n\
    \nnamespace math {\n\ttemplate<typename T>\n\tT crt(const pair<T, T> &p1, const\
    \ pair<T, T> &p2) {\n\t\tauto [a1, m1] = p1;\n\t\tauto [a2, m2] = p2;\n\t\tif\
    \ (a2 < a1) {\n\t\t\tswap(a1, a2);\n\t\t\tswap(m1, m2);\n\t\t}\n\t\tT n1, n2;\n\
    \t\tT g = ext_gcd(m1, m2, n1, n2), l = m1 / g * m2; \n\t\tif ((a2 - a1) % g !=\
    \ 0)\n\t\t\treturn -1;\n\t\treturn (n1 * (a2 - a1) / g % (m2 / g) * m1 + a1 +\
    \ l) % l;\n\t}\n}\n\n#pragma endregion chinese_remainder_theorem"
  dependsOn:
  - math/ext-gcd.hpp
  isVerificationFile: false
  path: math/crt.hpp
  requiredBy: []
  timestamp: '2022-04-29 22:36:50-07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/crt.hpp
layout: document
title: Chinese Remainder Theorem
---

## Chinese Remainder Theorem