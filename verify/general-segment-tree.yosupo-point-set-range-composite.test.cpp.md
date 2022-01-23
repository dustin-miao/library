---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/general-segment-tree.hpp
    title: General Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"verify/general-segment-tree.yosupo-point-set-range-composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/general-segment-tree.hpp\"\
    \ntemplate<class Base>\nclass Segtree : public Base {\n\tusing node = typename\
    \ Base::T;\n\n\tsize_t n;\n\tvector<node> tree;\n\npublic:\n\tSegtree() = default;\n\
    \n\tSegtree(size_t _n) { init(_n); }\n\n\tvoid init(size_t _n) {\n\t\tfor (n =\
    \ 1; n < _n; n *= 2);\n\t\ttree.assign(n * 2, Base::dval);\n\t}\n\n\tvoid update(int\
    \ i, node v) {\n\t\tBase::apply(tree[i += n], v);\n\t\tfor (i >>= 1; i > 1; i\
    \ >>= 1)\n\t\t\ttree[i] = Base::merge(tree[i << 1], tree[i << 1 | 1]);\n\t}\n\n\
    \tnode query(int l, int r) {\n\t\tnode lret = Base::dval, rret = Base::dval;\n\
    \t\tfor (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {\n\t\t\tif (l & 1) lret\
    \ = Base::merge(lret, tree[l++]);\n\t\t\tif (r & 1) rret = Base::merge(tree[--r],\
    \ rret);\n\t\t}\n\t\treturn Base::merge(lret, rret);\n\t}\n\n\tnode operator[](int\
    \ i) { return tree[i += n]; }\n};\n#line 7 \"verify/general-segment-tree.yosupo-point-set-range-composite.test.cpp\"\
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
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/general-segment-tree.hpp\"\
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
    \t\t}\n\t}\n}"
  dependsOn:
  - data-structure/general-segment-tree.hpp
  isVerificationFile: true
  path: verify/general-segment-tree.yosupo-point-set-range-composite.test.cpp
  requiredBy: []
  timestamp: '2022-01-22 23:50:20-08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/general-segment-tree.yosupo-point-set-range-composite.test.cpp
layout: document
redirect_from:
- /verify/verify/general-segment-tree.yosupo-point-set-range-composite.test.cpp
- /verify/verify/general-segment-tree.yosupo-point-set-range-composite.test.cpp.html
title: verify/general-segment-tree.yosupo-point-set-range-composite.test.cpp
---
