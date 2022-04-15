---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/ordered-set.aizu-the-number-of-inversions.test.cpp
    title: verify/ordered-set.aizu-the-number-of-inversions.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 1 "utility/ordered-set.hpp"

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
  path: utility/ordered-set.hpp
  requiredBy: []
  timestamp: '2022-04-15 10:18:13-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/ordered-set.aizu-the-number-of-inversions.test.cpp
documentation_of: utility/ordered-set.hpp
layout: document
redirect_from:
- /library/utility/ordered-set.hpp
- /library/utility/ordered-set.hpp.html
title: utility/ordered-set.hpp
---
