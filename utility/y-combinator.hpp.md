---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/y-combinator.aizu-greatest-common-denominator.test.cpp
    title: verify/y-combinator.aizu-greatest-common-denominator.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utility/y-combinator.hpp\"\n#pragma region y_combinator\n\
    \ntemplate<class Fun>\nclass y_combinator_result {\n\tFun fun_;\npublic:\n\ttemplate<class\
    \ T>\n\texplicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}\n\
    \n\ttemplate<class ...Args>\n\tdecltype(auto) operator()(Args &&...args) {\n\t\
    \treturn fun_(std::ref(*this), std::forward<Args>(args)...);\n\t}\n};\n\ntemplate<class\
    \ Fun>\ndecltype(auto) y_combinator(Fun &&fun) {\n\treturn y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));\n\
    }\n\n#pragma endregion y_combinator\n"
  code: "#pragma region y_combinator\n\ntemplate<class Fun>\nclass y_combinator_result\
    \ {\n\tFun fun_;\npublic:\n\ttemplate<class T>\n\texplicit y_combinator_result(T\
    \ &&fun): fun_(std::forward<T>(fun)) {}\n\n\ttemplate<class ...Args>\n\tdecltype(auto)\
    \ operator()(Args &&...args) {\n\t\treturn fun_(std::ref(*this), std::forward<Args>(args)...);\n\
    \t}\n};\n\ntemplate<class Fun>\ndecltype(auto) y_combinator(Fun &&fun) {\n\treturn\
    \ y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));\n}\n\n#pragma\
    \ endregion y_combinator"
  dependsOn: []
  isVerificationFile: false
  path: utility/y-combinator.hpp
  requiredBy: []
  timestamp: '2022-04-29 22:36:50-07:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/y-combinator.aizu-greatest-common-denominator.test.cpp
documentation_of: utility/y-combinator.hpp
layout: document
title: Y-Combinator
---

## Y-Combinator

Copied from [Open STD](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html). 