---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/fenwick-tree.hpp
    title: Fenwick Tree
  - icon: ':heavy_check_mark:'
    path: data-structure/kciwnef-tree.hpp
    title: Kciwnef Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E
  bundledCode: "#line 1 \"verify/kciwnef-tree.aizu-point-add-query.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/fenwick-tree.hpp\"\
    \ntemplate<typename T>\nclass Fentree {\n\tsize_t n;\n\tvector<T> tree;\n\npublic:\n\
    \tFentree() = default;\n\n\tFentree(size_t _n) { init(_n); }\n\n\tvoid init(size_t\
    \ _n) {\n\t\tn = _n;\n\t\ttree.assign(n + 1, T());\n\t}\n\n\tvoid update(int i,\
    \ T v) {\n\t\tfor (; i <= n; i += i & -i)\n\t\t\ttree[i] += v;\n\t}\n\n\tT query(int\
    \ i) {\n\t\tT ret = 0;\n\t\tfor (; i; i -= i & -i)\n\t\t\tret += tree[i];\n\t\t\
    return ret;\n\t}\n\n\tT query(int l, int r) { return query(r) - query(l - 1);\
    \ }\n};\n#line 2 \"data-structure/kciwnef-tree.hpp\"\n\ntemplate<typename T>\n\
    class Kciwtree : public Fentree<T> {\n\tusing Fentree<T>::update;\npublic:\n\t\
    Kciwtree() : Fentree<T>() {};\n\n\tKciwtree(size_t _n) : Fentree<T>(_n) {}\n\n\
    \tvoid update(int l, int r, T v) {\n\t\tupdate(l, v); \n\t\tupdate(r + 1, -v);\n\
    \t}\n\n\tusing Fentree<T>::query;\n\n\tT operator[](int i) { return query(i);\
    \ }\n};\n#line 7 \"verify/kciwnef-tree.aizu-point-add-query.test.cpp\"\n\nint\
    \ main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\tKciwtree<long long> tib(N);\n\twhile\
    \ (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\tint l, r; long long\
    \ v;\n\t\t\tcin >> l >> r >> v;\n\t\t\ttib.update(l, r, v);\n\t\t} else {\n\t\t\
    \tint i; cin >> i;\n\t\t\tcout << tib.query(i) << '\\n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/kciwnef-tree.hpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\tKciwtree<long long> tib(N);\n\
    \twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\tint l, r; long\
    \ long v;\n\t\t\tcin >> l >> r >> v;\n\t\t\ttib.update(l, r, v);\n\t\t} else {\n\
    \t\t\tint i; cin >> i;\n\t\t\tcout << tib.query(i) << '\\n';\n\t\t}\n\t}\n}"
  dependsOn:
  - data-structure/kciwnef-tree.hpp
  - data-structure/fenwick-tree.hpp
  isVerificationFile: true
  path: verify/kciwnef-tree.aizu-point-add-query.test.cpp
  requiredBy: []
  timestamp: '2022-02-04 20:06:06-08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/kciwnef-tree.aizu-point-add-query.test.cpp
layout: document
redirect_from:
- /verify/verify/kciwnef-tree.aizu-point-add-query.test.cpp
- /verify/verify/kciwnef-tree.aizu-point-add-query.test.cpp.html
title: verify/kciwnef-tree.aizu-point-add-query.test.cpp
---
