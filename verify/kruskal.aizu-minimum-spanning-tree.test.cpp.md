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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/kruskal.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"graph/kruskal.hpp\"\
    \n\nint main() {\n\tint N, M;\n\tcin >> N >> M;\n\tedgelist<long long> E;\n\t\
    for (int i = 0; i < M; i++) {\n\t\tint u, v; long long w;\n\t\tcin >> u >> v >>\
    \ w;\n\t\tE.emplace_back(u, v, w);\n\t}\n\tauto T = kruskal(N, E);\n\tlong long\
    \ ans = 0;\n\tfor (int u = 0; u < N; u++)\n\t\tfor (auto [v, w] : T[u])\n\t\t\t\
    ans += w;\n\tcout << ans / 2 << '\\n';\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/kruskal.aizu-minimum-spanning-tree.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/kruskal.aizu-minimum-spanning-tree.test.cpp
layout: document
redirect_from:
- /verify/verify/kruskal.aizu-minimum-spanning-tree.test.cpp
- /verify/verify/kruskal.aizu-minimum-spanning-tree.test.cpp.html
title: verify/kruskal.aizu-minimum-spanning-tree.test.cpp
---
