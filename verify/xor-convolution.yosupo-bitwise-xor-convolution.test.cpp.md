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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: convolution/fast-walsh-hadamand-transform.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"convolution/xor-convolution.hpp\"\
    \n#include \"utility/mint.hpp\"\n\nint main() {\n\tMOD = 998244353;\n\n\tint N;\n\
    \tcin >> N;\n\tvector<mint> A(1 << N), B(1 << N);\n\tfor (auto &a : A)\n\t\tcin\
    \ >> a;\n\tfor (auto &b : B)\n\t\tcin >> b;\n\tauto C = conv::xor_convolution(A,\
    \ B);\n\tfor (int i = 0; i < (1 << N); i++)\n\t\tcout << C[i] << ' ';\n\tcout\
    \ << '\\n';\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/xor-convolution.yosupo-bitwise-xor-convolution.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/xor-convolution.yosupo-bitwise-xor-convolution.test.cpp
layout: document
redirect_from:
- /verify/verify/xor-convolution.yosupo-bitwise-xor-convolution.test.cpp
- /verify/verify/xor-convolution.yosupo-bitwise-xor-convolution.test.cpp.html
title: verify/xor-convolution.yosupo-bitwise-xor-convolution.test.cpp
---
