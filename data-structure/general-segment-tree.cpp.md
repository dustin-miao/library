---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/general-segment-tree.cpp\"\ntemplate<typename\
    \ T, typename merge_t, typename apply_t, T dval>\nstruct segtree {\n    int n;\n\
    \    vector<T> tree;\n\n    merge_t merge;\n    apply_t apply;\n\n    segtree()\
    \ = default;\n\n    segtree(int _n) : n(_n) {\n        tree.assign(2 * n, dval);\n\
    \        for (int i = n - 1; i > 0; i--)\n            tree[i] = merge(tree[i <<\
    \ 1], tree[i << 1 | 1]);\n    }\n\n    template<typename Iterator>\n    segtree(Iterator\
    \ begin, Iterator end) : n(distance(begin, end)) {\n\t\ttree.resize(2 * n);\n\
    \        for (int i = n; i < 2 * n; i++, begin++)\n            tree[i] = *begin;\n\
    \        for (int i = n - 1; i > 0; i--)\n            tree[i] = merge(tree[i <<\
    \ 1], tree[i << 1 | 1]);\n    }\n\n    T query(int l, int r) {\n        T ret\
    \ = dval;\n        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {\n     \
    \       if (l & 1) ret = merge(ret, tree[l++]);\n            if (r & 1) ret =\
    \ merge(ret, tree[--r]);\n        }\n        return ret;\n    }\n\n    T operator[](int\
    \ i) { return tree[i += n]; }\n\n    void update(int i, T v) {\n        for (apply(tree[i\
    \ += n], v); i > 1; i >>= 1)\n            tree[i >> 1] = merge(tree[i], tree[i\
    \ ^ 1]);\n    }\n};\n"
  code: "template<typename T, typename merge_t, typename apply_t, T dval>\nstruct\
    \ segtree {\n    int n;\n    vector<T> tree;\n\n    merge_t merge;\n    apply_t\
    \ apply;\n\n    segtree() = default;\n\n    segtree(int _n) : n(_n) {\n      \
    \  tree.assign(2 * n, dval);\n        for (int i = n - 1; i > 0; i--)\n      \
    \      tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);\n    }\n\n    template<typename\
    \ Iterator>\n    segtree(Iterator begin, Iterator end) : n(distance(begin, end))\
    \ {\n\t\ttree.resize(2 * n);\n        for (int i = n; i < 2 * n; i++, begin++)\n\
    \            tree[i] = *begin;\n        for (int i = n - 1; i > 0; i--)\n    \
    \        tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);\n    }\n\n    T query(int\
    \ l, int r) {\n        T ret = dval;\n        for (l += n, r += n + 1; l < r;\
    \ l >>= 1, r >>= 1) {\n            if (l & 1) ret = merge(ret, tree[l++]);\n \
    \           if (r & 1) ret = merge(ret, tree[--r]);\n        }\n        return\
    \ ret;\n    }\n\n    T operator[](int i) { return tree[i += n]; }\n\n    void\
    \ update(int i, T v) {\n        for (apply(tree[i += n], v); i > 1; i >>= 1)\n\
    \            tree[i >> 1] = merge(tree[i], tree[i ^ 1]);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/general-segment-tree.cpp
  requiredBy: []
  timestamp: '2022-01-05 08:38:10-08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/general-segment-tree.cpp
layout: document
redirect_from:
- /library/data-structure/general-segment-tree.cpp
- /library/data-structure/general-segment-tree.cpp.html
title: data-structure/general-segment-tree.cpp
---
