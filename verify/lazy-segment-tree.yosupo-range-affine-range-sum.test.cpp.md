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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"utility/addmod.hpp\"\
    \n#include \"data-structure/lazy-segment-tree.hpp\"\n\nconst int MAX = 5e5 + 5;\n\
    const long long MOD = 998244353;\n\nint main() {\n\tint N, Q; \n\tcin >> N >>\
    \ Q;\n\t\n\tstruct stinfo {\n\t\tusing T = long long;\n\t\tusing L = pair<long\
    \ long, long long>;\n\n\t\tconst T Tdval = 0;\n\t\tconst L Ldval = {1, 0};\n\n\
    \t\tvoid apply(T &a, L &b, L c, int l, int r) {\n\t\t\ta = addmod(c.first * a\
    \ % MOD, c.second * (r - l + 1) % MOD, MOD);\n\t\t\tb = {c.first * b.first % MOD,\
    \ addmod(c.first * b.second % MOD, c.second, MOD)};\n\t\t}\t\n\n\t\tT merge(T\
    \ a, T b) { return addmod(a, b, MOD); }\n\t};\n\t\n\tSegtree<stinfo> sgt(N);\n\
    \tfor (int i = 0; i < N; i++) {\n\t\tlong long a; cin >> a;\n\t\tsgt.update(i,\
    \ i, {1, a});\n\t}\n\twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\
    \t\t\tint l, r; long long b, c;\n\t\t\tcin >> l >> r >> b >> c;\n\t\t\tsgt.update(l,\
    \ r - 1, {b, c});\n\t\t} else {\n\t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\t\t\t\
    cout << sgt.query(l, r - 1) << '\\n';\n\t\t}\n\t}\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/lazy-segment-tree.yosupo-range-affine-range-sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/lazy-segment-tree.yosupo-range-affine-range-sum.test.cpp
layout: document
redirect_from:
- /verify/verify/lazy-segment-tree.yosupo-range-affine-range-sum.test.cpp
- /verify/verify/lazy-segment-tree.yosupo-range-affine-range-sum.test.cpp.html
title: verify/lazy-segment-tree.yosupo-range-affine-range-sum.test.cpp
---
