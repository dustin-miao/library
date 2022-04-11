---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/static-segment-tree.hpp
    title: Static Segment Tree
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
  bundledCode: "#line 1 \"verify/static-segment-tree.yosupo-point-add-range-sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/static-segment-tree.hpp\"\
    \nclass sta_segment_tree {\n\tusing T = long long;\n\n\tstatic constexpr T default_value\
    \ = 0;\n\n\tstatic void apply(T &a, T b) { a += b; }\n\n\tstatic T merge(T a,\
    \ T b) { return a + b; }\n\nprotected:\n\tint n;\n\tvector<T> tree;\n\npublic:\n\
    \tsta_segment_tree() = default;\n\n\tsta_segment_tree(int _n) { init(_n); }\n\n\
    \tvoid init(int _n) {\n\t\tn = _n;\n\t\ttree.assign(n * 2, default_value);\n\t\
    }\n\n\tvoid update(int i, T v) {\n\t\tfor (apply(tree[i += n], v); i >>= 1;)\n\
    \t\t\ttree[i] = merge(tree[i << 1], tree[i << 1 | 1]);\n\t}\n\n\tT query(int l,\
    \ int r) {\n\t\tT ret = default_value;\n\t\tfor (l += n, r += n + 1; l < r; l\
    \ >>= 1, r >>= 1) {\n\t\t\tif (l & 1) \n\t\t\t\tret = merge(ret, tree[l++]);\n\
    \t\t\tif (r & 1) \n\t\t\t\tret = merge(ret, tree[--r]);\n\t\t}\n\t\treturn ret;\n\
    \t}\n\n\tT operator[](int i) { return tree[i + n]; }\n};\n#line 7 \"verify/static-segment-tree.yosupo-point-add-range-sum.test.cpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\n\tsta_segment_tree sgt(N);\n\
    \tfor (int i = 0; i < N; i++) {\n\t\tlong long a; cin >> a;\n\t\tsgt.update(i,\
    \ a);\n\t}\n\twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\tint\
    \ p; long long x;\n\t\t\tcin >> p >> x;\n\t\t\tsgt.update(p, x);\n\t\t} else {\n\
    \t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\t\t\tcout << sgt.query(l, r - 1) << '\\\
    n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/static-segment-tree.hpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\n\tsta_segment_tree sgt(N);\n\
    \tfor (int i = 0; i < N; i++) {\n\t\tlong long a; cin >> a;\n\t\tsgt.update(i,\
    \ a);\n\t}\n\twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\tint\
    \ p; long long x;\n\t\t\tcin >> p >> x;\n\t\t\tsgt.update(p, x);\n\t\t} else {\n\
    \t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\t\t\tcout << sgt.query(l, r - 1) << '\\\
    n';\n\t\t}\n\t}\n}\n"
  dependsOn:
  - data-structure/static-segment-tree.hpp
  isVerificationFile: true
  path: verify/static-segment-tree.yosupo-point-add-range-sum.test.cpp
  requiredBy: []
  timestamp: '2022-04-11 09:03:00-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/static-segment-tree.yosupo-point-add-range-sum.test.cpp
layout: document
redirect_from:
- /verify/verify/static-segment-tree.yosupo-point-add-range-sum.test.cpp
- /verify/verify/static-segment-tree.yosupo-point-add-range-sum.test.cpp.html
title: verify/static-segment-tree.yosupo-point-add-range-sum.test.cpp
---
