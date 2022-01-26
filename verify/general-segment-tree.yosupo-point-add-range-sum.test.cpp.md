---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/general-segment-tree.hpp
    title: General Segment Tree
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
  bundledCode: "#line 1 \"verify/general-segment-tree.yosupo-point-add-range-sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/general-segment-tree.hpp\"\
    \ntemplate<class Base>\nclass Segtree : public Base {\n\tusing node = typename\
    \ Base::T;\n\nprotected:\n\tsize_t n;\n\tvector<node> tree;\n\npublic:\n\tSegtree()\
    \ = default;\n\n\tSegtree(size_t _n) { init(_n); }\n\n\tvoid init(size_t _n) {\n\
    \t\tfor (n = 1; n < _n; n *= 2);\n\t\ttree.assign(n * 2, Base::dval);\n\t}\n\n\
    \tvoid update(int i, node v) {\n\t\tfor (Base::apply(tree[i += n], v); i >>= 1;)\n\
    \t\t\ttree[i] = Base::merge(tree[i << 1], tree[i << 1 | 1]);\n\t}\n\n\tnode query(int\
    \ l, int r) {\n\t\tnode lret = Base::dval, rret = Base::dval;\n\t\tfor (l += n,\
    \ r += n + 1; l < r; l >>= 1, r >>= 1) {\n\t\t\tif (l & 1) lret = Base::merge(lret,\
    \ tree[l++]);\n\t\t\tif (r & 1) rret = Base::merge(tree[--r], rret);\n\t\t}\n\t\
    \treturn Base::merge(lret, rret);\n\t}\n\n\tnode operator[](int i) { return tree[i\
    \ += n]; }\n};\n#line 7 \"verify/general-segment-tree.yosupo-point-add-range-sum.test.cpp\"\
    \n\nconst int MAX = 5e5 + 5;\n\n\n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\
    \n\tstruct stinfo {\n\t\tusing T = long long;\n\t\tconst T dval = 0;\n\t\tvoid\
    \ apply(T &a, T b) { a += b; }\n\t\tT merge(T a, T b) { return a + b; }\n\t};\n\
    \n\tSegtree<stinfo> sgt(N);\n\tfor (int i = 0; i < N; i++) {\n\t\tlong long a;\
    \ cin >> a;\n\t\tsgt.update(i, a);\n\t}\n\twhile (Q--) {\n\t\tint t; cin >> t;\n\
    \t\tif (t == 0) {\n\t\t\tint p; long long x;\n\t\t\tcin >> p >> x;\n\t\t\tsgt.update(p,\
    \ x);\n\t\t} else {\n\t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\t\t\tcout << sgt.query(l,\
    \ r - 1) << '\\n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/general-segment-tree.hpp\"\
    \n\nconst int MAX = 5e5 + 5;\n\n\n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\
    \n\tstruct stinfo {\n\t\tusing T = long long;\n\t\tconst T dval = 0;\n\t\tvoid\
    \ apply(T &a, T b) { a += b; }\n\t\tT merge(T a, T b) { return a + b; }\n\t};\n\
    \n\tSegtree<stinfo> sgt(N);\n\tfor (int i = 0; i < N; i++) {\n\t\tlong long a;\
    \ cin >> a;\n\t\tsgt.update(i, a);\n\t}\n\twhile (Q--) {\n\t\tint t; cin >> t;\n\
    \t\tif (t == 0) {\n\t\t\tint p; long long x;\n\t\t\tcin >> p >> x;\n\t\t\tsgt.update(p,\
    \ x);\n\t\t} else {\n\t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\t\t\tcout << sgt.query(l,\
    \ r - 1) << '\\n';\n\t\t}\n\t}\n}\n"
  dependsOn:
  - data-structure/general-segment-tree.hpp
  isVerificationFile: true
  path: verify/general-segment-tree.yosupo-point-add-range-sum.test.cpp
  requiredBy: []
  timestamp: '2022-01-26 05:31:56-08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/general-segment-tree.yosupo-point-add-range-sum.test.cpp
layout: document
redirect_from:
- /verify/verify/general-segment-tree.yosupo-point-add-range-sum.test.cpp
- /verify/verify/general-segment-tree.yosupo-point-add-range-sum.test.cpp.html
title: verify/general-segment-tree.yosupo-point-add-range-sum.test.cpp
---
