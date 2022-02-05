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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: data-structure/segment-tree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/segment-tree.hpp\"\
    \n\nconst int MAX = 5e5 + 5;\n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\n\
    \tstruct stinfo {\n\t\tusing T = long long;\n\t\tconst T dval = 0;\n\t\tvoid apply(T\
    \ &a, T b) { a += b; }\n\t\tT merge(T a, T b) { return a + b; }\n\t};\n\n\tSegtree<stinfo>\
    \ sgt(N);\n\tfor (int i = 0; i < N; i++) {\n\t\tlong long a; cin >> a;\n\t\tsgt.update(i,\
    \ a);\n\t}\n\twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\tint\
    \ p; long long x;\n\t\t\tcin >> p >> x;\n\t\t\tsgt.update(p, x);\n\t\t} else {\n\
    \t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\t\t\tcout << sgt.query(l, r - 1) << '\\\
    n';\n\t\t}\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/segment-tree.yosupo-point-add-range-sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/segment-tree.yosupo-point-add-range-sum.test.cpp
layout: document
redirect_from:
- /verify/verify/segment-tree.yosupo-point-add-range-sum.test.cpp
- /verify/verify/segment-tree.yosupo-point-add-range-sum.test.cpp.html
title: verify/segment-tree.yosupo-point-add-range-sum.test.cpp
---
