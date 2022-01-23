---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/general-segment-tree.yosupo-point-add-range-sum.test.cpp
    title: verify/general-segment-tree.yosupo-point-add-range-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/general-segment-tree.hpp\"\ntemplate<class\
    \ Base>\nclass Segtree : public Base {\n\tusing node = typename Base::T;\n\n\t\
    size_t n;\n\tvector<node> tree;\n\npublic:\n\tSegtree() = default;\n\n\tSegtree(size_t\
    \ _n) { init(n); }\n\n\tvoid init(size_t _n) {\n\t\tfor (n = 1; n < _n; n *= 2);\n\
    \t\ttree.assign(n * 2, Base::dval);\n\t}\n\n\tvoid update(int i, node v) {\n\t\
    \tfor (Base::apply(tree[i += n], v); i > 1; i >>= 1)\n\t\t\ttree[i >> 1] = Base::merge(tree[i],\
    \ tree[i ^ 1]);\n\t}\n\n\tnode query(int l, int r) {\n\t\tnode ret = Base::dval;\n\
    \t\tfor (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {\n\t\t\tif (l & 1) ret\
    \ = Base::merge(ret, tree[l++]);\n\t\t\tif (r & 1) ret = Base::merge(ret, tree[--r]);\n\
    \t\t}\n\t\treturn ret;\n\t}\n\n\tnode operator[](int i) { return tree[i += n];\
    \ }\n};\n"
  code: "template<class Base>\nclass Segtree : public Base {\n\tusing node = typename\
    \ Base::T;\n\n\tsize_t n;\n\tvector<node> tree;\n\npublic:\n\tSegtree() = default;\n\
    \n\tSegtree(size_t _n) { init(n); }\n\n\tvoid init(size_t _n) {\n\t\tfor (n =\
    \ 1; n < _n; n *= 2);\n\t\ttree.assign(n * 2, Base::dval);\n\t}\n\n\tvoid update(int\
    \ i, node v) {\n\t\tfor (Base::apply(tree[i += n], v); i > 1; i >>= 1)\n\t\t\t\
    tree[i >> 1] = Base::merge(tree[i], tree[i ^ 1]);\n\t}\n\n\tnode query(int l,\
    \ int r) {\n\t\tnode ret = Base::dval;\n\t\tfor (l += n, r += n + 1; l < r; l\
    \ >>= 1, r >>= 1) {\n\t\t\tif (l & 1) ret = Base::merge(ret, tree[l++]);\n\t\t\
    \tif (r & 1) ret = Base::merge(ret, tree[--r]);\n\t\t}\n\t\treturn ret;\n\t}\n\
    \n\tnode operator[](int i) { return tree[i += n]; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/general-segment-tree.hpp
  requiredBy: []
  timestamp: '2022-01-22 21:24:46-08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/general-segment-tree.yosupo-point-add-range-sum.test.cpp
documentation_of: data-structure/general-segment-tree.hpp
layout: document
title: General Segment Tree
---

## General Segment Tree

### Summary

See summary of [Segment Tree](https://dutinmeow.github.io/library/data-structure/segment-tree.hpp). Note that in this case, the operations **do not** have to be commutative. 


### Preconditions

- `B` is a class with the following defined:
  - `T`: A type.
  - `const T dval`: The identity element.
  - `void apply(T &a, T b)`: Applies an update of value `b` to a node with value `a`. 
  - `T merge(T a, T b)`: Merges two nodes with values `a` and `b`. 

### Methods

- `SegTree()`: Constructs an empty `Segtree` object.
- `SegTree(size_t _n)`: Constructs a `Segtree` object with initial capacity `_n` filled with the default value.
- `void init(int _n)`: Initializes a `Segtree` object with capacity `_n` filled with the default value. 
- `void update(int i, T v)`: Updates node `i` with value `v`.
- `T query(int l, int r)`: Queries the range from `l` to `r` inclusive. 
- `T operator[](int i)`: Returns the value of the element at index `i`. 