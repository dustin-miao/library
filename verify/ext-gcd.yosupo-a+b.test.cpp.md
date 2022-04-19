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
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: random/mersenne_twister.md:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"math/ext-gcd.hpp\"\
    \n#include \"random/mersenne_twister.md\"\n\nint main() {\n\tint T = 2e5;\n\t\
    while (T--) {\n\t\tlong long A = rng<long long>(1, 1e9);\n\t\tlong long B = rng<long\
    \ long>(1, 1e9);\n\t\tlong long X, Y;\n\t\tauto G = math::ext_gcd(A, B, X, Y);\n\
    \t\tassert(G == __gcd(A, B));\n\t\tassert(A * X + B * Y == G);\n\t}\n\n\tlong\
    \ long A, B;\n\tcin >> A >> B;\n\tcout << A + B << '\\n';\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/ext-gcd.yosupo-a+b.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/ext-gcd.yosupo-a+b.test.cpp
layout: document
redirect_from:
- /verify/verify/ext-gcd.yosupo-a+b.test.cpp
- /verify/verify/ext-gcd.yosupo-a+b.test.cpp.html
title: verify/ext-gcd.yosupo-a+b.test.cpp
---
