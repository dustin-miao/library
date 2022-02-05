---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data-structure/kciwnef-tree.hpp
    title: Kciwnef Tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/fenwick-tree.aizu-range-sum-query.test.cpp
    title: verify/fenwick-tree.aizu-range-sum-query.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fenwick-tree.yosupo-point-add-range-sum.test.cpp
    title: verify/fenwick-tree.yosupo-point-add-range-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/kciwnef-tree.aizu-point-add-query.test.cpp
    title: verify/kciwnef-tree.aizu-point-add-query.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/fenwick-tree.hpp\"\ntemplate<typename T>\n\
    class Fentree {\n\tsize_t n;\n\tvector<T> tree;\n\npublic:\n\tFentree() = default;\n\
    \n\tFentree(size_t _n) { init(_n); }\n\n\tvoid init(size_t _n) {\n\t\tn = _n;\n\
    \t\ttree.assign(n + 1, T());\n\t}\n\n\tvoid update(int i, T v) {\n\t\tfor (; i\
    \ <= n; i += i & -i)\n\t\t\ttree[i] += v;\n\t}\n\n\tT query(int i) {\n\t\tT ret\
    \ = 0;\n\t\tfor (; i; i -= i & -i)\n\t\t\tret += tree[i];\n\t\treturn ret;\n\t\
    }\n\n\tT query(int l, int r) { return query(r) - query(l - 1); }\n};\n"
  code: "template<typename T>\nclass Fentree {\n\tsize_t n;\n\tvector<T> tree;\n\n\
    public:\n\tFentree() = default;\n\n\tFentree(size_t _n) { init(_n); }\n\n\tvoid\
    \ init(size_t _n) {\n\t\tn = _n;\n\t\ttree.assign(n + 1, T());\n\t}\n\n\tvoid\
    \ update(int i, T v) {\n\t\tfor (; i <= n; i += i & -i)\n\t\t\ttree[i] += v;\n\
    \t}\n\n\tT query(int i) {\n\t\tT ret = 0;\n\t\tfor (; i; i -= i & -i)\n\t\t\t\
    ret += tree[i];\n\t\treturn ret;\n\t}\n\n\tT query(int l, int r) { return query(r)\
    \ - query(l - 1); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/fenwick-tree.hpp
  requiredBy:
  - data-structure/kciwnef-tree.hpp
  timestamp: '2022-02-04 19:46:21-08:00'
  verificationStatus: LIBRARY_ALL_AC
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

### Methods

- `Fentree()`: Constructs an empty fenwick tree.
- `Fentree(size_t _n)`: Constructs a fenwick tree with initial size $n$.
- `void init(size_t _n)`: Initializes a fenwick tree object of size $n$ (meaning it can perform operations on the range $[1, n]$). Works in linear time.
- `void update(int i, T v)`: Sets the value of $a_i$ to $a_i + v$. 
- `T query(int i)`: Returns the value $\sum_{k = 1}^i a_k$.
- `T query(int l, int r)`: Returns the value $\sum_{k = l}^r a_k$. 
