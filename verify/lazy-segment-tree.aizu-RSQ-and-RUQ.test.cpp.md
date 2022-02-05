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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: data-structure/lazy-segment-tree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/lazy-segment-tree.hpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\n\tstruct stinfo {\n\t\tusing\
    \ T = long long;\n\t\tusing L = long long;\n\n\t\tconst T Tdval = 0;\n\t\tconst\
    \ L Ldval = LLONG_MAX;\n\n\t\tvoid apply(T &a, L &b, L c, int l, int r) {\n\t\t\
    \ta = c * (r - l + 1);\n\t\t\tb = c;\n\t\t}\n\n\t\tT merge(T a, T b) { return\
    \ a + b; }\n\t};\n\n\tSegtree<stinfo> sgt(N);\n\twhile (Q--) {\n\t\tint t; cin\
    \ >> t;\n\t\tif (t == 0) {\n\t\t\tint l, r; long long v;\n\t\t\tcin >> l >> r\
    \ >> v;\n\t\t\tsgt.update(l, r, v);\n\t\t} else if (t == 1) {\n\t\t\tint l, r;\
    \ \n\t\t\tcin >> l >> r;\n\t\t\tcout << sgt.query(l, r) << '\\n';\n\t\t}\n\t}\n\
    }"
  dependsOn: []
  isVerificationFile: true
  path: verify/lazy-segment-tree.aizu-RSQ-and-RUQ.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/lazy-segment-tree.aizu-RSQ-and-RUQ.test.cpp
layout: document
redirect_from:
- /verify/verify/lazy-segment-tree.aizu-RSQ-and-RUQ.test.cpp
- /verify/verify/lazy-segment-tree.aizu-RSQ-and-RUQ.test.cpp.html
title: verify/lazy-segment-tree.aizu-RSQ-and-RUQ.test.cpp
---
