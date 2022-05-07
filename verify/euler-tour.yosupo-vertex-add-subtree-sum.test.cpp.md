---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: utility/y-combinator:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"tree/euler-tour.hpp\"\
    \n#include \"data-structure/static-segment-tree.hpp\"\n\nint main() {\n\tint N,\
    \ Q;\n\tcin >> N >> Q;\n\tvector<long long> A(N);\n\tfor (auto &a : A)\n\t\tcin\
    \ >> a;\n\tvector<vector<int>> T(N);\n\tfor (int i = 1; i < N; i++) {\n\t\tint\
    \ p;\n\t\tcin >> p;\n\t\tT[p].push_back(i);\n\t}\n\n\tauto [ltime, rtime] = tree::euler_tour(T);\n\
    \n\tsta_segment_tree st(N);\n\tfor (int u = 0; u < N; u++)\n\t\tst.update(ltime[u],\
    \ A[u]);\n\twhile (Q--) {\n\t\tint t;\n\t\tcin >> t;\n\t\tif (t == 0) {\n\t\t\t\
    int u;\n\t\t\tlong long x;\n\t\t\tcin >> u >> x;\n\t\t\tst.update(ltime[u], x);\n\
    \t\t} else if (t == 1) {\n\t\t\tint u;\n\t\t\tcin >> u;\n\t\t\tcout << st.query(ltime[u],\
    \ rtime[u]) << '\\n';\n\t\t}\n\t}\n\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/euler-tour.yosupo-vertex-add-subtree-sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/euler-tour.yosupo-vertex-add-subtree-sum.test.cpp
layout: document
redirect_from:
- /verify/verify/euler-tour.yosupo-vertex-add-subtree-sum.test.cpp
- /verify/verify/euler-tour.yosupo-vertex-add-subtree-sum.test.cpp.html
title: verify/euler-tour.yosupo-vertex-add-subtree-sum.test.cpp
---
