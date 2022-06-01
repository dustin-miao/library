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
  bundledCode: "#line 1 \"data-structure/segment-tree.hpp\"\n#pragma region segment_tree\n\
    \ntemplate<class segment_tree_template>\nclass segment_tree : public segment_tree_template\
    \ {\n\tusing T = typename segment_tree_template::type;\n\tusing segment_tree_template::default_value;\n\
    \tusing segment_tree_template::merge;\n\tusing segment_tree_template::apply;\n\
    \nprotected:\n\tint n;\n\tvector<T> tree;\n\npublic:\n\tsegment_tree() = default;\n\
    \n\tsegment_tree(int _n) { init(_n); }\n\n\tvoid init(int _n) {\n\t\tn = _n;\n\
    \t\ttree.assign(n * 2, default_value);\n\t}\n\n\tvoid update(int i, T v) {\n\t\
    \tfor (apply(tree[i += n], v); i >>= 1;)\n\t\t\ttree[i] = merge(tree[i << 1],\
    \ tree[i << 1 | 1]);\n\t}\n\n\tT query(int l, int r) {\n\t\tT ret = default_value;\n\
    \t\tfor (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {\n\t\t\tif (l & 1) \n\t\
    \t\t\tret = merge(ret, tree[l++]);\n\t\t\tif (r & 1) \n\t\t\t\tret = merge(ret,\
    \ tree[--r]);\n\t\t}\n\t\treturn ret;\n\t}\n\n\tT operator[](int i) { return tree[i\
    \ += n]; }\n};\n\n#pragma endregion segment_tree\n"
  code: "#pragma region segment_tree\n\ntemplate<class segment_tree_template>\nclass\
    \ segment_tree : public segment_tree_template {\n\tusing T = typename segment_tree_template::type;\n\
    \tusing segment_tree_template::default_value;\n\tusing segment_tree_template::merge;\n\
    \tusing segment_tree_template::apply;\n\nprotected:\n\tint n;\n\tvector<T> tree;\n\
    \npublic:\n\tsegment_tree() = default;\n\n\tsegment_tree(int _n) { init(_n); }\n\
    \n\tvoid init(int _n) {\n\t\tn = _n;\n\t\ttree.assign(n * 2, default_value);\n\
    \t}\n\n\tvoid update(int i, T v) {\n\t\tfor (apply(tree[i += n], v); i >>= 1;)\n\
    \t\t\ttree[i] = merge(tree[i << 1], tree[i << 1 | 1]);\n\t}\n\n\tT query(int l,\
    \ int r) {\n\t\tT ret = default_value;\n\t\tfor (l += n, r += n + 1; l < r; l\
    \ >>= 1, r >>= 1) {\n\t\t\tif (l & 1) \n\t\t\t\tret = merge(ret, tree[l++]);\n\
    \t\t\tif (r & 1) \n\t\t\t\tret = merge(ret, tree[--r]);\n\t\t}\n\t\treturn ret;\n\
    \t}\n\n\tT operator[](int i) { return tree[i += n]; }\n};\n\n#pragma endregion\
    \ segment_tree"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segment-tree.hpp
  requiredBy: []
  timestamp: '2022-04-29 22:36:50-07:00'
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