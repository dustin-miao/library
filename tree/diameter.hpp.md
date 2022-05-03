---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tree/depth.hpp
    title: tree/depth.hpp
  - icon: ':heavy_check_mark:'
    path: tree/distance.hpp
    title: tree/distance.hpp
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
    }\n\n#endif\n\n#pragma endregion y_combinator\n#line 2 \"tree/depth.hpp\"\n\n\
    #pragma region tree_depth\n\n#ifndef TREE_DEPTH_HPP\n#define TREE_DEPTH_HPP\n\n\
    namespace tree {\n\tvector<int> depth(const vector<vector<int>> &tree, int s =\
    \ 0) {\n\t\tint n = tree.size();\n\t\tvector<int> dep(n);\n\n\t\tauto dfs = y_combinator([&](auto\
    \ dfs, int u, int p = -1) -> void {\n\t\t\tfor (int v : tree[u]) {\n\t\t\t\tif\
    \ (v == p)\n\t\t\t\t\tcontinue;\n\t\t\t\tdep[v] = dep[u] + 1;\n\t\t\t\tdfs(v,\
    \ u);\n\t\t\t}\n\t\t});\n\n\t\tdep[s] = 0;\n\t\tdfs(s);\n\t\treturn dep;\n\t}\n\
    }\n\n#endif\n\n#pragma endregion tree_depth\n#line 1 \"utility/y-combinator.hpp\"\
    \n#pragma region y_combinator\n\n#ifndef Y_COMBINATOR_HPP\n#define Y_COMBINATOR_HPP\n\
    \ntemplate<class Fun>\nclass y_combinator_result {\n\tFun fun_;\npublic:\n\ttemplate<class\
    \ T>\n\texplicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}\n\
    \n\ttemplate<class ...Args>\n\tdecltype(auto) operator()(Args &&...args) {\n\t\
    \treturn fun_(std::ref(*this), std::forward<Args>(args)...);\n\t}\n};\n\ntemplate<class\
    \ Fun>\ndecltype(auto) y_combinator(Fun &&fun) {\n\treturn y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));\n\
    }\n\n#endif\n\n#pragma endregion y_combinator\n#line 2 \"tree/distance.hpp\"\n\
    \n#pragma region tree_distance\n\n#ifndef TREE_DISTANCE_HPP\n#define TREE_DISTANCE_HPP\n\
    \nnamespace tree {\n\ttemplate<typename T>\n\tvector<T> distance(const vector<vector<pair<int,\
    \ T>>> &tree, int s = 0) {\n\t\tint n = tree.size();\n\t\tvector<T> dis(n);\n\n\
    \t\tauto dfs = y_combinator([&](auto dfs, int u, int p = -1) -> void {\n\t\t\t\
    for (auto [v, w] : tree[u]) {\n\t\t\t\tif (v == p)\n\t\t\t\t\tcontinue;\n\t\t\t\
    \tdis[v] = dis[u] + w;\n\t\t\t\tdfs(v, u);\n\t\t\t}\n\t\t});\n\n\t\tdis[s] = 0;\n\
    \t\tdfs(s);\n\t\treturn dis;\n\t}\n}\n\n#endif\n\n#pragma endregion tree_distance\n\
    #line 3 \"tree/diameter.hpp\"\n\n#pragma region tree_diameter\n\n#ifndef TREE_DIAMETER_HPP\n\
    #define TREE_DIAMETER_HPP\n\nnamespace tree {\n\ttuple<int, int, int> diameter(const\
    \ vector<vector<int>> &tree) {\n\t\tauto dep1 = depth(tree, 0);\n\t\tint u = max_element(dep1.begin(),\
    \ dep1.end()) - dep1.begin();\n\t\tauto dep2 = depth(tree, u);\n\t\tint v = max_element(dep2.begin(),\
    \ dep2.end()) - dep2.begin();\n\t\treturn make_tuple(u, v, dep2[v]);\n\t}\n\n\t\
    template<typename T>\n\ttuple<int, int, T> diameter(const vector<vector<pair<int,\
    \ T>>> &tree) {\n\t\tauto dis1 = distance(tree, 0);\n\t\tint u = max_element(dis1.begin(),\
    \ dis1.end()) - dis1.begin();\n\t\tauto dis2 = distance(tree, u);\n\t\tint v =\
    \ max_element(dis2.begin(), dis2.end()) - dis2.begin();\n\t\treturn make_tuple(u,\
    \ v, dis2[v]);\n\t}\n}\n\n#endif\n\n#pragma endregion tree_diameter\n"
  code: "#include \"tree/depth.hpp\"\n#include \"tree/distance.hpp\"\n\n#pragma region\
    \ tree_diameter\n\n#ifndef TREE_DIAMETER_HPP\n#define TREE_DIAMETER_HPP\n\nnamespace\
    \ tree {\n\ttuple<int, int, int> diameter(const vector<vector<int>> &tree) {\n\
    \t\tauto dep1 = depth(tree, 0);\n\t\tint u = max_element(dep1.begin(), dep1.end())\
    \ - dep1.begin();\n\t\tauto dep2 = depth(tree, u);\n\t\tint v = max_element(dep2.begin(),\
    \ dep2.end()) - dep2.begin();\n\t\treturn make_tuple(u, v, dep2[v]);\n\t}\n\n\t\
    template<typename T>\n\ttuple<int, int, T> diameter(const vector<vector<pair<int,\
    \ T>>> &tree) {\n\t\tauto dis1 = distance(tree, 0);\n\t\tint u = max_element(dis1.begin(),\
    \ dis1.end()) - dis1.begin();\n\t\tauto dis2 = distance(tree, u);\n\t\tint v =\
    \ max_element(dis2.begin(), dis2.end()) - dis2.begin();\n\t\treturn make_tuple(u,\
    \ v, dis2[v]);\n\t}\n}\n\n#endif\n\n#pragma endregion tree_diameter"
  dependsOn:
  - tree/depth.hpp
  - utility/y-combinator.hpp
  - tree/distance.hpp
  isVerificationFile: false
  path: tree/diameter.hpp
  requiredBy: []
  timestamp: '2022-05-03 13:22:51-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/diameter.yosupo-tree-diameter.test.cpp
documentation_of: tree/diameter.hpp
layout: document
redirect_from:
- /library/tree/diameter.hpp
- /library/tree/diameter.hpp.html
title: tree/diameter.hpp
---
