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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: random/rng-int-vector.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"geometry/line-container.hpp\"\n#include \"\
    geometry/monotonic-dp-hull.hpp\"\n#include \"random/rng-int-vector.hpp\"\n\nint\
    \ main() {\n\t{\n\t\tint T = 2e5;\n\t\tauto slope = rng::rivec<long long>(T, -1e6,\
    \ 1e6), intercept = rng_verng::rivecctor<long long>(T, -1e9, 1e9);\n\t\tauto x_coord\
    \ = rng::rivec<long long>(5 * T, -1e6, 1e6);\n\n\t\tsort(slope.begin(), slope.end());\n\
    \t\tsort(x_coord.begin(), x_coord.end());\n\n\t\tline_container lc;\n\t\tmonotonic_dp_hull\
    \ mdh;\n\t\tfor (int tc = 0; tc < T; tc++) {\n\t\t\tlc.add(slope[tc], intercept[tc]);\n\
    \t\t\tmdh.add(slope[tc], intercept[tc]);\n\t\t\tfor (int i = tc * 5; i < (tc +\
    \ 1) * 5; i++) \n\t\t\t\tassert(lc.query(x_coord[i]) == mdh.query(x_coord[i]));\n\
    \t\t}\n\t}\n\n\tlong long A, B;\n\tcin >> A >> B;\n\tcout << A + B << '\\n';\n\
    }"
  dependsOn: []
  isVerificationFile: true
  path: verify/monotonic-dp-hull.yosupo-a+b.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/monotonic-dp-hull.yosupo-a+b.test.cpp
layout: document
redirect_from:
- /verify/verify/monotonic-dp-hull.yosupo-a+b.test.cpp
- /verify/verify/monotonic-dp-hull.yosupo-a+b.test.cpp.html
title: verify/monotonic-dp-hull.yosupo-a+b.test.cpp
---
