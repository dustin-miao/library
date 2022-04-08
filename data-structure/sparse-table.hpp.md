---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: data-structure/const-lca.hpp
    title: Constant Time LCA
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/sparse-table.yosupo-static-rmq.test.cpp
    title: verify/sparse-table.yosupo-static-rmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/sparse-table.hpp\"\ntemplate<typename T>\n\
    class SparseTable {\n\tsize_t n, logn;\n\tvector<vector<T>> table;\n\npublic:\n\
    \tSparseTable() = default;\n\n\ttemplate<typename I>\n\tSparseTable(I l, I r)\
    \ { init(l, r); }\n\n\ttemplate<typename I>\n\tvoid init(I l, I r) {\n\t\tn =\
    \ distance(l, r), logn = 32 - __builtin_clz(n);\n\t\ttable.assign(logn, vector<T>(n));\n\
    \t\tcopy(l, r, table[0].begin());\n\t\tfor (int k = 1; k < logn; k++)\n\t\t\t\
    for (int i = 0; i + (1 << k) <= n; i++)\n\t\t\t\ttable[k][i] = min(table[k - 1][i],\
    \ table[k - 1][i + (1 << (k - 1))]);\n\t}\n\n\tT query(int l, int r) {\n\t\tint\
    \ k = 31 - __builtin_clz(r - l + 1);\n\t\treturn min(table[k][l], table[k][r -\
    \ (1 << k) + 1]);\n\t}\n};\n"
  code: "template<typename T>\nclass SparseTable {\n\tsize_t n, logn;\n\tvector<vector<T>>\
    \ table;\n\npublic:\n\tSparseTable() = default;\n\n\ttemplate<typename I>\n\t\
    SparseTable(I l, I r) { init(l, r); }\n\n\ttemplate<typename I>\n\tvoid init(I\
    \ l, I r) {\n\t\tn = distance(l, r), logn = 32 - __builtin_clz(n);\n\t\ttable.assign(logn,\
    \ vector<T>(n));\n\t\tcopy(l, r, table[0].begin());\n\t\tfor (int k = 1; k < logn;\
    \ k++)\n\t\t\tfor (int i = 0; i + (1 << k) <= n; i++)\n\t\t\t\ttable[k][i] = min(table[k\
    \ - 1][i], table[k - 1][i + (1 << (k - 1))]);\n\t}\n\n\tT query(int l, int r)\
    \ {\n\t\tint k = 31 - __builtin_clz(r - l + 1);\n\t\treturn min(table[k][l], table[k][r\
    \ - (1 << k) + 1]);\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/sparse-table.hpp
  requiredBy:
  - data-structure/const-lca.hpp
  timestamp: '2022-02-05 09:55:16-08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/sparse-table.yosupo-static-rmq.test.cpp
documentation_of: data-structure/sparse-table.hpp
layout: document
title: Sparse Table
---

## Sparse Table

### Summary
The sparse table is an online data structure that supports range min and max queries in constant time. The space used is $\mathcal{O}(n \log n)$. All indices are 0-indexed.

### Methods
- `SparseTable()`: Constructs an empty sparse table.
- `Fentree(I l, I r)`: Constructs a sparse table with elements specified by iterators $[l, r)$.
- `void init(I l, I r)`: Initializes a sparse table with elements specified by iterators $[l, r)$ in $\mathcal{O}(n \log n)$ time, where $n$ is the number of elements between $l$ and $r$. .
- `T query(int l, int r)`: Returns the value $\min(a_l, a_{l + 1}, \dots, a_r)$ in $\mathcal{O}(1)$ time. 
