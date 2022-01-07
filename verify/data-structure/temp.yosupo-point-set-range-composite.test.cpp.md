---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/general-segment-tree.hpp
    title: Segment Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"verify/data-structure/temp.yosupo-point-set-range-composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"geometry/line.hpp\"\
    \ntemplate<typename T>\nstruct line {\n    T m, b;\n\n    constexpr line() = default;\n\
    \n    constexpr line(T _m, T _b) : m(_m), b(_b) {};\n\n    T operator()(T x) {\
    \ return m * x + b; }\n\n    friend double intersect(const line &l1, const line\
    \ &l2) { \n        return (double)(l1.b - l2.b) / (double)(l2.m - l1.m); \n  \
    \  }\n\n    friend ostream &operator<<(ostream &os, const line &l) { \n      \
    \  return os << \"y = \" << l.m << \"x + \" << l.b; \n    }\n};\n#line 7 \"verify/data-structure/temp.yosupo-point-set-range-composite.test.cpp\"\
    \n\n#line 1 \"data-structure/general-segment-tree.hpp\"\ntemplate<typename T,\
    \ typename merge_t, typename apply_t, T dval = T{}>\nclass segtree {\n\tint n;\n\
    \tvector<T> tree;\n\n\tmerge_t merge;\n\tapply_t apply;\n\npublic:\n\tsegtree(merge_t\
    \ _merge, apply_t _apply) : merge(_merge), apply(_apply) {}\n\n\tvoid init(int\
    \ _n) {\n\t\tn = _n;\n\t\ttree.assign(2 * n, dval);\n\t\tfor (int i = n - 1; i\
    \ > 0; i--)\n\t\t\ttree[i] = merge(tree[i << 1], tree[i << 1 | 1]);\n\t}\n\n\t\
    template<typename Iterator>\n\tvoid init(Iterator begin, Iterator end) {\n\t\t\
    n = distance(begin, end);\n\t\ttree.resize(2 * n);\n\t\tfor (int i = n; i < 2\
    \ * n; i++, begin++)\n\t\t\ttree[i] = *begin;\n\t\tfor (int i = n - 1; i > 0;\
    \ i--)\n\t\t\ttree[i] = merge(tree[i << 1], tree[i << 1 | 1]);\n\t}\n\n    void\
    \ update(int i, T v) {\n\t\tfor (apply(tree[i += n], v); i > 1; i >>= 1)\n\t\t\
    \ttree[i >> 1] = merge(tree[i], tree[i ^ 1]);\n\t}\n\n\tT query(int l, int r)\
    \ {\n\t\tT ret = dval;\n\t\tfor (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)\
    \ {\n\t\t\tif (l & 1) ret = merge(ret, tree[l++]);\n\t\t\tif (r & 1) ret = merge(ret,\
    \ tree[--r]);\n\t\t}\n\t\treturn ret;\n\t}\n\n\tT operator[](int i) { return tree[i\
    \ += n]; }\n};\n#line 9 \"verify/data-structure/temp.yosupo-point-set-range-composite.test.cpp\"\
    \n\nconst int MAX = 5e5 + 5;\nconst long long MOD = 998244353;\n\nauto merge =\
    \ [](const line<long long> &l1, const line<long long> &l2) {\n    return line<long\
    \ long>(l1.m * l2.m % MOD, (l1.b * l2.m + l2.b) % MOD);\n};\n\nauto apply = [](line<long\
    \ long> &l1, const line<long long> &l2) { l1 = l2; }\n\nint N, Q;\nline<long long>\
    \ A[MAX];\nsegtree<line<long long>, decltype(merge), decltype(apply), line<long\
    \ long>(1, 0)> sgt(merge, apply);\n\nint main() {\n    cin >> N >> Q;\n    for\
    \ (int i = 0; i < N; i++) {\n        long long m, b; \n        cin >> m >> b;\n\
    \        A[i] = line<long long>(m, b);\n    }\n\n    sgt = segtree<line<long long>>(A,\
    \ A + N);\n    sgt.dval = line<long long>(1, 0);\n\n    while (Q--) {\n      \
    \  int t; \n        cin >> t;\n        if (t == 0) {\n            int i;\n   \
    \         long long m, b;\n            cin >> i >> m >> b;\n            sgt.update(i,\
    \ line<long long>(m, b));\n        } else if (t == 1) {\n            int l, r;\n\
    \            long long x;\n            cin >> l >> r >> x;\n            cout <<\
    \ sgt.query(l, r - 1)(x) % MOD << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"geometry/line.hpp\"\
    \n\n#include \"data-structure/general-segment-tree.hpp\"\n\nconst int MAX = 5e5\
    \ + 5;\nconst long long MOD = 998244353;\n\nauto merge = [](const line<long long>\
    \ &l1, const line<long long> &l2) {\n    return line<long long>(l1.m * l2.m %\
    \ MOD, (l1.b * l2.m + l2.b) % MOD);\n};\n\nauto apply = [](line<long long> &l1,\
    \ const line<long long> &l2) { l1 = l2; }\n\nint N, Q;\nline<long long> A[MAX];\n\
    segtree<line<long long>, decltype(merge), decltype(apply), line<long long>(1,\
    \ 0)> sgt(merge, apply);\n\nint main() {\n    cin >> N >> Q;\n    for (int i =\
    \ 0; i < N; i++) {\n        long long m, b; \n        cin >> m >> b;\n       \
    \ A[i] = line<long long>(m, b);\n    }\n\n    sgt = segtree<line<long long>>(A,\
    \ A + N);\n    sgt.dval = line<long long>(1, 0);\n\n    while (Q--) {\n      \
    \  int t; \n        cin >> t;\n        if (t == 0) {\n            int i;\n   \
    \         long long m, b;\n            cin >> i >> m >> b;\n            sgt.update(i,\
    \ line<long long>(m, b));\n        } else if (t == 1) {\n            int l, r;\n\
    \            long long x;\n            cin >> l >> r >> x;\n            cout <<\
    \ sgt.query(l, r - 1)(x) % MOD << '\\n';\n        }\n    }\n}"
  dependsOn:
  - geometry/line.hpp
  - data-structure/general-segment-tree.hpp
  isVerificationFile: true
  path: verify/data-structure/temp.yosupo-point-set-range-composite.test.cpp
  requiredBy: []
  timestamp: '2022-01-07 08:20:28-08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/data-structure/temp.yosupo-point-set-range-composite.test.cpp
layout: document
redirect_from:
- /verify/verify/data-structure/temp.yosupo-point-set-range-composite.test.cpp
- /verify/verify/data-structure/temp.yosupo-point-set-range-composite.test.cpp.html
title: verify/data-structure/temp.yosupo-point-set-range-composite.test.cpp
---
