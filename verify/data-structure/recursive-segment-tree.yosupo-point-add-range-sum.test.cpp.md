---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/recursive-segment-tree.hpp
    title: Recursive Segment Tree
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
  bundledCode: "#line 1 \"verify/data-structure/recursive-segment-tree.yosupo-point-add-range-sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/recursive-segment-tree.hpp\"\
    \ntemplate<typename T>\nstruct segtree {\n    int n;\n    vector<T> tree;\n  \
    \  \n    T dval = T();\n\n    T merge(const T &a, const T &b) { return a + b;\
    \ }\n\n    void apply(T &a, const T &b) { a = b; }\n\nprivate:\n    T query(int\
    \ l, int r, int t, int tl, int tr) {\n        if (r < tl || tr < l)\n        \
    \    return dval;\n        if (l <= tl && tr <= r)\n            return tree[t];\n\
    \        int tm = (tl + tr) >> 1;\n        return merge(query(l, r, t << 1, tl,\
    \ tm), query(l, r, t << 1 | 1, tm + 1, tr));\n    }\n\n    void update(int i,\
    \ T v, int t, int tl, int tr) {\n        if (tl == tr) {\n            apply(tree[t],\
    \ v);\n            return;\n        }\n        int tm = (tl + tr) >> 1;\n    \
    \    if (i <= tm)\n            update(i, v, t << 1, tl, tm);\n        else \n\
    \            update(i, v, t << 1 | 1, tm + 1, tr);\n        tree[t] = merge(tree[t\
    \ << 1], tree[t << 1 | 1]);\n    }\n\npublic:\n    segtree() = default;\n\n  \
    \  segtree(int _n) : n(_n) {\n        tree.resize(4 * n);\n        for (int i\
    \ = 0; i < n; i++)\n            update(i, dval);\n    }\n\n    template<typename\
    \ Iterator>\n    segtree(Iterator begin, Iterator end) : n(distance(begin, end))\
    \ {\n\t\ttree.resize(4 * n);\n        for (int i = 0; i < n; i++, begin++)\n \
    \           update(i, *begin);\n    }\n\n    T query(int l, int r) {\n       \
    \ return query(l, r, 1, 0, n - 1);\n    }\n\n    T operator[](int i) { return\
    \ query(i, i); }\n\n    void update(int i, T v) {\n        update(i, v, 1, 0,\
    \ n - 1);\n    }\n};\n#line 7 \"verify/data-structure/recursive-segment-tree.yosupo-point-add-range-sum.test.cpp\"\
    \n\nconst int MAX = 5e5 + 5;\n\nint N, Q;\nlong long A[MAX];\nsegtree<long long>\
    \ sgt;\n\nint main() {\n  cin >> N >> Q;\n  for (int i = 0; i < N; i++)\n    cin\
    \ >> A[i];\n  sgt = segtree<long long>(A, A + N);\n  while (Q--) {\n    int t;\
    \ cin >> t;\n    if (t == 0) {\n      int p; long long x;\n      cin >> p >> x;\n\
    \      sgt.update(p, sgt[p] + x);\n    } else {\n      int l, r;\n      cin >>\
    \ l >> r;\n      cout << sgt.query(l, r - 1) << '\\n';\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/recursive-segment-tree.hpp\"\
    \n\nconst int MAX = 5e5 + 5;\n\nint N, Q;\nlong long A[MAX];\nsegtree<long long>\
    \ sgt;\n\nint main() {\n  cin >> N >> Q;\n  for (int i = 0; i < N; i++)\n    cin\
    \ >> A[i];\n  sgt = segtree<long long>(A, A + N);\n  while (Q--) {\n    int t;\
    \ cin >> t;\n    if (t == 0) {\n      int p; long long x;\n      cin >> p >> x;\n\
    \      sgt.update(p, sgt[p] + x);\n    } else {\n      int l, r;\n      cin >>\
    \ l >> r;\n      cout << sgt.query(l, r - 1) << '\\n';\n    }\n  }\n}"
  dependsOn:
  - data-structure/recursive-segment-tree.hpp
  isVerificationFile: true
  path: verify/data-structure/recursive-segment-tree.yosupo-point-add-range-sum.test.cpp
  requiredBy: []
  timestamp: '2022-01-02 09:54:38-08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data-structure/recursive-segment-tree.yosupo-point-add-range-sum.test.cpp
layout: document
redirect_from:
- /verify/verify/data-structure/recursive-segment-tree.yosupo-point-add-range-sum.test.cpp
- /verify/verify/data-structure/recursive-segment-tree.yosupo-point-add-range-sum.test.cpp.html
title: verify/data-structure/recursive-segment-tree.yosupo-point-add-range-sum.test.cpp
---
