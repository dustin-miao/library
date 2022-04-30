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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "#line 1 \"verify/segment-tree.aizu-range-sum-query.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/segment-tree.hpp\"\
    \n#pragma region segment_tree\n\ntemplate<class segment_tree_template>\nclass\
    \ segment_tree : public segment_tree_template {\n\tusing T = typename segment_tree_template::type;\n\
    \tusing segment_tree_template::default_value;\n\tusing segment_tree_template::merge;\n\
    \tusing segment_tree_template::apply;\n\nprotected:\n\tint n;\n\tvector<T> tree;\n\
    \npublic:\n\tsegment_tree() = default;\n\n\tsegment_tree(int _n) { init(_n); }\n\
    \n\tvoid init(int _n) {\n\t\tn = _n;\n\t\ttree.assign(n * 2, default_value);\n\
    \t}\n\n\tvoid update(int i, T v) {\n\t\tfor (apply(tree[i += n], v); i >>= 1;)\n\
    \t\t\ttree[i] = merge(tree[i << 1], tree[i << 1 | 1]);\n\t}\n\n\tT query(int l,\
    \ int r) {\n\t\tT ret = default_value;\n\t\tfor (l += n, r += n + 1; l < r; l\
    \ >>= 1, r >>= 1) {\n\t\t\tif (l & 1) \n\t\t\t\tret = merge(ret, tree[l++]);\n\
    \t\t\tif (r & 1) \n\t\t\t\tret = merge(ret, tree[--r]);\n\t\t}\n\t\treturn ret;\n\
    \t}\n\n\tT operator[](int i) { return tree[i += n]; }\n};\n\n#pragma endregion\
    \ segment_tree\n#line 7 \"verify/segment-tree.aizu-range-sum-query.test.cpp\"\n\
    \nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\n\tstruct segment_tree_template\
    \ {\n\t\tusing type = long long;\n\t\tconst type default_value = 0;\n\t\tvoid\
    \ apply(type &a, type b) { a += b; }\n\t\ttype merge(type a, type b) { return\
    \ a + b; }\n\t};\n\n\tsegment_tree<segment_tree_template> sgt(N + 1);\n\twhile\
    \ (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\tint i; long long v;\n\
    \t\t\tcin >> i >> v;\n\t\t\tsgt.update(i, v);\n\t\t} else if (t == 1) {\n\t\t\t\
    int l, r;\n\t\t\tcin >> l >> r;\n\t\t\tcout << sgt.query(l, r) << '\\n';\n\t\t\
    }\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/segment-tree.hpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\n\tstruct segment_tree_template\
    \ {\n\t\tusing type = long long;\n\t\tconst type default_value = 0;\n\t\tvoid\
    \ apply(type &a, type b) { a += b; }\n\t\ttype merge(type a, type b) { return\
    \ a + b; }\n\t};\n\n\tsegment_tree<segment_tree_template> sgt(N + 1);\n\twhile\
    \ (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\tint i; long long v;\n\
    \t\t\tcin >> i >> v;\n\t\t\tsgt.update(i, v);\n\t\t} else if (t == 1) {\n\t\t\t\
    int l, r;\n\t\t\tcin >> l >> r;\n\t\t\tcout << sgt.query(l, r) << '\\n';\n\t\t\
    }\n\t}\n}"
  dependsOn:
  - data-structure/segment-tree.hpp
  isVerificationFile: true
  path: verify/segment-tree.aizu-range-sum-query.test.cpp
  requiredBy: []
  timestamp: '2022-04-29 22:36:50-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/segment-tree.aizu-range-sum-query.test.cpp
layout: document
redirect_from:
- /verify/verify/segment-tree.aizu-range-sum-query.test.cpp
- /verify/verify/segment-tree.aizu-range-sum-query.test.cpp.html
title: verify/segment-tree.aizu-range-sum-query.test.cpp
---
