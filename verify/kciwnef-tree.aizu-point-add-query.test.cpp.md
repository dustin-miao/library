---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/fenwick-tree.hpp
    title: Fenwick Tree
  - icon: ':x:'
    path: data-structure/kciwnef-tree.hpp
    title: Kciwnef Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E
  bundledCode: "#line 1 \"verify/kciwnef-tree.aizu-point-add-query.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/fenwick-tree.hpp\"\
    \ntemplate<typename T>\nclass fenwick_tree {\n\tint n;\n\tvector<T> tree;\n\n\
    public:\n\tfenwick_tree() = default;\n\n\tfenwick_tree(int _n) { init(_n); }\n\
    \n\tvoid init(int _n) {\n\t\tn = _n;\n\t\ttree.assign(n + 1, T());\n\t}\n\n\t\
    void update(int i, T v) {\n\t\tfor (i++; i <= n; i += i & -i)\n\t\t\ttree[i] +=\
    \ v;\n\t}\n\n\tT query(int i) {\n\t\tT ret = T();\n\t\tfor (i++; i; i -= i & -i)\n\
    \t\t\tret += tree[i];\n\t\treturn ret;\n\t}\n\n\tT query(int l, int r) { return\
    \ query(r) - query(l - 1); }\n};\n#line 2 \"data-structure/kciwnef-tree.hpp\"\n\
    \ntemplate<typename T>\nclass kciwnef_tree : public fenwick_tree<T> {\n\tusing\
    \ fenwick_tree<T>::update;\n\npublic:\n\tkciwnef_tree() : fenwick_tree<T>() {};\n\
    \n\tkciwnef_tree(int _n) : fenwick_tree<T>(_n) {}\n\n\tvoid update(int l, int\
    \ r, T v) {\n\t\tupdate(l, v); \n\t\tupdate(r + 1, -v);\n\t}\n\n\tusing fenwick_tree<T>::query;\n\
    \n\tT operator[](int i) { return query(i); }\n};\n#line 7 \"verify/kciwnef-tree.aizu-point-add-query.test.cpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\tkciwnef_tree<long long> tib(N);\n\
    \twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\tint l, r; long\
    \ long v;\n\t\t\tcin >> l >> r >> v;\n\t\t\ttib.update(l, r, v);\n\t\t} else {\n\
    \t\t\tint i; cin >> i;\n\t\t\tcout << tib.query(i) << '\\n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/kciwnef-tree.hpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\tkciwnef_tree<long long> tib(N);\n\
    \twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\tint l, r; long\
    \ long v;\n\t\t\tcin >> l >> r >> v;\n\t\t\ttib.update(l, r, v);\n\t\t} else {\n\
    \t\t\tint i; cin >> i;\n\t\t\tcout << tib.query(i) << '\\n';\n\t\t}\n\t}\n}"
  dependsOn:
  - data-structure/kciwnef-tree.hpp
  - data-structure/fenwick-tree.hpp
  isVerificationFile: true
  path: verify/kciwnef-tree.aizu-point-add-query.test.cpp
  requiredBy: []
  timestamp: '2022-04-09 15:55:38-07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/kciwnef-tree.aizu-point-add-query.test.cpp
layout: document
redirect_from:
- /verify/verify/kciwnef-tree.aizu-point-add-query.test.cpp
- /verify/verify/kciwnef-tree.aizu-point-add-query.test.cpp.html
title: verify/kciwnef-tree.aizu-point-add-query.test.cpp
---
