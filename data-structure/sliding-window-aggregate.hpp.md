---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/sliding-window-aggregate.yosupo-queue-operate-all-composite.test.cpp
    title: verify/sliding-window-aggregate.yosupo-queue-operate-all-composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/sliding-window-aggregate.hpp\"\n#pragma region\
    \ sliding_window_aggregate\n\n#ifndef SLIDING_WINDOX_AGGREGATE_HPP\n#define SLIDING_WINDOX_AGGREGATE_HPP\n\
    \ntemplate<class sliding_window_aggregate_template>\nclass sliding_window_aggregate\
    \ : public sliding_window_aggregate_template {\n\tusing T = typename sliding_window_aggregate_template::type;\n\
    \tusing sliding_window_aggregate_template::default_value;\n\tusing sliding_window_aggregate_template::merge;\n\
    \n\tstack<pair<T, T>> s1, s2;\n\tT ret1, ret2;\n\npublic:\n\tsliding_window_aggregate()\
    \ { init(); };\n\n\tvoid init() { \n\t\twhile (!s1.empty())\n\t\t\ts1.pop();\n\
    \t\twhile (!s2.empty())\n\t\t\ts2.pop();\n\t\tret1 = ret2 = default_value; \n\t\
    }\n\n\tT query() { return merge(ret2, ret1); }\n\n\tvoid push(T x) {\n\t\tif (s2.empty())\
    \ {\n\t\t\ts2.emplace(x, ret2 = merge(x, ret2));\n\t\t\twhile (!s1.empty()) {\n\
    \t\t\t\tT y = s1.top().first; s1.pop();\n\t\t\t\ts2.emplace(y, ret2 = merge(y,\
    \ ret2));\n\t\t\t}\n\t\t\tret1 = default_value;\n\t\t} else {\n\t\t\ts1.emplace(x,\
    \ ret1 = merge(ret1, x));\n\t\t}\n\t}\n\n\tvoid pop() {\n\t\tif (s2.empty()) {\n\
    \t\t\twhile (!s1.empty()) {\n\t\t\t\tT x = s1.top().first; s1.pop();\n\t\t\t\t\
    s2.emplace(x, ret2 = merge(x, ret2));\n\t\t\t}\n\t\t\tret1 = default_value;\n\t\
    \t}\n\t\ts2.pop();\n\t\tret2 = s2.empty() ? default_value : s2.top().second;\n\
    \t}\n\n\tint size() { return s1.size() + s2.size(); }\t\n\n\tbool empty() { return\
    \ size() == 0; }\n};\n\n#endif\n\n#pragma endregion sliding_window_aggregate\n"
  code: "#pragma region sliding_window_aggregate\n\n#ifndef SLIDING_WINDOX_AGGREGATE_HPP\n\
    #define SLIDING_WINDOX_AGGREGATE_HPP\n\ntemplate<class sliding_window_aggregate_template>\n\
    class sliding_window_aggregate : public sliding_window_aggregate_template {\n\t\
    using T = typename sliding_window_aggregate_template::type;\n\tusing sliding_window_aggregate_template::default_value;\n\
    \tusing sliding_window_aggregate_template::merge;\n\n\tstack<pair<T, T>> s1, s2;\n\
    \tT ret1, ret2;\n\npublic:\n\tsliding_window_aggregate() { init(); };\n\n\tvoid\
    \ init() { \n\t\twhile (!s1.empty())\n\t\t\ts1.pop();\n\t\twhile (!s2.empty())\n\
    \t\t\ts2.pop();\n\t\tret1 = ret2 = default_value; \n\t}\n\n\tT query() { return\
    \ merge(ret2, ret1); }\n\n\tvoid push(T x) {\n\t\tif (s2.empty()) {\n\t\t\ts2.emplace(x,\
    \ ret2 = merge(x, ret2));\n\t\t\twhile (!s1.empty()) {\n\t\t\t\tT y = s1.top().first;\
    \ s1.pop();\n\t\t\t\ts2.emplace(y, ret2 = merge(y, ret2));\n\t\t\t}\n\t\t\tret1\
    \ = default_value;\n\t\t} else {\n\t\t\ts1.emplace(x, ret1 = merge(ret1, x));\n\
    \t\t}\n\t}\n\n\tvoid pop() {\n\t\tif (s2.empty()) {\n\t\t\twhile (!s1.empty())\
    \ {\n\t\t\t\tT x = s1.top().first; s1.pop();\n\t\t\t\ts2.emplace(x, ret2 = merge(x,\
    \ ret2));\n\t\t\t}\n\t\t\tret1 = default_value;\n\t\t}\n\t\ts2.pop();\n\t\tret2\
    \ = s2.empty() ? default_value : s2.top().second;\n\t}\n\n\tint size() { return\
    \ s1.size() + s2.size(); }\t\n\n\tbool empty() { return size() == 0; }\n};\n\n\
    #endif\n\n#pragma endregion sliding_window_aggregate\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/sliding-window-aggregate.hpp
  requiredBy: []
  timestamp: '2022-05-06 22:55:08-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/sliding-window-aggregate.yosupo-queue-operate-all-composite.test.cpp
documentation_of: data-structure/sliding-window-aggregate.hpp
layout: document
title: Sliding Window Aggregate
---

## Sliding Window Aggregate