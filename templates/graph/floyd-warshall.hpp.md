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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: utility/chmin.hpp:\
    \ line -1: no such header\n"
  code: "#include \"utility/chmin.hpp\"\n#include \"graph/graph-util.hpp\"\n\ntemplate<typename\
    \ T>\nvoid floyd_warshall(matgraph<T> &G, const T dval) {\n\tsize_t n = G.size();\n\
    \tfor (int i = 0; i < n; i++)\n\t\tG[i][i] = 0;\n\tfor (int k = 0; k < n; k++)\n\
    \t\tfor (int i = 0; i < n; i++)\n\t\t\tfor (int j = 0; j < n; j++)\n\t\t\t\tif\
    \ (G[i][k] != dval && G[k][j] != dval) {\n\t\t\t\t\tif (G[i][j] == dval)\n\t\t\
    \t\t\t\tG[i][j] = G[i][k] + G[k][j];\n\t\t\t\t\telse \n\t\t\t\t\t\tchmin(G[i][j],\
    \ G[i][k] + G[k][j]);\n\t\t\t\t}\n}"
  dependsOn: []
  isVerificationFile: false
  path: templates/graph/floyd-warshall.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: templates/graph/floyd-warshall.hpp
layout: document
redirect_from:
- /library/templates/graph/floyd-warshall.hpp
- /library/templates/graph/floyd-warshall.hpp.html
title: templates/graph/floyd-warshall.hpp
---
