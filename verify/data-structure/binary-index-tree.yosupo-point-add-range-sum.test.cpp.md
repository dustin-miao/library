---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/binary-index-tree.hpp
    title: Binary Index Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"verify/data-structure/binary-index-tree.yosupo-point-add-range-sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/binary-index-tree.hpp\"\
    \ntemplate<typename T>\nclass Fentree {\n\tsize_t n;\n\tvector<T> tree;\n\npublic:\n\
    \tFentree() = default;\n\n\tFentree(size_t _n) { init(_n); }\n\n\tvoid init(size_t\
    \ _n) {\n\t\tn = _n;\n\t\ttree.assign(n + 1, T());\n\t}\n\n\tvoid update(int i,\
    \ T v) {\n\t\tfor (i++; i <= n; i += i & -i)\n\t\t\ttree[i] += v;\n\t}\n\n\tT\
    \ query(int i) {\n\t\tT ret = 0;\n\t\tfor (i++; i; i -= i & -i)\n\t\t\tret +=\
    \ tree[i];\n\t\treturn ret;\n\t}\n\n\tT query(int l, int r) { return query(r)\
    \ - query(l - 1); }\n};\n#line 7 \"verify/data-structure/binary-index-tree.yosupo-point-add-range-sum.test.cpp\"\
    \n\nconst int MAX = 5e5 + 5;\n\nint N, Q;\nFentree<long long> bit;\n\nint main()\
    \ {\n  \tcin >> N >> Q;\n\tbit.init(N);\n  \tfor (int i = 0; i < N; i++) {\n\t\
    \tlong long a; cin >> a;\n\t\tbit.update(i + 1, a);\n\t}\n  \twhile (Q--) {\n\t\
    \tint t; cin >> t;\n\t\tif (t == 0) {\n\t  \t\tint p; long long x;\n\t  \t\tcin\
    \ >> p >> x;\n\t  \t\tbit.update(p + 1, x);\n\t\t} else {\n\t  \t\tint l, r;\n\
    \t  \t\tcin >> l >> r;\n\t  \t\tcout << bit.query(l + 1, r) << '\\n';\n\t\t}\n\
    \  \t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/binary-index-tree.hpp\"\
    \n\nconst int MAX = 5e5 + 5;\n\nint N, Q;\nFentree<long long> bit;\n\nint main()\
    \ {\n  \tcin >> N >> Q;\n\tbit.init(N);\n  \tfor (int i = 0; i < N; i++) {\n\t\
    \tlong long a; cin >> a;\n\t\tbit.update(i + 1, a);\n\t}\n  \twhile (Q--) {\n\t\
    \tint t; cin >> t;\n\t\tif (t == 0) {\n\t  \t\tint p; long long x;\n\t  \t\tcin\
    \ >> p >> x;\n\t  \t\tbit.update(p + 1, x);\n\t\t} else {\n\t  \t\tint l, r;\n\
    \t  \t\tcin >> l >> r;\n\t  \t\tcout << bit.query(l + 1, r) << '\\n';\n\t\t}\n\
    \  \t}\n}\n"
  dependsOn:
  - data-structure/binary-index-tree.hpp
  isVerificationFile: true
  path: verify/data-structure/binary-index-tree.yosupo-point-add-range-sum.test.cpp
  requiredBy: []
  timestamp: '2022-01-22 21:24:46-08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/data-structure/binary-index-tree.yosupo-point-add-range-sum.test.cpp
layout: document
redirect_from:
- /verify/verify/data-structure/binary-index-tree.yosupo-point-add-range-sum.test.cpp
- /verify/verify/data-structure/binary-index-tree.yosupo-point-add-range-sum.test.cpp.html
title: verify/data-structure/binary-index-tree.yosupo-point-add-range-sum.test.cpp
---
