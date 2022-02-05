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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/cycle-finding.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"graph/cycle-finding.hpp\"\
    \n\nint main() {\n\tint N, M;\n\tcin >> N >> M;\n\tu_graph G(N);\n\tmap<pair<int,\
    \ int>, vector<int>> id;\n\tfor (int i = 0; i < M; i++) {\n\t\tint u, v;\n\t\t\
    cin >> u >> v;\n\t\tG[u].push_back(v);\n\t\tid[{u, v}].push_back(i);\n\t}\n\n\t\
    auto cycle = find_cycle(G);\n\n\tif (cycle.empty()) {\n\t\tcout << -1 << '\\n';\n\
    \t} else {\n\t\tcout << cycle.size() << '\\n';\n\t\tfor (auto [u, v] : cycle)\
    \ {\n\t\t\tauto &vec = id[{u, v}];\n\t\t\tcout << vec.back() << '\\n';\n\t\t\t\
    vec.pop_back();\n\t\t}\n\t}\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/cycle-finding.yosupo-cycle-detection.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/cycle-finding.yosupo-cycle-detection.test.cpp
layout: document
redirect_from:
- /verify/verify/cycle-finding.yosupo-cycle-detection.test.cpp
- /verify/verify/cycle-finding.yosupo-cycle-detection.test.cpp.html
title: verify/cycle-finding.yosupo-cycle-detection.test.cpp
---
