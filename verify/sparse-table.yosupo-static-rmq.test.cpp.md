---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/sparse-table.hpp
    title: Sparse Table
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"verify/sparse-table.yosupo-static-rmq.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"data-structure/sparse-table.hpp\"\ntemplate<typename\
    \ T>\nclass sparse_table {\n\tint n, logn;\n\tvector<vector<T>> table;\n\npublic:\n\
    \tsparse_table() = default;\n\n\ttemplate<typename I>\n\tsparse_table(I l, I r)\
    \ { init(l, r); }\n\n\ttemplate<typename I>\n\tvoid init(I l, I r) {\n\t\tn =\
    \ distance(l, r);\n\t\tlogn = 32 - __builtin_clz(n);\n\t\ttable.assign(logn, vector<T>(n));\n\
    \t\tcopy(l, r, table[0].begin());\n\t\tfor (int k = 1; k < logn; k++)\n\t\t\t\
    for (int i = 0; i + (1 << k) <= n; i++)\n\t\t\t\ttable[k][i] = min(table[k - 1][i],\
    \ table[k - 1][i + (1 << (k - 1))]);\n\t}\n\n\tT query(int l, int r) {\n\t\tint\
    \ k = 31 - __builtin_clz(r - l + 1);\n\t\treturn min(table[k][l], table[k][r -\
    \ (1 << k) + 1]);\n\t}\n};\n#line 7 \"verify/sparse-table.yosupo-static-rmq.test.cpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\tvector<int> A(N);\n\tfor (int\
    \ i = 0; i < N; i++)\n\t\tcin >> A[i];\n\tsparse_table<int> st(A.begin(), A.end());\n\
    \twhile (Q--) {\n\t\tint l, r;\n\t\tcin >> l >> r;\n\t\tcout << st.query(l, r\
    \ - 1) << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/sparse-table.hpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\tvector<int> A(N);\n\tfor (int\
    \ i = 0; i < N; i++)\n\t\tcin >> A[i];\n\tsparse_table<int> st(A.begin(), A.end());\n\
    \twhile (Q--) {\n\t\tint l, r;\n\t\tcin >> l >> r;\n\t\tcout << st.query(l, r\
    \ - 1) << '\\n';\n\t}\n}\n"
  dependsOn:
  - data-structure/sparse-table.hpp
  isVerificationFile: true
  path: verify/sparse-table.yosupo-static-rmq.test.cpp
  requiredBy: []
  timestamp: '2022-04-11 08:59:21-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/sparse-table.yosupo-static-rmq.test.cpp
layout: document
redirect_from:
- /verify/verify/sparse-table.yosupo-static-rmq.test.cpp
- /verify/verify/sparse-table.yosupo-static-rmq.test.cpp.html
title: verify/sparse-table.yosupo-static-rmq.test.cpp
---
