---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/sparse-segment-tree.yosupo-point-add-range-sum.test.cpp
    title: verify/sparse-segment-tree.yosupo-point-add-range-sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/sparse-segent-tree.hpp\"\ntemplate<class\
    \ Base>\nclass Segtree : public Base {\n\tusing T = Base::T;\n\tusing Base::dval;\n\
    \tusing Base::merge;\n\tusing Base::apply;\n\nprotected:\n\tsize_t n;\n\n\tstruct\
    \ node {\n\t\tT v;\n\t\tint l, r;\n\t};\n\n\tint root;\n\tvector<node> tree;\n\
    \n\tsize_t new_node() {\n\t\ttree.emplace_back(dval, -1, -1);\n\t\treturn tree.size()\
    \ - 1;\n\t}\n\nprivate:\n\tvoid update(int i, T v, int t, int tl, int tr) {\n\t\
    \tif (tl == tr) {\n\t\t\tapply(tree[t].v, v);\n\t\t\treturn;\n\t\t}\n\t\tint tm\
    \ = (tl + tr) / 2;\n\t\tif (i <= tm) {\n\t\t\tif (tree[t].l == -1)\n\t\t\t\ttree[t].l\
    \ = new_node();\n\t\t\tupdate(i, v, tree[t].l, tl, tm);\n\t\t} else {\n\t\t\t\
    if (tree[t].r == -1)\n\t\t\t\ttree[t].r = new_node();\n\t\t\tupdate(i, v, tree[t].r,\
    \ tm + 1, tr);\n\t\t}\n\t\ttree[t].v = merge(tree[t].l == -1 ? dval : tree[tree[t].l].v,\
    \ tree[t].r == -1 ? dval : tree[tree[t].r].v);\n\t}\n\n\tT query(int l, int r,\
    \ int t, int tl, int tr) {\n\t\tif (r < tl || tr < l)\n\t\t\treturn dval;\n\t\t\
    if (l <= tl && tr <= r)\n\t\t\treturn tree[t].v;\n\t\tint tm = (tl + tr) / 2;\n\
    \t\treturn merge(tree[t].l == -1 ? dval : query(l, r, tree[t].l, tl, tm), tree[t].r\
    \ == -1 ? dval : query(l, r, tree[t].r, tm + 1, tr));\n\t}\n\npublic:\n\tSegtree()\
    \ = default;\n\n\tSegtree(size_t _n) { init(_n); }\n\n\tvoid init(size_t _n) {\n\
    \t\tn = _n;\n\t\troot = new_node();\n\t}\n\n\tvoid reserve(size_t _n) { tree.reserve(_n);\
    \ }\n\n\tvoid clear() { tree.clear(); }\n\n\tvoid update(int i, T v) { update(i,\
    \ v, root, 0, n - 1); }\n\n\tT query(int l, int r) { return query(l, r, root,\
    \ 0, n - 1); }\n};\n"
  code: "template<class Base>\nclass Segtree : public Base {\n\tusing T = Base::T;\n\
    \tusing Base::dval;\n\tusing Base::merge;\n\tusing Base::apply;\n\nprotected:\n\
    \tsize_t n;\n\n\tstruct node {\n\t\tT v;\n\t\tint l, r;\n\t};\n\n\tint root;\n\
    \tvector<node> tree;\n\n\tsize_t new_node() {\n\t\ttree.emplace_back(dval, -1,\
    \ -1);\n\t\treturn tree.size() - 1;\n\t}\n\nprivate:\n\tvoid update(int i, T v,\
    \ int t, int tl, int tr) {\n\t\tif (tl == tr) {\n\t\t\tapply(tree[t].v, v);\n\t\
    \t\treturn;\n\t\t}\n\t\tint tm = (tl + tr) / 2;\n\t\tif (i <= tm) {\n\t\t\tif\
    \ (tree[t].l == -1)\n\t\t\t\ttree[t].l = new_node();\n\t\t\tupdate(i, v, tree[t].l,\
    \ tl, tm);\n\t\t} else {\n\t\t\tif (tree[t].r == -1)\n\t\t\t\ttree[t].r = new_node();\n\
    \t\t\tupdate(i, v, tree[t].r, tm + 1, tr);\n\t\t}\n\t\ttree[t].v = merge(tree[t].l\
    \ == -1 ? dval : tree[tree[t].l].v, tree[t].r == -1 ? dval : tree[tree[t].r].v);\n\
    \t}\n\n\tT query(int l, int r, int t, int tl, int tr) {\n\t\tif (r < tl || tr\
    \ < l)\n\t\t\treturn dval;\n\t\tif (l <= tl && tr <= r)\n\t\t\treturn tree[t].v;\n\
    \t\tint tm = (tl + tr) / 2;\n\t\treturn merge(tree[t].l == -1 ? dval : query(l,\
    \ r, tree[t].l, tl, tm), tree[t].r == -1 ? dval : query(l, r, tree[t].r, tm +\
    \ 1, tr));\n\t}\n\npublic:\n\tSegtree() = default;\n\n\tSegtree(size_t _n) { init(_n);\
    \ }\n\n\tvoid init(size_t _n) {\n\t\tn = _n;\n\t\troot = new_node();\n\t}\n\n\t\
    void reserve(size_t _n) { tree.reserve(_n); }\n\n\tvoid clear() { tree.clear();\
    \ }\n\n\tvoid update(int i, T v) { update(i, v, root, 0, n - 1); }\n\n\tT query(int\
    \ l, int r) { return query(l, r, root, 0, n - 1); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/sparse-segent-tree.hpp
  requiredBy: []
  timestamp: '2022-02-03 12:35:34-08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/sparse-segment-tree.yosupo-point-add-range-sum.test.cpp
documentation_of: data-structure/sparse-segent-tree.hpp
layout: document
redirect_from:
- /library/data-structure/sparse-segent-tree.hpp
- /library/data-structure/sparse-segent-tree.hpp.html
title: data-structure/sparse-segent-tree.hpp
---
