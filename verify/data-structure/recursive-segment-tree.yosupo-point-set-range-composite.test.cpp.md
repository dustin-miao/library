---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/recursive-segment-tree.hpp
    title: Recursive Segment Tree
  - icon: ':x:'
    path: geometry/line.hpp
    title: Line
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
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"geometry/line.hpp\"\
    \ntemplate<typename T>\nstruct line {\n    T m, b;\n\n    line() = default;\n\n\
    \    line(T _m, T _b) : m(_m), b(_b) {};\n\n    T operator()(T x) { return m *\
    \ x + b; }\n\n    friend double intersect(const line &l1, const line &l2) { \n\
    \        return (double)(l1.b - l2.b) / (double)(l2.m - l1.m); \n    }\n\n   \
    \ friend ostream &operator<<(ostream &os, const line &l) { \n        return os\
    \ << \"y = \" << l.m << \"x + \" << l.b; \n    }\n};\n#line 1 \"data-structure/recursive-segment-tree.hpp\"\
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
    \ n - 1);\n    }\n};\n#line 8 \"verify/data-structure/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp\"\
    \n\nconst int MAX = 5e5 + 5;\nconst long long MOD = 998244353;\n\ntemplate<typename\
    \ T>\nline<T> operator+(const line<T> &l1, const line<T> &l2) { \n    return line<T>(l1.m\
    \ * l2.m % MOD, (l1.b * l2.m + l2.b) % MOD);\n}\n\nint N, Q;\nline<long long>\
    \ A[MAX];\nsegtree<line<long long>> sgt;\n\nint main() {\n    cin >> N >> Q;\n\
    \    for (int i = 0; i < N; i++) {\n        long long m, b; \n        cin >> m\
    \ >> b;\n        A[i] = line<long long>(m, b);\n    }\n\n    sgt = segtree<line<long\
    \ long>>(A, A + N);\n    sgt.dval = line<long long>(1, 0);\n\n    while (Q--)\
    \ {\n        int t; \n        cin >> t;\n        if (t == 0) {\n            int\
    \ i;\n            long long m, b;\n            cin >> i >> m >> b;\n         \
    \   sgt.update(i, line<long long>(m, b));\n        } else if (t == 1) {\n    \
    \        int l, r;\n            long long x;\n            cin >> l >> r >> x;\n\
    \            cout << sgt.query(l, r - 1)(x) % MOD << '\\n';\n        }\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"geometry/line.hpp\"\
    \n#include \"data-structure/recursive-segment-tree.hpp\"\n\nconst int MAX = 5e5\
    \ + 5;\nconst long long MOD = 998244353;\n\ntemplate<typename T>\nline<T> operator+(const\
    \ line<T> &l1, const line<T> &l2) { \n    return line<T>(l1.m * l2.m % MOD, (l1.b\
    \ * l2.m + l2.b) % MOD);\n}\n\nint N, Q;\nline<long long> A[MAX];\nsegtree<line<long\
    \ long>> sgt;\n\nint main() {\n    cin >> N >> Q;\n    for (int i = 0; i < N;\
    \ i++) {\n        long long m, b; \n        cin >> m >> b;\n        A[i] = line<long\
    \ long>(m, b);\n    }\n\n    sgt = segtree<line<long long>>(A, A + N);\n    sgt.dval\
    \ = line<long long>(1, 0);\n\n    while (Q--) {\n        int t; \n        cin\
    \ >> t;\n        if (t == 0) {\n            int i;\n            long long m, b;\n\
    \            cin >> i >> m >> b;\n            sgt.update(i, line<long long>(m,\
    \ b));\n        } else if (t == 1) {\n            int l, r;\n            long\
    \ long x;\n            cin >> l >> r >> x;\n            cout << sgt.query(l, r\
    \ - 1)(x) % MOD << '\\n';\n        }\n    }\n}"
  dependsOn:
  - geometry/line.hpp
  - data-structure/recursive-segment-tree.hpp
  isVerificationFile: true
  path: verify/data-structure/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp
  requiredBy: []
  timestamp: '2022-01-02 09:57:58-08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/data-structure/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp
layout: document
redirect_from:
- /verify/verify/data-structure/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp
- /verify/verify/data-structure/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp.html
title: verify/data-structure/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp
---
