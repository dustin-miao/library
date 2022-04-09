---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/general-segment-tree.hpp
    title: General Segment Tree
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
  bundledCode: "#line 1 \"verify/general-segment-tree.yosupo-point-add-range-sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/general-segment-tree.hpp\"\
    \ntemplate<class segment_tree_template>\nclass gen_segment_tree : public segment_tree_template\
    \ {\n\tusing T = typename segment_tree_template::type;\n\tusing segment_tree_template::default_value;\n\
    \tusing segment_tree_template::merge;\n\tusing segment_tree_template::apply;\n\
    \nprotected:\n\tint n;\n\tvector<T> tree;\n\npublic:\n\tgen_segment_tree() = default;\n\
    \n\tgen_segment_tree(int _n) { init(_n); }\n\n\tvoid init(int _n) {\n\t\tfor (n\
    \ = 1; n < _n; n *= 2);\n\t\ttree.assign(n * 2, dval);\n\t}\n\n\tvoid update(int\
    \ i, T v) {\n\t\tfor (apply(tree[i += n], v); i >>= 1;)\n\t\t\ttree[i] = merge(tree[i\
    \ << 1], tree[i << 1 | 1]);\n\t}\n\n\tT query(int l, int r) {\n\t\tT lret = default_value,\
    \ rret = default_value;\n\t\tfor (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)\
    \ {\n\t\t\tif (l & 1) \n\t\t\t\tlret = merge(lret, tree[l++]);\n\t\t\tif (r &\
    \ 1) \n\t\t\t\trret = merge(tree[--r], rret);\n\t\t}\n\t\treturn merge(lret, rret);\n\
    \t}\n\n\tT operator[](int i) { return tree[i + n]; }\n};\n#line 7 \"verify/general-segment-tree.yosupo-point-add-range-sum.test.cpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\n\tstruct segment_tree_template\
    \ {\n\t\tusing type = long long;\n\t\tconst type default_value = 0;\n\t\tvoid\
    \ apply(type &a, type b) { a += b; }\n\t\ttype merge(type a, type b) { return\
    \ a + b; }\n\t};\n\n\tgen_segment_tree<segment_tree_template> sgt(N);\n\tfor (int\
    \ i = 0; i < N; i++) {\n\t\tlong long a; cin >> a;\n\t\tsgt.update(i, a);\n\t\
    }\n\twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\tint p; long\
    \ long x;\n\t\t\tcin >> p >> x;\n\t\t\tsgt.update(p, x);\n\t\t} else {\n\t\t\t\
    int l, r;\n\t\t\tcin >> l >> r;\n\t\t\tcout << sgt.query(l, r - 1) << '\\n';\n\
    \t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/general-segment-tree.hpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\n\tstruct segment_tree_template\
    \ {\n\t\tusing type = long long;\n\t\tconst type default_value = 0;\n\t\tvoid\
    \ apply(type &a, type b) { a += b; }\n\t\ttype merge(type a, type b) { return\
    \ a + b; }\n\t};\n\n\tgen_segment_tree<segment_tree_template> sgt(N);\n\tfor (int\
    \ i = 0; i < N; i++) {\n\t\tlong long a; cin >> a;\n\t\tsgt.update(i, a);\n\t\
    }\n\twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\tint p; long\
    \ long x;\n\t\t\tcin >> p >> x;\n\t\t\tsgt.update(p, x);\n\t\t} else {\n\t\t\t\
    int l, r;\n\t\t\tcin >> l >> r;\n\t\t\tcout << sgt.query(l, r - 1) << '\\n';\n\
    \t\t}\n\t}\n}\n"
  dependsOn:
  - data-structure/general-segment-tree.hpp
  isVerificationFile: true
  path: verify/general-segment-tree.yosupo-point-add-range-sum.test.cpp
  requiredBy: []
  timestamp: '2022-04-09 15:55:38-07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/general-segment-tree.yosupo-point-add-range-sum.test.cpp
layout: document
redirect_from:
- /verify/verify/general-segment-tree.yosupo-point-add-range-sum.test.cpp
- /verify/verify/general-segment-tree.yosupo-point-add-range-sum.test.cpp.html
title: verify/general-segment-tree.yosupo-point-add-range-sum.test.cpp
---
