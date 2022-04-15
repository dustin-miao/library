---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/ordered-set.aizu-K-average-ranges.test.cpp
    title: verify/ordered-set.aizu-K-average-ranges.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/ordered-set.aizu-the-number-of-inversions.test.cpp
    title: verify/ordered-set.aizu-the-number-of-inversions.test.cpp
  - icon: ':x:'
    path: verify/ordered-set.aizu-unique.test.cpp
    title: verify/ordered-set.aizu-unique.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: '#line 1 "data-structure/ordered-set.hpp"

    #include <ext/pb_ds/assoc_container.hpp>

    #include <ext/pb_ds/tree_policy.hpp>

    using namespace __gnu_pbds;


    template <class K, class V>

    using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;


    template <class K>

    using ordered_set = ordered_map<K, null_type>;

    '
  code: '#include <ext/pb_ds/assoc_container.hpp>

    #include <ext/pb_ds/tree_policy.hpp>

    using namespace __gnu_pbds;


    template <class K, class V>

    using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;


    template <class K>

    using ordered_set = ordered_map<K, null_type>;'
  dependsOn: []
  isVerificationFile: false
  path: data-structure/ordered-set.hpp
  requiredBy: []
  timestamp: '2022-04-15 10:43:39-07:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/ordered-set.aizu-the-number-of-inversions.test.cpp
  - verify/ordered-set.aizu-K-average-ranges.test.cpp
  - verify/ordered-set.aizu-unique.test.cpp
documentation_of: data-structure/ordered-set.hpp
layout: document
title: Ordered Set
---

## Ordered Set