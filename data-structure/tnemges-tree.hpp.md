---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/tnemges-tree.aizu-point-add-query.test.cpp
    title: verify/tnemges-tree.aizu-point-add-query.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/tnemges-tree.hpp\"\ntemplate<typename T>\n\
    class tnemges_tree {\nprotected:\n\tint n;\n\tvector<T> tree;\n\npublic:\n\ttnemges_tree()\
    \ = default;\n\n\ttnemges_tree(int _n) { init(_n); }\n\n\tvoid init(int _n) {\n\
    \t\tn = _n;\n\t\ttree.assign(2 * n, 0);\n\t}\n\n\tvoid update(int l, int r, T\
    \ v) {\n\t\tfor (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {\n\t\t\tif (l &\
    \ 1) \n\t\t\t\ttree[l++] += v;\n\t\t\tif (r & 1) \n\t\t\t\ttree[--r] += v;\n\t\
    \t}\n\t}\n\n\tT query(int i) {\n\t\tT ret = 0;\n\t\tfor (i += n; i > 0; i >>=\
    \ 1)\n\t\t\tret += tree[i];\n\t\treturn ret;\n\t}\n\n\tT operator[](int i) { return\
    \ query(i); }\n};\n"
  code: "template<typename T>\nclass tnemges_tree {\nprotected:\n\tint n;\n\tvector<T>\
    \ tree;\n\npublic:\n\ttnemges_tree() = default;\n\n\ttnemges_tree(int _n) { init(_n);\
    \ }\n\n\tvoid init(int _n) {\n\t\tn = _n;\n\t\ttree.assign(2 * n, 0);\n\t}\n\n\
    \tvoid update(int l, int r, T v) {\n\t\tfor (l += n, r += n + 1; l < r; l >>=\
    \ 1, r >>= 1) {\n\t\t\tif (l & 1) \n\t\t\t\ttree[l++] += v;\n\t\t\tif (r & 1)\
    \ \n\t\t\t\ttree[--r] += v;\n\t\t}\n\t}\n\n\tT query(int i) {\n\t\tT ret = 0;\n\
    \t\tfor (i += n; i > 0; i >>= 1)\n\t\t\tret += tree[i];\n\t\treturn ret;\n\t}\n\
    \n\tT operator[](int i) { return query(i); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/tnemges-tree.hpp
  requiredBy: []
  timestamp: '2022-04-09 15:55:38-07:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/tnemges-tree.aizu-point-add-query.test.cpp
documentation_of: data-structure/tnemges-tree.hpp
layout: document
title: Tnemges Tree
---

## Tnemges Tree

### Summary
The tnemges tree is an online point query range update data structure that supports the following operations:
- Given an index $i$, returns the value at $a_i$.
- Given some indicies $l, r$ such that $l \leq r$ and a value $v$, assigns $a_i$ to $a_i + v$ for $i \in [l, r]$

Both these operations are performed in $\mathcal{O}(\log n) time, where $n$ is the number of elements represented by the tnemges tree. The total space used is $2 * n$. All indices represented in a tnemges tree are zero-indexed.