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
    \ T>\npair<vector<long long>, vector<int>> dijkstra(const graph<T> &G, int s)\
    \ {\n\tsize_t n = G.size();\n\tpriority_queue<pair<T, int>, vector<pair<T, int>>,\
    \ greater<pair<T, int>>> pq;\n\tvector<T> dis(n, numeric_limits<T>::max());\n\t\
    vector<int> par(n, -1);\n\n\tpq.emplace(0, s);\n\tdis[s] = 0;\n\tpar[s] = s;\n\
    \twhile (!pq.empty()) {\n\t\tauto [d, u] = pq.top(); pq.pop();\n\t\tif (d != dis[u])\n\
    \t\t\tcontinue;\n\t\tfor (auto [v, w] : G[u])\n\t\t\tif (chmin(dis[v], d + w))\
    \ {\n\t\t\t\tpar[v] = u;\n\t\t\t\tpq.emplace(dis[v], v);\n\t\t\t}\n\t}\n\treturn\
    \ {dis, par};\n}"
  dependsOn: []
  isVerificationFile: false
  path: templates/graph/dijkstra.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: templates/graph/dijkstra.hpp
layout: document
redirect_from:
- /library/templates/graph/dijkstra.hpp
- /library/templates/graph/dijkstra.hpp.html
title: templates/graph/dijkstra.hpp
---
