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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D
  bundledCode: "#line 1 \"verify/sparse-segment-tree.aizu-the-number-of-inversions.test.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/sparse-segment-tree.hpp\"\
    \ntemplate<class segment_tree_template>\nclass sparse_segment_tree : public segment_tree_template\
    \ {\n\tusing T = typename segment_tree_template::type;\n\tusing segment_tree_template::default_value;\n\
    \tusing segment_tree_template::merge;\n\tusing segment_tree_template::apply;\n\
    \nprotected:\n\tlong long n;\n\n\tstruct node {\n\t\tT v;\n\t\tlong long l, r;\n\
    \t\tnode() = default;\n\t\tnode(T _v, long long _l, long long _r) : v(_v), l(_l),\
    \ r(_r) {}\n\t};\n\n\tint root;\n\tvector<node> tree;\n\n\tint new_node() {\n\t\
    \ttree.emplace_back(default_value, -1, -1);\n\t\treturn tree.size() - 1;\n\t}\n\
    \nprivate:\n\tvoid update(long long i, T v, int t, long long tl, long long tr)\
    \ {\n\t\tif (tl == tr) {\n\t\t\tapply(tree[t].v, v);\n\t\t\treturn;\n\t\t}\n\t\
    \tlong long tm = (tl + tr) / 2;\n\t\tif (i <= tm) {\n\t\t\tif (tree[t].l == -1)\n\
    \t\t\t\ttree[t].l = new_node();\n\t\t\tupdate(i, v, tree[t].l, tl, tm);\n\t\t\
    } else {\n\t\t\tif (tree[t].r == -1)\n\t\t\t\ttree[t].r = new_node();\n\t\t\t\
    update(i, v, tree[t].r, tm + 1, tr);\n\t\t}\n\t\ttree[t].v = merge(tree[t].l ==\
    \ -1 ? default_value : tree[tree[t].l].v, \n\t\t\ttree[t].r == -1 ? default_value\
    \ : tree[tree[t].r].v);\n\t}\n\n\tT query(long long l, long long r, int t, long\
    \ long tl, long long tr) {\n\t\tif (r < tl || tr < l)\n\t\t\treturn default_value;\n\
    \t\tif (l <= tl && tr <= r)\n\t\t\treturn tree[t].v;\n\t\tlong long tm = (tl +\
    \ tr) / 2;\n\t\treturn merge(tree[t].l == -1 ? default_value : query(l, r, tree[t].l,\
    \ tl, tm), \n\t\t\ttree[t].r == -1 ? default_value : query(l, r, tree[t].r, tm\
    \ + 1, tr));\n\t}\n\npublic:\n\tsparse_segment_tree() = default;\n\n\tsparse_segment_tree(long\
    \ long _n) { init(_n); }\n\n\tvoid init(int _n) {\n\t\tn = _n;\n\t\troot = new_node();\n\
    \t}\n\n\tvoid reserve(int _n) { tree.reserve(_n); }\n\n\tvoid clear() { tree.clear();\
    \ }\n\n\tvoid update(long long i, T v) { update(i, v, root, 0, n - 1); }\n\n\t\
    T query(long long l, long long r) { return query(l, r, root, 0, n - 1); }\n};\n\
    #line 7 \"verify/sparse-segment-tree.aizu-the-number-of-inversions.test.cpp\"\n\
    \nconst int MAX = 1e9 + 5;\n\nint main() {\n\tint N;\n\tcin >> N;\n\n\tstruct\
    \ segment_tree_template {\n\t\tusing type = int;\n\t\tconst type default_value\
    \ = 0;\n\t\ttype merge(type a, type b) { return a + b; }\n\t\tvoid apply(type\
    \ &a, type b) { a += b; }\n\t};\n\n\tlong long ans = 0;\n\tsparse_segment_tree<segment_tree_template>\
    \ sgt(MAX);\n\tsgt.reserve(N * 30);\n\tfor (int i = 0; i < N; i++) {\n\t\tint\
    \ a; cin >> a;\n\t\tans += sgt.query(a, MAX - 1);\n\t\tsgt.update(a, 1);\n\t}\n\
    \tcout << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/sparse-segment-tree.hpp\"\
    \n\nconst int MAX = 1e9 + 5;\n\nint main() {\n\tint N;\n\tcin >> N;\n\n\tstruct\
    \ segment_tree_template {\n\t\tusing type = int;\n\t\tconst type default_value\
    \ = 0;\n\t\ttype merge(type a, type b) { return a + b; }\n\t\tvoid apply(type\
    \ &a, type b) { a += b; }\n\t};\n\n\tlong long ans = 0;\n\tsparse_segment_tree<segment_tree_template>\
    \ sgt(MAX);\n\tsgt.reserve(N * 30);\n\tfor (int i = 0; i < N; i++) {\n\t\tint\
    \ a; cin >> a;\n\t\tans += sgt.query(a, MAX - 1);\n\t\tsgt.update(a, 1);\n\t}\n\
    \tcout << ans << '\\n';\n}"
  dependsOn:
  - data-structure/sparse-segment-tree.hpp
  isVerificationFile: true
  path: verify/sparse-segment-tree.aizu-the-number-of-inversions.test.cpp
  requiredBy: []
  timestamp: '2022-04-24 16:17:38-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/sparse-segment-tree.aizu-the-number-of-inversions.test.cpp
layout: document
redirect_from:
- /verify/verify/sparse-segment-tree.aizu-the-number-of-inversions.test.cpp
- /verify/verify/sparse-segment-tree.aizu-the-number-of-inversions.test.cpp.html
title: verify/sparse-segment-tree.aizu-the-number-of-inversions.test.cpp
---
