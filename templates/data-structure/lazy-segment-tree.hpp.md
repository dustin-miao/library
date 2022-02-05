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
  bundledCode: "#line 1 \"templates/data-structure/lazy-segment-tree.hpp\"\ntemplate<class\
    \ Base>\nclass Segtree : public Base {\n\tusing T = typename Base::T;\n\tusing\
    \ L = typename Base::L;\n\tusing Base::Tdval;\n\tusing Base::Ldval;\n\tusing Base::merge;\n\
    \tusing Base::apply;\n\nprotected:\n\tsize_t n;\n\tvector<T> tree;\n\tvector<L>\
    \ lazy;\n\nprivate:\n\tvoid pushdown(int t, int tl, int tr) {\n\t\tif (lazy[t]\
    \ == Ldval)\n\t\t\treturn;\n\t\tint tm = (tl + tr) / 2;\n\t\tapply(tree[t * 2],\
    \ lazy[t * 2], lazy[t], tl, tm);\n\t\tapply(tree[t * 2 + 1], lazy[t * 2 + 1],\
    \ lazy[t], tm + 1, tr);\n\t\tlazy[t] = Ldval;\n\t}\n\n\tvoid update(int l, int\
    \ r, L v, int t, int tl, int tr) {\n\t\tif (r < tl || tr < l)\n\t\t\treturn;\n\
    \t\tif (l <= tl && tr <= r) {\n\t\t\tapply(tree[t], lazy[t], v, tl, tr);\n\t\t\
    \treturn;\n\t\t}\n\t\tpushdown(t, tl, tr);\n\t\tint tm = (tl + tr) / 2;\n\t\t\
    update(l, r, v, t * 2, tl, tm);\n\t\tupdate(l, r, v, t * 2 + 1, tm + 1, tr);\n\
    \t\ttree[t] = merge(tree[t * 2], tree[t * 2 + 1]);\n\t}\n\n\tT query(int l, int\
    \ r, int t, int tl, int tr) {\n\t\tif (r < tl || tr < l)\n\t\t\treturn Tdval;\n\
    \t\tif (l <= tl && tr <= r)\n\t\t\treturn tree[t];\n\t\tpushdown(t, tl, tr);\n\
    \t\tint tm = (tl + tr) / 2;\n\t\treturn merge(query(l, r, t * 2, tl, tm), query(l,\
    \ r, t * 2 + 1, tm + 1, tr));\n\t}\n\npublic:\n\tSegtree() = default;\n\n\tSegtree(size_t\
    \ _n) { init(_n); }\n\n\tvoid init(size_t _n) {\n\t\tn = _n;\n\t\ttree.assign(4\
    \ * n, Tdval);\n\t\tlazy.assign(4 * n, Ldval);\n\t}\n\n\tvoid update(int l, int\
    \ r, L v) { update(l, r, v, 1, 0, n - 1); }\n\n\tT query(int l, int r) { return\
    \ query(l, r, 1, 0, n - 1); }\n};\n"
  code: "template<class Base>\nclass Segtree : public Base {\n\tusing T = typename\
    \ Base::T;\n\tusing L = typename Base::L;\n\tusing Base::Tdval;\n\tusing Base::Ldval;\n\
    \tusing Base::merge;\n\tusing Base::apply;\n\nprotected:\n\tsize_t n;\n\tvector<T>\
    \ tree;\n\tvector<L> lazy;\n\nprivate:\n\tvoid pushdown(int t, int tl, int tr)\
    \ {\n\t\tif (lazy[t] == Ldval)\n\t\t\treturn;\n\t\tint tm = (tl + tr) / 2;\n\t\
    \tapply(tree[t * 2], lazy[t * 2], lazy[t], tl, tm);\n\t\tapply(tree[t * 2 + 1],\
    \ lazy[t * 2 + 1], lazy[t], tm + 1, tr);\n\t\tlazy[t] = Ldval;\n\t}\n\n\tvoid\
    \ update(int l, int r, L v, int t, int tl, int tr) {\n\t\tif (r < tl || tr < l)\n\
    \t\t\treturn;\n\t\tif (l <= tl && tr <= r) {\n\t\t\tapply(tree[t], lazy[t], v,\
    \ tl, tr);\n\t\t\treturn;\n\t\t}\n\t\tpushdown(t, tl, tr);\n\t\tint tm = (tl +\
    \ tr) / 2;\n\t\tupdate(l, r, v, t * 2, tl, tm);\n\t\tupdate(l, r, v, t * 2 + 1,\
    \ tm + 1, tr);\n\t\ttree[t] = merge(tree[t * 2], tree[t * 2 + 1]);\n\t}\n\n\t\
    T query(int l, int r, int t, int tl, int tr) {\n\t\tif (r < tl || tr < l)\n\t\t\
    \treturn Tdval;\n\t\tif (l <= tl && tr <= r)\n\t\t\treturn tree[t];\n\t\tpushdown(t,\
    \ tl, tr);\n\t\tint tm = (tl + tr) / 2;\n\t\treturn merge(query(l, r, t * 2, tl,\
    \ tm), query(l, r, t * 2 + 1, tm + 1, tr));\n\t}\n\npublic:\n\tSegtree() = default;\n\
    \n\tSegtree(size_t _n) { init(_n); }\n\n\tvoid init(size_t _n) {\n\t\tn = _n;\n\
    \t\ttree.assign(4 * n, Tdval);\n\t\tlazy.assign(4 * n, Ldval);\n\t}\n\n\tvoid\
    \ update(int l, int r, L v) { update(l, r, v, 1, 0, n - 1); }\n\n\tT query(int\
    \ l, int r) { return query(l, r, 1, 0, n - 1); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: templates/data-structure/lazy-segment-tree.hpp
  requiredBy: []
  timestamp: '2022-02-04 20:52:31-08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: templates/data-structure/lazy-segment-tree.hpp
layout: document
redirect_from:
- /library/templates/data-structure/lazy-segment-tree.hpp
- /library/templates/data-structure/lazy-segment-tree.hpp.html
title: templates/data-structure/lazy-segment-tree.hpp
---
