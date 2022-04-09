---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: data-structure/kciwnef-tree.hpp
    title: Kciwnef Tree
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/fenwick-tree.aizu-range-sum-query.test.cpp
    title: verify/fenwick-tree.aizu-range-sum-query.test.cpp
  - icon: ':x:'
    path: verify/fenwick-tree.yosupo-point-add-range-sum.test.cpp
    title: verify/fenwick-tree.yosupo-point-add-range-sum.test.cpp
  - icon: ':x:'
    path: verify/kciwnef-tree.aizu-point-add-query.test.cpp
    title: verify/kciwnef-tree.aizu-point-add-query.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/fenwick-tree.hpp\"\ntemplate<typename T>\n\
    class fenwick_tree {\n\tint n;\n\tvector<T> tree;\n\npublic:\n\tfenwick_tree()\
    \ = default;\n\n\tfenwick_tree(int _n) { init(_n); }\n\n\tvoid init(int _n) {\n\
    \t\tn = _n;\n\t\ttree.assign(n + 1, T());\n\t}\n\n\tvoid update(int i, T v) {\n\
    \t\tfor (i++; i <= n; i += i & -i)\n\t\t\ttree[i] += v;\n\t}\n\n\tT query(int\
    \ i) {\n\t\tT ret = T();\n\t\tfor (i++; i; i -= i & -i)\n\t\t\tret += tree[i];\n\
    \t\treturn ret;\n\t}\n\n\tT query(int l, int r) { return query(r) - query(l -\
    \ 1); }\n};\n"
  code: "template<typename T>\nclass fenwick_tree {\n\tint n;\n\tvector<T> tree;\n\
    \npublic:\n\tfenwick_tree() = default;\n\n\tfenwick_tree(int _n) { init(_n); }\n\
    \n\tvoid init(int _n) {\n\t\tn = _n;\n\t\ttree.assign(n + 1, T());\n\t}\n\n\t\
    void update(int i, T v) {\n\t\tfor (i++; i <= n; i += i & -i)\n\t\t\ttree[i] +=\
    \ v;\n\t}\n\n\tT query(int i) {\n\t\tT ret = T();\n\t\tfor (i++; i; i -= i & -i)\n\
    \t\t\tret += tree[i];\n\t\treturn ret;\n\t}\n\n\tT query(int l, int r) { return\
    \ query(r) - query(l - 1); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/fenwick-tree.hpp
  requiredBy:
  - data-structure/kciwnef-tree.hpp
  timestamp: '2022-04-09 15:55:38-07:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/kciwnef-tree.aizu-point-add-query.test.cpp
  - verify/fenwick-tree.yosupo-point-add-range-sum.test.cpp
  - verify/fenwick-tree.aizu-range-sum-query.test.cpp
documentation_of: data-structure/fenwick-tree.hpp
layout: document
title: Fenwick Tree
---

## Fenwick Tree

### Summary
The fenwick tree is an online range query point update data structure that supports the following operations:
- Given an index $i$, returns the value $\sum_{k = 1}^i a_k$.
- Given an index $i$ and a value $v$, assigns $a_i$ to $a_i + v$.

Both these operations are performed in $\mathcal{O}(\log n) time, where $n$ is the number of elements represented by the fenwick tree. The total space used is $n$. All indices represented in a fenwick tree are one-indexed.