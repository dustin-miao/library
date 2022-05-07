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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: utility/y-combinator:\
    \ line -1: no such header\n"
  code: "#include \"utility/y-combinator\"\n\n#pragma region euler_tour\n\n#ifndef\
    \ EULER_TOUR_HPP\n#define EULER_TOUR_HPP\n\nnamespace tree {\n\tpair<vector<int>,\
    \ vector<int>> euler_tour(const vector<vector<int>> &tree, int s = 0) {\n\t\t\
    int n = tree.size();\n\t\tvector<int> ltime(n), rtime(n);\n\t\tint time = -1;\n\
    \n\t\tauto dfs = y_combinator([&](auto dfs, int u, int p = -1) -> void {\n\t\t\
    \tltime[u] = ++time;\n\t\t\tfor (int v : tree[u]) {\n\t\t\t\tif (v == p)\n\t\t\
    \t\t\tcontinue;\n\t\t\t\tdfs(v, u);\n\t\t\t}\n\t\t\trtime[u] = time;\n\t\t});\n\
    \n\t\tdfs(s);\n\t\treturn make_pair(ltime, rtime);\n\t}\n}\n\n#endif\n\n#pragma\
    \ endregion euler_tour"
  dependsOn: []
  isVerificationFile: false
  path: tree/euler-tour.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/euler-tour.hpp
layout: document
title: Euler Tour
---

## Euler Tour