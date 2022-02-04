---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/lazy-segment-tree.aizu-RMQ-and-RAQ.test.cpp
    title: verify/lazy-segment-tree.aizu-RMQ-and-RAQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/lazy-segment-tree.aizu-RMQ-and-RUQ.test.cpp
    title: verify/lazy-segment-tree.aizu-RMQ-and-RUQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/lazy-segment-tree.aizu-RSQ-and-RAQ.test.cpp
    title: verify/lazy-segment-tree.aizu-RSQ-and-RAQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/lazy-segment-tree.aizu-RSQ-and-RUQ.test.cpp
    title: verify/lazy-segment-tree.aizu-RSQ-and-RUQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/lazy-segment-tree.yosupo-range-affine-range-sum.test.cpp
    title: verify/lazy-segment-tree.yosupo-range-affine-range-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/lazy-segment-tree.hpp\"\ntemplate<class Base>\n\
    class Segtree : public Base {\n\tusing T = typename Base::T;\n\tusing L = typename\
    \ Base::L;\n\tusing Base::Tdval;\n\tusing Base::Ldval;\n\tusing Base::merge;\n\
    \tusing Base::apply;\n\nprotected:\n\tsize_t n;\n\tvector<T> tree;\n\tvector<L>\
    \ lazy;\n\nprivate:\n\tvoid pushdown(int t, int tl, int tr) {\n\t\tif (lazy[t]\
    \ == Ldval)\n\t\t\treturn;\n\t\tint tm = (tl + tr) / 2;\n\t\tapply(tree[t * 2],\
    \ lazy[t * 2], lazy[t], tl, tm);\n\t\tapply(tree[t * 2 + 1], lazy[t * 2 + 1],\
    \ lazy[t], tm + 1, tr);\n\t\tlazy[t] = Ldval;\n\t}\n\n\tvoid update(int l, int\
    \ r, L v, int t, int tl, int tr) {\n\t\tif (r < tl || tr < l)\n\t\t\treturn;\n\
    \t\tif (l <= tl && tr <= r) {\n\t\t\tapply(tree[t], lazy[t], v, tl, tr);\n\t\t\
    \treturn;\n\t\t}\n\t\tpushdown(t, tl, tr);\n\t\tint tm = (tl + tr) / 2;\n\t\t\
    update(l, r, v, t * 2, tl, tm);\n\t\tupdate(l, r, v, t * 2 + 1, tm + 1, tr);\n\
    \t\ttree[t] = merge(tree[t * 2], tree[t * 2 + 1]);\n\t}\n\n\tT query(int l, int\
    \ r, int t, int tl, int tr) {\n\t\tif (r < tl || tr < l)\n\t\t\treturn Tdval;\n\
    \t\tif (l <= tl && tr <= r)\n\t\t\treturn tree[t];\n\t\tpushdown(t, tl, tr);\n\
    \t\tint tm = (tl + tr) / 2;\n\t\treturn merge(query(l, r, t * 2, tl, tm), query(l,\
    \ r, t * 2 + 1, tm + 1, tr));\n\t}\n\npublic:\n\tSegtree() = default;\n\n\tSegtree(size_t\
    \ _n) { init(_n); }\n\n\tvoid init(size_t _n) {\n\t\tn = _n;\n\t\ttree.assign(4\
    \ * n, Tdval);\n\t\tlazy.assign(4 * n, Ldval);\n\t}\n\n\tvoid update(int l, int\
    \ r, L v) { update(l, r, v, 1, 0, n - 1); }\n\n\tT query(int l, int r) { return\
    \ query(l, r, 1, 0, n - 1); }\n};\n"
  code: "template<class Base>\nclass Segtree : public Base {\n\tusing T = typename\
    \ Base::T;\n\tusing L = typename Base::L;\n\tusing Base::Tdval;\n\tusing Base::Ldval;\n\
    \tusing Base::merge;\n\tusing Base::apply;\n\nprotected:\n\tsize_t n;\n\tvector<T>\
    \ tree;\n\tvector<L> lazy;\n\nprivate:\n\tvoid pushdown(int t, int tl, int tr)\
    \ {\n\t\tif (lazy[t] == Ldval)\n\t\t\treturn;\n\t\tint tm = (tl + tr) / 2;\n\t\
    \tapply(tree[t * 2], lazy[t * 2], lazy[t], tl, tm);\n\t\tapply(tree[t * 2 + 1],\
    \ lazy[t * 2 + 1], lazy[t], tm + 1, tr);\n\t\tlazy[t] = Ldval;\n\t}\n\n\tvoid\
    \ update(int l, int r, L v, int t, int tl, int tr) {\n\t\tif (r < tl || tr < l)\n\
    \t\t\treturn;\n\t\tif (l <= tl && tr <= r) {\n\t\t\tapply(tree[t], lazy[t], v,\
    \ tl, tr);\n\t\t\treturn;\n\t\t}\n\t\tpushdown(t, tl, tr);\n\t\tint tm = (tl +\
    \ tr) / 2;\n\t\tupdate(l, r, v, t * 2, tl, tm);\n\t\tupdate(l, r, v, t * 2 + 1,\
    \ tm + 1, tr);\n\t\ttree[t] = merge(tree[t * 2], tree[t * 2 + 1]);\n\t}\n\n\t\
    T query(int l, int r, int t, int tl, int tr) {\n\t\tif (r < tl || tr < l)\n\t\t\
    \treturn Tdval;\n\t\tif (l <= tl && tr <= r)\n\t\t\treturn tree[t];\n\t\tpushdown(t,\
    \ tl, tr);\n\t\tint tm = (tl + tr) / 2;\n\t\treturn merge(query(l, r, t * 2, tl,\
    \ tm), query(l, r, t * 2 + 1, tm + 1, tr));\n\t}\n\npublic:\n\tSegtree() = default;\n\
    \n\tSegtree(size_t _n) { init(_n); }\n\n\tvoid init(size_t _n) {\n\t\tn = _n;\n\
    \t\ttree.assign(4 * n, Tdval);\n\t\tlazy.assign(4 * n, Ldval);\n\t}\n\n\tvoid\
    \ update(int l, int r, L v) { update(l, r, v, 1, 0, n - 1); }\n\n\tT query(int\
    \ l, int r) { return query(l, r, 1, 0, n - 1); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/lazy-segment-tree.hpp
  requiredBy: []
  timestamp: '2022-02-02 15:19:45-08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lazy-segment-tree.yosupo-range-affine-range-sum.test.cpp
  - verify/lazy-segment-tree.aizu-RSQ-and-RUQ.test.cpp
  - verify/lazy-segment-tree.aizu-RMQ-and-RAQ.test.cpp
  - verify/lazy-segment-tree.aizu-RMQ-and-RUQ.test.cpp
  - verify/lazy-segment-tree.aizu-RSQ-and-RAQ.test.cpp
documentation_of: data-structure/lazy-segment-tree.hpp
layout: document
title: Lazy Segment Tree
---

## Lazy Segment Tree

### Summary

The lazy segment tree is an online range query range update data structure that supports the following operations:
- Given some indicies $l, r$ such that $l \leq r$, returns the value $\Pi_{i = l}^r a_i$, where "$\cdot$" is an associative function.
- Given some indicies $l, r$ such that $l \leq r$ and a value $v$, applies an update of $v$ to $a_i \forall i \in [l, r]$. 

Both these operations are performed in $\mathcal{O}(\log n)$ time, where $n$ is the number of elements represented by the segment tree. The space complexity is $\mathcal{O}(q \log n)$, where $q$ is the number of update operations performed. All indices are 0-based. 

### Preconditions

- `B` is a class with the following defined:
  - `T`: The node type.
  - `L`: The update type.
  - `const T Tdval`: The identity node type, such that for any element $a$ it satisfies $a \cdot dval = dval \cdot a = a$.
  - `const L Ldval`: The identity update type, such that any update $v$ applied to some node with lazy value $Ldval$ returns $v$. 
  - `T merge(T a, T b)`: Merges two nodes with values $a$ and $b$. 
  - `void apply(T &a, L &b, L c, int l, int r)`: Applies an update with value $c$ to a node with node value $a$, lazy value $b$ and spans a range from $l$ to $r$. 

### Methods

- `SegTree()`: Constructs an empty `Segtree` object.
- `SegTree(size_t _n)`: Constructs a `Segtree` object with initial capacity $n$ filled with the default value.
- `void init(int _n)`: Initializes a `Segtree` object with capacity $n$ filled with the default value in linear time. 
- `void update(int l, int r, T v)`: Applies an update of $v$ to $a_i \forall i \in [l, r]$ in logarithmic time. 
- `T query(int l, int r)`: Returns $\Pi_{i = l}^r a_i$ in logarithmic time. 