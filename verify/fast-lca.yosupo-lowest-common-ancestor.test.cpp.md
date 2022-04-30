---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/fast-lca.hpp
    title: Fast Lowest Common Ancestor
  - icon: ':question:'
    path: data-structure/sparse-table.hpp
    title: Sparse Table
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"verify/fast-lca.yosupo-lowest-common-ancestor.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"data-structure/sparse-table.hpp\"\n#pragma region\
    \ sparse_table\n\ntemplate<typename T>\nclass sparse_table {\n\tint n, logn;\n\
    \tvector<vector<T>> table;\n\npublic:\n\tsparse_table() = default;\n\n\ttemplate<typename\
    \ I>\n\tsparse_table(I l, I r) { init(l, r); }\n\n\ttemplate<typename I>\n\tvoid\
    \ init(I l, I r) {\n\t\tn = distance(l, r);\n\t\tlogn = 32 - __builtin_clz(n);\n\
    \t\ttable.assign(logn, vector<T>(n));\n\t\tcopy(l, r, table[0].begin());\n\t\t\
    for (int k = 1; k < logn; k++)\n\t\t\tfor (int i = 0; i + (1 << k) <= n; i++)\n\
    \t\t\t\ttable[k][i] = min(table[k - 1][i], table[k - 1][i + (1 << (k - 1))]);\n\
    \t}\n\n\tT query(int l, int r) {\n\t\tint k = 31 - __builtin_clz(r - l + 1);\n\
    \t\treturn min(table[k][l], table[k][r - (1 << k) + 1]);\n\t}\n};\n\n#pragma endregion\
    \ sparse_table\n#line 2 \"data-structure/fast-lca.hpp\"\n\n#pragma region fast_lca\n\
    \nclass fast_lca {\n\tsparse_table<pair<int, int>> st;\n\tvector<int> pos;\n\n\
    public:\n\tfast_lca() = default;\n\n\tfast_lca(const vector<vector<int>> &tree,\
    \ int s = 0) { init(tree, s); }\n\n\ttemplate<typename T>\n\tfast_lca(const vector<vector<pair<int,\
    \ T>>> &tree, int s = 0) { \n\t\tint n = tree.size();\n\t\tvector<vector<int>>\
    \ _tree(n);\n\t\tfor (int u = 0; u < n; u++)\n\t\t\tfor (auto [v, w] : tree[u])\n\
    \t\t\t\t_tree[u].push_back(v);\n\t\tinit(_tree, s); \n\t}\n\n\tvoid init(const\
    \ vector<vector<int>> &tree, int s = 0) {\n\t\tint n = tree.size();\n\t\tpos.resize(n);\n\
    \t\tvector<pair<int, int>> A;\n\t\tA.reserve(2 * n);\n\n\t\tconst auto dfs = [&](const\
    \ auto &self, int u, int d = 0, int p = -1) -> void {\n\t\t\tpos[u] = A.size();\n\
    \t\t\tA.emplace_back(d, u);\n\t\t\tfor (int v : tree[u]) {\n\t\t\t\tif (v == p)\n\
    \t\t\t\t\tcontinue;\n\t\t\t\tself(self, v, d + 1, u);\n\t\t\t\tA.emplace_back(d,\
    \ u);\n\t\t\t}\n\t\t};\n\n\t\tdfs(dfs, s);\n\n\t\tst.init(A.begin(), A.end());\n\
    \t}\n\n\tint query(int u, int v) {\n\t\tif (pos[u] > pos[v])\n\t\t\tswap(u, v);\n\
    \t\tauto [d, a] = st.query(pos[u], pos[v]);\n\t\treturn a;\n\t}\n\n\tint operator()(int\
    \ u, int v) { return query(u, v); }\n};\n\n#pragma endregion fast_lca\n#line 7\
    \ \"verify/fast-lca.yosupo-lowest-common-ancestor.test.cpp\"\n\nint main() {\n\
    \tint N, Q;\n\tcin >> N >> Q;\n\tvector<vector<int>> T(N);\n\tfor (int i = 1;\
    \ i < N; i++) {\n\t\tint p;\n\t\tcin >> p;\n\t\tT[p].push_back(i);\n\t}\n\tfast_lca\
    \ lca(T);\n\twhile (Q--) {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\tcout << lca(u,\
    \ v) << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"data-structure/fast-lca.hpp\"\n\nint main()\
    \ {\n\tint N, Q;\n\tcin >> N >> Q;\n\tvector<vector<int>> T(N);\n\tfor (int i\
    \ = 1; i < N; i++) {\n\t\tint p;\n\t\tcin >> p;\n\t\tT[p].push_back(i);\n\t}\n\
    \tfast_lca lca(T);\n\twhile (Q--) {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\tcout\
    \ << lca(u, v) << '\\n';\n\t}\n}"
  dependsOn:
  - data-structure/fast-lca.hpp
  - data-structure/sparse-table.hpp
  isVerificationFile: true
  path: verify/fast-lca.yosupo-lowest-common-ancestor.test.cpp
  requiredBy: []
  timestamp: '2022-04-29 22:36:50-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/fast-lca.yosupo-lowest-common-ancestor.test.cpp
layout: document
redirect_from:
- /verify/verify/fast-lca.yosupo-lowest-common-ancestor.test.cpp
- /verify/verify/fast-lca.yosupo-lowest-common-ancestor.test.cpp.html
title: verify/fast-lca.yosupo-lowest-common-ancestor.test.cpp
---
