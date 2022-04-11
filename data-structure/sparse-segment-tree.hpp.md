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
    \ segment_tree_template>\nclass sparse_segment_tree : public segment_tree_template\
    \ {\n\tusing T = typename segment_tree_template::type;\n\tusing segment_tree_template::default_value;\n\
    \tusing segment_tree_template::merge;\n\tusing segment_tree_template::apply;\n\
    \nprotected:\n\tint n;\n\n\tstruct node {\n\t\tT v;\n\t\tint l, r;\n\t\tnode()\
    \ = default;\n\t\tnode(T _v, int _l, int _r) : v(_v), l(_l), r(_r) {}\n\t};\n\n\
    \tint root;\n\tvector<node> tree;\n\n\tint new_node() {\n\t\ttree.emplace_back(default_value,\
    \ -1, -1);\n\t\treturn tree.size() - 1;\n\t}\n\nprivate:\n\tvoid update(int i,\
    \ T v, int t, int tl, int tr) {\n\t\tif (tl == tr) {\n\t\t\tapply(tree[t].v, v);\n\
    \t\t\treturn;\n\t\t}\n\t\tint tm = (tl + tr) / 2;\n\t\tif (i <= tm) {\n\t\t\t\
    if (tree[t].l == -1)\n\t\t\t\ttree[t].l = new_node();\n\t\t\tupdate(i, v, tree[t].l,\
    \ tl, tm);\n\t\t} else {\n\t\t\tif (tree[t].r == -1)\n\t\t\t\ttree[t].r = new_node();\n\
    \t\t\tupdate(i, v, tree[t].r, tm + 1, tr);\n\t\t}\n\t\ttree[t].v = merge(tree[t].l\
    \ == -1 ? default_value : tree[tree[t].l].v, \n\t\t\ttree[t].r == -1 ? default_value\
    \ : tree[tree[t].r].v);\n\t}\n\n\tT query(int l, int r, int t, int tl, int tr)\
    \ {\n\t\tif (r < tl || tr < l)\n\t\t\treturn default_value;\n\t\tif (l <= tl &&\
    \ tr <= r)\n\t\t\treturn tree[t].v;\n\t\tint tm = (tl + tr) / 2;\n\t\treturn merge(tree[t].l\
    \ == -1 ? default_value : query(l, r, tree[t].l, tl, tm), \n\t\t\ttree[t].r ==\
    \ -1 ? default_value : query(l, r, tree[t].r, tm + 1, tr));\n\t}\n\npublic:\n\t\
    sparse_segment_tree() = default;\n\n\tsparse_segment_tree(int _n) { init(_n);\
    \ }\n\n\tvoid init(int _n) {\n\t\tn = _n;\n\t\troot = new_node();\n\t}\n\n\tvoid\
    \ reserve(int _n) { tree.reserve(_n); }\n\n\tvoid clear() { tree.clear(); }\n\n\
    \tvoid update(int i, T v) { update(i, v, root, 0, n - 1); }\n\n\tT query(int l,\
    \ int r) { return query(l, r, root, 0, n - 1); }\n};\n"
  code: "template<class segment_tree_template>\nclass sparse_segment_tree : public\
    \ segment_tree_template {\n\tusing T = typename segment_tree_template::type;\n\
    \tusing segment_tree_template::default_value;\n\tusing segment_tree_template::merge;\n\
    \tusing segment_tree_template::apply;\n\nprotected:\n\tint n;\n\n\tstruct node\
    \ {\n\t\tT v;\n\t\tint l, r;\n\t\tnode() = default;\n\t\tnode(T _v, int _l, int\
    \ _r) : v(_v), l(_l), r(_r) {}\n\t};\n\n\tint root;\n\tvector<node> tree;\n\n\t\
    int new_node() {\n\t\ttree.emplace_back(default_value, -1, -1);\n\t\treturn tree.size()\
    \ - 1;\n\t}\n\nprivate:\n\tvoid update(int i, T v, int t, int tl, int tr) {\n\t\
    \tif (tl == tr) {\n\t\t\tapply(tree[t].v, v);\n\t\t\treturn;\n\t\t}\n\t\tint tm\
    \ = (tl + tr) / 2;\n\t\tif (i <= tm) {\n\t\t\tif (tree[t].l == -1)\n\t\t\t\ttree[t].l\
    \ = new_node();\n\t\t\tupdate(i, v, tree[t].l, tl, tm);\n\t\t} else {\n\t\t\t\
    if (tree[t].r == -1)\n\t\t\t\ttree[t].r = new_node();\n\t\t\tupdate(i, v, tree[t].r,\
    \ tm + 1, tr);\n\t\t}\n\t\ttree[t].v = merge(tree[t].l == -1 ? default_value :\
    \ tree[tree[t].l].v, \n\t\t\ttree[t].r == -1 ? default_value : tree[tree[t].r].v);\n\
    \t}\n\n\tT query(int l, int r, int t, int tl, int tr) {\n\t\tif (r < tl || tr\
    \ < l)\n\t\t\treturn default_value;\n\t\tif (l <= tl && tr <= r)\n\t\t\treturn\
    \ tree[t].v;\n\t\tint tm = (tl + tr) / 2;\n\t\treturn merge(tree[t].l == -1 ?\
    \ default_value : query(l, r, tree[t].l, tl, tm), \n\t\t\ttree[t].r == -1 ? default_value\
    \ : query(l, r, tree[t].r, tm + 1, tr));\n\t}\n\npublic:\n\tsparse_segment_tree()\
    \ = default;\n\n\tsparse_segment_tree(int _n) { init(_n); }\n\n\tvoid init(int\
    \ _n) {\n\t\tn = _n;\n\t\troot = new_node();\n\t}\n\n\tvoid reserve(int _n) {\
    \ tree.reserve(_n); }\n\n\tvoid clear() { tree.clear(); }\n\n\tvoid update(int\
    \ i, T v) { update(i, v, root, 0, n - 1); }\n\n\tT query(int l, int r) { return\
    \ query(l, r, root, 0, n - 1); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/sparse-segment-tree.hpp
  requiredBy: []
  timestamp: '2022-04-11 08:59:21-07:00'
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