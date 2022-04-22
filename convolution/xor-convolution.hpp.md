---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: fast-walsh-hadamand-transform.hpp:\
    \ line -1: no such header\n"
  code: "#include \"fast-walsh-hadamard-transform.hpp\"\n#include \"inverse-fast-walsh-hadamard-transform.hpp\"\
    \n\n#pragma region xor convolution\n\nnamespace conv {\n\ttemplate<typename T>\n\
    \tvector<T> xor_convolution(const vector<T> &a, const vector<T> &b) {\n\t\tvector<T>\
    \ pa(a.begin(), a.end()), pb(b.begin(), b.end());\n\t\tint n = 1;\n\t\twhile (n\
    \ < a.size() + b.size()) \n\t\t\tn <<= 1;\n\t\tpa.resize(n), pb.resize(n);\n\t\
    \tfast_walsh_hadamard_transform(pa);\n\t\tfast_walsh_hadamard_transform(pb);\n\
    \t\tfor (int i = 0; i < n; i++)\n\t\t\tpa[i] *= pb[i];\n\t\tinverse_fast_walsh_hadamard_transform(pa);\n\
    \t\treturn pa;\n\t}\n}\n\n#pragma endregion xor convolution"
  dependsOn: []
  isVerificationFile: false
  path: convolution/xor-convolution.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convolution/xor-convolution.hpp
layout: document
title: Xor Convolution
---

## Xor Convolution