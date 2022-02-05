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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
  bundledCode: "#line 1 \"verify/segment-tree.aizu-range-minimum-query.test.cpp\"\n\
    #define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/segment-tree.hpp\"\
    \ntemplate<class Base>\nclass Segtree : public Base {\n\tusing T = typename Base::T;\n\
    \tusing Base::dval;\n\tusing Base::merge;\n\tusing Base::apply;\n\nprotected:\n\
    \tsize_t n;\n\tvector<T> tree;\n\npublic:\n\tSegtree() = default;\n\n\tSegtree(size_t\
    \ _n) { init(_n); }\n\n\tvoid init(size_t _n) {\n\t\tn = _n;\n\t\ttree.assign(n\
    \ * 2, dval);\n\t}\n\n\tvoid update(int i, T v) {\n\t\tfor (apply(tree[i += n],\
    \ v); i >>= 1;)\n\t\t\ttree[i] = merge(tree[i << 1], tree[i << 1 | 1]);\n\t}\n\
    \n\tT query(int l, int r) {\n\t\tT ret = dval;\n\t\tfor (l += n, r += n + 1; l\
    \ < r; l >>= 1, r >>= 1) {\n\t\t\tif (l & 1) ret = merge(ret, tree[l++]);\n\t\t\
    \tif (r & 1) ret = merge(ret, tree[--r]);\n\t\t}\n\t\treturn ret;\n\t}\n\n\tT\
    \ operator[](int i) { return tree[i += n]; }\n};\n#line 7 \"verify/segment-tree.aizu-range-minimum-query.test.cpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\n\tstruct stinfo {\n\t\tusing\
    \ T = long long;\n\t\tconst T dval = LLONG_MAX;\n\t\tvoid apply(T &a, T b) { a\
    \ = b; }\n\t\tT merge(T a, T b) { return min(a, b); }\n\t};\n\n\tSegtree<stinfo>\
    \ sgt(N);\n\tfor (int i = 0; i < N; i++)\n\t\tsgt.update(i, INT_MAX);\n\twhile\
    \ (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\tint i; long long v;\n\
    \t\t\tcin >> i >> v;\n\t\t\tsgt.update(i, v);\n\t\t} else if (t == 1) {\n\t\t\t\
    int l, r;\n\t\t\tcin >> l >> r;\n\t\t\tcout << sgt.query(l, r) << '\\n';\n\t\t\
    }\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/segment-tree.hpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\n\tstruct stinfo {\n\t\tusing\
    \ T = long long;\n\t\tconst T dval = LLONG_MAX;\n\t\tvoid apply(T &a, T b) { a\
    \ = b; }\n\t\tT merge(T a, T b) { return min(a, b); }\n\t};\n\n\tSegtree<stinfo>\
    \ sgt(N);\n\tfor (int i = 0; i < N; i++)\n\t\tsgt.update(i, INT_MAX);\n\twhile\
    \ (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\tint i; long long v;\n\
    \t\t\tcin >> i >> v;\n\t\t\tsgt.update(i, v);\n\t\t} else if (t == 1) {\n\t\t\t\
    int l, r;\n\t\t\tcin >> l >> r;\n\t\t\tcout << sgt.query(l, r) << '\\n';\n\t\t\
    }\n\t}\n}"
  dependsOn:
  - data-structure/segment-tree.hpp
  isVerificationFile: true
  path: verify/segment-tree.aizu-range-minimum-query.test.cpp
  requiredBy: []
  timestamp: '2022-02-04 21:19:28-08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/segment-tree.aizu-range-minimum-query.test.cpp
layout: document
redirect_from:
- /verify/verify/segment-tree.aizu-range-minimum-query.test.cpp
- /verify/verify/segment-tree.aizu-range-minimum-query.test.cpp.html
title: verify/segment-tree.aizu-range-minimum-query.test.cpp
---
