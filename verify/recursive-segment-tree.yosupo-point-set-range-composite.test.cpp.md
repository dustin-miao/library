---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/recursive-segment-tree.hpp
    title: Recursive Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"verify/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/recursive-segment-tree.hpp\"\
    \ntemplate<class Base>\nclass Segtree : public Base {\n\tusing node = typename\
    \ Base::T;\n\n\tsize_t n;\n\tvector<node> tree;\n\n\tvoid update(int i, node v,\
    \ int t, int tl, int tr) {\n\t\tif (tl == tr) {\n\t\t\tBase::apply(tree[t], v);\n\
    \t\t\treturn;\n\t\t}\n\t\tint tm = (tl + tr) / 2;\n\t\tif (i <= tm)\n\t\t\tupdate(i,\
    \ v, t * 2, tl, tm);\n\t\telse \n\t\t\tupdate(i, v, t * 2 + 1, tm + 1, tr);\n\t\
    \ttree[t] = Base::merge(tree[t * 2], tree[t * 2 + 1]);\n\t}\n\n\tnode query(int\
    \ l, int r, int t, int tl, int tr) {\n\t\tif (r < tl || tr < l)\n\t\t\treturn\
    \ Base::dval;\n\t\tif (l <= tl && tr <= r)\n\t\t\treturn tree[t];\n\t\tint tm\
    \ = (tl + tr) / 2;\n\t\treturn Base::merge(query(l, r, t * 2, tl, tm), query(l,\
    \ r, t * 2 + 1, tm + 1, tr));\n\t}\n\npublic:\n\tSegtree() = default;\n\n\tSegtree(size_t\
    \ _n) { init(_n); }\n\n\tvoid init(size_t _n) {\n\t\tn = _n;\n\t\ttree.assign(n\
    \ * 4, Base::dval);\n\t}\n\n\tvoid update(int i, node v) { update(i, v, 1, 0,\
    \ n - 1); }\n\n\tnode query(int l, int r) { return query(l, r, 1, 0, n - 1); }\n\
    };\n#line 7 \"verify/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp\"\
    \n\nconst int MAX = 5e5 + 5;\nconst long long MOD = 998244353;\n\nint N, Q;\n\n\
    struct stinfo {\n\tstruct node { long long a, b; };\n\n\tusing T = node;\n\n\t\
    const T dval = {1, 0};\n\n\tvoid apply(T &a, T b) { a = b; }\n\n\tT merge(T a,\
    \ T b) { return {a.a * b.a % MOD, (b.a * a.b + b.b) % MOD}; }\n};\n\nSegtree<stinfo>\
    \ sgt;\n\nint main() {\n\tcin >> N >> Q;\n\tsgt.init(N);\n\tfor (int i = 0; i\
    \ < N; i++) {\n\t\tlong long a, b; \n\t\tcin >> a >> b;\n\t\tsgt.update(i, {a,\
    \ b});\n\t}\n\twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\t\
    int p; long long c, d;\n\t\t\tcin >> p >> c >> d;\n\t\t\tsgt.update(p, {c, d});\n\
    \t\t} else {\n\t\t\tint l, r; long long x;\n\t\t\tcin >> l >> r >> x;\n\t\t\t\
    auto [a, b] = sgt.query(l, r - 1);\n\t\t\tcout << (a * x + b) % MOD << '\\n';\n\
    \t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/recursive-segment-tree.hpp\"\
    \n\nconst int MAX = 5e5 + 5;\nconst long long MOD = 998244353;\n\nint N, Q;\n\n\
    struct stinfo {\n\tstruct node { long long a, b; };\n\n\tusing T = node;\n\n\t\
    const T dval = {1, 0};\n\n\tvoid apply(T &a, T b) { a = b; }\n\n\tT merge(T a,\
    \ T b) { return {a.a * b.a % MOD, (b.a * a.b + b.b) % MOD}; }\n};\n\nSegtree<stinfo>\
    \ sgt;\n\nint main() {\n\tcin >> N >> Q;\n\tsgt.init(N);\n\tfor (int i = 0; i\
    \ < N; i++) {\n\t\tlong long a, b; \n\t\tcin >> a >> b;\n\t\tsgt.update(i, {a,\
    \ b});\n\t}\n\twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\t\
    int p; long long c, d;\n\t\t\tcin >> p >> c >> d;\n\t\t\tsgt.update(p, {c, d});\n\
    \t\t} else {\n\t\t\tint l, r; long long x;\n\t\t\tcin >> l >> r >> x;\n\t\t\t\
    auto [a, b] = sgt.query(l, r - 1);\n\t\t\tcout << (a * x + b) % MOD << '\\n';\n\
    \t\t}\n\t}\n}\n"
  dependsOn:
  - data-structure/recursive-segment-tree.hpp
  isVerificationFile: true
  path: verify/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp
  requiredBy: []
  timestamp: '2022-01-22 23:50:20-08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp
layout: document
redirect_from:
- /verify/verify/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp
- /verify/verify/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp.html
title: verify/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp
---
