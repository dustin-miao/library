---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/static-general-segment-tree.yosupo-point-add-range-sum.test.cpp
    title: verify/static-general-segment-tree.yosupo-point-add-range-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/static-general-segment-tree.hpp\"\nclass\
    \ sta_gen_segment_tree {\n\tusing T = long long;\n\n\tstatic constexpr T default_value\
    \ = 0;\n\n\tstatic void apply(T &a, T b) { a += b; }\n\n\tstatic T merge(T a,\
    \ T b) { return a + b; }\n\nprotected:\n\tint n;\n\tvector<T> tree;\n\npublic:\n\
    \tsta_gen_segment_tree() = default;\n\n\tsta_gen_segment_tree(size_t _n) { init(_n);\
    \ }\n\n\tvoid init(int _n) {\n\t\tfor (n = 1; n < _n; n *= 2);\n\t\ttree.assign(n\
    \ * 2, default_value);\n\t}\n\n\tvoid update(int i, T v) {\n\t\tfor (apply(tree[i\
    \ += n], v); i >>= 1;)\n\t\t\ttree[i] = merge(tree[i << 1], tree[i << 1 | 1]);\n\
    \t}\n\n\tT query(int l, int r) {\n\t\tT lret = default_value, rret = default_value;\n\
    \t\tfor (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {\n\t\t\tif (l & 1) \n\t\
    \t\t\tlret = merge(lret, tree[l++]);\n\t\t\tif (r & 1) \n\t\t\t\trret = merge(tree[--r],\
    \ rret);\n\t\t}\n\t\treturn merge(lret, rret);\n\t}\n\n\tT operator[](int i) {\
    \ return tree[i + n]; }\n};\n"
  code: "class sta_gen_segment_tree {\n\tusing T = long long;\n\n\tstatic constexpr\
    \ T default_value = 0;\n\n\tstatic void apply(T &a, T b) { a += b; }\n\n\tstatic\
    \ T merge(T a, T b) { return a + b; }\n\nprotected:\n\tint n;\n\tvector<T> tree;\n\
    \npublic:\n\tsta_gen_segment_tree() = default;\n\n\tsta_gen_segment_tree(size_t\
    \ _n) { init(_n); }\n\n\tvoid init(int _n) {\n\t\tfor (n = 1; n < _n; n *= 2);\n\
    \t\ttree.assign(n * 2, default_value);\n\t}\n\n\tvoid update(int i, T v) {\n\t\
    \tfor (apply(tree[i += n], v); i >>= 1;)\n\t\t\ttree[i] = merge(tree[i << 1],\
    \ tree[i << 1 | 1]);\n\t}\n\n\tT query(int l, int r) {\n\t\tT lret = default_value,\
    \ rret = default_value;\n\t\tfor (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)\
    \ {\n\t\t\tif (l & 1) \n\t\t\t\tlret = merge(lret, tree[l++]);\n\t\t\tif (r &\
    \ 1) \n\t\t\t\trret = merge(tree[--r], rret);\n\t\t}\n\t\treturn merge(lret, rret);\n\
    \t}\n\n\tT operator[](int i) { return tree[i + n]; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/static-general-segment-tree.hpp
  requiredBy: []
  timestamp: '2022-04-09 15:55:38-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/static-general-segment-tree.yosupo-point-add-range-sum.test.cpp
documentation_of: data-structure/static-general-segment-tree.hpp
layout: document
title: Static General Segment Tree
---

## Static General Segment Tree