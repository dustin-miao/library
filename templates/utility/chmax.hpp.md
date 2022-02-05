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
  bundledCode: "#line 1 \"templates/utility/chmax.hpp\"\ntemplate<typename T>\nbool\
    \ chmax(T &a, T b) {\n\tif (a < b) {\n\t\ta = b;\n\t\treturn true;\n\t}\n\treturn\
    \ false;\n}\n"
  code: "template<typename T>\nbool chmax(T &a, T b) {\n\tif (a < b) {\n\t\ta = b;\n\
    \t\treturn true;\n\t}\n\treturn false;\n}"
  dependsOn: []
  isVerificationFile: false
  path: templates/utility/chmax.hpp
  requiredBy: []
  timestamp: '2022-02-04 20:52:31-08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: templates/utility/chmax.hpp
layout: document
redirect_from:
- /library/templates/utility/chmax.hpp
- /library/templates/utility/chmax.hpp.html
title: templates/utility/chmax.hpp
---
