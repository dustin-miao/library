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
  bundledCode: "#line 1 \"templates/utility/addmod.hpp\"\ntemplate<typename T>\nT\
    \ addmod(T a, T b, long long MOD) {\n\tT t = a + b;\n\treturn t >= MOD ? t - MOD\
    \ : t;\n}\n"
  code: "template<typename T>\nT addmod(T a, T b, long long MOD) {\n\tT t = a + b;\n\
    \treturn t >= MOD ? t - MOD : t;\n}"
  dependsOn: []
  isVerificationFile: false
  path: templates/utility/addmod.hpp
  requiredBy: []
  timestamp: '2022-02-04 20:52:31-08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: templates/utility/addmod.hpp
layout: document
redirect_from:
- /library/templates/utility/addmod.hpp
- /library/templates/utility/addmod.hpp.html
title: templates/utility/addmod.hpp
---
