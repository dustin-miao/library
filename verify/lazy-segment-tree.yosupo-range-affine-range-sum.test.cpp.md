---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/lazy-segment-tree.hpp
    title: Lazy Segment Tree
  - icon: ':heavy_check_mark:'
    path: utility/addmod.hpp
    title: Addmod
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"verify/lazy-segment-tree.yosupo-range-affine-range-sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"utility/addmod.hpp\"\
    \ntemplate<typename T>\nT addmod(T a, T b, long long MOD) {\n\tT t = a + b;\n\t\
    return t >= MOD ? t - MOD : t;\n}\n#line 1 \"data-structure/lazy-segment-tree.hpp\"\
    \ntemplate<class Base>\nclass Segtree : public Base {\n\tusing T = typename Base::T;\n\
    \tusing L = typename Base::L;\n\tusing Base::Tdval;\n\tusing Base::Ldval;\n\t\
    using Base::merge;\n\tusing Base::apply;\n\nprotected:\n\tsize_t n;\n\tvector<T>\
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
    \ l, int r) { return query(l, r, 1, 0, n - 1); }\n};\n#line 8 \"verify/lazy-segment-tree.yosupo-range-affine-range-sum.test.cpp\"\
    \n\nconst int MAX = 5e5 + 5;\nconst long long MOD = 998244353;\n\nint main() {\n\
    \tint N, Q; \n\tcin >> N >> Q;\n\t\n\tstruct stinfo {\n\t\tusing T = long long;\n\
    \t\tusing L = pair<long long, long long>;\n\n\t\tconst T Tdval = 0;\n\t\tconst\
    \ L Ldval = {1, 0};\n\n\t\tvoid apply(T &a, L &b, L c, int l, int r) {\n\t\t\t\
    a = addmod(c.first * a % MOD, c.second * (r - l + 1) % MOD, MOD);\n\t\t\tb = {c.first\
    \ * b.first % MOD, addmod(c.first * b.second % MOD, c.second, MOD)};\n\t\t}\t\n\
    \n\t\tT merge(T a, T b) { return addmod(a, b, MOD); }\n\t};\n\t\n\tSegtree<stinfo>\
    \ sgt(N);\n\tfor (int i = 0; i < N; i++) {\n\t\tlong long a; cin >> a;\n\t\tsgt.update(i,\
    \ i, {1, a});\n\t}\n\twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\
    \t\t\tint l, r; long long b, c;\n\t\t\tcin >> l >> r >> b >> c;\n\t\t\tsgt.update(l,\
    \ r - 1, {b, c});\n\t\t} else {\n\t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\t\t\t\
    cout << sgt.query(l, r - 1) << '\\n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"utility/addmod.hpp\"\
    \n#include \"data-structure/lazy-segment-tree.hpp\"\n\nconst int MAX = 5e5 + 5;\n\
    const long long MOD = 998244353;\n\nint main() {\n\tint N, Q; \n\tcin >> N >>\
    \ Q;\n\t\n\tstruct stinfo {\n\t\tusing T = long long;\n\t\tusing L = pair<long\
    \ long, long long>;\n\n\t\tconst T Tdval = 0;\n\t\tconst L Ldval = {1, 0};\n\n\
    \t\tvoid apply(T &a, L &b, L c, int l, int r) {\n\t\t\ta = addmod(c.first * a\
    \ % MOD, c.second * (r - l + 1) % MOD, MOD);\n\t\t\tb = {c.first * b.first % MOD,\
    \ addmod(c.first * b.second % MOD, c.second, MOD)};\n\t\t}\t\n\n\t\tT merge(T\
    \ a, T b) { return addmod(a, b, MOD); }\n\t};\n\t\n\tSegtree<stinfo> sgt(N);\n\
    \tfor (int i = 0; i < N; i++) {\n\t\tlong long a; cin >> a;\n\t\tsgt.update(i,\
    \ i, {1, a});\n\t}\n\twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\
    \t\t\tint l, r; long long b, c;\n\t\t\tcin >> l >> r >> b >> c;\n\t\t\tsgt.update(l,\
    \ r - 1, {b, c});\n\t\t} else {\n\t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\t\t\t\
    cout << sgt.query(l, r - 1) << '\\n';\n\t\t}\n\t}\n}"
  dependsOn:
  - utility/addmod.hpp
  - data-structure/lazy-segment-tree.hpp
  isVerificationFile: true
  path: verify/lazy-segment-tree.yosupo-range-affine-range-sum.test.cpp
  requiredBy: []
  timestamp: '2022-02-02 15:19:45-08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/lazy-segment-tree.yosupo-range-affine-range-sum.test.cpp
layout: document
redirect_from:
- /verify/verify/lazy-segment-tree.yosupo-range-affine-range-sum.test.cpp
- /verify/verify/lazy-segment-tree.yosupo-range-affine-range-sum.test.cpp.html
title: verify/lazy-segment-tree.yosupo-range-affine-range-sum.test.cpp
---
