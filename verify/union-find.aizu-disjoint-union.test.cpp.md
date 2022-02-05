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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: data-structure/union-find.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/union-find.hpp\"\
    \n\nint main() {\n\tint N, Q;\n  \tcin >> N >> Q;\n\tUnionFind dsu(N);\n  \twhile\
    \ (Q--) {\n    \tint t, u, v;\n    \tcin >> t >> u >> v;\n\t\tif (t == 0)\n\t\
    \      \tdsu.merge(u, v);\n    \telse\n      \t\tcout << (dsu.find(u) == dsu.find(v)\
    \ ? 1 : 0) << '\\n';\n  \t}\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/union-find.aizu-disjoint-union.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/union-find.aizu-disjoint-union.test.cpp
layout: document
redirect_from:
- /verify/verify/union-find.aizu-disjoint-union.test.cpp
- /verify/verify/union-find.aizu-disjoint-union.test.cpp.html
title: verify/union-find.aizu-disjoint-union.test.cpp
---
