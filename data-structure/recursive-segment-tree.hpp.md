---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data-structure/recursive-segment-tree.yosupo-point-add-range-sum.test.cpp
    title: verify/data-structure/recursive-segment-tree.yosupo-point-add-range-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/recursive-segment-tree.hpp\"\nclass segtree\
    \ {\n    using T = long long;\n\n    const static T dval = T();\n\n    static\
    \ T merge(const T &a, const T &b) { return a + b; }\n\n    static void apply(T\
    \ &a, const T &b) { a += b; }\n\n    int n;\n    vector<T> tree;\n\nprivate:\n\
    \    void update(int i, T v, int t, int tl, int tr) {\n        if (tl == tr) {\n\
    \            apply(tree[t], v);\n            return;\n        }\n        int tm\
    \ = (tl + tr) >> 1;\n        if (i <= tm)\n            update(i, v, t << 1, tl,\
    \ tm);\n        else \n            update(i, v, t << 1 | 1, tm + 1, tr);\n   \
    \     tree[t] = merge(tree[t << 1], tree[t << 1 | 1]);\n    }\n\n    T query(int\
    \ l, int r, int t, int tl, int tr) {\n        if (r < tl || tr < l)\n        \
    \    return dval;\n        if (l <= tl && tr <= r)\n            return tree[t];\n\
    \        int tm = (tl + tr) >> 1;\n        return merge(query(l, r, t << 1, tl,\
    \ tm), query(l, r, t << 1 | 1, tm + 1, tr));\n    }\n\npublic:\n    void init(int\
    \ _n) {\n        n = _n;\n        tree.resize(4 * n);\n        for (int i = 0;\
    \ i < n; i++)\n            update(i, dval);\n    }\n\n    template<typename Iterator>\n\
    \    void init(Iterator begin, Iterator end) {\n        n = distance(begin, end);\
    \ \n\t\ttree.resize(4 * n);\n        for (int i = 0; i < n; i++, begin++)\n  \
    \          update(i, *begin);\n    }\n\n    void update(int i, T v) {\n      \
    \  update(i, v, 1, 0, n - 1);\n    }\n\n    T query(int l, int r) {\n        return\
    \ query(l, r, 1, 0, n - 1);\n    }\n\n    T operator[](int i) { return query(i,\
    \ i); }\n};\n"
  code: "class segtree {\n    using T = long long;\n\n    const static T dval = T();\n\
    \n    static T merge(const T &a, const T &b) { return a + b; }\n\n    static void\
    \ apply(T &a, const T &b) { a += b; }\n\n    int n;\n    vector<T> tree;\n\nprivate:\n\
    \    void update(int i, T v, int t, int tl, int tr) {\n        if (tl == tr) {\n\
    \            apply(tree[t], v);\n            return;\n        }\n        int tm\
    \ = (tl + tr) >> 1;\n        if (i <= tm)\n            update(i, v, t << 1, tl,\
    \ tm);\n        else \n            update(i, v, t << 1 | 1, tm + 1, tr);\n   \
    \     tree[t] = merge(tree[t << 1], tree[t << 1 | 1]);\n    }\n\n    T query(int\
    \ l, int r, int t, int tl, int tr) {\n        if (r < tl || tr < l)\n        \
    \    return dval;\n        if (l <= tl && tr <= r)\n            return tree[t];\n\
    \        int tm = (tl + tr) >> 1;\n        return merge(query(l, r, t << 1, tl,\
    \ tm), query(l, r, t << 1 | 1, tm + 1, tr));\n    }\n\npublic:\n    void init(int\
    \ _n) {\n        n = _n;\n        tree.resize(4 * n);\n        for (int i = 0;\
    \ i < n; i++)\n            update(i, dval);\n    }\n\n    template<typename Iterator>\n\
    \    void init(Iterator begin, Iterator end) {\n        n = distance(begin, end);\
    \ \n\t\ttree.resize(4 * n);\n        for (int i = 0; i < n; i++, begin++)\n  \
    \          update(i, *begin);\n    }\n\n    void update(int i, T v) {\n      \
    \  update(i, v, 1, 0, n - 1);\n    }\n\n    T query(int l, int r) {\n        return\
    \ query(l, r, 1, 0, n - 1);\n    }\n\n    T operator[](int i) { return query(i,\
    \ i); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/recursive-segment-tree.hpp
  requiredBy: []
  timestamp: '2022-01-05 09:26:34-08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data-structure/recursive-segment-tree.yosupo-point-add-range-sum.test.cpp
documentation_of: data-structure/recursive-segment-tree.hpp
layout: document
title: Recursive Segment Tree
---

## Recursive Segment Tree

### Summary

Segment Trees are a general class of online data structures, represented by a complete binary tree with the leaves built on an array such that all nodes in the tree (excluding leaves) are a function of its children. More specifically, it supports:
- Given two indices $l, r$, it finds $a_l \oplus a_{l + 1} \oplus \dots \oplus a_r$ where "$\oplus$" is an operation. 
- Given an index $i$ and a value $v$, assigns $a_i$ to $v$. 

Both these operations are performed in $\mathcal{O}(\log n)$, where $n$ is the number of elements represented by the segment tree. The total space complexity is linear (more specifically, it allocates $2n$ memory). Note that all indices are zero-based. For a similar data structure, see the [binary index tree](https://dutinmeow.github.io/library/data-structure/binary-index-tree.hpp). 

It is important to note that this version implements segment tree recusively, which incurs a higher runtime and a memory upperbound of $4n$ (as opposed to $2n$ from the iterative version). Alternatively, see the [iterative segment tree](https://dutinmeow.github.io/library/data-structure/segment-tree.hpp).

### Documentation

#### Functions

- `segtree()`: Constructs an empty segment tree.
- `void init(int n)`: Initializes a segment tree of size $n$. This takes $\mathcal{O}(n)$ time.
- `void init(Iterator begin, Iterator end)`: Initializes a segment tree with values specified by $\texttt{begin}$ and $\texttt{end}$. This runs in $\mathcal{O}(n)$ time.
- `void update(int i, T v)`: Assigns $a_i$ to value $v$. This runs in $\mathcal{O}(\log n)$. 
- `T query(int l, int r)`: Returns $\bigoplus_{k = l}^r a_k$, where "$\oplus$" is a commutative merge function (defined in `merge` – see below). This runs in $\mathcal{O}(\log n)$ time.
- `T operator[](int i)`: Returns $a_i$. This runs in $\mathcal{O}(1)$ time.

#### Static

Note that the following methods and variables are meant to be modified or overriden. 
- `T`: Controls the type of the segment tree
- `T dval`: This variable is the default value, which depends on the type of $T$ and $\texttt{merge}$ function. For any $v \neq \texttt{dval}$, $\texttt{dval}$ should satisfy $v = \texttt{merge}(v, \texttt{dval})$. For instance, a sum operator would mean that $\texttt{dval} = 0$, and a min operator would mean that $\texttt{dval} = \infty$. 
- `T merge(T a, T b)`: Specifies how values are to be combined (essentially the "$\oplus$" operator). It takes in two values and merges them into a single value.
- `T apply(T &a, T b)`: Applies an update with value $b$ to a node with value $a$. This will most likely always be the `=` or `+=` operator. 


