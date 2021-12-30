---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data-structure/segment-tree/yosupo-point-add-range-sum.test.cpp
    title: verify/data-structure/segment-tree/yosupo-point-add-range-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/segment-tree.hpp\"\ntemplate<typename T>\n\
    struct SegmentTree {\n    int n;\n    vector<T> tree;\n\nprotected:\n    T dval\
    \ = T();\n\n    T merge(const T &a, const T &b) { return a + b; }\n\n    void\
    \ apply(T &a, const T &b) { a = b; }\n\npublic:\n    SegmentTree() = default;\n\
    \n    SegmentTree(int _n, T _v = T()) : n(_n), dval(_v) {\n        tree.assign(2\
    \ * n, dval);\n    }\n\n    template<typename Iterator>\n    SegmentTree(Iterator\
    \ begin, Iterator end, T _v = T()) : n(distance(begin, end)), dval(_v) {\n\t\t\
    tree.resize(2 * n);\n        for (int i = n; i < 2 * n; i++, begin++)\n      \
    \      tree[i] = *begin;\n        for (int i = n - 1; i > 0; i--)\n          \
    \  tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);\n    }\n\n    T query(int\
    \ l, int r) {\n        T ret = dval;\n        for (l += n, r += n + 1; l < r;\
    \ l >>= 1, r >>= 1) {\n            if (l & 1) ret = merge(ret, tree[l++]);\n \
    \           if (r & 1) ret = merge(ret, tree[--r]);\n        }\n        return\
    \ ret;\n    }\n\n    T operator[](int i) { return tree[i += n]; }\n\n    void\
    \ update(int i, T v) {\n        for (apply(tree[i += n], v); i > 1; i >>= 1)\n\
    \            tree[i >> 1] = merge(tree[i], tree[i ^ 1]);\n    }\n};\n"
  code: "template<typename T>\nstruct SegmentTree {\n    int n;\n    vector<T> tree;\n\
    \nprotected:\n    T dval = T();\n\n    T merge(const T &a, const T &b) { return\
    \ a + b; }\n\n    void apply(T &a, const T &b) { a = b; }\n\npublic:\n    SegmentTree()\
    \ = default;\n\n    SegmentTree(int _n, T _v = T()) : n(_n), dval(_v) {\n    \
    \    tree.assign(2 * n, dval);\n    }\n\n    template<typename Iterator>\n   \
    \ SegmentTree(Iterator begin, Iterator end, T _v = T()) : n(distance(begin, end)),\
    \ dval(_v) {\n\t\ttree.resize(2 * n);\n        for (int i = n; i < 2 * n; i++,\
    \ begin++)\n            tree[i] = *begin;\n        for (int i = n - 1; i > 0;\
    \ i--)\n            tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);\n    }\n\n\
    \    T query(int l, int r) {\n        T ret = dval;\n        for (l += n, r +=\
    \ n + 1; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) ret = merge(ret, tree[l++]);\n\
    \            if (r & 1) ret = merge(ret, tree[--r]);\n        }\n        return\
    \ ret;\n    }\n\n    T operator[](int i) { return tree[i += n]; }\n\n    void\
    \ update(int i, T v) {\n        for (apply(tree[i += n], v); i > 1; i >>= 1)\n\
    \            tree[i >> 1] = merge(tree[i], tree[i ^ 1]);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segment-tree.hpp
  requiredBy: []
  timestamp: '2021-12-30 09:21:24-08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data-structure/segment-tree/yosupo-point-add-range-sum.test.cpp
documentation_of: data-structure/segment-tree.hpp
layout: document
redirect_from:
- /library/data-structure/segment-tree.hpp
- /library/data-structure/segment-tree.hpp.html
title: data-structure/segment-tree.hpp
---
