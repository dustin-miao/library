---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segment-tree-beats.hpp
    title: Segment Tree Beats
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
  bundledCode: "#line 1 \"verify/segment-tree-beats.yosupo-range-chmin-chmax-range-sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/segment-tree-beats.hpp\"\
    \nclass segment_tree_beats {\nprotected:\n\tint n;\n\n\tstruct node { \n\t\tlong\
    \ long sum, max1, max2, maxc, min1, min2, minc, lazy; \n\t};\n\n\tvector<node>\
    \ tree;\n\nprivate:\n\tvoid merge(int t) {\n\t\t// sum\n\t\ttree[t].sum = tree[t\
    \ * 2].sum + tree[t * 2 + 1].sum;\n\n\t\t// max\n\t\tif (tree[t * 2].max1 == tree[t\
    \ * 2 + 1].max1) {\n\t\t\ttree[t].max1 = tree[t * 2].max1;\n\t\t\ttree[t].max2\
    \ = max(tree[t * 2].max2, tree[t * 2 + 1].max2);\n\t\t\ttree[t].maxc = tree[t\
    \ * 2].maxc + tree[t * 2 + 1].maxc;\n\t\t}\n\t\telse {\n\t\t\tif (tree[t * 2].max1\
    \ > tree[t * 2 + 1].max1) {\n\t\t\t\ttree[t].max1 = tree[t * 2].max1;\n\t\t\t\t\
    tree[t].max2 = max(tree[t * 2].max2, tree[t * 2 + 1].max1);\n\t\t\t\ttree[t].maxc\
    \ = tree[t * 2].maxc;\n\t\t\t}\n\t\t\telse {\n\t\t\t\ttree[t].max1 = tree[t *\
    \ 2 + 1].max1;\n\t\t\t\ttree[t].max2 = max(tree[t * 2].max1, tree[t * 2 + 1].max2);\n\
    \t\t\t\ttree[t].maxc = tree[t * 2 + 1].maxc;\n\t\t\t}\n\t\t}\n\n\t\t// min\n\t\
    \tif (tree[t * 2].min1 == tree[t * 2 + 1].min1) {\n\t\t\ttree[t].min1 = tree[t\
    \ * 2].min1;\n\t\t\ttree[t].min2 = min(tree[t * 2].min2, tree[t * 2 + 1].min2);\n\
    \t\t\ttree[t].minc = tree[t * 2].minc + tree[t * 2 + 1].minc;\n\t\t}\n\t\telse\
    \ {\n\t\t\tif (tree[t * 2].min1 < tree[t * 2 + 1].min1) {\n\t\t\t\ttree[t].min1\
    \ = tree[t * 2].min1;\n\t\t\t\ttree[t].min2 = min(tree[t * 2].min2, tree[t * 2\
    \ + 1].min1);\n\t\t\t\ttree[t].minc = tree[t * 2].minc;\n\t\t\t}\n\t\t\telse {\n\
    \t\t\t\ttree[t].min1 = tree[t * 2 + 1].min1;\n\t\t\t\ttree[t].min2 = min(tree[t\
    \ * 2].min1, tree[t * 2 + 1].min2);\n\t\t\t\ttree[t].minc = tree[t * 2 + 1].minc;\n\
    \t\t\t}\n\t\t}\n\t}\n\n\tvoid push_add(int t, int tl, int tr, long long v) {\n\
    \t\tif (v == 0)\n\t\t\treturn;\n\t\ttree[t].sum += (tr - tl + 1) *v;\n\t\ttree[t].max1\
    \ += v;\n\t\tif (tree[t].max2 != LLONG_MIN)\n\t\t\ttree[t].max2 += v;\n\t\ttree[t].min1\
    \ += v;\n\t\tif (tree[t].min2 != LLONG_MAX)\n\t\t\ttree[t].min2 += v;\n\t\ttree[t].lazy\
    \ += v;\n\t}\n\n\t// corresponds to a chmin update\n\tvoid push_max(int t, long\
    \ long v, bool l) {\n\t\tif (v >= tree[t].max1)\n\t\t\treturn;\n\t\ttree[t].sum\
    \ -= tree[t].max1 * tree[t].maxc;\n\t\ttree[t].max1 = v;\n\t\ttree[t].sum += tree[t].max1\
    \ * tree[t].maxc;\n\t\tif (l) \n\t\t\ttree[t].min1 = tree[t].max1;\n\t\telse {\n\
    \t\t\tif (v <= tree[t].min1)\n\t\t\t\ttree[t].min1 = v;\n\t\t\telse if (v < tree[t].min2)\n\
    \t\t\t\ttree[t].min2 = v;\n\t\t}\n\t}\n\n\t// corresponds to a chmax update\n\t\
    void push_min(int t, long long v, bool l) {\n\t\tif (v <= tree[t].min1)\n\t\t\t\
    return;\n\t\ttree[t].sum -= tree[t].min1 * tree[t].minc;\n\t\ttree[t].min1 = v;\n\
    \t\ttree[t].sum += tree[t].min1 * tree[t].minc;\n\t\tif (l)\n\t\t\ttree[t].max1\
    \ = tree[t].min1;\n\t\telse {\n\t\t\tif (v >= tree[t].max1)\n\t\t\t\ttree[t].max1\
    \ = v;\n\t\t\telse if (v > tree[t].max2)\n\t\t\t\ttree[t].max2 = v;\n\t\t}\n\t\
    }\n\n\tvoid pushdown(int t, int tl, int tr) {\n\t\tif (tl == tr)\n\t\t\treturn;\n\
    \t\t// sum\n\t\tint tm = (tl + tr) / 2;\n\t\tpush_add(t * 2, tl, tm, tree[t].lazy);\n\
    \t\tpush_add(t * 2 + 1, tm + 1, tr, tree[t].lazy);\n\t\ttree[t].lazy = 0;\n\n\t\
    \t// max\n\t\tpush_max(t * 2, tree[t].max1, tl == tm);\n\t\tpush_max(t * 2 + 1,\
    \ tree[t].max1, tm + 1 == tr);\n\n\t\t// min\n\t\tpush_min(t * 2, tree[t].min1,\
    \ tl == tm);\n\t\tpush_min(t * 2 + 1, tree[t].min1, tm + 1 == tr);\n\t}\n\n\t\
    void build(int t, int tl, int tr) {\n\t\ttree[t].lazy = 0;\n\t\tif (tl == tr)\
    \ {\n\t\t\ttree[t].sum = tree[t].max1 = tree[t].min1 = 0;\n\t\t\ttree[t].maxc\
    \ = tree[t].minc = 1;\n\t\t\ttree[t].max2 = LLONG_MIN;\n\t\t\ttree[t].min2 = LLONG_MAX;\n\
    \t\t\treturn;\n\t\t}\n\n\t\tint tm = (tl + tr) / 2;\n\t\tbuild(t * 2, tl, tm);\n\
    \t\tbuild(t * 2 + 1, tm + 1, tr);\n\t\tmerge(t);\n\t}\n\n\tvoid update_add(int\
    \ l, int r, long long v, int t, int tl, int tr) {\n\t\tif (r < tl || tr < l)\n\
    \t\t\treturn;\n\t\tif (l <= tl && tr <= r) {\n\t\t\tpush_add(t, tl, tr, v);\n\t\
    \t\treturn;\n\t\t}\n\t\tpushdown(t, tl, tr);\n\n\t\tint tm = (tl + tr) / 2;\n\t\
    \tupdate_add(l, r, v, t * 2, tl, tm);\n\t\tupdate_add(l, r, v, t * 2 + 1, tm +\
    \ 1, tr);\n\t\tmerge(t);\n\t}\n\n\tvoid update_chmin(int l, int r, long long v,\
    \ int t, int tl, int tr) {\n\t\tif (r < tl || tr < l || v >= tree[t].max1)\n\t\
    \t\treturn;\n\t\tif (l <= tl && tr <= r && v > tree[t].max2) {\n\t\t\tpush_max(t,\
    \ v, tl == tr);\n\t\t\treturn;\n\t\t}\n\t\tpushdown(t, tl, tr);\n\n\t\tint tm\
    \ = (tl + tr) / 2;\n\t\tupdate_chmin(l, r, v, t * 2, tl, tm);\n\t\tupdate_chmin(l,\
    \ r, v, t * 2 + 1, tm + 1, tr);\n\t\tmerge(t);\n\t}\n\n\tvoid update_chmax(int\
    \ l, int r, long long v, int t, int tl, int tr) {\n\t\tif (r < tl || tr < l ||\
    \ v <= tree[t].min1)\n\t\t\treturn;\n\t\tif (l <= tl && tr <= r && v < tree[t].min2)\
    \ {\n\t\t\tpush_min(t, v, tl == tr);\n\t\t\treturn;\n\t\t}\n\t\tpushdown(t, tl,\
    \ tr);\n\n\t\tint tm = (tl + tr) / 2;\n\t\tupdate_chmax(l, r, v, t * 2, tl, tm);\n\
    \t\tupdate_chmax(l, r, v, t * 2 + 1, tm + 1, tr);\n\t\tmerge(t);\n\t}\n\n\tlong\
    \ long query(int l, int r, int t, int tl, int tr) {\n\t\tif (r < tl || tr < l)\n\
    \t\t\treturn 0;\n\t\tif (l <= tl && tr <= r)\n\t\t\treturn tree[t].sum;\n\t\t\
    pushdown(t, tl, tr);\n\n\t\tint tm = (tl + tr) / 2;\n\t\treturn query(l, r, t\
    \ * 2, tl, tm) + query(l, r, t * 2 + 1, tm + 1, tr);\n\t}\n\npublic:\n\tsegment_tree_beats()\
    \ = default;\n\n\tsegment_tree_beats(int _n) { init(_n); }\n\n\tvoid init(int\
    \ _n) {\n\t\tn = _n;\n\t\ttree.resize(n * 4);\n\t\tbuild();\n\t}\n\n\tvoid build()\
    \ { build(1, 0, n - 1); }\n\n\tvoid update_add(int l, int r, long long v) { update_add(l,\
    \ r, v, 1, 0, n - 1); }\n\n\tvoid update_chmin(int l, int r, long long v) { update_chmin(l,\
    \ r, v, 1, 0, n - 1); }\n\n\tvoid update_chmax(int l, int r, long long v) { update_chmax(l,\
    \ r, v, 1, 0, n - 1); }\n\n\tlong long query(int l, int r) { return query(l, r,\
    \ 1, 0, n - 1); }\n};\n#line 7 \"verify/segment-tree-beats.yosupo-range-chmin-chmax-range-sum.test.cpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\tsegment_tree_beats stb(N);\n\
    \tfor (int i = 0; i < N; i++) {\n\t\tlong long a; cin >> a;\n\t\tstb.update_add(i,\
    \ i, a);\n\t}\n\twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\t\
    int l, r; long long v;\n\t\t\tcin >> l >> r >> v;\n\t\t\tstb.update_chmin(l, r\
    \ - 1, v);\n\t\t} else if (t == 1) {\n\t\t\tint l, r; long long v;\n\t\t\tcin\
    \ >> l >> r >> v;\n\t\t\tstb.update_chmax(l, r - 1, v);\n\t\t} else if (t == 2)\
    \ {\n\t\t\tint l, r; long long v;\n\t\t\tcin >> l >> r >> v;\n\t\t\tstb.update_add(l,\
    \ r - 1, v);\n\t\t} else if (t == 3) {\n\t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\
    \t\t\tcout << stb.query(l, r - 1) << '\\n';\n\t\t}\t\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/segment-tree-beats.hpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\tsegment_tree_beats stb(N);\n\
    \tfor (int i = 0; i < N; i++) {\n\t\tlong long a; cin >> a;\n\t\tstb.update_add(i,\
    \ i, a);\n\t}\n\twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\t\
    int l, r; long long v;\n\t\t\tcin >> l >> r >> v;\n\t\t\tstb.update_chmin(l, r\
    \ - 1, v);\n\t\t} else if (t == 1) {\n\t\t\tint l, r; long long v;\n\t\t\tcin\
    \ >> l >> r >> v;\n\t\t\tstb.update_chmax(l, r - 1, v);\n\t\t} else if (t == 2)\
    \ {\n\t\t\tint l, r; long long v;\n\t\t\tcin >> l >> r >> v;\n\t\t\tstb.update_add(l,\
    \ r - 1, v);\n\t\t} else if (t == 3) {\n\t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\
    \t\t\tcout << stb.query(l, r - 1) << '\\n';\n\t\t}\t\n\t}\n}"
  dependsOn:
  - data-structure/segment-tree-beats.hpp
  isVerificationFile: true
  path: verify/segment-tree-beats.yosupo-range-chmin-chmax-range-sum.test.cpp
  requiredBy: []
  timestamp: '2022-04-09 15:55:38-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/segment-tree-beats.yosupo-range-chmin-chmax-range-sum.test.cpp
layout: document
redirect_from:
- /verify/verify/segment-tree-beats.yosupo-range-chmin-chmax-range-sum.test.cpp
- /verify/verify/segment-tree-beats.yosupo-range-chmin-chmax-range-sum.test.cpp.html
title: verify/segment-tree-beats.yosupo-range-chmin-chmax-range-sum.test.cpp
---
