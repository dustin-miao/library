---
data:
  _extendedDependsOn: []
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
  bundledCode: "#line 1 \"tree/unweight.hpp\"\n#pragma region tree_unweight \n\n#ifndef\
    \ TREE_UNWEIGHT_HPP\n#define TREE_UNWEIGHT_HPP\n\nnamespace tree {\n\ttemplate<typename\
    \ T>\n\tvector<vector<int>> unweight(const vector<vector<pair<int, T>>> &tree)\
    \ {\n\t\tint n = tree.size();\n\t\tvector<vector<int>> ret(n);\n\t\tfor (int u\
    \ = 0; u < n; u++) \n\t\t\tfor (auto [v, w] : tree[u])\n\t\t\t\tret[u].push_back(v);\n\
    \t\treturn ret;\n\t}\n}\n\n#endif\n\n#pragma endregion tree_unweight\n"
  code: "#pragma region tree_unweight \n\n#ifndef TREE_UNWEIGHT_HPP\n#define TREE_UNWEIGHT_HPP\n\
    \nnamespace tree {\n\ttemplate<typename T>\n\tvector<vector<int>> unweight(const\
    \ vector<vector<pair<int, T>>> &tree) {\n\t\tint n = tree.size();\n\t\tvector<vector<int>>\
    \ ret(n);\n\t\tfor (int u = 0; u < n; u++) \n\t\t\tfor (auto [v, w] : tree[u])\n\
    \t\t\t\tret[u].push_back(v);\n\t\treturn ret;\n\t}\n}\n\n#endif\n\n#pragma endregion\
    \ tree_unweight"
  dependsOn: []
  isVerificationFile: false
  path: tree/unweight.hpp
  requiredBy: []
  timestamp: '2022-05-03 13:22:51-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/diameter.yosupo-tree-diameter.test.cpp
documentation_of: tree/unweight.hpp
layout: document
redirect_from:
- /library/tree/unweight.hpp
- /library/tree/unweight.hpp.html
title: tree/unweight.hpp
---
