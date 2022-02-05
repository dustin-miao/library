---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"templates/data-structure/fenwick-tree.hpp\"\ntemplate<typename\
    \ T>\nclass Fentree {\n\tsize_t n;\n\tvector<T> tree;\n\npublic:\n\tFentree()\
    \ = default;\n\n\tFentree(size_t _n) { init(_n); }\n\n\tvoid init(size_t _n) {\n\
    \t\tn = _n;\n\t\ttree.assign(n + 1, T());\n\t}\n\n\tvoid update(int i, T v) {\n\
    \t\tfor (; i <= n; i += i & -i)\n\t\t\ttree[i] += v;\n\t}\n\n\tT query(int i)\
    \ {\n\t\tT ret = 0;\n\t\tfor (; i; i -= i & -i)\n\t\t\tret += tree[i];\n\t\treturn\
    \ ret;\n\t}\n\n\tT query(int l, int r) { return query(r) - query(l - 1); }\n};\n"
  code: "template<typename T>\nclass Fentree {\n\tsize_t n;\n\tvector<T> tree;\n\n\
    public:\n\tFentree() = default;\n\n\tFentree(size_t _n) { init(_n); }\n\n\tvoid\
    \ init(size_t _n) {\n\t\tn = _n;\n\t\ttree.assign(n + 1, T());\n\t}\n\n\tvoid\
    \ update(int i, T v) {\n\t\tfor (; i <= n; i += i & -i)\n\t\t\ttree[i] += v;\n\
    \t}\n\n\tT query(int i) {\n\t\tT ret = 0;\n\t\tfor (; i; i -= i & -i)\n\t\t\t\
    ret += tree[i];\n\t\treturn ret;\n\t}\n\n\tT query(int l, int r) { return query(r)\
    \ - query(l - 1); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: templates/data-structure/fenwick-tree.hpp
  requiredBy: []
  timestamp: '2022-02-04 20:52:31-08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: templates/data-structure/fenwick-tree.hpp
layout: document
redirect_from:
- /library/templates/data-structure/fenwick-tree.hpp
- /library/templates/data-structure/fenwick-tree.hpp.html
title: templates/data-structure/fenwick-tree.hpp
---
