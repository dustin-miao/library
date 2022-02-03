---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/recursive-segment-tree.aizu-range-minimum-query.test.cpp
    title: verify/recursive-segment-tree.aizu-range-minimum-query.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/recursive-segment-tree.aizu-range-sum-query.test.cpp
    title: verify/recursive-segment-tree.aizu-range-sum-query.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/recursive-segment-tree.yosupo-point-add-range-sum.test.cpp
    title: verify/recursive-segment-tree.yosupo-point-add-range-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp
    title: verify/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/recursive-segment-tree.hpp\"\ntemplate<class\
    \ Base>\nclass Segtree : public Base {\n\tusing T = typename Base::T;\n\tusing\
    \ Base::dval;\n\tusing Base::merge;\n\tusing Base::apply;\n\nprotected:\n\tsize_t\
    \ n;\n\tvector<T> tree;\n\nprivate:\n\tvoid update(int i, T v, int t, int tl,\
    \ int tr) {\n\t\tif (tl == tr) {\n\t\t\tapply(tree[t], v);\n\t\t\treturn;\n\t\t\
    }\n\t\tint tm = (tl + tr) / 2;\n\t\tif (i <= tm)\n\t\t\tupdate(i, v, t * 2, tl,\
    \ tm);\n\t\telse \n\t\t\tupdate(i, v, t * 2 + 1, tm + 1, tr);\n\t\ttree[t] = merge(tree[t\
    \ * 2], tree[t * 2 + 1]);\n\t}\n\n\tT query(int l, int r, int t, int tl, int tr)\
    \ {\n\t\tif (r < tl || tr < l)\n\t\t\treturn dval;\n\t\tif (l <= tl && tr <= r)\n\
    \t\t\treturn tree[t];\n\t\tint tm = (tl + tr) / 2;\n\t\treturn merge(query(l,\
    \ r, t * 2, tl, tm), query(l, r, t * 2 + 1, tm + 1, tr));\n\t}\n\npublic:\n\t\
    Segtree() = default;\n\n\tSegtree(size_t _n) { init(_n); }\n\n\tvoid init(size_t\
    \ _n) {\n\t\tn = _n;\n\t\ttree.assign(n * 4, dval);\n\t}\n\n\tvoid update(int\
    \ i, T v) { update(i, v, 1, 0, n - 1); }\n\n\tT query(int l, int r) { return query(l,\
    \ r, 1, 0, n - 1); }\n};\n"
  code: "template<class Base>\nclass Segtree : public Base {\n\tusing T = typename\
    \ Base::T;\n\tusing Base::dval;\n\tusing Base::merge;\n\tusing Base::apply;\n\n\
    protected:\n\tsize_t n;\n\tvector<T> tree;\n\nprivate:\n\tvoid update(int i, T\
    \ v, int t, int tl, int tr) {\n\t\tif (tl == tr) {\n\t\t\tapply(tree[t], v);\n\
    \t\t\treturn;\n\t\t}\n\t\tint tm = (tl + tr) / 2;\n\t\tif (i <= tm)\n\t\t\tupdate(i,\
    \ v, t * 2, tl, tm);\n\t\telse \n\t\t\tupdate(i, v, t * 2 + 1, tm + 1, tr);\n\t\
    \ttree[t] = merge(tree[t * 2], tree[t * 2 + 1]);\n\t}\n\n\tT query(int l, int\
    \ r, int t, int tl, int tr) {\n\t\tif (r < tl || tr < l)\n\t\t\treturn dval;\n\
    \t\tif (l <= tl && tr <= r)\n\t\t\treturn tree[t];\n\t\tint tm = (tl + tr) / 2;\n\
    \t\treturn merge(query(l, r, t * 2, tl, tm), query(l, r, t * 2 + 1, tm + 1, tr));\n\
    \t}\n\npublic:\n\tSegtree() = default;\n\n\tSegtree(size_t _n) { init(_n); }\n\
    \n\tvoid init(size_t _n) {\n\t\tn = _n;\n\t\ttree.assign(n * 4, dval);\n\t}\n\n\
    \tvoid update(int i, T v) { update(i, v, 1, 0, n - 1); }\n\n\tT query(int l, int\
    \ r) { return query(l, r, 1, 0, n - 1); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/recursive-segment-tree.hpp
  requiredBy: []
  timestamp: '2022-02-02 18:18:31-08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/recursive-segment-tree.aizu-range-sum-query.test.cpp
  - verify/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp
  - verify/recursive-segment-tree.yosupo-point-add-range-sum.test.cpp
  - verify/recursive-segment-tree.aizu-range-minimum-query.test.cpp
documentation_of: data-structure/recursive-segment-tree.hpp
layout: document
title: Recursive Segment Tree
---

## Recursive Segment Tree

### Summary

See summary of [Segment Tree](https://dutinmeow.github.io/library/data-structure/segment-tree.hpp). 


### Preconditions

- `B` is a class with the following defined:
  - `T`: The node type.
  - `const T dval`: The identity element.
  - `void apply(T &a, T b)`: Applies an update of value `b` to a node with value `a`. 
  - `T merge(T a, T b)`: Merges two nodes with values `a` and `b`. 

### Methods

- `SegTree()`: Constructs an empty `Segtree` object.
- `SegTree(size_t _n)`: Constructs a `Segtree` object with initial capacity `_n` filled with the default value.
- `void init(int _n)`: Initializes a `Segtree` object with capacity `_n` filled with the default value. 
- `void update(int i, T v)`: Updates index `i` with value `v`.
- `T query(int l, int r)`: Queries the range from `l` to `r` inclusive. 