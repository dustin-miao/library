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
  bundledCode: "#line 1 \"verify/data-structure/segment-tree.yosupo-point-add-range-sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/segment-tree.hpp\"\
    \ntemplate<typename T>\nstruct segtree {\n    int n;\n    vector<T> tree;\n\n\
    \    T dval = T();\n\n    T merge(const T &a, const T &b) { return a + b; }\n\n\
    \    void apply(T &a, const T &b) { a = b; }\n\n    segtree() = default;\n\n \
    \   segtree(int _n) : n(_n) {\n        tree.assign(2 * n, dval);\n        for\
    \ (int i = n - 1; i > 0; i--)\n            tree[i] = merge(tree[i << 1], tree[i\
    \ << 1 | 1]);\n    }\n\n    template<typename Iterator>\n    segtree(Iterator\
    \ begin, Iterator end) : n(distance(begin, end)) {\n\t\ttree.resize(2 * n);\n\
    \        for (int i = n; i < 2 * n; i++, begin++)\n            tree[i] = *begin;\n\
    \        for (int i = n - 1; i > 0; i--)\n            tree[i] = merge(tree[i <<\
    \ 1], tree[i << 1 | 1]);\n    }\n\n    T query(int l, int r) {\n        T ret\
    \ = dval;\n        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {\n     \
    \       if (l & 1) ret = merge(ret, tree[l++]);\n            if (r & 1) ret =\
    \ merge(ret, tree[--r]);\n        }\n        return ret;\n    }\n\n    T operator[](int\
    \ i) { return tree[i += n]; }\n\n    void update(int i, T v) {\n        for (apply(tree[i\
    \ += n], v); i > 1; i >>= 1)\n            tree[i >> 1] = merge(tree[i], tree[i\
    \ ^ 1]);\n    }\n};\n#line 7 \"verify/data-structure/segment-tree.yosupo-point-add-range-sum.test.cpp\"\
    \n\nconst int MAX = 5e5 + 5;\n\nint N, Q;\nlong long A[MAX];\nsegtree<long long>\
    \ sgt;\n\nint main() {\n  cin >> N >> Q;\n  for (int i = 0; i < N; i++)\n    cin\
    \ >> A[i];\n  sgt = segtree<long long>(A, A + N);\n  while (Q--) {\n    int t;\
    \ cin >> t;\n    if (t == 0) {\n      int p; long long x;\n      cin >> p >> x;\n\
    \      sgt.update(p, sgt[p] + x);\n    } else {\n      int l, r;\n      cin >>\
    \ l >> r;\n      cout << sgt.query(l, r - 1) << '\\n';\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/segment-tree.hpp\"\
    \n\nconst int MAX = 5e5 + 5;\n\nint N, Q;\nlong long A[MAX];\nsegtree<long long>\
    \ sgt;\n\nint main() {\n  cin >> N >> Q;\n  for (int i = 0; i < N; i++)\n    cin\
    \ >> A[i];\n  sgt = segtree<long long>(A, A + N);\n  while (Q--) {\n    int t;\
    \ cin >> t;\n    if (t == 0) {\n      int p; long long x;\n      cin >> p >> x;\n\
    \      sgt.update(p, sgt[p] + x);\n    } else {\n      int l, r;\n      cin >>\
    \ l >> r;\n      cout << sgt.query(l, r - 1) << '\\n';\n    }\n  }\n}\n"
  dependsOn:
  - data-structure/segment-tree.hpp
  isVerificationFile: true
  path: verify/data-structure/segment-tree.yosupo-point-add-range-sum.test.cpp
  requiredBy: []
  timestamp: '2022-01-02 09:54:38-08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data-structure/segment-tree.yosupo-point-add-range-sum.test.cpp
layout: document
redirect_from:
- /verify/verify/data-structure/segment-tree.yosupo-point-add-range-sum.test.cpp
- /verify/verify/data-structure/segment-tree.yosupo-point-add-range-sum.test.cpp.html
title: verify/data-structure/segment-tree.yosupo-point-add-range-sum.test.cpp
---
