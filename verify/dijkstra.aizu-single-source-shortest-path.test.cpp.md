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
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"graph/dijkstra.hpp\"\
    \n\nint main() {\n\tint N, M, S;\n\tcin >> N >> M >> S;\n\tgraph<long long> G(N);\n\
    \tfor (int i = 0; i < M; i++) {\n\t\tint u, v; long long w;\n\t\tcin >> u >> v\
    \ >> w;\n\t\tG[u].emplace_back(v, w);\n\t}\n\t\n\tauto [dis, par] = dijkstra(G,\
    \ S);\n\n\tfor (int i = 0; i < N; i++) {\n\t\tif (par[i] == -1)\n\t\t\tcout <<\
    \ \"INF\\n\";\n\t\telse \n\t\t\tcout << dis[i] << '\\n';\n\t}\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/dijkstra.aizu-single-source-shortest-path.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/dijkstra.aizu-single-source-shortest-path.test.cpp
layout: document
redirect_from:
- /verify/verify/dijkstra.aizu-single-source-shortest-path.test.cpp
- /verify/verify/dijkstra.aizu-single-source-shortest-path.test.cpp.html
title: verify/dijkstra.aizu-single-source-shortest-path.test.cpp
---
