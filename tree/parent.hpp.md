---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/y-combinator.hpp
    title: Y-Combinator
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/diameter.yosupo-tree-diameter.test.cpp
    title: verify/diameter.yosupo-tree-diameter.test.cpp
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
    }\n\n#endif\n\n#pragma endregion y_combinator\n#line 2 \"tree/parent.hpp\"\n\n\
    #pragma region tree_parent\n\n#ifndef TREE_PARENT_HPP\n#define TREE_PARENT_HPP\n\
    \nnamespace tree {\n\tvector<int> parent(const vector<vector<int>> &tree, int\
    \ s = 0) {\n\t\tint n = tree.size();\n\t\tvector<int> par(n);\n\n\t\tauto dfs\
    \ = y_combinator([&](auto dfs, int u) -> void {\n\t\t\tfor (int v : tree[u]) {\n\
    \t\t\t\tif (v == par[u])\n\t\t\t\t\tcontinue;\n\t\t\t\tpar[v] = u;\n\t\t\t\tdfs(v);\n\
    \t\t\t}\n\t\t});\n\t\t\n\t\tpar[s] = s;\n\t\tdfs(s);\n\t\treturn par;\n\t}\n}\n\
    \n#endif\n\n#pragma endregion tree_parent\n"
  code: "#include \"utility/y-combinator.hpp\"\n\n#pragma region tree_parent\n\n#ifndef\
    \ TREE_PARENT_HPP\n#define TREE_PARENT_HPP\n\nnamespace tree {\n\tvector<int>\
    \ parent(const vector<vector<int>> &tree, int s = 0) {\n\t\tint n = tree.size();\n\
    \t\tvector<int> par(n);\n\n\t\tauto dfs = y_combinator([&](auto dfs, int u) ->\
    \ void {\n\t\t\tfor (int v : tree[u]) {\n\t\t\t\tif (v == par[u])\n\t\t\t\t\t\
    continue;\n\t\t\t\tpar[v] = u;\n\t\t\t\tdfs(v);\n\t\t\t}\n\t\t});\n\t\t\n\t\t\
    par[s] = s;\n\t\tdfs(s);\n\t\treturn par;\n\t}\n}\n\n#endif\n\n#pragma endregion\
    \ tree_parent\n"
  dependsOn:
  - utility/y-combinator.hpp
  isVerificationFile: false
  path: tree/parent.hpp
  requiredBy: []
  timestamp: '2022-05-03 13:22:51-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/diameter.yosupo-tree-diameter.test.cpp
documentation_of: tree/parent.hpp
layout: document
title: Parent
---

## Tree Parent