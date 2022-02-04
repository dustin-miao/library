---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/sparse-segment-tree.aizu-range-minimum-query.test.cpp
    title: verify/sparse-segment-tree.aizu-range-minimum-query.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/sparse-segment-tree.aizu-range-sum-query.test.cpp
    title: verify/sparse-segment-tree.aizu-range-sum-query.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/sparse-segment-tree.aizu-the-number-of-inversions.test.cpp
    title: verify/sparse-segment-tree.aizu-the-number-of-inversions.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/sparse-segment-tree.yosupo-point-add-range-sum.test.cpp
    title: verify/sparse-segment-tree.yosupo-point-add-range-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/sparse-segment-tree.yosupo-point-set-range-composite.test.cpp
    title: verify/sparse-segment-tree.yosupo-point-set-range-composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/sparse-segment-tree.hpp\"\ntemplate<class\
    \ Base>\nclass Segtree : public Base {\n\tusing T = typename Base::T;\n\tusing\
    \ Base::dval;\n\tusing Base::merge;\n\tusing Base::apply;\n\nprotected:\n\tsize_t\
    \ n;\n\n\tstruct node {\n\t\tT v;\n\t\tint l, r;\n\t\tnode() = default;\n\t\t\
    node(T _v, int _l, int _r) : v(_v), l(_l), r(_r) {}\n\t};\n\n\tint root;\n\tvector<node>\
    \ tree;\n\n\tsize_t new_node() {\n\t\ttree.emplace_back(dval, -1, -1);\n\t\treturn\
    \ tree.size() - 1;\n\t}\n\nprivate:\n\tvoid update(int i, T v, int t, int tl,\
    \ int tr) {\n\t\tif (tl == tr) {\n\t\t\tapply(tree[t].v, v);\n\t\t\treturn;\n\t\
    \t}\n\t\tint tm = (tl + tr) / 2;\n\t\tif (i <= tm) {\n\t\t\tif (tree[t].l == -1)\n\
    \t\t\t\ttree[t].l = new_node();\n\t\t\tupdate(i, v, tree[t].l, tl, tm);\n\t\t\
    } else {\n\t\t\tif (tree[t].r == -1)\n\t\t\t\ttree[t].r = new_node();\n\t\t\t\
    update(i, v, tree[t].r, tm + 1, tr);\n\t\t}\n\t\ttree[t].v = merge(tree[t].l ==\
    \ -1 ? dval : tree[tree[t].l].v, tree[t].r == -1 ? dval : tree[tree[t].r].v);\n\
    \t}\n\n\tT query(int l, int r, int t, int tl, int tr) {\n\t\tif (r < tl || tr\
    \ < l)\n\t\t\treturn dval;\n\t\tif (l <= tl && tr <= r)\n\t\t\treturn tree[t].v;\n\
    \t\tint tm = (tl + tr) / 2;\n\t\treturn merge(tree[t].l == -1 ? dval : query(l,\
    \ r, tree[t].l, tl, tm), tree[t].r == -1 ? dval : query(l, r, tree[t].r, tm +\
    \ 1, tr));\n\t}\n\npublic:\n\tSegtree() = default;\n\n\tSegtree(size_t _n) { init(_n);\
    \ }\n\n\tvoid init(size_t _n) {\n\t\tn = _n;\n\t\troot = new_node();\n\t}\n\n\t\
    void reserve(size_t _n) { tree.reserve(_n); }\n\n\tvoid clear() { tree.clear();\
    \ }\n\n\tvoid update(int i, T v) { update(i, v, root, 0, n - 1); }\n\n\tT query(int\
    \ l, int r) { return query(l, r, root, 0, n - 1); }\n};\n"
  code: "template<class Base>\nclass Segtree : public Base {\n\tusing T = typename\
    \ Base::T;\n\tusing Base::dval;\n\tusing Base::merge;\n\tusing Base::apply;\n\n\
    protected:\n\tsize_t n;\n\n\tstruct node {\n\t\tT v;\n\t\tint l, r;\n\t\tnode()\
    \ = default;\n\t\tnode(T _v, int _l, int _r) : v(_v), l(_l), r(_r) {}\n\t};\n\n\
    \tint root;\n\tvector<node> tree;\n\n\tsize_t new_node() {\n\t\ttree.emplace_back(dval,\
    \ -1, -1);\n\t\treturn tree.size() - 1;\n\t}\n\nprivate:\n\tvoid update(int i,\
    \ T v, int t, int tl, int tr) {\n\t\tif (tl == tr) {\n\t\t\tapply(tree[t].v, v);\n\
    \t\t\treturn;\n\t\t}\n\t\tint tm = (tl + tr) / 2;\n\t\tif (i <= tm) {\n\t\t\t\
    if (tree[t].l == -1)\n\t\t\t\ttree[t].l = new_node();\n\t\t\tupdate(i, v, tree[t].l,\
    \ tl, tm);\n\t\t} else {\n\t\t\tif (tree[t].r == -1)\n\t\t\t\ttree[t].r = new_node();\n\
    \t\t\tupdate(i, v, tree[t].r, tm + 1, tr);\n\t\t}\n\t\ttree[t].v = merge(tree[t].l\
    \ == -1 ? dval : tree[tree[t].l].v, tree[t].r == -1 ? dval : tree[tree[t].r].v);\n\
    \t}\n\n\tT query(int l, int r, int t, int tl, int tr) {\n\t\tif (r < tl || tr\
    \ < l)\n\t\t\treturn dval;\n\t\tif (l <= tl && tr <= r)\n\t\t\treturn tree[t].v;\n\
    \t\tint tm = (tl + tr) / 2;\n\t\treturn merge(tree[t].l == -1 ? dval : query(l,\
    \ r, tree[t].l, tl, tm), tree[t].r == -1 ? dval : query(l, r, tree[t].r, tm +\
    \ 1, tr));\n\t}\n\npublic:\n\tSegtree() = default;\n\n\tSegtree(size_t _n) { init(_n);\
    \ }\n\n\tvoid init(size_t _n) {\n\t\tn = _n;\n\t\troot = new_node();\n\t}\n\n\t\
    void reserve(size_t _n) { tree.reserve(_n); }\n\n\tvoid clear() { tree.clear();\
    \ }\n\n\tvoid update(int i, T v) { update(i, v, root, 0, n - 1); }\n\n\tT query(int\
    \ l, int r) { return query(l, r, root, 0, n - 1); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/sparse-segment-tree.hpp
  requiredBy: []
  timestamp: '2022-02-03 12:53:46-08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/sparse-segment-tree.aizu-the-number-of-inversions.test.cpp
  - verify/sparse-segment-tree.aizu-range-sum-query.test.cpp
  - verify/sparse-segment-tree.aizu-range-minimum-query.test.cpp
  - verify/sparse-segment-tree.yosupo-point-add-range-sum.test.cpp
  - verify/sparse-segment-tree.yosupo-point-set-range-composite.test.cpp
documentation_of: data-structure/sparse-segment-tree.hpp
layout: document
title: Sparse Segment Tree
---

## Sparse Segment Tree

### Summary

The segment tree is an online range query point update data structure that supports the following operations:
- Given some indicies $l, r$ such that $l \leq r$, returns the value $\Pi_{i = l}^r a_i$, where "$\cdot$" is an associative function.
- Given an index $i$ and a value $v$, applies an update of $v$ to $a_i$. 

Both these operations are performed in $\mathcal{O}(\log n)$ time, where $n$ is the number of elements represented by the segment tree. The space complexity is $\mathcal{O}(q \log n)$, where $q$ is the number of update operations performed. All indices are 0-based. 

### Preconditions

- `B` is a class with the following defined:
  - `T`: The node type.
  - `const T dval`: The identity element, such that for any element $a$ it satisfies $a \cdot dval = dval \cdot a = a$.
  - `T merge(T a, T b)`: Merges two nodes with values $a$ and $b$. 
  - `void apply(T &a, T b)`: Applies an update of value $b$ to a node with value $a$. 

### Methods

- `SegTree()`: Constructs an empty `Segtree` object.
- `SegTree(size_t _n)`: Constructs a `Segtree` object with initial capacity $n$ filled with the default value.
- `void init(int _n)`: Initializes a `Segtree` object with capacity $n$ filled with the default value in linear time. 
- `void update(int i, T v)`: Applies an update of $v$ to $a_i$ in logarithmic time. 
- `T query(int l, int r)`: Returns $\Pi_{i = l}^r a_i$ in logarithmic time. 