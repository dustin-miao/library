---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/sparse-segment-tree.hpp
    title: Sparse Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"verify/sparse-segment-tree.yosupo-point-add-range-sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/sparse-segment-tree.hpp\"\
    \ntemplate<class Base>\nclass Segtree : public Base {\n\tusing T = Base::T;\n\t\
    using Base::dval;\n\tusing Base::merge;\n\tusing Base::apply;\n\nprotected:\n\t\
    size_t n;\n\n\tstruct node {\n\t\tT v;\n\t\tint l, r;\n\t};\n\n\tint root;\n\t\
    vector<node> tree;\n\n\tsize_t new_node() {\n\t\ttree.emplace_back(dval, -1, -1);\n\
    \t\treturn tree.size() - 1;\n\t}\n\nprivate:\n\tvoid update(int i, T v, int t,\
    \ int tl, int tr) {\n\t\tif (tl == tr) {\n\t\t\tapply(tree[t].v, v);\n\t\t\treturn;\n\
    \t\t}\n\t\tint tm = (tl + tr) / 2;\n\t\tif (i <= tm) {\n\t\t\tif (tree[t].l ==\
    \ -1)\n\t\t\t\ttree[t].l = new_node();\n\t\t\tupdate(i, v, tree[t].l, tl, tm);\n\
    \t\t} else {\n\t\t\tif (tree[t].r == -1)\n\t\t\t\ttree[t].r = new_node();\n\t\t\
    \tupdate(i, v, tree[t].r, tm + 1, tr);\n\t\t}\n\t\ttree[t].v = merge(tree[t].l\
    \ == -1 ? dval : tree[tree[t].l].v, tree[t].r == -1 ? dval : tree[tree[t].r].v);\n\
    \t}\n\n\tT query(int l, int r, int t, int tl, int tr) {\n\t\tif (r < tl || tr\
    \ < l)\n\t\t\treturn dval;\n\t\tif (l <= tl && tr <= r)\n\t\t\treturn tree[t].v;\n\
    \t\tint tm = (tl + tr) / 2;\n\t\treturn merge(tree[t].l == -1 ? dval : query(l,\
    \ r, tree[t].l, tl, tm), tree[t].r == -1 ? dval : query(l, r, tree[t].r, tm +\
    \ 1, tr));\n\t}\n\npublic:\n\tSegtree() = default;\n\n\tSegtree(size_t _n) { init(_n);\
    \ }\n\n\tvoid init(size_t _n) {\n\t\tn = _n;\n\t\troot = new_node();\n\t}\n\n\t\
    void reserve(size_t _n) { tree.reserve(_n); }\n\n\tvoid clear() { tree.clear();\
    \ }\n\n\tvoid update(int i, T v) { update(i, v, root, 0, n - 1); }\n\n\tT query(int\
    \ l, int r) { return query(l, r, root, 0, n - 1); }\n};\n#line 7 \"verify/sparse-segment-tree.yosupo-point-add-range-sum.test.cpp\"\
    \n\nconst int MAX = 5e5 + 5;\n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\n\
    \tstruct stinfo {\n\t\tusing T = long long;\n\t\tconst T dval = 0;\n\t\tvoid apply(T\
    \ &a, T b) { a += b; }\n\t\tT merge(T a, T b) { return a + b; }\n\t};\n\n\tSegtree<stinfo>\
    \ sgt(N);\n\tsgt.reserve(N * 4);\n\tfor (int i = 0; i < N; i++) {\n\t\tlong long\
    \ a; cin >> a;\n\t\tsgt.update(i, a);\n\t}\n\twhile (Q--) {\n\t\tint t; cin >>\
    \ t;\n\t\tif (t == 0) {\n\t\t\tint p; long long x;\n\t\t\tcin >> p >> x;\n\t\t\
    \tsgt.update(p, x);\n\t\t} else {\n\t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\t\t\
    \tcout << sgt.query(l, r - 1) << '\\n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/sparse-segment-tree.hpp\"\
    \n\nconst int MAX = 5e5 + 5;\n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\n\
    \tstruct stinfo {\n\t\tusing T = long long;\n\t\tconst T dval = 0;\n\t\tvoid apply(T\
    \ &a, T b) { a += b; }\n\t\tT merge(T a, T b) { return a + b; }\n\t};\n\n\tSegtree<stinfo>\
    \ sgt(N);\n\tsgt.reserve(N * 4);\n\tfor (int i = 0; i < N; i++) {\n\t\tlong long\
    \ a; cin >> a;\n\t\tsgt.update(i, a);\n\t}\n\twhile (Q--) {\n\t\tint t; cin >>\
    \ t;\n\t\tif (t == 0) {\n\t\t\tint p; long long x;\n\t\t\tcin >> p >> x;\n\t\t\
    \tsgt.update(p, x);\n\t\t} else {\n\t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\t\t\
    \tcout << sgt.query(l, r - 1) << '\\n';\n\t\t}\n\t}\n}"
  dependsOn:
  - data-structure/sparse-segment-tree.hpp
  isVerificationFile: true
  path: verify/sparse-segment-tree.yosupo-point-add-range-sum.test.cpp
  requiredBy: []
  timestamp: '2022-02-03 12:42:26-08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/sparse-segment-tree.yosupo-point-add-range-sum.test.cpp
layout: document
redirect_from:
- /verify/verify/sparse-segment-tree.yosupo-point-add-range-sum.test.cpp
- /verify/verify/sparse-segment-tree.yosupo-point-add-range-sum.test.cpp.html
title: verify/sparse-segment-tree.yosupo-point-add-range-sum.test.cpp
---
