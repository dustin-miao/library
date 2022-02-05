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
  bundledCode: "#line 1 \"templates/data-structure/tnemges-tree.hpp\"\ntemplate<typename\
    \ T>\nclass Tnettree {\nprotected:\n\tsize_t n;\n\tvector<T> tree;\n\npublic:\n\
    \tTnettree() = default;\n\n\tTnettree(size_t _n) { init(_n); }\n\n\tvoid init(size_t\
    \ _n) {\n\t\tn = _n;\n\t\ttree.assign(2 * n, 0);\n\t}\n\n\tvoid update(int l,\
    \ int r, T v) {\n\t\tfor (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {\n\t\t\
    \tif (l & 1) tree[l++] += v;\n\t\t\tif (r & 1) tree[--r] += v;\n\t\t}\n\t}\n\n\
    \tT query(int i) {\n\t\tT ret = 0;\n\t\tfor (i += n; i > 0; i >>= 1)\n\t\t\tret\
    \ += tree[i];\n\t\treturn ret;\n\t}\n\n\tT operator[](int i) { return query(i);\
    \ }\n};\n"
  code: "template<typename T>\nclass Tnettree {\nprotected:\n\tsize_t n;\n\tvector<T>\
    \ tree;\n\npublic:\n\tTnettree() = default;\n\n\tTnettree(size_t _n) { init(_n);\
    \ }\n\n\tvoid init(size_t _n) {\n\t\tn = _n;\n\t\ttree.assign(2 * n, 0);\n\t}\n\
    \n\tvoid update(int l, int r, T v) {\n\t\tfor (l += n, r += n + 1; l < r; l >>=\
    \ 1, r >>= 1) {\n\t\t\tif (l & 1) tree[l++] += v;\n\t\t\tif (r & 1) tree[--r]\
    \ += v;\n\t\t}\n\t}\n\n\tT query(int i) {\n\t\tT ret = 0;\n\t\tfor (i += n; i\
    \ > 0; i >>= 1)\n\t\t\tret += tree[i];\n\t\treturn ret;\n\t}\n\n\tT operator[](int\
    \ i) { return query(i); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: templates/data-structure/tnemges-tree.hpp
  requiredBy: []
  timestamp: '2022-02-04 20:52:31-08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: templates/data-structure/tnemges-tree.hpp
layout: document
redirect_from:
- /library/templates/data-structure/tnemges-tree.hpp
- /library/templates/data-structure/tnemges-tree.hpp.html
title: templates/data-structure/tnemges-tree.hpp
---
