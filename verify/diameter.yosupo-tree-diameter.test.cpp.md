---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tree/depth.hpp
    title: tree/depth.hpp
  - icon: ':heavy_check_mark:'
    path: tree/diameter.hpp
    title: tree/diameter.hpp
  - icon: ':heavy_check_mark:'
    path: tree/distance.hpp
    title: tree/distance.hpp
  - icon: ':heavy_check_mark:'
    path: tree/parent.hpp
    title: tree/parent.hpp
  - icon: ':heavy_check_mark:'
    path: tree/unweight.hpp
    title: tree/unweight.hpp
  - icon: ':heavy_check_mark:'
    path: utility/y-combinator.hpp
    title: Y-Combinator
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"verify/diameter.yosupo-tree-diameter.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"utility/y-combinator.hpp\"\n#pragma region y_combinator\n\
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
    \ v, dis2[v]);\n\t}\n}\n\n#endif\n\n#pragma endregion tree_diameter\n#line 1 \"\
    utility/y-combinator.hpp\"\n#pragma region y_combinator\n\n#ifndef Y_COMBINATOR_HPP\n\
    #define Y_COMBINATOR_HPP\n\ntemplate<class Fun>\nclass y_combinator_result {\n\
    \tFun fun_;\npublic:\n\ttemplate<class T>\n\texplicit y_combinator_result(T &&fun)\
    \ : fun_(std::forward<T>(fun)) {}\n\n\ttemplate<class ...Args>\n\tdecltype(auto)\
    \ operator()(Args &&...args) {\n\t\treturn fun_(std::ref(*this), std::forward<Args>(args)...);\n\
    \t}\n};\n\ntemplate<class Fun>\ndecltype(auto) y_combinator(Fun &&fun) {\n\treturn\
    \ y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));\n}\n\n#endif\n\
    \n#pragma endregion y_combinator\n#line 2 \"tree/parent.hpp\"\n\n#pragma region\
    \ tree_parent\n\n#ifndef TREE_PARENT_HPP\n#define TREE_PARENT_HPP\n\nnamespace\
    \ tree {\n\tvector<int> parent(const vector<vector<int>> &tree, int s = 0) {\n\
    \t\tint n = tree.size();\n\t\tvector<int> par(n);\n\n\t\tauto dfs = y_combinator([&](auto\
    \ dfs, int u) -> void {\n\t\t\tfor (int v : tree[u]) {\n\t\t\t\tif (v == par[u])\n\
    \t\t\t\t\tcontinue;\n\t\t\t\tpar[v] = u;\n\t\t\t\tdfs(v);\n\t\t\t}\n\t\t});\n\t\
    \t\n\t\tpar[s] = s;\n\t\tdfs(s);\n\t\treturn par;\n\t}\n}\n\n#endif\n\n#pragma\
    \ endregion tree_parent\n#line 1 \"tree/unweight.hpp\"\n#pragma region tree_unweight\
    \ \n\n#ifndef TREE_UNWEIGHT_HPP\n#define TREE_UNWEIGHT_HPP\n\nnamespace tree {\n\
    \ttemplate<typename T>\n\tvector<vector<int>> unweight(const vector<vector<pair<int,\
    \ T>>> &tree) {\n\t\tint n = tree.size();\n\t\tvector<vector<int>> ret(n);\n\t\
    \tfor (int u = 0; u < n; u++) \n\t\t\tfor (auto [v, w] : tree[u])\n\t\t\t\tret[u].push_back(v);\n\
    \t\treturn ret;\n\t}\n}\n\n#endif\n\n#pragma endregion tree_unweight\n#line 9\
    \ \"verify/diameter.yosupo-tree-diameter.test.cpp\"\n\nint main() {\n\tint N;\n\
    \tcin >> N;\n\tvector<vector<pair<int, long long>>> T(N);\n\tfor (int i = 1; i\
    \ < N; i++) {\n\t\tint u, v;\n\t\tlong long w;\n\t\tcin >> u >> v >> w;\n\t\t\
    T[u].emplace_back(v, w);\n\t\tT[v].emplace_back(u, w);\n\t}\n\n\tauto [e1, e2,\
    \ d] = tree::diameter(T);\n\tauto par = tree::parent(tree::unweight(T), e1);\n\
    \n\tvector<int> ans;\n\tfor (int u = e2; u != e1; u = par[u]) \n\t\tans.push_back(u);\n\
    \tans.push_back(e1);\n\n\tcout << d << ' ' << ans.size() << '\\n';\n\tfor (int\
    \ u : ans)\n\t\tcout << u << ' ';\n\tcout << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"tree/diameter.hpp\"\n#include\
    \ \"tree/parent.hpp\"\n#include \"tree/unweight.hpp\"\n\nint main() {\n\tint N;\n\
    \tcin >> N;\n\tvector<vector<pair<int, long long>>> T(N);\n\tfor (int i = 1; i\
    \ < N; i++) {\n\t\tint u, v;\n\t\tlong long w;\n\t\tcin >> u >> v >> w;\n\t\t\
    T[u].emplace_back(v, w);\n\t\tT[v].emplace_back(u, w);\n\t}\n\n\tauto [e1, e2,\
    \ d] = tree::diameter(T);\n\tauto par = tree::parent(tree::unweight(T), e1);\n\
    \n\tvector<int> ans;\n\tfor (int u = e2; u != e1; u = par[u]) \n\t\tans.push_back(u);\n\
    \tans.push_back(e1);\n\n\tcout << d << ' ' << ans.size() << '\\n';\n\tfor (int\
    \ u : ans)\n\t\tcout << u << ' ';\n\tcout << '\\n';\n}"
  dependsOn:
  - tree/diameter.hpp
  - tree/depth.hpp
  - utility/y-combinator.hpp
  - tree/distance.hpp
  - tree/parent.hpp
  - tree/unweight.hpp
  isVerificationFile: true
  path: verify/diameter.yosupo-tree-diameter.test.cpp
  requiredBy: []
  timestamp: '2022-05-03 13:22:51-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/diameter.yosupo-tree-diameter.test.cpp
layout: document
redirect_from:
- /verify/verify/diameter.yosupo-tree-diameter.test.cpp
- /verify/verify/diameter.yosupo-tree-diameter.test.cpp.html
title: verify/diameter.yosupo-tree-diameter.test.cpp
---
