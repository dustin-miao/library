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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: data-structure/sparse-segment-tree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/sparse-segment-tree.hpp\"\
    \n\nconst int MAX = 1e9 + 5;\n\nint main() {\n\tint N;\n\tcin >> N;\n\n\tstruct\
    \ stinfo {\n\t\tusing T = int;\n\t\tconst T dval = 0;\n\t\tT merge(T a, T b) {\
    \ return a + b; }\n\t\tvoid apply(T &a, T b) { a += b; }\n\t};\n\n\tlong long\
    \ ans = 0;\n\tSegtree<stinfo> sgt(MAX);\n\tsgt.reserve(N * 30);\n\tfor (int i\
    \ = 0; i < N; i++) {\n\t\tint a; cin >> a;\n\t\tans += sgt.query(a, MAX - 1);\n\
    \t\tsgt.update(a, 1);\n\t}\n\tcout << ans << '\\n';\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/sparse-segment-tree.aizu-the-number-of-inversions.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/sparse-segment-tree.aizu-the-number-of-inversions.test.cpp
layout: document
redirect_from:
- /verify/verify/sparse-segment-tree.aizu-the-number-of-inversions.test.cpp
- /verify/verify/sparse-segment-tree.aizu-the-number-of-inversions.test.cpp.html
title: verify/sparse-segment-tree.aizu-the-number-of-inversions.test.cpp
---
