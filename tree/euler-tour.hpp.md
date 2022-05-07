---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/y-combinator.hpp
    title: Y-Combinator
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/euler-tour.yosupo-vertex-add-subtree-sum.test.cpp
    title: verify/euler-tour.yosupo-vertex-add-subtree-sum.test.cpp
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
    }\n\n#endif\n\n#pragma endregion y_combinator\n#line 2 \"tree/euler-tour.hpp\"\
    \n\n#pragma region euler_tour\n\n#ifndef EULER_TOUR_HPP\n#define EULER_TOUR_HPP\n\
    \nnamespace tree {\n\tpair<vector<int>, vector<int>> euler_tour(const vector<vector<int>>\
    \ &tree, int s = 0) {\n\t\tint n = tree.size();\n\t\tvector<int> ltime(n), rtime(n);\n\
    \t\tint time = -1;\n\n\t\tauto dfs = y_combinator([&](auto dfs, int u, int p =\
    \ -1) -> void {\n\t\t\tltime[u] = ++time;\n\t\t\tfor (int v : tree[u]) {\n\t\t\
    \t\tif (v == p)\n\t\t\t\t\tcontinue;\n\t\t\t\tdfs(v, u);\n\t\t\t}\n\t\t\trtime[u]\
    \ = time;\n\t\t});\n\n\t\tdfs(s);\n\t\treturn make_pair(ltime, rtime);\n\t}\n\
    }\n\n#endif\n\n#pragma endregion euler_tour\n"
  code: "#include \"utility/y-combinator.hpp\"\n\n#pragma region euler_tour\n\n#ifndef\
    \ EULER_TOUR_HPP\n#define EULER_TOUR_HPP\n\nnamespace tree {\n\tpair<vector<int>,\
    \ vector<int>> euler_tour(const vector<vector<int>> &tree, int s = 0) {\n\t\t\
    int n = tree.size();\n\t\tvector<int> ltime(n), rtime(n);\n\t\tint time = -1;\n\
    \n\t\tauto dfs = y_combinator([&](auto dfs, int u, int p = -1) -> void {\n\t\t\
    \tltime[u] = ++time;\n\t\t\tfor (int v : tree[u]) {\n\t\t\t\tif (v == p)\n\t\t\
    \t\t\tcontinue;\n\t\t\t\tdfs(v, u);\n\t\t\t}\n\t\t\trtime[u] = time;\n\t\t});\n\
    \n\t\tdfs(s);\n\t\treturn make_pair(ltime, rtime);\n\t}\n}\n\n#endif\n\n#pragma\
    \ endregion euler_tour"
  dependsOn:
  - utility/y-combinator.hpp
  isVerificationFile: false
  path: tree/euler-tour.hpp
  requiredBy: []
  timestamp: '2022-05-06 20:02:47-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/euler-tour.yosupo-vertex-add-subtree-sum.test.cpp
documentation_of: tree/euler-tour.hpp
layout: document
title: Euler Tour
---

## Euler Tour