---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/fenwick-tree.hpp
    title: Fenwick Tree
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
  bundledCode: "#line 1 \"verify/fenwick-tree.aizu-range-sum-query.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/fenwick-tree.hpp\"\
    \ntemplate<typename T>\nclass fenwick_tree {\n\tint n;\n\tvector<T> tree;\n\n\
    public:\n\tfenwick_tree() = default;\n\n\tfenwick_tree(int _n) { init(_n); }\n\
    \n\tvoid init(int _n) {\n\t\tn = _n;\n\t\ttree.assign(n + 1, T());\n\t}\n\n\t\
    void update(int i, T v) {\n\t\tfor (i++; i <= n; i += i & -i)\n\t\t\ttree[i] +=\
    \ v;\n\t}\n\n\tT query(int i) {\n\t\tT ret = T();\n\t\tfor (i++; i; i -= i & -i)\n\
    \t\t\tret += tree[i];\n\t\treturn ret;\n\t}\n\n\tT query(int l, int r) { return\
    \ query(r) - query(l - 1); }\n};\n#line 7 \"verify/fenwick-tree.aizu-range-sum-query.test.cpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\tfenwick_tree<long long> bit(N);\n\
    \twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\tint i; long long\
    \ v;\n\t\t\tcin >> i >> v;\n\t\t\tbit.update(i - 1, v);\n\t\t} else if (t == 1)\
    \ {\n\t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\t\t\tcout << bit.query(l - 1, r -\
    \ 1) << '\\n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/fenwick-tree.hpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\tfenwick_tree<long long> bit(N);\n\
    \twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\tint i; long long\
    \ v;\n\t\t\tcin >> i >> v;\n\t\t\tbit.update(i - 1, v);\n\t\t} else if (t == 1)\
    \ {\n\t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\t\t\tcout << bit.query(l - 1, r -\
    \ 1) << '\\n';\n\t\t}\n\t}\n}"
  dependsOn:
  - data-structure/fenwick-tree.hpp
  isVerificationFile: true
  path: verify/fenwick-tree.aizu-range-sum-query.test.cpp
  requiredBy: []
  timestamp: '2022-04-09 16:28:08-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/fenwick-tree.aizu-range-sum-query.test.cpp
layout: document
redirect_from:
- /verify/verify/fenwick-tree.aizu-range-sum-query.test.cpp
- /verify/verify/fenwick-tree.aizu-range-sum-query.test.cpp.html
title: verify/fenwick-tree.aizu-range-sum-query.test.cpp
---
