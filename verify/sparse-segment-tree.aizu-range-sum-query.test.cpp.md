---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/sparse-segment-tree.hpp
    title: Sparse Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "#line 1 \"verify/sparse-segment-tree.aizu-range-sum-query.test.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/sparse-segment-tree.hpp\"\
    \ntemplate<class Base>\nclass Segtree : public Base {\n\tusing T = typename Base::T;\n\
    \tusing Base::dval;\n\tusing Base::merge;\n\tusing Base::apply;\n\nprotected:\n\
    \tsize_t n;\n\n\tstruct node {\n\t\tT v;\n\t\tint l, r;\n\t\tnode() = default;\n\
    \t\tnode(T _v, int _l, int _r) : v(_v), l(_l), r(_r) {}\n\t};\n\n\tint root;\n\
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
    \ l, int r) { return query(l, r, root, 0, n - 1); }\n};\n#line 7 \"verify/sparse-segment-tree.aizu-range-sum-query.test.cpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\n\tstruct stinfo {\n\t\tusing\
    \ T = long long;\n\t\tconst T dval = 0;\n\t\tvoid apply(T &a, T b) { a += b; }\n\
    \t\tT merge(T a, T b) { return a + b; }\n\t};\n\n\tSegtree<stinfo> sgt(N + 1);\n\
    \tsgt.reserve((N + 1) * 4);\n\twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t\
    \ == 0) {\n\t\t\tint i; long long v;\n\t\t\tcin >> i >> v;\n\t\t\tsgt.update(i,\
    \ v);\n\t\t} else if (t == 1) {\n\t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\t\t\t\
    cout << sgt.query(l, r) << '\\n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/sparse-segment-tree.hpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\n\tstruct stinfo {\n\t\tusing\
    \ T = long long;\n\t\tconst T dval = 0;\n\t\tvoid apply(T &a, T b) { a += b; }\n\
    \t\tT merge(T a, T b) { return a + b; }\n\t};\n\n\tSegtree<stinfo> sgt(N + 1);\n\
    \tsgt.reserve((N + 1) * 4);\n\twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t\
    \ == 0) {\n\t\t\tint i; long long v;\n\t\t\tcin >> i >> v;\n\t\t\tsgt.update(i,\
    \ v);\n\t\t} else if (t == 1) {\n\t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\t\t\t\
    cout << sgt.query(l, r) << '\\n';\n\t\t}\n\t}\n}"
  dependsOn:
  - data-structure/sparse-segment-tree.hpp
  isVerificationFile: true
  path: verify/sparse-segment-tree.aizu-range-sum-query.test.cpp
  requiredBy: []
  timestamp: '2022-02-04 21:19:28-08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/sparse-segment-tree.aizu-range-sum-query.test.cpp
layout: document
redirect_from:
- /verify/verify/sparse-segment-tree.aizu-range-sum-query.test.cpp
- /verify/verify/sparse-segment-tree.aizu-range-sum-query.test.cpp.html
title: verify/sparse-segment-tree.aizu-range-sum-query.test.cpp
---
