---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/lazy-segment-tree.hpp
    title: Lazy Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
  bundledCode: "#line 1 \"verify/lazy-segment-tree.aizu-RSQ-and-RAQ.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/lazy-segment-tree.hpp\"\
    \ntemplate<class Base>\nclass Segtree : public Base {\n\tusing node = typename\
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
    \ r, 1, 0, n - 1); }\n};\n#line 7 \"verify/lazy-segment-tree.aizu-RSQ-and-RAQ.test.cpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\n\tstruct stinfo {\n\t\tusing\
    \ T = long long;\n\t\tusing L = long long;\n\n\t\tconst T Tdval = 0;\n\t\tconst\
    \ L Ldval = 0;\n\n\t\tvoid apply(T &a, L &b, L c, int l, int r) {\n\t\t\ta +=\
    \ c * (r - l + 1);\n\t\t\tb += c;\n\t\t}\n\n\t\tT merge(T a, T b) { return a +\
    \ b; }\n\t};\n\n\tSegtree<stinfo> sgt(N + 1);\n\twhile (Q--) {\n\t\tint t; cin\
    \ >> t;\n\t\tif (t == 0) {\n\t\t\tint l, r; long long v;\n\t\t\tcin >> l >> r\
    \ >> v;\n\t\t\tsgt.update(l, r, v);\n\t\t} else if (t == 1) {\n\t\t\tint l, r;\
    \ \n\t\t\tcin >> l >> r;\n\t\t\tcout << sgt.query(l, r) << '\\n';\n\t\t}\n\t}\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/lazy-segment-tree.hpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\n\tstruct stinfo {\n\t\tusing\
    \ T = long long;\n\t\tusing L = long long;\n\n\t\tconst T Tdval = 0;\n\t\tconst\
    \ L Ldval = 0;\n\n\t\tvoid apply(T &a, L &b, L c, int l, int r) {\n\t\t\ta +=\
    \ c * (r - l + 1);\n\t\t\tb += c;\n\t\t}\n\n\t\tT merge(T a, T b) { return a +\
    \ b; }\n\t};\n\n\tSegtree<stinfo> sgt(N + 1);\n\twhile (Q--) {\n\t\tint t; cin\
    \ >> t;\n\t\tif (t == 0) {\n\t\t\tint l, r; long long v;\n\t\t\tcin >> l >> r\
    \ >> v;\n\t\t\tsgt.update(l, r, v);\n\t\t} else if (t == 1) {\n\t\t\tint l, r;\
    \ \n\t\t\tcin >> l >> r;\n\t\t\tcout << sgt.query(l, r) << '\\n';\n\t\t}\n\t}\n\
    }"
  dependsOn:
  - data-structure/lazy-segment-tree.hpp
  isVerificationFile: true
  path: verify/lazy-segment-tree.aizu-RSQ-and-RAQ.test.cpp
  requiredBy: []
  timestamp: '2022-01-26 06:50:04-08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/lazy-segment-tree.aizu-RSQ-and-RAQ.test.cpp
layout: document
redirect_from:
- /verify/verify/lazy-segment-tree.aizu-RSQ-and-RAQ.test.cpp
- /verify/verify/lazy-segment-tree.aizu-RSQ-and-RAQ.test.cpp.html
title: verify/lazy-segment-tree.aizu-RSQ-and-RAQ.test.cpp
---
