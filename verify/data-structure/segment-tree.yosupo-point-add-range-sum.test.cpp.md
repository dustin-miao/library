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
    \nclass segtree {\n\tusing T = long long;\n\n\tconst static T dval = T();\n\n\t\
    static T merge(const T &a, const T &b) { return a + b; }\n\n\tstatic void apply(T\
    \ &a, const T &b) { a += b; }\n\n\tint n;\n\tvector<T> tree;\n\npublic:\n\tvoid\
    \ init(int _n) {\n\t\tn = _n;\n\t\ttree.assign(2 * n, dval);\n\t\tfor (int i =\
    \ n - 1; i > 0; i--)\n\t\t\ttree[i] = merge(tree[i << 1], tree[i << 1 | 1]);\n\
    \t}\n\n\ttemplate<typename Iterator>\n\tvoid init(Iterator begin, Iterator end)\
    \ {\n\t\tn = distance(begin, end);\n\t\ttree.resize(2 * n);\n\t\tfor (int i =\
    \ n; i < 2 * n; i++, begin++)\n\t\t\ttree[i] = *begin;\n\t\tfor (int i = n - 1;\
    \ i > 0; i--)\n\t\t\ttree[i] = merge(tree[i << 1], tree[i << 1 | 1]);\n\t}\n\n\
    \tvoid update(int i, T v) {\n\t\tfor (apply(tree[i += n], v); i > 1; i >>= 1)\n\
    \t\t\ttree[i >> 1] = merge(tree[i], tree[i ^ 1]);\n\t}\n\n\tT query(int l, int\
    \ r) {\n\t\tT ret = segtree::dval;\n\t\tfor (l += n, r += n + 1; l < r; l >>=\
    \ 1, r >>= 1) {\n\t\t\tif (l & 1) ret = merge(ret, tree[l++]);\n\t\t\tif (r &\
    \ 1) ret = merge(ret, tree[--r]);\n\t\t}\n\t\treturn ret;\n\t}\n\n\tT operator[](int\
    \ i) { return tree[i += n]; }\n};\n#line 7 \"verify/data-structure/segment-tree.yosupo-point-add-range-sum.test.cpp\"\
    \n\nconst int MAX = 5e5 + 5;\n\nint N, Q;\nlong long A[MAX];\nsegtree sgt;\n\n\
    int main() {\n\tcin >> N >> Q;\n\tfor (int i = 0; i < N; i++)\n\t\tcin >> A[i];\n\
    \tsgt.init(A, A + N);\n\twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0)\
    \ {\n\t\t\tint p; long long x;\n\t\t\tcin >> p >> x;\n\t\t\tsgt.update(p, x);\n\
    \t\t} else {\n\t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\t\t\tcout << sgt.query(l,\
    \ r - 1) << '\\n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/segment-tree.hpp\"\
    \n\nconst int MAX = 5e5 + 5;\n\nint N, Q;\nlong long A[MAX];\nsegtree sgt;\n\n\
    int main() {\n\tcin >> N >> Q;\n\tfor (int i = 0; i < N; i++)\n\t\tcin >> A[i];\n\
    \tsgt.init(A, A + N);\n\twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0)\
    \ {\n\t\t\tint p; long long x;\n\t\t\tcin >> p >> x;\n\t\t\tsgt.update(p, x);\n\
    \t\t} else {\n\t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\t\t\tcout << sgt.query(l,\
    \ r - 1) << '\\n';\n\t\t}\n\t}\n}\n"
  dependsOn:
  - data-structure/segment-tree.hpp
  isVerificationFile: true
  path: verify/data-structure/segment-tree.yosupo-point-add-range-sum.test.cpp
  requiredBy: []
  timestamp: '2022-01-05 09:09:47-08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data-structure/segment-tree.yosupo-point-add-range-sum.test.cpp
layout: document
redirect_from:
- /verify/verify/data-structure/segment-tree.yosupo-point-add-range-sum.test.cpp
- /verify/verify/data-structure/segment-tree.yosupo-point-add-range-sum.test.cpp.html
title: verify/data-structure/segment-tree.yosupo-point-add-range-sum.test.cpp
---
