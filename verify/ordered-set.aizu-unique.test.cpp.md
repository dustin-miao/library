---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/ordered-set.hpp
    title: Ordered Set
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_4_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_4_D
  bundledCode: "#line 1 \"verify/ordered-set.aizu-unique.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_4_D\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/ordered-set.hpp\"\
    \n#include <ext/pb_ds/assoc_container.hpp>\n#include <ext/pb_ds/tree_policy.hpp>\n\
    using namespace __gnu_pbds;\n\ntemplate <class K, class V>\nusing ordered_map\
    \ = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;\n\ntemplate\
    \ <class K>\nusing ordered_set = ordered_map<K, null_type>;\n#line 7 \"verify/ordered-set.aizu-unique.test.cpp\"\
    \n\nint main() {\n\tint N;\n\tcin >> N;\n\tordered_set<int> S;\n\tfor (int i =\
    \ 0; i < N; i++) {\n\t\tint a;\n\t\tcin >> a;\n\t\tS.insert(a);\n\t}\n\tfor (int\
    \ a : S)\n\t\tcout << a << \" \\n\"[a == *prev(S.end())];\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_4_D\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/ordered-set.hpp\"\
    \n\nint main() {\n\tint N;\n\tcin >> N;\n\tordered_set<int> S;\n\tfor (int i =\
    \ 0; i < N; i++) {\n\t\tint a;\n\t\tcin >> a;\n\t\tS.insert(a);\n\t}\n\tfor (int\
    \ a : S)\n\t\tcout << a << \" \\n\"[a == *prev(S.end())];\n}"
  dependsOn:
  - data-structure/ordered-set.hpp
  isVerificationFile: true
  path: verify/ordered-set.aizu-unique.test.cpp
  requiredBy: []
  timestamp: '2022-04-15 13:52:19-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/ordered-set.aizu-unique.test.cpp
layout: document
redirect_from:
- /verify/verify/ordered-set.aizu-unique.test.cpp
- /verify/verify/ordered-set.aizu-unique.test.cpp.html
title: verify/ordered-set.aizu-unique.test.cpp
---
