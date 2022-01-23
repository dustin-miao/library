---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segment-tree.hpp
    title: Segment Tree
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
  bundledCode: "#line 1 \"verify/segment-tree.yosupo-point-add-range-sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/segment-tree.hpp\"\
    \ntemplate<class Base>\nclass Segtree : public Base {\n\tusing node = typename\
    \ Base::T;\n\n\tsize_t n;\n\tvector<node> tree;\n\npublic:\n\tSegtree() = default;\n\
    \n\tSegtree(size_t _n) { init(_n); }\n\n\tvoid init(size_t _n) {\n\t\tn = _n;\n\
    \t\ttree.assign(n * 2, Base::dval);\n\t}\n\n\tvoid update(int i, node v) {\n\t\
    \tfor (Base::apply(tree[i += n], v); i >>= 1;)\n\t\t\ttree[i] = Base::merge(tree[i\
    \ << 1], tree[i << 1 | 1]);\n\t}\n\n\tnode query(int l, int r) {\n\t\tnode ret\
    \ = Base::dval;\n\t\tfor (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {\n\t\t\
    \tif (l & 1) ret = Base::merge(ret, tree[l++]);\n\t\t\tif (r & 1) ret = Base::merge(ret,\
    \ tree[--r]);\n\t\t}\n\t\treturn ret;\n\t}\n\n\tnode operator[](int i) { return\
    \ tree[i += n]; }\n};\n#line 7 \"verify/segment-tree.yosupo-point-add-range-sum.test.cpp\"\
    \n\nconst int MAX = 5e5 + 5;\n\nint N, Q;\n\nstruct stinfo {\n\tusing T = long\
    \ long;\n\n\tconst T dval = 0;\n\n\tvoid apply(T &a, T b) { a += b; }\n\n\tT merge(T\
    \ a, T b) { return a + b; }\n};\n\nSegtree<stinfo> sgt;\n\nint main() {\n\tcin\
    \ >> N >> Q;\n\tsgt.init(N);\n\tfor (int i = 0; i < N; i++) {\n\t\tlong long a;\
    \ cin >> a;\n\t\tsgt.update(i, a);\n\t}\n\twhile (Q--) {\n\t\tint t; cin >> t;\n\
    \t\tif (t == 0) {\n\t\t\tint p; long long x;\n\t\t\tcin >> p >> x;\n\t\t\tsgt.update(p,\
    \ x);\n\t\t} else {\n\t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\t\t\tcout << sgt.query(l,\
    \ r - 1) << '\\n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/segment-tree.hpp\"\
    \n\nconst int MAX = 5e5 + 5;\n\nint N, Q;\n\nstruct stinfo {\n\tusing T = long\
    \ long;\n\n\tconst T dval = 0;\n\n\tvoid apply(T &a, T b) { a += b; }\n\n\tT merge(T\
    \ a, T b) { return a + b; }\n};\n\nSegtree<stinfo> sgt;\n\nint main() {\n\tcin\
    \ >> N >> Q;\n\tsgt.init(N);\n\tfor (int i = 0; i < N; i++) {\n\t\tlong long a;\
    \ cin >> a;\n\t\tsgt.update(i, a);\n\t}\n\twhile (Q--) {\n\t\tint t; cin >> t;\n\
    \t\tif (t == 0) {\n\t\t\tint p; long long x;\n\t\t\tcin >> p >> x;\n\t\t\tsgt.update(p,\
    \ x);\n\t\t} else {\n\t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\t\t\tcout << sgt.query(l,\
    \ r - 1) << '\\n';\n\t\t}\n\t}\n}\n"
  dependsOn:
  - data-structure/segment-tree.hpp
  isVerificationFile: true
  path: verify/segment-tree.yosupo-point-add-range-sum.test.cpp
  requiredBy: []
  timestamp: '2022-01-22 23:50:20-08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/segment-tree.yosupo-point-add-range-sum.test.cpp
layout: document
redirect_from:
- /verify/verify/segment-tree.yosupo-point-add-range-sum.test.cpp
- /verify/verify/segment-tree.yosupo-point-add-range-sum.test.cpp.html
title: verify/segment-tree.yosupo-point-add-range-sum.test.cpp
---
