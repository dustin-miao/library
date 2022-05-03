---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: utility/prefix-sum.hpp
    title: Prefix Sum
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"verify/prefix-sum.yosupo-static-range-sum.test.cpp\"\n#define\
    \ PROBLM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"utility/prefix-sum.hpp\"\n#pragma region prefix_sum\n\
    \n#ifndef PREFIX_SUM_HPP\n#define PREFIX_SUM_HPP\n\ntemplate<typename T>\nvector<T>\
    \ prefix_sum(vector<T> a) {\n\tint n = a.size();\n\tfor (int i = 1; i < n; i++)\n\
    \t\ta[i] += a[i - 1];\n\treturn a;\n}\n\n#endif\n\n#pragma endregion prefix_sum\n\
    #line 7 \"verify/prefix-sum.yosupo-static-range-sum.test.cpp\"\n\nint main() {\n\
    \tint N, Q;\n\tcin >> N >> Q;\n\tvector<long long> A(N);\n\tfor (auto &a : A)\n\
    \t\tcin >> a;\n\tauto P = prefix_sum(A);\n\twhile (Q--) {\n\t\tint l, r;\n\t\t\
    cin >> l >> r;\n\t\tcout << P[r - 1] - (l == 0 ? 0 : P[l - 1]) << '\\n';\n\t}\n\
    } \n"
  code: "#define PROBLM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"utility/prefix-sum.hpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\tvector<long long> A(N);\n\t\
    for (auto &a : A)\n\t\tcin >> a;\n\tauto P = prefix_sum(A);\n\twhile (Q--) {\n\
    \t\tint l, r;\n\t\tcin >> l >> r;\n\t\tcout << P[r - 1] - (l == 0 ? 0 : P[l -\
    \ 1]) << '\\n';\n\t}\n} "
  dependsOn:
  - utility/prefix-sum.hpp
  isVerificationFile: true
  path: verify/prefix-sum.yosupo-static-range-sum.test.cpp
  requiredBy: []
  timestamp: '2022-05-03 15:23:53-07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/prefix-sum.yosupo-static-range-sum.test.cpp
layout: document
redirect_from:
- /verify/verify/prefix-sum.yosupo-static-range-sum.test.cpp
- /verify/verify/prefix-sum.yosupo-static-range-sum.test.cpp.html
title: verify/prefix-sum.yosupo-static-range-sum.test.cpp
---
