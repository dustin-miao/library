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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: utility/addmod.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"utility/addmod.hpp\"\
    \n#include \"data-structure/recursive-segment-tree.hpp\"\n\nconst int MAX = 5e5\
    \ + 5;\nconst long long MOD = 998244353;\n\nint main() {\n\tint N, Q;\n\tcin >>\
    \ N >> Q;\n\n\tstruct stinfo {\n\t\tstruct node { long long a, b; };\n\t\tusing\
    \ T = node;\n\t\tconst T dval = {1, 0};\n\t\tvoid apply(T &a, T b) { a = b; }\n\
    \t\tT merge(T a, T b) { return {a.a * b.a % MOD, addmod(b.a * a.b % MOD, b.b,\
    \ MOD)}; }\n\t};\n\n\tSegtree<stinfo> sgt(N);\n\tfor (int i = 0; i < N; i++) {\n\
    \t\tlong long a, b; \n\t\tcin >> a >> b;\n\t\tsgt.update(i, {a, b});\n\t}\n\n\t\
    while (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\tint p; long long\
    \ c, d;\n\t\t\tcin >> p >> c >> d;\n\t\t\tsgt.update(p, {c, d});\n\t\t} else {\n\
    \t\t\tint l, r; long long x;\n\t\t\tcin >> l >> r >> x;\n\t\t\tauto [a, b] = sgt.query(l,\
    \ r - 1);\n\t\t\tcout << addmod(a * x % MOD, b, MOD) << '\\n';\n\t\t}\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp
layout: document
redirect_from:
- /verify/verify/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp
- /verify/verify/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp.html
title: verify/recursive-segment-tree.yosupo-point-set-range-composite.test.cpp
---
