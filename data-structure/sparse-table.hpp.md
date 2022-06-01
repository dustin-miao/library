---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data-structure/fast-lca.hpp
    title: Fast Lowest Common Ancestor
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/fast-lca.yosupo-lowest-common-ancestor.test.cpp
    title: verify/fast-lca.yosupo-lowest-common-ancestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/sparse-table.yosupo-static-rmq.test.cpp
    title: verify/sparse-table.yosupo-static-rmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/sparse-table.hpp\"\n#pragma region sparse_table\n\
    \ntemplate<typename T>\nclass sparse_table {\n\tint n, logn;\n\tvector<vector<T>>\
    \ table;\n\npublic:\n\tsparse_table() = default;\n\n\ttemplate<typename I>\n\t\
    sparse_table(I l, I r) { init(l, r); }\n\n\ttemplate<typename I>\n\tvoid init(I\
    \ l, I r) {\n\t\tn = distance(l, r);\n\t\tlogn = 32 - __builtin_clz(n);\n\t\t\
    table.assign(logn, vector<T>(n));\n\t\tcopy(l, r, table[0].begin());\n\t\tfor\
    \ (int k = 1; k < logn; k++)\n\t\t\tfor (int i = 0; i + (1 << k) <= n; i++)\n\t\
    \t\t\ttable[k][i] = min(table[k - 1][i], table[k - 1][i + (1 << (k - 1))]);\n\t\
    }\n\n\tT query(int l, int r) {\n\t\tint k = 31 - __builtin_clz(r - l + 1);\n\t\
    \treturn min(table[k][l], table[k][r - (1 << k) + 1]);\n\t}\n};\n\n#pragma endregion\
    \ sparse_table\n"
  code: "#pragma region sparse_table\n\ntemplate<typename T>\nclass sparse_table {\n\
    \tint n, logn;\n\tvector<vector<T>> table;\n\npublic:\n\tsparse_table() = default;\n\
    \n\ttemplate<typename I>\n\tsparse_table(I l, I r) { init(l, r); }\n\n\ttemplate<typename\
    \ I>\n\tvoid init(I l, I r) {\n\t\tn = distance(l, r);\n\t\tlogn = 32 - __builtin_clz(n);\n\
    \t\ttable.assign(logn, vector<T>(n));\n\t\tcopy(l, r, table[0].begin());\n\t\t\
    for (int k = 1; k < logn; k++)\n\t\t\tfor (int i = 0; i + (1 << k) <= n; i++)\n\
    \t\t\t\ttable[k][i] = min(table[k - 1][i], table[k - 1][i + (1 << (k - 1))]);\n\
    \t}\n\n\tT query(int l, int r) {\n\t\tint k = 31 - __builtin_clz(r - l + 1);\n\
    \t\treturn min(table[k][l], table[k][r - (1 << k) + 1]);\n\t}\n};\n\n#pragma endregion\
    \ sparse_table"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/sparse-table.hpp
  requiredBy:
  - data-structure/fast-lca.hpp
  timestamp: '2022-04-29 22:36:50-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/fast-lca.yosupo-lowest-common-ancestor.test.cpp
  - verify/sparse-table.yosupo-static-rmq.test.cpp
documentation_of: data-structure/sparse-table.hpp
layout: document
title: Sparse Table
---

## Sparse Table

### Summary
The sparse table is an online data structure that supports range min and max queries in constant time. The space used is $\mathcal{O}(n \log n)$. All indices are 0-indexed.