---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/sparse-segment-tree.hpp
    title: Sparse Segment Tree
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
  bundledCode: "#line 1 \"verify/sparse-segment-tree.aizu-range-minimum-query.test.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/sparse-segment-tree.hpp\"\
    \n#pragma region sparse_segment_tree\n\ntemplate<class segment_tree_template>\n\
    class sparse_segment_tree : public segment_tree_template {\n\tusing T = typename\
    \ segment_tree_template::type;\n\tusing segment_tree_template::default_value;\n\
    \tusing segment_tree_template::merge;\n\tusing segment_tree_template::apply;\n\
    \nprotected:\n\tlong long n;\n\n\tstruct node {\n\t\tT v;\n\t\tint l, r;\n\t\t\
    node() = default;\n\t\tnode(T _v, int  _l, int _r) : v(_v), l(_l), r(_r) {}\n\t\
    };\n\n\tint root;\n\tvector<node> tree;\n\n\tint new_node() {\n\t\ttree.emplace_back(default_value,\
    \ -1, -1);\n\t\treturn tree.size() - 1;\n\t}\n\nprivate:\n\tvoid update(long long\
    \ i, T v, int t, long long tl, long long tr) {\n\t\tif (tl == tr) {\n\t\t\tapply(tree[t].v,\
    \ v);\n\t\t\treturn;\n\t\t}\n\t\tlong long tm = (tl + tr) / 2;\n\t\tif (i <= tm)\
    \ {\n\t\t\tif (tree[t].l == -1)\n\t\t\t\ttree[t].l = new_node();\n\t\t\tupdate(i,\
    \ v, tree[t].l, tl, tm);\n\t\t} else {\n\t\t\tif (tree[t].r == -1)\n\t\t\t\ttree[t].r\
    \ = new_node();\n\t\t\tupdate(i, v, tree[t].r, tm + 1, tr);\n\t\t}\n\t\ttree[t].v\
    \ = merge(tree[t].l == -1 ? default_value : tree[tree[t].l].v, \n\t\t\ttree[t].r\
    \ == -1 ? default_value : tree[tree[t].r].v);\n\t}\n\n\tT query(long long l, long\
    \ long r, int t, long long tl, long long tr) {\n\t\tif (r < tl || tr < l)\n\t\t\
    \treturn default_value;\n\t\tif (l <= tl && tr <= r)\n\t\t\treturn tree[t].v;\n\
    \t\tlong long tm = (tl + tr) / 2;\n\t\treturn merge(tree[t].l == -1 ? default_value\
    \ : query(l, r, tree[t].l, tl, tm), \n\t\t\ttree[t].r == -1 ? default_value :\
    \ query(l, r, tree[t].r, tm + 1, tr));\n\t}\n\npublic:\n\tsparse_segment_tree()\
    \ = default;\n\n\tsparse_segment_tree(long long _n) { init(_n); }\n\n\tvoid init(int\
    \ _n) {\n\t\tn = _n;\n\t\troot = new_node();\n\t}\n\n\tvoid reserve(int _n) {\
    \ tree.reserve(_n); }\n\n\tvoid clear() { tree.clear(); }\n\n\tvoid update(long\
    \ long i, T v) { update(i, v, root, 0, n - 1); }\n\n\tT query(long long l, long\
    \ long r) { return query(l, r, root, 0, n - 1); }\n};\n\n#pragma endregion sparse_segment_tree\n\
    #line 7 \"verify/sparse-segment-tree.aizu-range-minimum-query.test.cpp\"\n\nint\
    \ main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\n\tstruct segment_tree_template {\n\
    \t\tusing type = long long;\n\t\tconst type default_value = LLONG_MAX;\n\t\tvoid\
    \ apply(type &a, type b) { a = b; }\n\t\ttype merge(type a, type b) { return min(a,\
    \ b); }\n\t};\n\n\tsparse_segment_tree<segment_tree_template> sgt(N);\n\tsgt.reserve(N\
    \ * 4);\n\tfor (int i = 0; i < N; i++)\n\t\tsgt.update(i, INT_MAX);\n\twhile (Q--)\
    \ {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\tint i; long long v;\n\t\t\t\
    cin >> i >> v;\n\t\t\tsgt.update(i, v);\n\t\t} else if (t == 1) {\n\t\t\tint l,\
    \ r;\n\t\t\tcin >> l >> r;\n\t\t\tcout << sgt.query(l, r) << '\\n';\n\t\t}\n\t\
    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/sparse-segment-tree.hpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\n\tstruct segment_tree_template\
    \ {\n\t\tusing type = long long;\n\t\tconst type default_value = LLONG_MAX;\n\t\
    \tvoid apply(type &a, type b) { a = b; }\n\t\ttype merge(type a, type b) { return\
    \ min(a, b); }\n\t};\n\n\tsparse_segment_tree<segment_tree_template> sgt(N);\n\
    \tsgt.reserve(N * 4);\n\tfor (int i = 0; i < N; i++)\n\t\tsgt.update(i, INT_MAX);\n\
    \twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\tint i; long long\
    \ v;\n\t\t\tcin >> i >> v;\n\t\t\tsgt.update(i, v);\n\t\t} else if (t == 1) {\n\
    \t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\t\t\tcout << sgt.query(l, r) << '\\n';\n\
    \t\t}\n\t}\n}"
  dependsOn:
  - data-structure/sparse-segment-tree.hpp
  isVerificationFile: true
  path: verify/sparse-segment-tree.aizu-range-minimum-query.test.cpp
  requiredBy: []
  timestamp: '2022-05-03 12:34:00-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/sparse-segment-tree.aizu-range-minimum-query.test.cpp
layout: document
redirect_from:
- /verify/verify/sparse-segment-tree.aizu-range-minimum-query.test.cpp
- /verify/verify/sparse-segment-tree.aizu-range-minimum-query.test.cpp.html
title: verify/sparse-segment-tree.aizu-range-minimum-query.test.cpp
---
