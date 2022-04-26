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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: data-structure/line-container.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/line-container.hpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\tline_container lc;\n\tfor (int\
    \ i = 0; i < N; i++) {\n\t\tlong long m, b;\n\t\tcin >> m >> b;\n\t\tlc.add(-m,\
    \ -b);\n\t}\n\twhile (Q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\t\
    long long m, b;\n\t\t\tcin >> m >> b;\n\t\t\tlc.add(-m, -b);\n\t\t} else if (t\
    \ == 1) {\n\t\t\tlong long x;\n\t\t\tcin >> x;\n\t\t\tcout << -lc.query(x) <<\
    \ '\\n';\n\t\t}\n\t}\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/line-container.yosupo-line-add-get-min.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/line-container.yosupo-line-add-get-min.test.cpp
layout: document
redirect_from:
- /verify/verify/line-container.yosupo-line-add-get-min.test.cpp
- /verify/verify/line-container.yosupo-line-add-get-min.test.cpp.html
title: verify/line-container.yosupo-line-add-get-min.test.cpp
---
