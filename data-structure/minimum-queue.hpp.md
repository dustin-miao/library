---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/minimum-queue.aizu-sliding-minimum-elements.test.cpp
    title: verify/minimum-queue.aizu-sliding-minimum-elements.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/minimum-queue.hpp\"\n#pragma region minimum_queue\n\
    \n#ifndef MINIMUM_QUEUE_HPP\n#define MINIMUM_QUEUE_HPP\n\ntemplate<typename T>\n\
    class minimum_queue {\n\tstack<pair<T, T>> s1, s2;\n\npublic:\n\tT query() { return\
    \ s1.empty() || s2.empty() ? (s1.empty() ? s2.top().second : s1.top().second)\
    \ : min(s1.top().second, s2.top().second); }\n\n\tvoid push(T x) { s1.emplace(x,\
    \ s1.empty() ? x : min(x, s1.top().second)); }\n\n\tT top() {\n\t\tif (s2.empty())\
    \ {\n\t\t\twhile (!s1.empty()) {\n\t\t\t\tint x = s1.top().first; s1.pop();\n\t\
    \t\t\ts2.emplace(x, s2.empty() ? x : min(x, s2.top().second));\n\t\t\t}\n\t\t\
    }\n\t\treturn s2.top().first;\n\t}\n\n\tvoid pop() {\n\t\tif (s2.empty()) {\n\t\
    \t\twhile (!s1.empty()) {\n\t\t\t\tint x = s1.top().first; s1.pop();\n\t\t\t\t\
    s2.emplace(x, s2.empty() ? x : min(x, s2.top().second));\n\t\t\t}\n\t\t}\n\t\t\
    s2.pop();\n\t}\n\n\tint size() { return s1.size() + s2.size(); }\n};\n\n#endif\n\
    \n#pragma endregion minimum_queue\n"
  code: "#pragma region minimum_queue\n\n#ifndef MINIMUM_QUEUE_HPP\n#define MINIMUM_QUEUE_HPP\n\
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
    #endif\n\n#pragma endregion minimum_queue"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/minimum-queue.hpp
  requiredBy: []
  timestamp: '2022-05-06 15:00:10-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/minimum-queue.aizu-sliding-minimum-elements.test.cpp
documentation_of: data-structure/minimum-queue.hpp
layout: document
title: Minimum Queue
---

## Minimum Queue