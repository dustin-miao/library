---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/recursive-segment-tree.hpp
    title: Recursive Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"verify/recursive-segment-tree.yosupo-point-add-range-sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/recursive-segment-tree.hpp\"\
    \ntemplate<class Base>\nclass Segtree : public Base {\n\tusing T = typename Base::T;\n\
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
    \ r) { return query(l, r, 1, 0, n - 1); }\n};\n#line 7 \"verify/recursive-segment-tree.yosupo-point-add-range-sum.test.cpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\n\tstruct stinfo {\n\t\tusing\
    \ T = long long;\n\n\t\tconst T dval = 0;\n\n\t\tvoid apply(T &a, T b) { a +=\
    \ b; }\n\n\t\tT merge(T a, T b) { return a + b; }\n\t};\n\n\tSegtree<stinfo> sgt(N);\n\
    \tfor (int i = 0; i < N; i++) {\n\t\tlong long a; cin >> a;\n\t\tsgt.update(i,\
    \ a);\n\t}\n\twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\tint\
    \ p; long long x;\n\t\t\tcin >> p >> x;\n\t\t\tsgt.update(p, x);\n\t\t} else {\n\
    \t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\t\t\tcout << sgt.query(l, r - 1) << '\\\
    n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/recursive-segment-tree.hpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\n\tstruct stinfo {\n\t\tusing\
    \ T = long long;\n\n\t\tconst T dval = 0;\n\n\t\tvoid apply(T &a, T b) { a +=\
    \ b; }\n\n\t\tT merge(T a, T b) { return a + b; }\n\t};\n\n\tSegtree<stinfo> sgt(N);\n\
    \tfor (int i = 0; i < N; i++) {\n\t\tlong long a; cin >> a;\n\t\tsgt.update(i,\
    \ a);\n\t}\n\twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\tint\
    \ p; long long x;\n\t\t\tcin >> p >> x;\n\t\t\tsgt.update(p, x);\n\t\t} else {\n\
    \t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\t\t\tcout << sgt.query(l, r - 1) << '\\\
    n';\n\t\t}\n\t}\n}\n"
  dependsOn:
  - data-structure/recursive-segment-tree.hpp
  isVerificationFile: true
  path: verify/recursive-segment-tree.yosupo-point-add-range-sum.test.cpp
  requiredBy: []
  timestamp: '2022-04-02 12:35:37-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/recursive-segment-tree.yosupo-point-add-range-sum.test.cpp
layout: document
redirect_from:
- /verify/verify/recursive-segment-tree.yosupo-point-add-range-sum.test.cpp
- /verify/verify/recursive-segment-tree.yosupo-point-add-range-sum.test.cpp.html
title: verify/recursive-segment-tree.yosupo-point-add-range-sum.test.cpp
---
