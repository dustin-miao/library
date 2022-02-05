---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/fenwick-tree.hpp
    title: data-structure/fenwick-tree.hpp
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
    \ntemplate<typename T>\nclass Fentree {\n\tsize_t n;\n\tvector<T> tree;\n\npublic:\n\
    \tFentree() = default;\n\n\tFentree(size_t _n) { init(_n); }\n\n\tvoid init(size_t\
    \ _n) {\n\t\tn = _n;\n\t\ttree.assign(n + 1, T());\n\t}\n\n\tvoid update(int i,\
    \ T v) {\n\t\tfor (; i <= n; i += i & -i)\n\t\t\ttree[i] += v;\n\t}\n\n\tT query(int\
    \ i) {\n\t\tT ret = 0;\n\t\tfor (; i; i -= i & -i)\n\t\t\tret += tree[i];\n\t\t\
    return ret;\n\t}\n\n\tT query(int l, int r) { return query(r) - query(l - 1);\
    \ }\n};\n#line 7 \"verify/fenwick-tree.yosupo-point-add-range-sum.test.cpp\"\n\
    \nconst int MAX = 5e5 + 5;\n\nint main() {\n\tint N, Q;\n  \tcin >> N >> Q;\n\t\
    Fentree<long long> bit(N);\n  \tfor (int i = 0; i < N; i++) {\n\t\tlong long a;\
    \ cin >> a;\n\t\tbit.update(i + 1, a);\n\t}\n  \twhile (Q--) {\n\t\tint t; cin\
    \ >> t;\n\t\tif (t == 0) {\n\t  \t\tint p; long long x;\n\t  \t\tcin >> p >> x;\n\
    \t  \t\tbit.update(p + 1, x);\n\t\t} else {\n\t  \t\tint l, r;\n\t  \t\tcin >>\
    \ l >> r;\n\t  \t\tcout << bit.query(l + 1, r) << '\\n';\n\t\t}\n  \t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/fenwick-tree.hpp\"\
    \n\nconst int MAX = 5e5 + 5;\n\nint main() {\n\tint N, Q;\n  \tcin >> N >> Q;\n\
    \tFentree<long long> bit(N);\n  \tfor (int i = 0; i < N; i++) {\n\t\tlong long\
    \ a; cin >> a;\n\t\tbit.update(i + 1, a);\n\t}\n  \twhile (Q--) {\n\t\tint t;\
    \ cin >> t;\n\t\tif (t == 0) {\n\t  \t\tint p; long long x;\n\t  \t\tcin >> p\
    \ >> x;\n\t  \t\tbit.update(p + 1, x);\n\t\t} else {\n\t  \t\tint l, r;\n\t  \t\
    \tcin >> l >> r;\n\t  \t\tcout << bit.query(l + 1, r) << '\\n';\n\t\t}\n  \t}\n\
    }\n"
  dependsOn:
  - data-structure/fenwick-tree.hpp
  isVerificationFile: true
  path: verify/fenwick-tree.yosupo-point-add-range-sum.test.cpp
  requiredBy: []
  timestamp: '2022-02-04 19:46:21-08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/fenwick-tree.yosupo-point-add-range-sum.test.cpp
layout: document
redirect_from:
- /verify/verify/fenwick-tree.yosupo-point-add-range-sum.test.cpp
- /verify/verify/fenwick-tree.yosupo-point-add-range-sum.test.cpp.html
title: verify/fenwick-tree.yosupo-point-add-range-sum.test.cpp
---
