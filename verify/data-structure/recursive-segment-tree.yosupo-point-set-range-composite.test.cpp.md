---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/recursive-segment-tree.hpp
    title: Recursive Segment Tree
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
  bundledCode: "#line 1 \"verify/data-structure/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp\"\
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
    \ n - 1);\n    }\n};\n#line 7 \"verify/data-structure/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp\"\
    \n\nconst int MAX = 5e5 + 5;\n\n\nstruct line {\n\n};\n"
  code: '#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"


    #include <bits/stdc++.h>

    using namespace std;


    #include "data-structure/recursive-segment-tree.hpp"


    const int MAX = 5e5 + 5;



    struct line {


    };'
  dependsOn:
  - data-structure/recursive-segment-tree.hpp
  isVerificationFile: true
  path: verify/data-structure/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp
  requiredBy: []
  timestamp: '2022-01-02 09:54:38-08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/data-structure/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp
layout: document
redirect_from:
- /verify/verify/data-structure/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp
- /verify/verify/data-structure/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp.html
title: verify/data-structure/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp
---
