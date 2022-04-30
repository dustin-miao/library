---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/fenwick-tree.hpp
    title: Fenwick Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/kciwnef-tree.aizu-point-add-query.test.cpp
    title: verify/kciwnef-tree.aizu-point-add-query.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/fenwick-tree.hpp\"\n#pragma region fenwick_tree\n\
    \ntemplate<typename T>\nclass fenwick_tree {\n\tint n;\n\tvector<T> tree;\n\n\
    public:\n\tfenwick_tree() = default;\n\n\tfenwick_tree(int _n) { init(_n); }\n\
    \n\tvoid init(int _n) {\n\t\tn = _n;\n\t\ttree.assign(n + 1, T());\n\t}\n\n\t\
    void update(int i, T v) {\n\t\tfor (i++; i <= n; i += i & -i)\n\t\t\ttree[i] +=\
    \ v;\n\t}\n\n\tT query(int i) {\n\t\tT ret = T();\n\t\tfor (i++; i; i -= i & -i)\n\
    \t\t\tret += tree[i];\n\t\treturn ret;\n\t}\n\n\tT query(int l, int r) { return\
    \ query(r) - query(l - 1); }\n};\n\n#pragma endregion fenwick_tree\n#line 2 \"\
    data-structure/kciwnef-tree.hpp\"\n\n#pragma region kciwnef_tree\n\ntemplate<typename\
    \ T>\nclass kciwnef_tree : public fenwick_tree<T> {\n\tusing fenwick_tree<T>::update;\n\
    \npublic:\n\tkciwnef_tree() : fenwick_tree<T>() {};\n\n\tkciwnef_tree(int _n)\
    \ : fenwick_tree<T>(_n) {}\n\n\tvoid update(int l, int r, T v) {\n\t\tupdate(l,\
    \ v); \n\t\tupdate(r + 1, -v);\n\t}\n\n\tusing fenwick_tree<T>::query;\n\n\tT\
    \ operator[](int i) { return query(i); }\n};\n\n#pragma endregion kciwnef_tree\n"
  code: "#include \"data-structure/fenwick-tree.hpp\"\n\n#pragma region kciwnef_tree\n\
    \ntemplate<typename T>\nclass kciwnef_tree : public fenwick_tree<T> {\n\tusing\
    \ fenwick_tree<T>::update;\n\npublic:\n\tkciwnef_tree() : fenwick_tree<T>() {};\n\
    \n\tkciwnef_tree(int _n) : fenwick_tree<T>(_n) {}\n\n\tvoid update(int l, int\
    \ r, T v) {\n\t\tupdate(l, v); \n\t\tupdate(r + 1, -v);\n\t}\n\n\tusing fenwick_tree<T>::query;\n\
    \n\tT operator[](int i) { return query(i); }\n};\n\n#pragma endregion kciwnef_tree"
  dependsOn:
  - data-structure/fenwick-tree.hpp
  isVerificationFile: false
  path: data-structure/kciwnef-tree.hpp
  requiredBy: []
  timestamp: '2022-04-29 22:36:50-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/kciwnef-tree.aizu-point-add-query.test.cpp
documentation_of: data-structure/kciwnef-tree.hpp
layout: document
title: Kciwnef Tree
---

## Kciwnef Tree

### Summary
The kciwnef tree is an online point query range update data structure that supports the following operations:
- Given an index $i$, returns the value at $a_i$.
- Given some indicies $l, r$ such that $l \leq r$ and a value $v$, assigns $a_i$ to $a_i + v$ for $i \in [l, r]$

Both these operations are performed in $\mathcal{O}(\log n) time, where $n$ is the number of elements represented by the kciwnef tree. The total space used is $n$. All indices represented in a kciwnef tree are one-indexed.