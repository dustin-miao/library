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
  bundledCode: "#line 1 \"templates/data-structure/recursive-segment-tree.hpp\"\n\
    template<class Base>\nclass Segtree : public Base {\n\tusing T = typename Base::T;\n\
    \tusing Base::dval;\n\tusing Base::merge;\n\tusing Base::apply;\n\nprotected:\n\
    \tsize_t n;\n\tvector<T> tree;\n\nprivate:\n\tvoid update(int i, T v, int t, int\
    \ tl, int tr) {\n\t\tif (tl == tr) {\n\t\t\tapply(tree[t], v);\n\t\t\treturn;\n\
    \t\t}\n\t\tint tm = (tl + tr) / 2;\n\t\tif (i <= tm)\n\t\t\tupdate(i, v, t * 2,\
    \ tl, tm);\n\t\telse \n\t\t\tupdate(i, v, t * 2 + 1, tm + 1, tr);\n\t\ttree[t]\
    \ = merge(tree[t * 2], tree[t * 2 + 1]);\n\t}\n\n\tT query(int l, int r, int t,\
    \ int tl, int tr) {\n\t\tif (r < tl || tr < l)\n\t\t\treturn dval;\n\t\tif (l\
    \ <= tl && tr <= r)\n\t\t\treturn tree[t];\n\t\tint tm = (tl + tr) / 2;\n\t\t\
    return merge(query(l, r, t * 2, tl, tm), query(l, r, t * 2 + 1, tm + 1, tr));\n\
    \t}\n\npublic:\n\tSegtree() = default;\n\n\tSegtree(size_t _n) { init(_n); }\n\
    \n\tvoid init(size_t _n) {\n\t\tn = _n;\n\t\ttree.assign(n * 4, dval);\n\t}\n\n\
    \tvoid update(int i, T v) { update(i, v, 1, 0, n - 1); }\n\n\tT query(int l, int\
    \ r) { return query(l, r, 1, 0, n - 1); }\n};\n"
  code: "template<class Base>\nclass Segtree : public Base {\n\tusing T = typename\
    \ Base::T;\n\tusing Base::dval;\n\tusing Base::merge;\n\tusing Base::apply;\n\n\
    protected:\n\tsize_t n;\n\tvector<T> tree;\n\nprivate:\n\tvoid update(int i, T\
    \ v, int t, int tl, int tr) {\n\t\tif (tl == tr) {\n\t\t\tapply(tree[t], v);\n\
    \t\t\treturn;\n\t\t}\n\t\tint tm = (tl + tr) / 2;\n\t\tif (i <= tm)\n\t\t\tupdate(i,\
    \ v, t * 2, tl, tm);\n\t\telse \n\t\t\tupdate(i, v, t * 2 + 1, tm + 1, tr);\n\t\
    \ttree[t] = merge(tree[t * 2], tree[t * 2 + 1]);\n\t}\n\n\tT query(int l, int\
    \ r, int t, int tl, int tr) {\n\t\tif (r < tl || tr < l)\n\t\t\treturn dval;\n\
    \t\tif (l <= tl && tr <= r)\n\t\t\treturn tree[t];\n\t\tint tm = (tl + tr) / 2;\n\
    \t\treturn merge(query(l, r, t * 2, tl, tm), query(l, r, t * 2 + 1, tm + 1, tr));\n\
    \t}\n\npublic:\n\tSegtree() = default;\n\n\tSegtree(size_t _n) { init(_n); }\n\
    \n\tvoid init(size_t _n) {\n\t\tn = _n;\n\t\ttree.assign(n * 4, dval);\n\t}\n\n\
    \tvoid update(int i, T v) { update(i, v, 1, 0, n - 1); }\n\n\tT query(int l, int\
    \ r) { return query(l, r, 1, 0, n - 1); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: templates/data-structure/recursive-segment-tree.hpp
  requiredBy: []
  timestamp: '2022-02-04 20:52:31-08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: templates/data-structure/recursive-segment-tree.hpp
layout: document
redirect_from:
- /library/templates/data-structure/recursive-segment-tree.hpp
- /library/templates/data-structure/recursive-segment-tree.hpp.html
title: templates/data-structure/recursive-segment-tree.hpp
---
