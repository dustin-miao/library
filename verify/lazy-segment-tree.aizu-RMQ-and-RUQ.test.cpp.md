---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/lazy-segment-tree.hpp
    title: Lazy Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
  bundledCode: "#line 1 \"verify/lazy-segment-tree.aizu-RMQ-and-RUQ.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/lazy-segment-tree.hpp\"\
    \ntemplate<class segment_tree_template>\nclass lazy_segment_tree : public segment_tree_template\
    \ {\n\tusing T = typename segment_tree_template::node_type;\n\tusing L = typename\
    \ segment_tree_template::lazy_type;\n\tusing segment_tree_template::node_default_value;\n\
    \tusing segment_tree_template::lazy_default_value;\n\tusing segment_tree_template::merge;\n\
    \tusing segment_tree_template::apply;\n\nprotected:\n\tint n;\n\tvector<T> tree;\n\
    \tvector<L> lazy;\n\nprivate:\n\tvoid pushdown(int t, int tl, int tr) {\n\t\t\
    if (lazy[t] == lazy_default_value)\n\t\t\treturn;\n\t\tint tm = (tl + tr) / 2;\n\
    \t\tapply(tree[t * 2], lazy[t * 2], lazy[t], tl, tm);\n\t\tapply(tree[t * 2 +\
    \ 1], lazy[t * 2 + 1], lazy[t], tm + 1, tr);\n\t\tlazy[t] = lazy_default_value;\n\
    \t}\n\n\tvoid update(int l, int r, L v, int t, int tl, int tr) {\n\t\tif (r <\
    \ tl || tr < l)\n\t\t\treturn;\n\t\tif (l <= tl && tr <= r) {\n\t\t\tapply(tree[t],\
    \ lazy[t], v, tl, tr);\n\t\t\treturn;\n\t\t}\n\t\tpushdown(t, tl, tr);\n\t\tint\
    \ tm = (tl + tr) / 2;\n\t\tupdate(l, r, v, t * 2, tl, tm);\n\t\tupdate(l, r, v,\
    \ t * 2 + 1, tm + 1, tr);\n\t\ttree[t] = merge(tree[t * 2], tree[t * 2 + 1]);\n\
    \t}\n\n\tT query(int l, int r, int t, int tl, int tr) {\n\t\tif (r < tl || tr\
    \ < l)\n\t\t\treturn node_default_value;\n\t\tif (l <= tl && tr <= r)\n\t\t\t\
    return tree[t];\n\t\tpushdown(t, tl, tr);\n\t\tint tm = (tl + tr) / 2;\n\t\treturn\
    \ merge(query(l, r, t * 2, tl, tm), query(l, r, t * 2 + 1, tm + 1, tr));\n\t}\n\
    \npublic:\n\tlazy_segment_tree() = default;\n\n\tlazy_segment_tree(int _n) { init(_n);\
    \ }\n\n\tvoid init(int _n) {\n\t\tn = _n;\n\t\ttree.assign(4 * n, node_default_value);\n\
    \t\tlazy.assign(4 * n, lazy_default_value);\n\t}\n\n\tvoid update(int l, int r,\
    \ L v) { update(l, r, v, 1, 0, n - 1); }\n\n\tT query(int l, int r) { return query(l,\
    \ r, 1, 0, n - 1); }\n};\n#line 7 \"verify/lazy-segment-tree.aizu-RMQ-and-RUQ.test.cpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\n\tstruct segment_tree_template\
    \ {\n\t\tusing node_type = long long;\n\t\tusing lazy_type = long long;\n\n\t\t\
    const node_type node_default_value = LLONG_MAX;\n\t\tconst lazy_type lazy_default_value\
    \ = LLONG_MAX;\n\n\t\tvoid apply(node_type &a, lazy_type &b, lazy_type c, int\
    \ l, int r) {\n\t\t\ta = c;\n\t\t\tb = c;\n\t\t}\n\n\t\tnode_type merge(node_type\
    \ a, node_type b) { return min(a, b); }\n\t};\n\n\tlazy_segment_tree<segment_tree_template>\
    \ sgt(N);\n\tfor (int i = 0; i < N; i++) \n\t\tsgt.update(i, i, INT_MAX);\n\t\
    while (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\tint l, r; long long\
    \ v;\n\t\t\tcin >> l >> r >> v;\n\t\t\tsgt.update(l, r, v);\n\t\t} else if (t\
    \ == 1) {\n\t\t\tint l, r; \n\t\t\tcin >> l >> r;\n\t\t\tcout << sgt.query(l,\
    \ r) << '\\n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/lazy-segment-tree.hpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\n\tstruct segment_tree_template\
    \ {\n\t\tusing node_type = long long;\n\t\tusing lazy_type = long long;\n\n\t\t\
    const node_type node_default_value = LLONG_MAX;\n\t\tconst lazy_type lazy_default_value\
    \ = LLONG_MAX;\n\n\t\tvoid apply(node_type &a, lazy_type &b, lazy_type c, int\
    \ l, int r) {\n\t\t\ta = c;\n\t\t\tb = c;\n\t\t}\n\n\t\tnode_type merge(node_type\
    \ a, node_type b) { return min(a, b); }\n\t};\n\n\tlazy_segment_tree<segment_tree_template>\
    \ sgt(N);\n\tfor (int i = 0; i < N; i++) \n\t\tsgt.update(i, i, INT_MAX);\n\t\
    while (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\tint l, r; long long\
    \ v;\n\t\t\tcin >> l >> r >> v;\n\t\t\tsgt.update(l, r, v);\n\t\t} else if (t\
    \ == 1) {\n\t\t\tint l, r; \n\t\t\tcin >> l >> r;\n\t\t\tcout << sgt.query(l,\
    \ r) << '\\n';\n\t\t}\n\t}\n}"
  dependsOn:
  - data-structure/lazy-segment-tree.hpp
  isVerificationFile: true
  path: verify/lazy-segment-tree.aizu-RMQ-and-RUQ.test.cpp
  requiredBy: []
  timestamp: '2022-04-09 15:55:38-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/lazy-segment-tree.aizu-RMQ-and-RUQ.test.cpp
layout: document
redirect_from:
- /verify/verify/lazy-segment-tree.aizu-RMQ-and-RUQ.test.cpp
- /verify/verify/lazy-segment-tree.aizu-RMQ-and-RUQ.test.cpp.html
title: verify/lazy-segment-tree.aizu-RMQ-and-RUQ.test.cpp
---
