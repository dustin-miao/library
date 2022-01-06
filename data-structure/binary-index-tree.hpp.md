---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data-structure/binary-index-tree.yosupo-point-add-range-sum.test.cpp
    title: verify/data-structure/binary-index-tree.yosupo-point-add-range-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/binary-index-tree.hpp\"\ntemplate<typename\
    \ T>\nclass fentree {\n\tint n;\n\tvector<T> tree;\n\npublic:\n\tvoid init(int\
    \ _n) {\n\t\tn = _n;\n\t\ttree.assign(n + 1, T());\n\t}\n\n\ttemplate<class Iterator>\n\
    \tvoid init(Iterator begin, Iterator end) {\n\t\tn = distance(begin, end);\n\t\
    \ttree.resize(n + 1);\n\t\tfor (int i = 1; begin != end; i++, begin++)\n\t\t\t\
    update(i, *begin);\n\t}\n\n\tvoid update(int i, T v) {\n\t\tfor (; i <= n; i +=\
    \ i & -i)\n\t\t\ttree[i] += v;\n\t}\n\n\tT query(int i) {\n\t\tT ret = 0;\n\t\t\
    for (; i; i -= i & -i)\n\t\t\tret += tree[i];\n\t\treturn ret;\n\t}\n\n\tT query(int\
    \ l, int r) { return query(r) - query(l - 1); }\n\n\tT operator[](int i) { return\
    \ query(i, i); }\n};\n"
  code: "template<typename T>\nclass fentree {\n\tint n;\n\tvector<T> tree;\n\npublic:\n\
    \tvoid init(int _n) {\n\t\tn = _n;\n\t\ttree.assign(n + 1, T());\n\t}\n\n\ttemplate<class\
    \ Iterator>\n\tvoid init(Iterator begin, Iterator end) {\n\t\tn = distance(begin,\
    \ end);\n\t\ttree.resize(n + 1);\n\t\tfor (int i = 1; begin != end; i++, begin++)\n\
    \t\t\tupdate(i, *begin);\n\t}\n\n\tvoid update(int i, T v) {\n\t\tfor (; i <=\
    \ n; i += i & -i)\n\t\t\ttree[i] += v;\n\t}\n\n\tT query(int i) {\n\t\tT ret =\
    \ 0;\n\t\tfor (; i; i -= i & -i)\n\t\t\tret += tree[i];\n\t\treturn ret;\n\t}\n\
    \n\tT query(int l, int r) { return query(r) - query(l - 1); }\n\n\tT operator[](int\
    \ i) { return query(i, i); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/binary-index-tree.hpp
  requiredBy: []
  timestamp: '2022-01-05 19:16:14-08:00'
  verificationStatus: LIBRARY_ALL_AC
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

Binary index trees cannot support non-reversible queries. This almost completely limits BIT to exclusively sum queries. Thus, for type `T`, the addition and subtraction operator must be defined. For other range operations, see [segment tree](https://dutinmeow.github.io/library/data-structure/segment-tree.hpp).

### Documentation

#### Functions

- `fentree()`: Constructs an empty binary index tree.
- `void init(int n)`: Initializes a binary index tree object of size $n$ (meaning it can perform operations on the range $[1, n]$). Works in linear time.
- `void init(Iterator begin, Iterator end)`: Initializes a binary index tree with values specified by $\texttt{begin}$ and $\texttt{end}$. Works in $\mathcal{O}(n \log n)$ time.
- `void update(int i, T v)`: Sets the value of $a_i$ to $a_i + v$. Works in $\mathcal{O}(\log n)$.
- `T query(int i)`: Returns the value $\sum_{k = 1}^i a_k$. Works in $\mathcal{O}(\log n)$.
- `T query(int l, int r)`: Returns the value $\sum_{k = l}^r a_k$. Works in $\mathcal{O}(\log n)$.
- `T operator[](int i)`: Returns the value at index $i$ in $\mathcal{O}(\log n)$. 
