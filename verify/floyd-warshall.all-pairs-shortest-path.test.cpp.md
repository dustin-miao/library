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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/floyd-warshall.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"graph/floyd-warshall.hpp\"\
    \n\nint main() {\n\tint N, M;\n\tcin >> N >> M;\n\tmatgraph<long long> G(N, vector<long\
    \ long>(N, LLONG_MAX));\n\tfor (int i = 0; i < M; i++) {\n\t\tint u, v; long long\
    \ w;\n\t\tcin >> u >> v >> w;\n\t\tG[u][v] = w;\n\t}\n\n\tfloyd_warshall(G, LLONG_MAX);\
    \ \n\n\tbool cycle = false;\n\tfor (int i = 0; i < N; i++)\n\t\tif (G[i][i] <\
    \ 0)\n\t\t\tcycle = true;\n\t\n\tif (cycle) {\n\t\tcout << \"NEGATIVE CYCLE\\\
    n\";\n\t} else {\n\t\tfor (int i = 0; i < N; i++) {\n\t\t\tfor (int j = 0; j <\
    \ N; j++) {\n\t\t\t\tif (G[i][j] == LLONG_MAX)\n\t\t\t\t\tcout << \"INF\";\n\t\
    \t\t\telse \n\t\t\t\t\tcout << G[i][j];\n\t\t\t\tcout << \" \\n\"[j == N - 1];\n\
    \t\t\t}\n\t\t}\n\t}\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/floyd-warshall.all-pairs-shortest-path.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/floyd-warshall.all-pairs-shortest-path.test.cpp
layout: document
redirect_from:
- /verify/verify/floyd-warshall.all-pairs-shortest-path.test.cpp
- /verify/verify/floyd-warshall.all-pairs-shortest-path.test.cpp.html
title: verify/floyd-warshall.all-pairs-shortest-path.test.cpp
---
