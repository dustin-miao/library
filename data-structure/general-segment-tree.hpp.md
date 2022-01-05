---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/data-structure/general-segment-tree.yosupo-point-add-range-sum.test.cpp
    title: verify/data-structure/general-segment-tree.yosupo-point-add-range-sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/general-segment-tree.hpp\"\ntemplate<typename\
    \ T, typename merge_t, typename apply_t, T dval = T{}>\nclass segtree {\n\tint\
    \ n;\n\tvector<T> tree;\n\n\tmerge_t merge;\n\tapply_t apply;\n\npublic:\n\tsegtree(merge_t\
    \ _merge, apply_t _apply) : merge(_merge), apply(_apply) {}\n\n\tvoid init(int\
    \ _n) {\n\t\tn = _n;\n\t\ttree.assign(2 * n, dval);\n\t\tfor (int i = n - 1; i\
    \ > 0; i--)\n\t\t\ttree[i] = merge(tree[i << 1], tree[i << 1 | 1]);\n\t}\n\n\t\
    template<typename Iterator>\n\tvoid init(Iterator begin, Iterator end) {\n\t\t\
    n = distance(begin, end);\n\t\ttree.resize(2 * n);\n\t\tfor (int i = n; i < 2\
    \ * n; i++, begin++)\n\t\t\ttree[i] = *begin;\n\t\tfor (int i = n - 1; i > 0;\
    \ i--)\n\t\t\ttree[i] = merge(tree[i << 1], tree[i << 1 | 1]);\n\t}\n\n    void\
    \ update(int i, T v) {\n\t\tfor (apply(tree[i += n], v); i > 1; i >>= 1)\n\t\t\
    \ttree[i >> 1] = merge(tree[i], tree[i ^ 1]);\n\t}\n\n\tT query(int l, int r)\
    \ {\n\t\tT ret = dval;\n\t\tfor (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)\
    \ {\n\t\t\tif (l & 1) ret = merge(ret, tree[l++]);\n\t\t\tif (r & 1) ret = merge(ret,\
    \ tree[--r]);\n\t\t}\n\t\treturn ret;\n\t}\n\n\tT operator[](int i) { return tree[i\
    \ += n]; }\n};\n"
  code: "template<typename T, typename merge_t, typename apply_t, T dval = T{}>\n\
    class segtree {\n\tint n;\n\tvector<T> tree;\n\n\tmerge_t merge;\n\tapply_t apply;\n\
    \npublic:\n\tsegtree(merge_t _merge, apply_t _apply) : merge(_merge), apply(_apply)\
    \ {}\n\n\tvoid init(int _n) {\n\t\tn = _n;\n\t\ttree.assign(2 * n, dval);\n\t\t\
    for (int i = n - 1; i > 0; i--)\n\t\t\ttree[i] = merge(tree[i << 1], tree[i <<\
    \ 1 | 1]);\n\t}\n\n\ttemplate<typename Iterator>\n\tvoid init(Iterator begin,\
    \ Iterator end) {\n\t\tn = distance(begin, end);\n\t\ttree.resize(2 * n);\n\t\t\
    for (int i = n; i < 2 * n; i++, begin++)\n\t\t\ttree[i] = *begin;\n\t\tfor (int\
    \ i = n - 1; i > 0; i--)\n\t\t\ttree[i] = merge(tree[i << 1], tree[i << 1 | 1]);\n\
    \t}\n\n    void update(int i, T v) {\n\t\tfor (apply(tree[i += n], v); i > 1;\
    \ i >>= 1)\n\t\t\ttree[i >> 1] = merge(tree[i], tree[i ^ 1]);\n\t}\n\n\tT query(int\
    \ l, int r) {\n\t\tT ret = dval;\n\t\tfor (l += n, r += n + 1; l < r; l >>= 1,\
    \ r >>= 1) {\n\t\t\tif (l & 1) ret = merge(ret, tree[l++]);\n\t\t\tif (r & 1)\
    \ ret = merge(ret, tree[--r]);\n\t\t}\n\t\treturn ret;\n\t}\n\n\tT operator[](int\
    \ i) { return tree[i += n]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/general-segment-tree.hpp
  requiredBy: []
  timestamp: '2022-01-05 09:21:24-08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/data-structure/general-segment-tree.yosupo-point-add-range-sum.test.cpp
documentation_of: data-structure/general-segment-tree.hpp
layout: document
redirect_from:
- /library/data-structure/general-segment-tree.hpp
- /library/data-structure/general-segment-tree.hpp.html
title: data-structure/general-segment-tree.hpp
---
