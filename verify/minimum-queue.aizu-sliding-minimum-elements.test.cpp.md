---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/minimum-queue.hpp
    title: Minimum Queue
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D
  bundledCode: "#line 1 \"verify/minimum-queue.aizu-sliding-minimum-elements.test.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/minimum-queue.hpp\"\
    \n#pragma region minimum_queue\n\n#ifndef MINIMUM_QUEUE_HPP\n#define MINIMUM_QUEUE_HPP\n\
    \ntemplate<typename T>\nclass minimum_queue {\n\tstack<pair<T, T>> s1, s2;\n\n\
    public:\n\tT query() { return s1.empty() || s2.empty() ? (s1.empty() ? s2.top().second\
    \ : s1.top().second) : min(s1.top().second, s2.top().second); }\n\n\tvoid push(T\
    \ x) { s1.emplace(x, s1.empty() ? x : min(x, s1.top().second)); }\n\n\tT top()\
    \ {\n\t\tif (s2.empty()) {\n\t\t\twhile (!s1.empty()) {\n\t\t\t\tint x = s1.top().first;\
    \ s1.pop();\n\t\t\t\ts2.emplace(x, s2.empty() ? x : min(x, s2.top().second));\n\
    \t\t\t}\n\t\t}\n\t\treturn s2.top().first;\n\t}\n\n\tvoid pop() {\n\t\tif (s2.empty())\
    \ {\n\t\t\twhile (!s1.empty()) {\n\t\t\t\tint x = s1.top().first; s1.pop();\n\t\
    \t\t\ts2.emplace(x, s2.empty() ? x : min(x, s2.top().second));\n\t\t\t}\n\t\t\
    }\n\t\ts2.pop();\n\t}\n\n\tint size() { return s1.size() + s2.size(); }\n};\n\n\
    #endif\n\n#pragma endregion minimum_queue\n#line 7 \"verify/minimum-queue.aizu-sliding-minimum-elements.test.cpp\"\
    \n\nint main() {\n\tint N, L;\n\tcin >> N >> L;\n\tminimum_queue<int> q;\n\tfor\
    \ (int i = 0; i < L - 1; i++) {\n\t\tint a;\n\t\tcin >> a;\n\t\tq.push(a);\n\t\
    }\n\tfor (int i = L - 1; i < N; i++) {\n\t\tint a;\n\t\tcin >> a;\n\t\tq.push(a);\n\
    \t\tassert(q.size() == L);\n\t\tcout << q.query() << \" \\n\"[i == N - 1];\n\t\
    \tq.pop();\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/minimum-queue.hpp\"\
    \n\nint main() {\n\tint N, L;\n\tcin >> N >> L;\n\tminimum_queue<int> q;\n\tfor\
    \ (int i = 0; i < L - 1; i++) {\n\t\tint a;\n\t\tcin >> a;\n\t\tq.push(a);\n\t\
    }\n\tfor (int i = L - 1; i < N; i++) {\n\t\tint a;\n\t\tcin >> a;\n\t\tq.push(a);\n\
    \t\tassert(q.size() == L);\n\t\tcout << q.query() << \" \\n\"[i == N - 1];\n\t\
    \tq.pop();\n\t}\n}"
  dependsOn:
  - data-structure/minimum-queue.hpp
  isVerificationFile: true
  path: verify/minimum-queue.aizu-sliding-minimum-elements.test.cpp
  requiredBy: []
  timestamp: '2022-05-06 15:00:10-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/minimum-queue.aizu-sliding-minimum-elements.test.cpp
layout: document
redirect_from:
- /verify/verify/minimum-queue.aizu-sliding-minimum-elements.test.cpp
- /verify/verify/minimum-queue.aizu-sliding-minimum-elements.test.cpp.html
title: verify/minimum-queue.aizu-sliding-minimum-elements.test.cpp
---
