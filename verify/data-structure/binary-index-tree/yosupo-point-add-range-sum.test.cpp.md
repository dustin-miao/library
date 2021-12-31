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
  bundledCode: "#line 1 \"verify/data-structure/binary-index-tree/yosupo-point-add-range-sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/binary-index-tree.hpp\"\
    \ntemplate<typename T>\nstruct fentree {\n    int n;\n    vector<T> tree;\n\n\
    \    fentree() = default;\n\n    fentree(int _n) : n(_n + 1) {\n        tree.assign(n,\
    \ T());\n    }\n\n    template<class Iterator>\n    fentree(Iterator begin, Iterator\
    \ end) : n(distance(begin, end) + 1) {\n        tree.resize(n);\n        for (int\
    \ i = 1; begin != end; i++, begin++)\n            update(i, *begin);\n    }\n\n\
    \    T query(int i) {\n        T ret = 0;\n        for (; i; i -= i & -i)\n  \
    \          ret += tree[i];\n        return ret;\n    }\n\n    T query(int l, int\
    \ r) { return query(r) - query(l - 1); }\n\n    T operator[](int i) { return query(i,\
    \ i); }\n\n    void update(int i, T v) {\n        for (; i <= n; i += i & -i)\n\
    \            tree[i] += v;\n    }\n};\n#line 7 \"verify/data-structure/binary-index-tree/yosupo-point-add-range-sum.test.cpp\"\
    \n\nconst int MAX = 5e5 + 5;\n\nint N, Q;\nlong long A[MAX];\nfentree<long long>\
    \ bit;\n\nint main() {\n  cin >> N >> Q;\n  for (int i = 0; i < N; i++)\n    cin\
    \ >> A[i];\n  bit = fentree<long long>(A, A + N);\n  while (Q--) {\n    int t;\
    \ cin >> t;\n    if (t == 0) {\n      int p; long long x;\n      cin >> p >> x;\n\
    \      bit.update(p + 1, x);\n    } else {\n      int l, r;\n      cin >> l >>\
    \ r;\n      cout << bit.query(l + 1, r) << '\\n';\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/binary-index-tree.hpp\"\
    \n\nconst int MAX = 5e5 + 5;\n\nint N, Q;\nlong long A[MAX];\nfentree<long long>\
    \ bit;\n\nint main() {\n  cin >> N >> Q;\n  for (int i = 0; i < N; i++)\n    cin\
    \ >> A[i];\n  bit = fentree<long long>(A, A + N);\n  while (Q--) {\n    int t;\
    \ cin >> t;\n    if (t == 0) {\n      int p; long long x;\n      cin >> p >> x;\n\
    \      bit.update(p + 1, x);\n    } else {\n      int l, r;\n      cin >> l >>\
    \ r;\n      cout << bit.query(l + 1, r) << '\\n';\n    }\n  }\n}\n"
  dependsOn:
  - data-structure/binary-index-tree.hpp
  isVerificationFile: true
  path: verify/data-structure/binary-index-tree/yosupo-point-add-range-sum.test.cpp
  requiredBy: []
  timestamp: '2021-12-31 09:05:27-08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data-structure/binary-index-tree/yosupo-point-add-range-sum.test.cpp
layout: document
redirect_from:
- /verify/verify/data-structure/binary-index-tree/yosupo-point-add-range-sum.test.cpp
- /verify/verify/data-structure/binary-index-tree/yosupo-point-add-range-sum.test.cpp.html
title: verify/data-structure/binary-index-tree/yosupo-point-add-range-sum.test.cpp
---
