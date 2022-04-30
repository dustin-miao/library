---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/fenwick-tree.hpp
    title: Fenwick Tree
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
  bundledCode: "#line 1 \"verify/fenwick-tree.yosupo-point-add-range-sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/fenwick-tree.hpp\"\
    \n#pragma region fenwick_tree\n\ntemplate<typename T>\nclass fenwick_tree {\n\t\
    int n;\n\tvector<T> tree;\n\npublic:\n\tfenwick_tree() = default;\n\n\tfenwick_tree(int\
    \ _n) { init(_n); }\n\n\tvoid init(int _n) {\n\t\tn = _n;\n\t\ttree.assign(n +\
    \ 1, T());\n\t}\n\n\tvoid update(int i, T v) {\n\t\tfor (i++; i <= n; i += i &\
    \ -i)\n\t\t\ttree[i] += v;\n\t}\n\n\tT query(int i) {\n\t\tT ret = T();\n\t\t\
    for (i++; i; i -= i & -i)\n\t\t\tret += tree[i];\n\t\treturn ret;\n\t}\n\n\tT\
    \ query(int l, int r) { return query(r) - query(l - 1); }\n};\n\n#pragma endregion\
    \ fenwick_tree\n#line 7 \"verify/fenwick-tree.yosupo-point-add-range-sum.test.cpp\"\
    \n\nconst int MAX = 5e5 + 5;\n\nint main() {\n\tint N, Q;\n  \tcin >> N >> Q;\n\
    \tfenwick_tree<long long> bit(N);\n  \tfor (int i = 0; i < N; i++) {\n\t\tlong\
    \ long a; cin >> a;\n\t\tbit.update(i, a);\n\t}\n  \twhile (Q--) {\n\t\tint t;\
    \ cin >> t;\n\t\tif (t == 0) {\n\t  \t\tint p; long long x;\n\t  \t\tcin >> p\
    \ >> x;\n\t  \t\tbit.update(p, x);\n\t\t} else {\n\t  \t\tint l, r;\n\t  \t\t\
    cin >> l >> r;\n\t  \t\tcout << bit.query(l, r - 1) << '\\n';\n\t\t}\n  \t}\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/fenwick-tree.hpp\"\
    \n\nconst int MAX = 5e5 + 5;\n\nint main() {\n\tint N, Q;\n  \tcin >> N >> Q;\n\
    \tfenwick_tree<long long> bit(N);\n  \tfor (int i = 0; i < N; i++) {\n\t\tlong\
    \ long a; cin >> a;\n\t\tbit.update(i, a);\n\t}\n  \twhile (Q--) {\n\t\tint t;\
    \ cin >> t;\n\t\tif (t == 0) {\n\t  \t\tint p; long long x;\n\t  \t\tcin >> p\
    \ >> x;\n\t  \t\tbit.update(p, x);\n\t\t} else {\n\t  \t\tint l, r;\n\t  \t\t\
    cin >> l >> r;\n\t  \t\tcout << bit.query(l, r - 1) << '\\n';\n\t\t}\n  \t}\n\
    }\n"
  dependsOn:
  - data-structure/fenwick-tree.hpp
  isVerificationFile: true
  path: verify/fenwick-tree.yosupo-point-add-range-sum.test.cpp
  requiredBy: []
  timestamp: '2022-04-29 22:36:50-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/fenwick-tree.yosupo-point-add-range-sum.test.cpp
layout: document
redirect_from:
- /verify/verify/fenwick-tree.yosupo-point-add-range-sum.test.cpp
- /verify/verify/fenwick-tree.yosupo-point-add-range-sum.test.cpp.html
title: verify/fenwick-tree.yosupo-point-add-range-sum.test.cpp
---
