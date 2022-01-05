---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data-structure/segment-tree.yosupo-point-add-range-sum.test.cpp
    title: verify/data-structure/segment-tree.yosupo-point-add-range-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/segment-tree.hpp\"\nclass segtree {\n\tusing\
    \ T = long long;\n\n\tconst static T dval = T();\n\n\tstatic T merge(const T &a,\
    \ const T &b) { return a + b; }\n\n\tstatic void apply(T &a, const T &b) { a +=\
    \ b; }\n\n\tint n;\n\tvector<T> tree;\n\npublic:\n\tvoid init(int _n) {\n\t\t\
    n = _n;\n\t\ttree.assign(2 * n, dval);\n\t\tfor (int i = n - 1; i > 0; i--)\n\t\
    \t\ttree[i] = merge(tree[i << 1], tree[i << 1 | 1]);\n\t}\n\n\ttemplate<typename\
    \ Iterator>\n\tvoid init(Iterator begin, Iterator end) {\n\t\tn = distance(begin,\
    \ end);\n\t\ttree.resize(2 * n);\n\t\tfor (int i = n; i < 2 * n; i++, begin++)\n\
    \t\t\ttree[i] = *begin;\n\t\tfor (int i = n - 1; i > 0; i--)\n\t\t\ttree[i] =\
    \ merge(tree[i << 1], tree[i << 1 | 1]);\n\t}\n\n\tvoid update(int i, T v) {\n\
    \t\tfor (apply(tree[i += n], v); i > 1; i >>= 1)\n\t\t\ttree[i >> 1] = merge(tree[i],\
    \ tree[i ^ 1]);\n\t}\n\n\tT query(int l, int r) {\n\t\tT ret = segtree::dval;\n\
    \t\tfor (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {\n\t\t\tif (l & 1) ret\
    \ = merge(ret, tree[l++]);\n\t\t\tif (r & 1) ret = merge(ret, tree[--r]);\n\t\t\
    }\n\t\treturn ret;\n\t}\n\n\tT operator[](int i) { return tree[i += n]; }\n};\n"
  code: "class segtree {\n\tusing T = long long;\n\n\tconst static T dval = T();\n\
    \n\tstatic T merge(const T &a, const T &b) { return a + b; }\n\n\tstatic void\
    \ apply(T &a, const T &b) { a += b; }\n\n\tint n;\n\tvector<T> tree;\n\npublic:\n\
    \tvoid init(int _n) {\n\t\tn = _n;\n\t\ttree.assign(2 * n, dval);\n\t\tfor (int\
    \ i = n - 1; i > 0; i--)\n\t\t\ttree[i] = merge(tree[i << 1], tree[i << 1 | 1]);\n\
    \t}\n\n\ttemplate<typename Iterator>\n\tvoid init(Iterator begin, Iterator end)\
    \ {\n\t\tn = distance(begin, end);\n\t\ttree.resize(2 * n);\n\t\tfor (int i =\
    \ n; i < 2 * n; i++, begin++)\n\t\t\ttree[i] = *begin;\n\t\tfor (int i = n - 1;\
    \ i > 0; i--)\n\t\t\ttree[i] = merge(tree[i << 1], tree[i << 1 | 1]);\n\t}\n\n\
    \tvoid update(int i, T v) {\n\t\tfor (apply(tree[i += n], v); i > 1; i >>= 1)\n\
    \t\t\ttree[i >> 1] = merge(tree[i], tree[i ^ 1]);\n\t}\n\n\tT query(int l, int\
    \ r) {\n\t\tT ret = segtree::dval;\n\t\tfor (l += n, r += n + 1; l < r; l >>=\
    \ 1, r >>= 1) {\n\t\t\tif (l & 1) ret = merge(ret, tree[l++]);\n\t\t\tif (r &\
    \ 1) ret = merge(ret, tree[--r]);\n\t\t}\n\t\treturn ret;\n\t}\n\n\tT operator[](int\
    \ i) { return tree[i += n]; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segment-tree.hpp
  requiredBy: []
  timestamp: '2022-01-05 09:09:47-08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data-structure/segment-tree.yosupo-point-add-range-sum.test.cpp
documentation_of: data-structure/segment-tree.hpp
layout: document
title: Segment Tree
---

## Segment Tree

### Summary

Segment Trees are a general class of online data structures, represented by a complete binary tree with the leaves built on an array such that all nodes in the tree (excluding leaves) are a function of its children. This specific implementation requires said function to be commutative (such as sum, min, max, gcd, etc.). More specifically, it supports:
- Given two indices $l, r$, it finds $\sum_{k = l}^r a_k$, or the sum of values in the range $[l, r]$.
- Given an index $i$ and a value $v$, assigns $a_i$ to $v$. 

Both these operations are performed in $\mathcal{O}(\log n)$, where $n$ is the number of elements represented by the segment tree. The total space complexity is linear (more specifically, it allocates $2n$ memory). Note that all indices are zero-based. For a similar data structure, see the [binary index tree](https://dutinmeow.github.io/library/data-structure/binary-index-tree.hpp). 

### Documentation

- `segtree()`: Constructs an empty segment tree.
- `segtree(int n)`: Constructs a segment tree of size $n$. This takes $\mathcal{O}(n)$ time.
- `segtree(Iterator begin, Iterator end)`: Constructs a segment tree initialized with values specified by $\texttt{begin}$ and $\texttt{end}$. This runs in $\mathcal{O}(n)$ time.
- `T query(int l, int r)`: Returns $\sum_{k = l}^r a_k$. This runs in $\mathcal{O}(\log n)$ time.
- `T operator[](int i)`: Returns $a_i$. This runs in $\mathcal{O}(1)$ time.
- `void update(int i, T v)`: Assigns $a_i$ to value $v$. This runs in $\mathcal{O}(\log n)$. 

Note that the following methods and variables are meant to be modified or overriden. 
- `T dval`: This variable is the default value, which depends on the type of $T$ and $\texttt{merge}$ function. For any $v \neq \texttt{dval}$, $\texttt{dval}$ should satisfy $v = \texttt{merge}(v, \texttt{dval})$. For instance, a sum operator would mean that $\texttt{dval} = 0$, and a min operator would mean that $\texttt{dval} = \infty$. 
- `T merge(T a, T b)`: Specifies how values are to be combined. It takes in two values and merges them into a single value. In this specific use case, this function must be commutative (ie $\texttt{merge}(a, b) = \texttt{merge}(b, a)$). For non-commutative merge functions, see the [recursive implementation of segment tree](https://dutinmeow.github.io/library/data-structure/recursive-segment-tree.hpp). 
- `T apply(T &a, T b)`: Applies an update with value $b$ to a node with value $a$. This will most likely always be the `=` or `+=` operator. 

