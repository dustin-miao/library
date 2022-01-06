---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/binary-index-tree.hpp
    title: Binary Index Tree
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
  bundledCode: "#line 1 \"verify/data-structure/binary-index-tree.yosupo-point-add-range-sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/binary-index-tree.hpp\"\
    \ntemplate<typename T>\nclass fentree {\n\tint n;\n\tvector<T> tree;\n\npublic:\n\
    \tvoid init(int _n) {\n\t\tn = _n;\n\t\ttree.assign(n + 1, T());\n\t}\n\n\ttemplate<class\
    \ Iterator>\n\tvoid init(Iterator begin, Iterator end) {\n\t\tn = distance(begin,\
    \ end);\n\t\ttree.resize(n + 1);\n\t\tfor (int i = 1; begin != end; i++, begin++)\n\
    \t\t\tupdate(i, *begin);\n\t}\n\n\tvoid update(int i, T v) {\n\t\tfor (; i <=\
    \ n; i += i & -i)\n\t\t\ttree[i] += v;\n\t}\n\n\tT query(int i) {\n\t\tT ret =\
    \ 0;\n\t\tfor (; i; i -= i & -i)\n\t\t\tret += tree[i];\n\t\treturn ret;\n\t}\n\
    \n\tT query(int l, int r) { return query(r) - query(l - 1); }\n\n\tT operator[](int\
    \ i) { return query(i, i); }\n};\n#line 7 \"verify/data-structure/binary-index-tree.yosupo-point-add-range-sum.test.cpp\"\
    \n\nconst int MAX = 5e5 + 5;\n\nint N, Q;\nlong long A[MAX];\nfentree<long long>\
    \ bit;\n\nint main() {\n  cin >> N >> Q;\n  for (int i = 0; i < N; i++)\n    cin\
    \ >> A[i];\n  bit.init(A, A + N);\n  while (Q--) {\n    int t; cin >> t;\n   \
    \ if (t == 0) {\n      int p; long long x;\n      cin >> p >> x;\n      bit.update(p\
    \ + 1, x);\n    } else {\n      int l, r;\n      cin >> l >> r;\n      cout <<\
    \ bit.query(l + 1, r) << '\\n';\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/binary-index-tree.hpp\"\
    \n\nconst int MAX = 5e5 + 5;\n\nint N, Q;\nlong long A[MAX];\nfentree<long long>\
    \ bit;\n\nint main() {\n  cin >> N >> Q;\n  for (int i = 0; i < N; i++)\n    cin\
    \ >> A[i];\n  bit.init(A, A + N);\n  while (Q--) {\n    int t; cin >> t;\n   \
    \ if (t == 0) {\n      int p; long long x;\n      cin >> p >> x;\n      bit.update(p\
    \ + 1, x);\n    } else {\n      int l, r;\n      cin >> l >> r;\n      cout <<\
    \ bit.query(l + 1, r) << '\\n';\n    }\n  }\n}\n"
  dependsOn:
  - data-structure/binary-index-tree.hpp
  isVerificationFile: true
  path: verify/data-structure/binary-index-tree.yosupo-point-add-range-sum.test.cpp
  requiredBy: []
  timestamp: '2022-01-05 19:16:14-08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data-structure/binary-index-tree.yosupo-point-add-range-sum.test.cpp
layout: document
redirect_from:
- /verify/verify/data-structure/binary-index-tree.yosupo-point-add-range-sum.test.cpp
- /verify/verify/data-structure/binary-index-tree.yosupo-point-add-range-sum.test.cpp.html
title: verify/data-structure/binary-index-tree.yosupo-point-add-range-sum.test.cpp
---
