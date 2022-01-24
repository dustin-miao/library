---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/lazy-segment-tree.yosupo-range-affine-range-sum.test.cpp
    title: verify/lazy-segment-tree.yosupo-range-affine-range-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/lazy-segment-tree.hpp\"\ntemplate<class Base>\n\
    class Segtree : public Base {\n\tusing node = typename Base::T;\n\tusing upd =\
    \ typename Base::L;\n\nprotected:\n\tsize_t n;\n\tvector<node> tree;\n\tvector<upd>\
    \ lazy;\n\nprivate:\n\tvoid pushdown(int t, int tl, int tr) {\n\t\tif (lazy[t]\
    \ == Base::Ldval)\n\t\t\treturn;\n\t\tint tm = (tl + tr) / 2;\n\t\tBase::apply(tree[t\
    \ * 2], lazy[t * 2], lazy[t], tl, tm);\n\t\tBase::apply(tree[t * 2 + 1], lazy[t\
    \ * 2 + 1], lazy[t], tm + 1, tr);\n\t\tlazy[t] = Base::Ldval;\n\t}\n\n\tvoid update(int\
    \ l, int r, upd v, int t, int tl, int tr) {\n\t\tif (r < tl || tr < l)\n\t\t\t\
    return;\n\t\tif (l <= tl && tr <= r) {\n\t\t\tBase::apply(tree[t], lazy[t], v,\
    \ tl, tr);\n\t\t\treturn;\n\t\t}\n\t\tpushdown(t, tl, tr);\n\t\tint tm = (tl +\
    \ tr) / 2;\n\t\tupdate(l, r, v, t * 2, tl, tm);\n\t\tupdate(l, r, v, t * 2 + 1,\
    \ tm + 1, tr);\n\t\ttree[t] = Base::merge(tree[t * 2], tree[t * 2 + 1]);\n\t}\n\
    \n\tnode query(int l, int r, int t, int tl, int tr) {\n\t\tif (r < tl || tr <\
    \ l)\n\t\t\treturn Base::Tdval;\n\t\tif (l <= tl && tr <= r)\n\t\t\treturn tree[t];\n\
    \t\tpushdown(t, tl, tr);\n\t\tint tm = (tl + tr) / 2;\n\t\treturn Base::merge(query(l,\
    \ r, t * 2, tl, tm), query(l, r, t * 2 + 1, tm + 1, tr));\n\t}\n\npublic:\n\t\
    Segtree() = default;\n\n\tSegtree(size_t _n) { init(_n); }\n\n\tvoid init(size_t\
    \ _n) {\n\t\tn = _n;\n\t\ttree.assign(4 * n, Base::Tdval);\n\t\tlazy.assign(4\
    \ * n, Base::Ldval);\n\t}\n\n\tvoid update(int l, int r, upd v) { update(l, r,\
    \ v, 1, 0, n - 1); }\n\n\tnode query(int l, int r) { return query(l, r, 1, 0,\
    \ n - 1); }\n};\n"
  code: "template<class Base>\nclass Segtree : public Base {\n\tusing node = typename\
    \ Base::T;\n\tusing upd = typename Base::L;\n\nprotected:\n\tsize_t n;\n\tvector<node>\
    \ tree;\n\tvector<upd> lazy;\n\nprivate:\n\tvoid pushdown(int t, int tl, int tr)\
    \ {\n\t\tif (lazy[t] == Base::Ldval)\n\t\t\treturn;\n\t\tint tm = (tl + tr) /\
    \ 2;\n\t\tBase::apply(tree[t * 2], lazy[t * 2], lazy[t], tl, tm);\n\t\tBase::apply(tree[t\
    \ * 2 + 1], lazy[t * 2 + 1], lazy[t], tm + 1, tr);\n\t\tlazy[t] = Base::Ldval;\n\
    \t}\n\n\tvoid update(int l, int r, upd v, int t, int tl, int tr) {\n\t\tif (r\
    \ < tl || tr < l)\n\t\t\treturn;\n\t\tif (l <= tl && tr <= r) {\n\t\t\tBase::apply(tree[t],\
    \ lazy[t], v, tl, tr);\n\t\t\treturn;\n\t\t}\n\t\tpushdown(t, tl, tr);\n\t\tint\
    \ tm = (tl + tr) / 2;\n\t\tupdate(l, r, v, t * 2, tl, tm);\n\t\tupdate(l, r, v,\
    \ t * 2 + 1, tm + 1, tr);\n\t\ttree[t] = Base::merge(tree[t * 2], tree[t * 2 +\
    \ 1]);\n\t}\n\n\tnode query(int l, int r, int t, int tl, int tr) {\n\t\tif (r\
    \ < tl || tr < l)\n\t\t\treturn Base::Tdval;\n\t\tif (l <= tl && tr <= r)\n\t\t\
    \treturn tree[t];\n\t\tpushdown(t, tl, tr);\n\t\tint tm = (tl + tr) / 2;\n\t\t\
    return Base::merge(query(l, r, t * 2, tl, tm), query(l, r, t * 2 + 1, tm + 1,\
    \ tr));\n\t}\n\npublic:\n\tSegtree() = default;\n\n\tSegtree(size_t _n) { init(_n);\
    \ }\n\n\tvoid init(size_t _n) {\n\t\tn = _n;\n\t\ttree.assign(4 * n, Base::Tdval);\n\
    \t\tlazy.assign(4 * n, Base::Ldval);\n\t}\n\n\tvoid update(int l, int r, upd v)\
    \ { update(l, r, v, 1, 0, n - 1); }\n\n\tnode query(int l, int r) { return query(l,\
    \ r, 1, 0, n - 1); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/lazy-segment-tree.hpp
  requiredBy: []
  timestamp: '2022-01-23 17:49:10-08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lazy-segment-tree.yosupo-range-affine-range-sum.test.cpp
documentation_of: data-structure/lazy-segment-tree.hpp
layout: document
title: Lazy Segment Tree
---

## Lazy Segment Tree

[Placeholder]