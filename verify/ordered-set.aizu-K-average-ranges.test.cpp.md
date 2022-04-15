---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/ordered-set.hpp
    title: Ordered Set
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3117
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3117
  bundledCode: "#line 1 \"verify/ordered-set.aizu-K-average-ranges.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3117\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/ordered-set.hpp\"\
    \n#include <ext/pb_ds/assoc_container.hpp>\n#include <ext/pb_ds/tree_policy.hpp>\n\
    using namespace __gnu_pbds;\n\ntemplate <class K, class V>\nusing ordered_map\
    \ = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;\n\ntemplate\
    \ <class K>\nusing ordered_set = ordered_map<K, null_type>;\n#line 7 \"verify/ordered-set.aizu-K-average-ranges.test.cpp\"\
    \n\nint main() {\n\tint N;\n\tlong long K;\n\tcin >> N >> K;\n\tvector<long long>\
    \ A(N);\n\tfor (auto &a : A) {\n\t\tcin >> a;\n\t\ta -= K;\n\t}\n\n\tordered_set<pair<long\
    \ long, int>> S;\n\tlong long sum = 0, ans = 0;\n\tS.insert(make_pair(sum, -1));\n\
    \tfor (int i = 0; i < N; i++) {\n\t\tsum += A[i];\n\t\tS.insert(make_pair(sum,\
    \ i));\n\t\tans += S.order_of_key(make_pair(sum, i));\n\t}\n\tcout << ans << '\\\
    n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3117\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/ordered-set.hpp\"\
    \n\nint main() {\n\tint N;\n\tlong long K;\n\tcin >> N >> K;\n\tvector<long long>\
    \ A(N);\n\tfor (auto &a : A) {\n\t\tcin >> a;\n\t\ta -= K;\n\t}\n\n\tordered_set<pair<long\
    \ long, int>> S;\n\tlong long sum = 0, ans = 0;\n\tS.insert(make_pair(sum, -1));\n\
    \tfor (int i = 0; i < N; i++) {\n\t\tsum += A[i];\n\t\tS.insert(make_pair(sum,\
    \ i));\n\t\tans += S.order_of_key(make_pair(sum, i));\n\t}\n\tcout << ans << '\\\
    n';\n}"
  dependsOn:
  - data-structure/ordered-set.hpp
  isVerificationFile: true
  path: verify/ordered-set.aizu-K-average-ranges.test.cpp
  requiredBy: []
  timestamp: '2022-04-15 10:43:39-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/ordered-set.aizu-K-average-ranges.test.cpp
layout: document
redirect_from:
- /verify/verify/ordered-set.aizu-K-average-ranges.test.cpp
- /verify/verify/ordered-set.aizu-K-average-ranges.test.cpp.html
title: verify/ordered-set.aizu-K-average-ranges.test.cpp
---
