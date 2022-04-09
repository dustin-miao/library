---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/tnemges-tree.hpp
    title: Tnemges Tree
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
  bundledCode: "#line 1 \"verify/tnemges-tree.aizu-point-add-query.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/tnemges-tree.hpp\"\
    \ntemplate<typename T>\nclass tnemges_tree {\nprotected:\n\tint n;\n\tvector<T>\
    \ tree;\n\npublic:\n\ttnemges_tree() = default;\n\n\ttnemges_tree(int _n) { init(_n);\
    \ }\n\n\tvoid init(int _n) {\n\t\tn = _n;\n\t\ttree.assign(2 * n, 0);\n\t}\n\n\
    \tvoid update(int l, int r, T v) {\n\t\tfor (l += n, r += n + 1; l < r; l >>=\
    \ 1, r >>= 1) {\n\t\t\tif (l & 1) \n\t\t\t\ttree[l++] += v;\n\t\t\tif (r & 1)\
    \ \n\t\t\t\ttree[--r] += v;\n\t\t}\n\t}\n\n\tT query(int i) {\n\t\tT ret = 0;\n\
    \t\tfor (i += n; i > 0; i >>= 1)\n\t\t\tret += tree[i];\n\t\treturn ret;\n\t}\n\
    \n\tT operator[](int i) { return query(i); }\n};\n#line 7 \"verify/tnemges-tree.aizu-point-add-query.test.cpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\ttnemges_tree<long long> tib(N\
    \ + 1);\n\twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\tint l,\
    \ r; long long v;\n\t\t\tcin >> l >> r >> v;\n\t\t\ttib.update(l, r, v);\n\t\t\
    } else {\n\t\t\tint i; cin >> i;\n\t\t\tcout << tib.query(i) << '\\n';\n\t\t}\n\
    \t}\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/tnemges-tree.hpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\ttnemges_tree<long long> tib(N\
    \ + 1);\n\twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\tint l,\
    \ r; long long v;\n\t\t\tcin >> l >> r >> v;\n\t\t\ttib.update(l, r, v);\n\t\t\
    } else {\n\t\t\tint i; cin >> i;\n\t\t\tcout << tib.query(i) << '\\n';\n\t\t}\n\
    \t}\n}"
  dependsOn:
  - data-structure/tnemges-tree.hpp
  isVerificationFile: true
  path: verify/tnemges-tree.aizu-point-add-query.test.cpp
  requiredBy: []
  timestamp: '2022-04-09 15:55:38-07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/tnemges-tree.aizu-point-add-query.test.cpp
layout: document
redirect_from:
- /verify/verify/tnemges-tree.aizu-point-add-query.test.cpp
- /verify/verify/tnemges-tree.aizu-point-add-query.test.cpp.html
title: verify/tnemges-tree.aizu-point-add-query.test.cpp
---
