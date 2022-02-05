---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/fenwick-tree.hpp
    title: Fenwick Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
    }\n\n\tT query(int l, int r) { return query(r) - query(l - 1); }\n};\n#line 2\
    \ \"data-structure/kciwnef-tree.hpp\"\n\ntemplate<typename T>\nclass Kciwtree\
    \ : public Fentree<T> {\n\tusing Fentree<T>::update;\npublic:\n\tKciwtree() :\
    \ Fentree<T>() {};\n\n\tKciwtree(size_t _n) : Fentree<T>(_n) {}\n\n\tvoid update(int\
    \ l, int r, T v) {\n\t\tupdate(l, v); \n\t\tupdate(r + 1, -v);\n\t}\n\n\tusing\
    \ Fentree<T>::query;\n\n\tT operator[](int i) { return query(i); }\n};\n"
  code: "#include \"data-structure/fenwick-tree.hpp\"\n\ntemplate<typename T>\nclass\
    \ Kciwtree : public Fentree<T> {\n\tusing Fentree<T>::update;\npublic:\n\tKciwtree()\
    \ : Fentree<T>() {};\n\n\tKciwtree(size_t _n) : Fentree<T>(_n) {}\n\n\tvoid update(int\
    \ l, int r, T v) {\n\t\tupdate(l, v); \n\t\tupdate(r + 1, -v);\n\t}\n\n\tusing\
    \ Fentree<T>::query;\n\n\tT operator[](int i) { return query(i); }\n};"
  dependsOn:
  - data-structure/fenwick-tree.hpp
  isVerificationFile: false
  path: data-structure/kciwnef-tree.hpp
  requiredBy: []
  timestamp: '2022-02-04 21:19:28-08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/kciwnef-tree.aizu-point-add-query.test.cpp
documentation_of: data-structure/kciwnef-tree.hpp
layout: document
title: Kciwnef Tree
---

## Kciwnef Tree

### Summary

The kciwnef tree is an online point query range update data structure that supports the following operations:
- Given an index $i$, returns the value at $a_i$.
- Given some indicies $l, r$ such that $l \leq r$ and a value $v$, assigns $a_i$ to $a_i + v$ for $i \in [l, r]$

Both these operations are performed in $\mathcal{O}(\log n) time, where $n$ is the number of elements represented by the kciwnef tree. The total space used is $n$. All indices represented in a kciwnef tree are one-indexed.

### Methods

- `Kciwtree()`: Constructs an empty kciwnef tree.
- `Kciwtree(size_t _n)`: Constructs a kciwnef tree with initial size $n$.
- `void init(size_t _n)`: Initializes a kciwnef tree object of size $n$ (meaning it can perform operations on the range $[1, n]$). Works in linear time.
- `void update(int l, int r, T v)`: Sets the value of $a_i$ to $a_i + v$ for $i \in [l, r]$. 
- `T query(int i)`: Returns the value $a_i$.
- `T operator[](int i)`: Same as `query(int i)`. 