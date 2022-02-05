---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"templates/data-structure/general-segment-tree.hpp\"\ntemplate<class\
    \ Base>\nclass Segtree : public Base {\n\tusing T = typename Base::T;\n\tusing\
    \ Base::dval;\n\tusing Base::merge;\n\tusing Base::apply;\n\nprotected:\n\tsize_t\
    \ n;\n\tvector<T> tree;\n\npublic:\n\tSegtree() = default;\n\n\tSegtree(size_t\
    \ _n) { init(_n); }\n\n\tvoid init(size_t _n) {\n\t\tfor (n = 1; n < _n; n *=\
    \ 2);\n\t\ttree.assign(n * 2, dval);\n\t}\n\n\tvoid update(int i, T v) {\n\t\t\
    for (apply(tree[i += n], v); i >>= 1;)\n\t\t\ttree[i] = merge(tree[i << 1], tree[i\
    \ << 1 | 1]);\n\t}\n\n\tT query(int l, int r) {\n\t\tT lret = dval, rret = dval;\n\
    \t\tfor (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {\n\t\t\tif (l & 1) lret\
    \ = merge(lret, tree[l++]);\n\t\t\tif (r & 1) rret = merge(tree[--r], rret);\n\
    \t\t}\n\t\treturn merge(lret, rret);\n\t}\n\n\tT operator[](int i) { return tree[i\
    \ += n]; }\n};\n"
  code: "template<class Base>\nclass Segtree : public Base {\n\tusing T = typename\
    \ Base::T;\n\tusing Base::dval;\n\tusing Base::merge;\n\tusing Base::apply;\n\n\
    protected:\n\tsize_t n;\n\tvector<T> tree;\n\npublic:\n\tSegtree() = default;\n\
    \n\tSegtree(size_t _n) { init(_n); }\n\n\tvoid init(size_t _n) {\n\t\tfor (n =\
    \ 1; n < _n; n *= 2);\n\t\ttree.assign(n * 2, dval);\n\t}\n\n\tvoid update(int\
    \ i, T v) {\n\t\tfor (apply(tree[i += n], v); i >>= 1;)\n\t\t\ttree[i] = merge(tree[i\
    \ << 1], tree[i << 1 | 1]);\n\t}\n\n\tT query(int l, int r) {\n\t\tT lret = dval,\
    \ rret = dval;\n\t\tfor (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {\n\t\t\t\
    if (l & 1) lret = merge(lret, tree[l++]);\n\t\t\tif (r & 1) rret = merge(tree[--r],\
    \ rret);\n\t\t}\n\t\treturn merge(lret, rret);\n\t}\n\n\tT operator[](int i) {\
    \ return tree[i += n]; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: templates/data-structure/general-segment-tree.hpp
  requiredBy: []
  timestamp: '2022-02-04 20:52:31-08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: templates/data-structure/general-segment-tree.hpp
layout: document
redirect_from:
- /library/templates/data-structure/general-segment-tree.hpp
- /library/templates/data-structure/general-segment-tree.hpp.html
title: templates/data-structure/general-segment-tree.hpp
---
