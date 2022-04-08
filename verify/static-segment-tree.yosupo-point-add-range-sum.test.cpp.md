---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "#line 1 \"verify/static-segment-tree.yosupo-point-add-range-sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/static-segment-tree.hpp\n\
    \nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\n\tSegtree sgt(N);\n\tfor (int\
    \ i = 0; i < N; i++) {\n\t\tlong long a; cin >> a;\n\t\tsgt.update(i, a);\n\t\
    }\n\twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\tint p; long\
    \ long x;\n\t\t\tcin >> p >> x;\n\t\t\tsgt.update(p, x);\n\t\t} else {\n\t\t\t\
    int l, r;\n\t\t\tcin >> l >> r;\n\t\t\tcout << sgt.query(l, r - 1) << '\\n';\n\
    \t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/static-segment-tree.hpp\n\
    \nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\n\tSegtree sgt(N);\n\tfor (int\
    \ i = 0; i < N; i++) {\n\t\tlong long a; cin >> a;\n\t\tsgt.update(i, a);\n\t\
    }\n\twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\tint p; long\
    \ long x;\n\t\t\tcin >> p >> x;\n\t\t\tsgt.update(p, x);\n\t\t} else {\n\t\t\t\
    int l, r;\n\t\t\tcin >> l >> r;\n\t\t\tcout << sgt.query(l, r - 1) << '\\n';\n\
    \t\t}\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/static-segment-tree.yosupo-point-add-range-sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/static-segment-tree.yosupo-point-add-range-sum.test.cpp
layout: document
redirect_from:
- /verify/verify/static-segment-tree.yosupo-point-add-range-sum.test.cpp
- /verify/verify/static-segment-tree.yosupo-point-add-range-sum.test.cpp.html
title: verify/static-segment-tree.yosupo-point-add-range-sum.test.cpp
---
