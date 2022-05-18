---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/manacher.yosupo-enumerate-palindromes.test.cpp
    title: verify/manacher.yosupo-enumerate-palindromes.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/manacher.hpp\"\n#pragma region str_manacher\n\n#ifndef\
    \ STR_MANACHER_HPP\n#define STR_MANACHER_HPP\n\nnamespace str {\n\tvector<int>\
    \ manacher(const string &s) {\n\t\tint n = s.size();\n\t\tvector<int> d1(n), d2(n);\n\
    \t\tfor (int i = 0, l = 0, r = -1; i < n; i++) {\n\t\t\tint k = (i > r) ? 1 :\
    \ min(d1[l + r - i], r - i + 1);\n\t\t\tfor (; 0 <= i - k && i + k < n && s[i\
    \ - k] == s[i + k]; k++);\n\t\t\td1[i] = k--;\n\t\t\tif (i + k > r) \n\t\t\t\t\
    l = i - k, r = i + k;\n\t\t}\n\t\tfor (int i = 0, l = 0, r = -1; i < n; i++) {\n\
    \t\t\tint k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);\n\t\t\tfor (; 0\
    \ <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]; k++);\n\t\t\td2[i] =\
    \ k--;\n\t\t\tif (i + k > r) \n\t\t\t\tl = i - k - 1, r = i + k;\n\t\t}\n\n\t\t\
    vector<int> d(2 * n - 1);\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\td[i * 2] =\
    \ d1[i] * 2 - 1;\n\t\t\tif (i != n - 1)\n\t\t\t\td[i * 2 + 1] = d2[i + 1] * 2;\n\
    \t\t}\n\t\treturn d;\n\t}\n}\n\n#endif\n\n#pragma endregion str_manacher\n"
  code: "#pragma region str_manacher\n\n#ifndef STR_MANACHER_HPP\n#define STR_MANACHER_HPP\n\
    \nnamespace str {\n\tvector<int> manacher(const string &s) {\n\t\tint n = s.size();\n\
    \t\tvector<int> d1(n), d2(n);\n\t\tfor (int i = 0, l = 0, r = -1; i < n; i++)\
    \ {\n\t\t\tint k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);\n\t\t\tfor (;\
    \ 0 <= i - k && i + k < n && s[i - k] == s[i + k]; k++);\n\t\t\td1[i] = k--;\n\
    \t\t\tif (i + k > r) \n\t\t\t\tl = i - k, r = i + k;\n\t\t}\n\t\tfor (int i =\
    \ 0, l = 0, r = -1; i < n; i++) {\n\t\t\tint k = (i > r) ? 0 : min(d2[l + r -\
    \ i + 1], r - i + 1);\n\t\t\tfor (; 0 <= i - k - 1 && i + k < n && s[i - k - 1]\
    \ == s[i + k]; k++);\n\t\t\td2[i] = k--;\n\t\t\tif (i + k > r) \n\t\t\t\tl = i\
    \ - k - 1, r = i + k;\n\t\t}\n\n\t\tvector<int> d(2 * n - 1);\n\t\tfor (int i\
    \ = 0; i < n; i++) {\n\t\t\td[i * 2] = d1[i] * 2 - 1;\n\t\t\tif (i != n - 1)\n\
    \t\t\t\td[i * 2 + 1] = d2[i + 1] * 2;\n\t\t}\n\t\treturn d;\n\t}\n}\n\n#endif\n\
    \n#pragma endregion str_manacher\n"
  dependsOn: []
  isVerificationFile: false
  path: string/manacher.hpp
  requiredBy: []
  timestamp: '2022-05-18 13:16:46-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/manacher.yosupo-enumerate-palindromes.test.cpp
documentation_of: string/manacher.hpp
layout: document
redirect_from:
- /library/string/manacher.hpp
- /library/string/manacher.hpp.html
title: string/manacher.hpp
---
