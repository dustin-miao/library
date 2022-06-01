---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tree/depth.hpp
    title: Depth
  - icon: ':heavy_check_mark:'
    path: tree/diameter.hpp
    title: Diameter
  - icon: ':heavy_check_mark:'
    path: tree/distance.hpp
    title: Distance
  - icon: ':heavy_check_mark:'
    path: tree/euler-tour.hpp
    title: Euler Tour
  - icon: ':heavy_check_mark:'
    path: tree/parent.hpp
    title: Parent
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/diameter.yosupo-tree-diameter.test.cpp
    title: verify/diameter.yosupo-tree-diameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/euler-tour.yosupo-vertex-add-subtree-sum.test.cpp
    title: verify/euler-tour.yosupo-vertex-add-subtree-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/y-combinator.aizu-greatest-common-denominator.test.cpp
    title: verify/y-combinator.aizu-greatest-common-denominator.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utility/y-combinator.hpp\"\n#pragma region y_combinator\n\
    \n#ifndef Y_COMBINATOR_HPP\n#define Y_COMBINATOR_HPP\n\ntemplate<class Fun>\n\
    class y_combinator_result {\n\tFun fun_;\npublic:\n\ttemplate<class T>\n\texplicit\
    \ y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}\n\n\ttemplate<class\
    \ ...Args>\n\tdecltype(auto) operator()(Args &&...args) {\n\t\treturn fun_(std::ref(*this),\
    \ std::forward<Args>(args)...);\n\t}\n};\n\ntemplate<class Fun>\ndecltype(auto)\
    \ y_combinator(Fun &&fun) {\n\treturn y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));\n\
    }\n\n#endif\n\n#pragma endregion y_combinator\n"
  code: "#pragma region y_combinator\n\n#ifndef Y_COMBINATOR_HPP\n#define Y_COMBINATOR_HPP\n\
    \ntemplate<class Fun>\nclass y_combinator_result {\n\tFun fun_;\npublic:\n\ttemplate<class\
    \ T>\n\texplicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}\n\
    \n\ttemplate<class ...Args>\n\tdecltype(auto) operator()(Args &&...args) {\n\t\
    \treturn fun_(std::ref(*this), std::forward<Args>(args)...);\n\t}\n};\n\ntemplate<class\
    \ Fun>\ndecltype(auto) y_combinator(Fun &&fun) {\n\treturn y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));\n\
    }\n\n#endif\n\n#pragma endregion y_combinator"
  dependsOn: []
  isVerificationFile: false
  path: utility/y-combinator.hpp
  requiredBy:
  - tree/diameter.hpp
  - tree/euler-tour.hpp
  - tree/depth.hpp
  - tree/distance.hpp
  - tree/parent.hpp
  timestamp: '2022-05-03 13:22:51-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/y-combinator.aizu-greatest-common-denominator.test.cpp
  - verify/diameter.yosupo-tree-diameter.test.cpp
  - verify/euler-tour.yosupo-vertex-add-subtree-sum.test.cpp
documentation_of: utility/y-combinator.hpp
layout: document
title: Y-Combinator
---

## Y-Combinator

Copied from [Open STD](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html). 