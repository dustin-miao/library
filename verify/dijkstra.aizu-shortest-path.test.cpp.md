---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/dijkstra.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"graph/dijkstra.hpp\"\n\n\
    int main() {\n\tint N, M, S, T;\n\tcin >> N >> M >> S >> T;\n\tgraph<long long>\
    \ G(N);\n\tfor (int i = 0; i < M; i++) {\n\t\tint u, v; long long w;\n\t\tcin\
    \ >> u >> v >> w;\n\t\tG[u].emplace_back(v, w);\n\t}\n\t\n\tauto [dis, par] =\
    \ dijkstra(G, S);\n\n\tif (par[T] == -1) {\n\t\tcout << -1 << '\\n';\n\t\treturn\
    \ 0;\n\t}\n\n\tvector<int> path;\n\tfor (int u = T; u != S; u = par[u])\n\t\t\
    path.push_back(u);\n\tpath.push_back(S);\n\treverse(path.begin(), path.end());\n\
    \n\tcout << dis[T] << ' ' << path.size() - 1 << '\\n';\n\tfor (int i = 1; i <\
    \ path.size(); i++)\n\t\tcout << path[i - 1] << ' ' << path[i] << '\\n';\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/dijkstra.aizu-shortest-path.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/dijkstra.aizu-shortest-path.test.cpp
layout: document
redirect_from:
- /verify/verify/dijkstra.aizu-shortest-path.test.cpp
- /verify/verify/dijkstra.aizu-shortest-path.test.cpp.html
title: verify/dijkstra.aizu-shortest-path.test.cpp
---
