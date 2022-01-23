---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/data-structure/binary-index-tree.yosupo-point-add-range-sum.test.cpp
    title: verify/data-structure/binary-index-tree.yosupo-point-add-range-sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/binary-index-tree.hpp\"\ntemplate<typename\
    \ T>\nclass Fentree {\n\tsize_t n;\n\tvector<T> tree;\n\npublic:\n\tFentree()\
    \ = default;\n\n\tFentree(size_t _n) { init(_n); }\n\n\tvoid init(size_t _n) {\n\
    \t\tn = _n;\n\t\ttree.assign(n + 1, T());\n\t}\n\n\tvoid update(int i, T v) {\n\
    \t\tfor (i++; i <= n; i += i & -i)\n\t\t\ttree[i] += v;\n\t}\n\n\tT query(int\
    \ i) {\n\t\tT ret = 0;\n\t\tfor (i++; i; i -= i & -i)\n\t\t\tret += tree[i];\n\
    \t\treturn ret;\n\t}\n\n\tT query(int l, int r) { return query(r) - query(l -\
    \ 1); }\n};\n"
  code: "template<typename T>\nclass Fentree {\n\tsize_t n;\n\tvector<T> tree;\n\n\
    public:\n\tFentree() = default;\n\n\tFentree(size_t _n) { init(_n); }\n\n\tvoid\
    \ init(size_t _n) {\n\t\tn = _n;\n\t\ttree.assign(n + 1, T());\n\t}\n\n\tvoid\
    \ update(int i, T v) {\n\t\tfor (i++; i <= n; i += i & -i)\n\t\t\ttree[i] += v;\n\
    \t}\n\n\tT query(int i) {\n\t\tT ret = 0;\n\t\tfor (i++; i; i -= i & -i)\n\t\t\
    \tret += tree[i];\n\t\treturn ret;\n\t}\n\n\tT query(int l, int r) { return query(r)\
    \ - query(l - 1); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/binary-index-tree.hpp
  requiredBy: []
  timestamp: '2022-01-22 21:24:46-08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/data-structure/binary-index-tree.yosupo-point-add-range-sum.test.cpp
documentation_of: data-structure/binary-index-tree.hpp
layout: document
title: Binary Index Tree
---

## Binary Index Tree

### Summary

The binary index tree is an online range query point update data structure that supports the following operations:
- Given an index $i$, returns the value $\sum_{k = 1}^i a_k$.
- Given an index $i$ and a value $v$, assigns $a_i$ to $a_i + v$.

Both these operations are performed in $\mathcal{O}(\log n) time, where $n$ is the number of elements represented by the binary index tree. The total space complexity is linear. Note that all indices represented in a binary index tree are one-indexed.

### Methods

- `Fentree()`: Constructs an empty binary index tree.
- `Fentree(size_t _n)`: Constructs a binary index tree with initial size `_n`
- `void init(size_t n)`: Initializes a binary index tree object of size `_n` (meaning it can perform operations on the range $[1, n]$). Works in linear time.
- `void update(int i, T v)`: Sets the value of $a_i$ to $a_i + v$. 
- `T query(int i)`: Returns the value $\sum_{k = 1}^i a_k$.
- `T query(int l, int r)`: Returns the value $\sum_{k = l}^r a_k$. 
