---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/static-segment-tree.hpp
    title: Static Segment Tree
  - icon: ':heavy_check_mark:'
    path: tree/euler-tour.hpp
    title: Euler Tour
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"verify/euler-tour.yosupo-vertex-add-subtree-sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"utility/y-combinator.hpp\"\
    \n#pragma region y_combinator\n\n#ifndef Y_COMBINATOR_HPP\n#define Y_COMBINATOR_HPP\n\
    \ntemplate<class Fun>\nclass y_combinator_result {\n\tFun fun_;\npublic:\n\ttemplate<class\
    \ T>\n\texplicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}\n\
    \n\ttemplate<class ...Args>\n\tdecltype(auto) operator()(Args &&...args) {\n\t\
    \treturn fun_(std::ref(*this), std::forward<Args>(args)...);\n\t}\n};\n\ntemplate<class\
    \ Fun>\ndecltype(auto) y_combinator(Fun &&fun) {\n\treturn y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));\n\
    }\n\n#endif\n\n#pragma endregion y_combinator\n#line 2 \"tree/euler-tour.hpp\"\
    \n\n#pragma region euler_tour\n\n#ifndef EULER_TOUR_HPP\n#define EULER_TOUR_HPP\n\
    \nnamespace tree {\n\tpair<vector<int>, vector<int>> euler_tour(const vector<vector<int>>\
    \ &tree, int s = 0) {\n\t\tint n = tree.size();\n\t\tvector<int> ltime(n), rtime(n);\n\
    \t\tint time = -1;\n\n\t\tauto dfs = y_combinator([&](auto dfs, int u, int p =\
    \ -1) -> void {\n\t\t\tltime[u] = ++time;\n\t\t\tfor (int v : tree[u]) {\n\t\t\
    \t\tif (v == p)\n\t\t\t\t\tcontinue;\n\t\t\t\tdfs(v, u);\n\t\t\t}\n\t\t\trtime[u]\
    \ = time;\n\t\t});\n\n\t\tdfs(s);\n\t\treturn make_pair(ltime, rtime);\n\t}\n\
    }\n\n#endif\n\n#pragma endregion euler_tour\n#line 1 \"data-structure/static-segment-tree.hpp\"\
    \n#pragma region sta_segment_tree\n\nclass sta_segment_tree {\n\tusing T = long\
    \ long;\n\n\tstatic constexpr T default_value = 0;\n\n\tstatic void apply(T &a,\
    \ T b) { a += b; }\n\n\tstatic T merge(T a, T b) { return a + b; }\n\nprotected:\n\
    \tint n;\n\tvector<T> tree;\n\npublic:\n\tsta_segment_tree() = default;\n\n\t\
    sta_segment_tree(int _n) { init(_n); }\n\n\tvoid init(int _n) {\n\t\tn = _n;\n\
    \t\ttree.assign(n * 2, default_value);\n\t}\n\n\tvoid update(int i, T v) {\n\t\
    \tfor (apply(tree[i += n], v); i >>= 1;)\n\t\t\ttree[i] = merge(tree[i << 1],\
    \ tree[i << 1 | 1]);\n\t}\n\n\tT query(int l, int r) {\n\t\tT ret = default_value;\n\
    \t\tfor (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {\n\t\t\tif (l & 1) \n\t\
    \t\t\tret = merge(ret, tree[l++]);\n\t\t\tif (r & 1) \n\t\t\t\tret = merge(ret,\
    \ tree[--r]);\n\t\t}\n\t\treturn ret;\n\t}\n\n\tT operator[](int i) { return tree[i\
    \ + n]; }\n};\n\n#pragma endregion sta_segment_tree\n#line 8 \"verify/euler-tour.yosupo-vertex-add-subtree-sum.test.cpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\tvector<long long> A(N);\n\t\
    for (auto &a : A)\n\t\tcin >> a;\n\tvector<vector<int>> T(N);\n\tfor (int i =\
    \ 1; i < N; i++) {\n\t\tint p;\n\t\tcin >> p;\n\t\tT[p].push_back(i);\n\t}\n\n\
    \tauto [ltime, rtime] = tree::euler_tour(T);\n\n\tsta_segment_tree st(N);\n\t\
    for (int u = 0; u < N; u++)\n\t\tst.update(ltime[u], A[u]);\n\twhile (Q--) {\n\
    \t\tint t;\n\t\tcin >> t;\n\t\tif (t == 0) {\n\t\t\tint u;\n\t\t\tlong long x;\n\
    \t\t\tcin >> u >> x;\n\t\t\tst.update(ltime[u], x);\n\t\t} else if (t == 1) {\n\
    \t\t\tint u;\n\t\t\tcin >> u;\n\t\t\tcout << st.query(ltime[u], rtime[u]) << '\\\
    n';\n\t\t}\n\t}\n\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"tree/euler-tour.hpp\"\
    \n#include \"data-structure/static-segment-tree.hpp\"\n\nint main() {\n\tint N,\
    \ Q;\n\tcin >> N >> Q;\n\tvector<long long> A(N);\n\tfor (auto &a : A)\n\t\tcin\
    \ >> a;\n\tvector<vector<int>> T(N);\n\tfor (int i = 1; i < N; i++) {\n\t\tint\
    \ p;\n\t\tcin >> p;\n\t\tT[p].push_back(i);\n\t}\n\n\tauto [ltime, rtime] = tree::euler_tour(T);\n\
    \n\tsta_segment_tree st(N);\n\tfor (int u = 0; u < N; u++)\n\t\tst.update(ltime[u],\
    \ A[u]);\n\twhile (Q--) {\n\t\tint t;\n\t\tcin >> t;\n\t\tif (t == 0) {\n\t\t\t\
    int u;\n\t\t\tlong long x;\n\t\t\tcin >> u >> x;\n\t\t\tst.update(ltime[u], x);\n\
    \t\t} else if (t == 1) {\n\t\t\tint u;\n\t\t\tcin >> u;\n\t\t\tcout << st.query(ltime[u],\
    \ rtime[u]) << '\\n';\n\t\t}\n\t}\n\n}"
  dependsOn:
  - tree/euler-tour.hpp
  - utility/y-combinator.hpp
  - data-structure/static-segment-tree.hpp
  isVerificationFile: true
  path: verify/euler-tour.yosupo-vertex-add-subtree-sum.test.cpp
  requiredBy: []
  timestamp: '2022-05-06 20:02:47-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/euler-tour.yosupo-vertex-add-subtree-sum.test.cpp
layout: document
redirect_from:
- /verify/verify/euler-tour.yosupo-vertex-add-subtree-sum.test.cpp
- /verify/verify/euler-tour.yosupo-vertex-add-subtree-sum.test.cpp.html
title: verify/euler-tour.yosupo-vertex-add-subtree-sum.test.cpp
---
