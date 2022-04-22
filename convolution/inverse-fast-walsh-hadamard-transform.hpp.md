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
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: convolution/fast-walsh-hadamand-transform.hpp:\
    \ line -1: no such header\n"
  code: "#include \"convolution/fast-walsh-hadamand-transform.hpp\"\n\n#pragma region\
    \ inverse fast walsh hadamard transform\n\nnamespace conv {\n\ttemplate<typename\
    \ T>\n\tvoid inverse_fast_walsh_hadamard_transform(vector<T> &a) {\n\t\tfast_walsh_hadamard_transform<T>(a);\n\
    \t\tif constexpr (is_integral<T>::value) {\n\t\t\tint n = a.size();\n\t\t\tfor\
    \ (auto &x : a)\n\t\t\t\tx /= n;\n\t\t} else {\n\t\t\tT t = T(1) / T(a.size());\n\
    \t\t\tfor (auto &x : a)\n\t\t\t\tx *= t;\n\t\t}\n\t}\n}\n\n#pragma endregion inverse\
    \ fast walsh hadamard transform"
  dependsOn: []
  isVerificationFile: false
  path: convolution/inverse-fast-walsh-hadamard-transform.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convolution/inverse-fast-walsh-hadamard-transform.hpp
layout: document
title: Inverse Fast Walsh-Hadamard Transform
---

## Inverse Fast Walsh-Hadamard Transform