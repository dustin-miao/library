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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: data-structure/union-find.hpp:\
    \ line -1: no such header\n"
  code: "#include \"data-structure/union-find.hpp\"\n#include \"graph/graph-util.hpp\"\
    \n\ntemplate<typename T>\ngraph<T> kruskal(size_t n, edgelist<T> E) {\n\tgraph<T>\
    \ mst(n);\n\tif (n <= 1)\n\t\treturn mst;\n\tUnionFind dsu(n);\n\tsort(E.begin(),\
    \ E.end(), \n\t\t[](auto a, auto b) { \n\t\t\treturn get<2>(a) < get<2>(b); \n\
    \t\t}\n\t);\n\tfor (auto [u, v, w] : E) {\n\t\tif (dsu.merge(u, v)) {\n\t\t\t\
    mst[u].emplace_back(v, w);\n\t\t\tmst[v].emplace_back(u, w);\n\t\t}\n\t\tif (dsu.size(0)\
    \ == n)\n\t\t\tbreak;\n\t}\n\treturn mst;\n}"
  dependsOn: []
  isVerificationFile: false
  path: templates/graph/kruskal.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: templates/graph/kruskal.hpp
layout: document
redirect_from:
- /library/templates/graph/kruskal.hpp
- /library/templates/graph/kruskal.hpp.html
title: templates/graph/kruskal.hpp
---
