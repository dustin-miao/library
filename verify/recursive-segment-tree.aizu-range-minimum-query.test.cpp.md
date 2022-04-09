---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/recursive-segment-tree.hpp
    title: Recursive Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
  bundledCode: "#line 1 \"verify/recursive-segment-tree.aizu-range-minimum-query.test.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/recursive-segment-tree.hpp\"\
    \ntemplate<class segment_tree_template>\nclass recursive_segment_tree : public\
    \ segment_tree_template {\n\tusing T = typename segment_tree_template::type;\n\
    \tusing segment_tree_template::default_value;\n\tusing segment_tree_template::merge;\n\
    \tusing segment_tree_template::apply;\n\nprotected:\n\tint n;\n\tvector<T> tree;\n\
    \nprivate:\n\tvoid update(int i, T v, int t, int tl, int tr) {\n\t\tif (tl ==\
    \ tr) {\n\t\t\tapply(tree[t], v);\n\t\t\treturn;\n\t\t}\n\t\tint tm = (tl + tr)\
    \ / 2;\n\t\tif (i <= tm)\n\t\t\tupdate(i, v, t * 2, tl, tm);\n\t\telse \n\t\t\t\
    update(i, v, t * 2 + 1, tm + 1, tr);\n\t\ttree[t] = merge(tree[t * 2], tree[t\
    \ * 2 + 1]);\n\t}\n\n\tT query(int l, int r, int t, int tl, int tr) {\n\t\tif\
    \ (r < tl || tr < l)\n\t\t\treturn default_value;\n\t\tif (l <= tl && tr <= r)\n\
    \t\t\treturn tree[t];\n\t\tint tm = (tl + tr) / 2;\n\t\treturn merge(query(l,\
    \ r, t * 2, tl, tm), query(l, r, t * 2 + 1, tm + 1, tr));\n\t}\n\npublic:\n\t\
    recursive_segment_tree() = default;\n\n\trecursive_segment_tree(int _n) { init(_n);\
    \ }\n\n\tvoid init(int _n) {\n\t\tn = _n;\n\t\ttree.assign(n * 4, default_value);\n\
    \t}\n\n\tvoid update(int i, T v) { update(i, v, 1, 0, n - 1); }\n\n\tT query(int\
    \ l, int r) { return query(l, r, 1, 0, n - 1); }\n};\n#line 7 \"verify/recursive-segment-tree.aizu-range-minimum-query.test.cpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\n\tstruct segment_tree_template\
    \ {\n\t\tusing type = long long;\n\t\tconst type default_value = LLONG_MAX;\n\t\
    \tvoid apply(type &a, type b) { a = b; }\n\t\ttype merge(type a, type b) { return\
    \ min(a, b); }\n\t};\n\n\trecursive_segment_tree<segment_tree_template> sgt(N);\n\
    \tfor (int i = 0; i < N; i++)\n\t\tsgt.update(i, INT_MAX);\n\twhile (Q--) {\n\t\
    \tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\tint i; long long v;\n\t\t\tcin >>\
    \ i >> v;\n\t\t\tsgt.update(i, v);\n\t\t} else if (t == 1) {\n\t\t\tint l, r;\n\
    \t\t\tcin >> l >> r;\n\t\t\tcout << sgt.query(l, r) << '\\n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/recursive-segment-tree.hpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\n\tstruct segment_tree_template\
    \ {\n\t\tusing type = long long;\n\t\tconst type default_value = LLONG_MAX;\n\t\
    \tvoid apply(type &a, type b) { a = b; }\n\t\ttype merge(type a, type b) { return\
    \ min(a, b); }\n\t};\n\n\trecursive_segment_tree<segment_tree_template> sgt(N);\n\
    \tfor (int i = 0; i < N; i++)\n\t\tsgt.update(i, INT_MAX);\n\twhile (Q--) {\n\t\
    \tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\tint i; long long v;\n\t\t\tcin >>\
    \ i >> v;\n\t\t\tsgt.update(i, v);\n\t\t} else if (t == 1) {\n\t\t\tint l, r;\n\
    \t\t\tcin >> l >> r;\n\t\t\tcout << sgt.query(l, r) << '\\n';\n\t\t}\n\t}\n}"
  dependsOn:
  - data-structure/recursive-segment-tree.hpp
  isVerificationFile: true
  path: verify/recursive-segment-tree.aizu-range-minimum-query.test.cpp
  requiredBy: []
  timestamp: '2022-04-09 15:55:38-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/recursive-segment-tree.aizu-range-minimum-query.test.cpp
layout: document
redirect_from:
- /verify/verify/recursive-segment-tree.aizu-range-minimum-query.test.cpp
- /verify/verify/recursive-segment-tree.aizu-range-minimum-query.test.cpp.html
title: verify/recursive-segment-tree.aizu-range-minimum-query.test.cpp
---
