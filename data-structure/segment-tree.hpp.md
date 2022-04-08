---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/segment-tree.aizu-range-minimum-query.test.cpp
    title: verify/segment-tree.aizu-range-minimum-query.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/segment-tree.aizu-range-sum-query.test.cpp
    title: verify/segment-tree.aizu-range-sum-query.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/segment-tree.yosupo-point-add-range-sum.test.cpp
    title: verify/segment-tree.yosupo-point-add-range-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/segment-tree.hpp\"\ntemplate<class Base>\n\
    class Segtree : public Base {\n\tusing T = typename Base::T;\n\tusing Base::dval;\n\
    \tusing Base::merge;\n\tusing Base::apply;\n\nprotected:\n\tsize_t n;\n\tvector<T>\
    \ tree;\n\npublic:\n\tSegtree() = default;\n\n\tSegtree(size_t _n) { init(_n);\
    \ }\n\n\tvoid init(size_t _n) {\n\t\tn = _n;\n\t\ttree.assign(n * 2, dval);\n\t\
    }\n\n\tvoid update(int i, T v) {\n\t\tfor (apply(tree[i += n], v); i >>= 1;)\n\
    \t\t\ttree[i] = merge(tree[i << 1], tree[i << 1 | 1]);\n\t}\n\n\tT query(int l,\
    \ int r) {\n\t\tT ret = dval;\n\t\tfor (l += n, r += n + 1; l < r; l >>= 1, r\
    \ >>= 1) {\n\t\t\tif (l & 1) ret = merge(ret, tree[l++]);\n\t\t\tif (r & 1) ret\
    \ = merge(ret, tree[--r]);\n\t\t}\n\t\treturn ret;\n\t}\n\n\tT operator[](int\
    \ i) { return tree[i += n]; }\n};\n"
  code: "template<class Base>\nclass Segtree : public Base {\n\tusing T = typename\
    \ Base::T;\n\tusing Base::dval;\n\tusing Base::merge;\n\tusing Base::apply;\n\n\
    protected:\n\tsize_t n;\n\tvector<T> tree;\n\npublic:\n\tSegtree() = default;\n\
    \n\tSegtree(size_t _n) { init(_n); }\n\n\tvoid init(size_t _n) {\n\t\tn = _n;\n\
    \t\ttree.assign(n * 2, dval);\n\t}\n\n\tvoid update(int i, T v) {\n\t\tfor (apply(tree[i\
    \ += n], v); i >>= 1;)\n\t\t\ttree[i] = merge(tree[i << 1], tree[i << 1 | 1]);\n\
    \t}\n\n\tT query(int l, int r) {\n\t\tT ret = dval;\n\t\tfor (l += n, r += n +\
    \ 1; l < r; l >>= 1, r >>= 1) {\n\t\t\tif (l & 1) ret = merge(ret, tree[l++]);\n\
    \t\t\tif (r & 1) ret = merge(ret, tree[--r]);\n\t\t}\n\t\treturn ret;\n\t}\n\n\
    \tT operator[](int i) { return tree[i += n]; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segment-tree.hpp
  requiredBy: []
  timestamp: '2022-02-04 21:19:28-08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/segment-tree.aizu-range-minimum-query.test.cpp
  - verify/segment-tree.aizu-range-sum-query.test.cpp
  - verify/segment-tree.yosupo-point-add-range-sum.test.cpp
documentation_of: data-structure/segment-tree.hpp
layout: document
title: Segment Tree
---

## Segment Tree

### Summary
The segment tree is an online range query point update data structure that supports the following operations:
- Given some indicies $l, r$ such that $l \leq r$, returns the value $\Pi_{i = l}^r a_i$, where "$\cdot$" is an associative function.
- Given an index $i$ and a value $v$, applies an update of $v$ to $a_i$. 

Both these operations are performed in $\mathcal{O}(\log n)$ time, where $n$ is the number of elements represented by the segment tree. The total space used is $2n$. All indices are 0-based. 

### Preconditions
- `B` is a class with the following defined:
  - `T`: The node type.
  - `const T dval`: The identity element, such that for any element $a$ it satisfies $a \cdot dval = dval \cdot a = a$.
  - `T merge(T a, T b)`: Merges two nodes with values $a$ and $b$. 
  - `void apply(T &a, T b)`: Applies an update of value $b$ to a node with value $a$. 
- "$\cdot$" is a commutative function (i.e. $a \cdot b = b \cdot a$ for all $a, b \in S$). 

### Methods
- `SegTree()`: Constructs an empty `Segtree` object.
- `SegTree(size_t _n)`: Constructs a `Segtree` object with initial capacity $n$ filled with the default value.
- `void init(int _n)`: Initializes a `Segtree` object with capacity $n$ filled with the default value in linear time. 
- `void update(int i, T v)`: Applies an update of $v$ to $a_i$ in logarithmic time. 
- `T query(int l, int r)`: Returns $\Pi_{i = l}^r a_i$ in logarithmic time. 
- `T operator[](int i)`: Returns $a_i$ in constant time. 