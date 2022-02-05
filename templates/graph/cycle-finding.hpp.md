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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/graph-util.hpp:\
    \ line -1: no such header\n"
  code: "#include \"graph/graph-util.hpp\"\n\nvector<pair<int, int>> find_cycle(const\
    \ u_graph &G, const bool directed = true) {\n\tsize_t n = G.size();\n\tvector<int>\
    \ idx(n, -1), vis(n, 0);\n\tvector<pair<int, int>> cycle;\n\tbool fin = 0;\n\n\
    \tconst auto dfs = [&](const auto &self, int u, int id, int p) -> int {\n\t\t\
    idx[u] = id, vis[u] = 1;\n\t\tfor (int v : G[u]) {\n\t\t\tif (fin)\n\t\t\t\treturn\
    \ -1;\n\t\t\tif (!directed && v == p)\n\t\t\t\tcontinue;\n\t\t\tif (idx[u] ==\
    \ idx[v]) {\n\t\t\t\tcycle.emplace_back(u, v);\n\t\t\t\treturn v;\n\t\t\t}\n\t\
    \t\tif (vis[v])\n\t\t\t\tcontinue;\n\t\t\tint k = self(self, v, id, u);\n\t\t\t\
    if (k != -1) {\n\t\t\t\tcycle.emplace_back(u, v);\n\t\t\t\tif (u == k) {\n\t\t\
    \t\t\tfin = 1;\n\t\t\t\t\treturn -1;\n\t\t\t\t}\n\t\t\t\treturn k;\n\t\t\t}\n\t\
    \t}\n\t\tidx[u] = -1;\n\t\treturn -1;\n\t};\n\n\tfor (int i = 0; i < n; i++) {\n\
    \t\tif (vis[i])\n\t\t\tcontinue;\n\t\tdfs(dfs, i, i, -1);\n\t\tif (fin) {\n\t\t\
    \treverse(cycle.begin(), cycle.end());\n\t\t\treturn cycle;\n\t\t}\n\t}\n\treturn\
    \ vector<pair<int, int>>{};\n}\n\ntemplate<typename T>\nvector<pair<int, int>>\
    \ find_cycle(const graph<T> &G, const bool directed = true) {\n\tsize_t n = G.size();\n\
    \tvector<int> idx(n, -1), vis(n, 0);\n\tvector<pair<int, int>> cycle;\n\tbool\
    \ fin = 0;\n\n\tconst auto dfs = [&](const auto &self, int u, int id, int p) ->\
    \ int {\n\t\tidx[u] = id, vis[u] = 1;\n\t\tfor (auto [v, w] : G[u]) {\n\t\t\t\
    if (fin)\n\t\t\t\treturn -1;\n\t\t\tif (!directed && v == p)\n\t\t\t\tcontinue;\n\
    \t\t\tif (idx[u] == idx[v]) {\n\t\t\t\tcycle.emplace_back(u, v);\n\t\t\t\treturn\
    \ v;\n\t\t\t}\n\t\t\tif (vis[v])\n\t\t\t\tcontinue;\n\t\t\tint k = self(self,\
    \ v, id, u);\n\t\t\tif (k != -1) {\n\t\t\t\tcycle.emplace_back(u, v);\n\t\t\t\t\
    if (u == k) {\n\t\t\t\t\tfin = 1;\n\t\t\t\t\treturn -1;\n\t\t\t\t}\n\t\t\t\treturn\
    \ k;\n\t\t\t}\n\t\t}\n\t\tidx[u] = -1;\n\t\treturn -1;\n\t};\n\n\tfor (int i =\
    \ 0; i < n; i++) {\n\t\tif (vis[i])\n\t\t\tcontinue;\n\t\tdfs(dfs, i, i, -1);\n\
    \t\tif (fin) {\n\t\t\treverse(cycle.begin(), cycle.end());\n\t\t\treturn cycle;\n\
    \t\t}\n\t}\n\treturn vector<pair<int, int>>{};\n}"
  dependsOn: []
  isVerificationFile: false
  path: templates/graph/cycle-finding.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: templates/graph/cycle-finding.hpp
layout: document
redirect_from:
- /library/templates/graph/cycle-finding.hpp
- /library/templates/graph/cycle-finding.hpp.html
title: templates/graph/cycle-finding.hpp
---
