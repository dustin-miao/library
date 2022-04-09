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
  bundledCode: "#line 1 \"data-structure/lazy-segment-tree.hpp\"\ntemplate<class segment_tree_template>\n\
    class lazy_segment_tree : public segment_tree_template {\n\tusing T = typename\
    \ segment_tree_template::node_type;\n\tusing L = typename segment_tree_template::lazy_type;\n\
    \tusing segment_tree_template::node_default_value;\n\tusing segment_tree_template::lazy_default_value;\n\
    \tusing segment_tree_template::merge;\n\tusing segment_tree_template::apply;\n\
    \nprotected:\n\tint n;\n\tvector<T> tree;\n\tvector<L> lazy;\n\nprivate:\n\tvoid\
    \ pushdown(int t, int tl, int tr) {\n\t\tif (lazy[t] == lazy_default_value)\n\t\
    \t\treturn;\n\t\tint tm = (tl + tr) / 2;\n\t\tapply(tree[t * 2], lazy[t * 2],\
    \ lazy[t], tl, tm);\n\t\tapply(tree[t * 2 + 1], lazy[t * 2 + 1], lazy[t], tm +\
    \ 1, tr);\n\t\tlazy[t] = lazy_default_value;\n\t}\n\n\tvoid update(int l, int\
    \ r, L v, int t, int tl, int tr) {\n\t\tif (r < tl || tr < l)\n\t\t\treturn;\n\
    \t\tif (l <= tl && tr <= r) {\n\t\t\tapply(tree[t], lazy[t], v, tl, tr);\n\t\t\
    \treturn;\n\t\t}\n\t\tpushdown(t, tl, tr);\n\t\tint tm = (tl + tr) / 2;\n\t\t\
    update(l, r, v, t * 2, tl, tm);\n\t\tupdate(l, r, v, t * 2 + 1, tm + 1, tr);\n\
    \t\ttree[t] = merge(tree[t * 2], tree[t * 2 + 1]);\n\t}\n\n\tT query(int l, int\
    \ r, int t, int tl, int tr) {\n\t\tif (r < tl || tr < l)\n\t\t\treturn node_default_value;\n\
    \t\tif (l <= tl && tr <= r)\n\t\t\treturn tree[t];\n\t\tpushdown(t, tl, tr);\n\
    \t\tint tm = (tl + tr) / 2;\n\t\treturn merge(query(l, r, t * 2, tl, tm), query(l,\
    \ r, t * 2 + 1, tm + 1, tr));\n\t}\n\npublic:\n\tlazy_segment_tree() = default;\n\
    \n\tlazy_segment_tree(int _n) { init(_n); }\n\n\tvoid init(int _n) {\n\t\tn =\
    \ _n;\n\t\ttree.assign(4 * n, node_default_value);\n\t\tlazy.assign(4 * n, lazy_default_value);\n\
    \t}\n\n\tvoid update(int l, int r, L v) { update(l, r, v, 1, 0, n - 1); }\n\n\t\
    T query(int l, int r) { return query(l, r, 1, 0, n - 1); }\n};\n"
  code: "template<class segment_tree_template>\nclass lazy_segment_tree : public segment_tree_template\
    \ {\n\tusing T = typename segment_tree_template::node_type;\n\tusing L = typename\
    \ segment_tree_template::lazy_type;\n\tusing segment_tree_template::node_default_value;\n\
    \tusing segment_tree_template::lazy_default_value;\n\tusing segment_tree_template::merge;\n\
    \tusing segment_tree_template::apply;\n\nprotected:\n\tint n;\n\tvector<T> tree;\n\
    \tvector<L> lazy;\n\nprivate:\n\tvoid pushdown(int t, int tl, int tr) {\n\t\t\
    if (lazy[t] == lazy_default_value)\n\t\t\treturn;\n\t\tint tm = (tl + tr) / 2;\n\
    \t\tapply(tree[t * 2], lazy[t * 2], lazy[t], tl, tm);\n\t\tapply(tree[t * 2 +\
    \ 1], lazy[t * 2 + 1], lazy[t], tm + 1, tr);\n\t\tlazy[t] = lazy_default_value;\n\
    \t}\n\n\tvoid update(int l, int r, L v, int t, int tl, int tr) {\n\t\tif (r <\
    \ tl || tr < l)\n\t\t\treturn;\n\t\tif (l <= tl && tr <= r) {\n\t\t\tapply(tree[t],\
    \ lazy[t], v, tl, tr);\n\t\t\treturn;\n\t\t}\n\t\tpushdown(t, tl, tr);\n\t\tint\
    \ tm = (tl + tr) / 2;\n\t\tupdate(l, r, v, t * 2, tl, tm);\n\t\tupdate(l, r, v,\
    \ t * 2 + 1, tm + 1, tr);\n\t\ttree[t] = merge(tree[t * 2], tree[t * 2 + 1]);\n\
    \t}\n\n\tT query(int l, int r, int t, int tl, int tr) {\n\t\tif (r < tl || tr\
    \ < l)\n\t\t\treturn node_default_value;\n\t\tif (l <= tl && tr <= r)\n\t\t\t\
    return tree[t];\n\t\tpushdown(t, tl, tr);\n\t\tint tm = (tl + tr) / 2;\n\t\treturn\
    \ merge(query(l, r, t * 2, tl, tm), query(l, r, t * 2 + 1, tm + 1, tr));\n\t}\n\
    \npublic:\n\tlazy_segment_tree() = default;\n\n\tlazy_segment_tree(int _n) { init(_n);\
    \ }\n\n\tvoid init(int _n) {\n\t\tn = _n;\n\t\ttree.assign(4 * n, node_default_value);\n\
    \t\tlazy.assign(4 * n, lazy_default_value);\n\t}\n\n\tvoid update(int l, int r,\
    \ L v) { update(l, r, v, 1, 0, n - 1); }\n\n\tT query(int l, int r) { return query(l,\
    \ r, 1, 0, n - 1); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/lazy-segment-tree.hpp
  requiredBy: []
  timestamp: '2022-04-09 15:55:38-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lazy-segment-tree.aizu-RMQ-and-RAQ.test.cpp
  - verify/lazy-segment-tree.yosupo-range-affine-range-sum.test.cpp
  - verify/lazy-segment-tree.aizu-RSQ-and-RAQ.test.cpp
  - verify/lazy-segment-tree.aizu-RMQ-and-RUQ.test.cpp
  - verify/lazy-segment-tree.aizu-RSQ-and-RUQ.test.cpp
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