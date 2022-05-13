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
  bundledCode: "#line 1 \"data-structure/recursive-segment-tree.hpp\"\n#pragma region\
    \ recursive_segment_tree\n\ntemplate<class segment_tree_template>\nclass recursive_segment_tree\
    \ : public segment_tree_template {\n\tusing T = typename segment_tree_template::type;\n\
    \tusing segment_tree_template::default_value;\n\tusing segment_tree_template::merge;\n\
    \tusing segment_tree_template::apply;\n\nprotected:\n\tint n;\n\tvector<T> tree;\n\
    \nprivate:\n\tvoid update(int i, T v, int t, int tl, int tr) {\n\t\tif (tl ==\
    \ tr) {\n\t\t\tapply(tree[t], v);\n\t\t\treturn;\n\t\t}\n\t\tint tm = (tl + tr)\
    \ / 2;\n\t\tif (i <= tm)\n\t\t\tupdate(i, v, t * 2, tl, tm);\n\t\telse \n\t\t\t\
    update(i, v, t * 2 + 1, tm + 1, tr);\n\t\ttree[t] = merge(tree[t * 2], tree[t\
    \ * 2 + 1]);\n\t}\n\n\tT query(int l, int r, int t, int tl, int tr) {\n\t\tif\
    \ (r < tl || tr < l)\n\t\t\treturn default_value;\n\t\tif (l <= tl && tr <= r)\n\
    \t\t\treturn tree[t];\n\t\tint tm = (tl + tr) / 2;\n\t\treturn merge(query(l,\
    \ r, t * 2, tl, tm), query(l, r, t * 2 + 1, tm + 1, tr));\n\t}\n\npublic:\n\t\
    recursive_segment_tree() = default;\n\n\trecursive_segment_tree(int _n) { init(_n);\
    \ }\n\n\tvoid init(int _n) {\n\t\tn = _n;\n\t\ttree.assign(n * 4, default_value);\n\
    \t}\n\n\tvoid update(int i, T v) { update(i, v, 1, 0, n - 1); }\n\n\tT query(int\
    \ l, int r) { return query(l, r, 1, 0, n - 1); }\n};\n\n#pragma endregion recursive_segment_tree\n"
  code: "#pragma region recursive_segment_tree\n\ntemplate<class segment_tree_template>\n\
    class recursive_segment_tree : public segment_tree_template {\n\tusing T = typename\
    \ segment_tree_template::type;\n\tusing segment_tree_template::default_value;\n\
    \tusing segment_tree_template::merge;\n\tusing segment_tree_template::apply;\n\
    \nprotected:\n\tint n;\n\tvector<T> tree;\n\nprivate:\n\tvoid update(int i, T\
    \ v, int t, int tl, int tr) {\n\t\tif (tl == tr) {\n\t\t\tapply(tree[t], v);\n\
    \t\t\treturn;\n\t\t}\n\t\tint tm = (tl + tr) / 2;\n\t\tif (i <= tm)\n\t\t\tupdate(i,\
    \ v, t * 2, tl, tm);\n\t\telse \n\t\t\tupdate(i, v, t * 2 + 1, tm + 1, tr);\n\t\
    \ttree[t] = merge(tree[t * 2], tree[t * 2 + 1]);\n\t}\n\n\tT query(int l, int\
    \ r, int t, int tl, int tr) {\n\t\tif (r < tl || tr < l)\n\t\t\treturn default_value;\n\
    \t\tif (l <= tl && tr <= r)\n\t\t\treturn tree[t];\n\t\tint tm = (tl + tr) / 2;\n\
    \t\treturn merge(query(l, r, t * 2, tl, tm), query(l, r, t * 2 + 1, tm + 1, tr));\n\
    \t}\n\npublic:\n\trecursive_segment_tree() = default;\n\n\trecursive_segment_tree(int\
    \ _n) { init(_n); }\n\n\tvoid init(int _n) {\n\t\tn = _n;\n\t\ttree.assign(n *\
    \ 4, default_value);\n\t}\n\n\tvoid update(int i, T v) { update(i, v, 1, 0, n\
    \ - 1); }\n\n\tT query(int l, int r) { return query(l, r, 1, 0, n - 1); }\n};\n\
    \n#pragma endregion recursive_segment_tree"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/recursive-segment-tree.hpp
  requiredBy: []
  timestamp: '2022-04-29 22:36:50-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/recursive-segment-tree.yosupo-point-add-range-sum.test.cpp
  - verify/recursive-segment-tree.aizu-range-minimum-query.test.cpp
  - verify/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp
  - verify/recursive-segment-tree.aizu-range-sum-query.test.cpp
documentation_of: data-structure/recursive-segment-tree.hpp
layout: document
title: Recursive Segment Tree
---

## Recursive Segment Tree

### Summary
The segment tree is an online range query point update data structure that supports the following operations:
- Given some indicies $l, r$ such that $l \leq r$, returns the value $\Pi_{i = l}^r a_i$, where "$\cdot$" is an associative function.
- Given an index $i$ and a value $v$, applies an update of $v$ to $a_i$. 

Both these operations are performed in $\mathcal{O}(\log n)$ time, where $n$ is the number of elements represented by the segment tree. The total space used is $4n$. All indices are 0-based. 