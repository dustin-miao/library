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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: slow-convolution/convolution.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"slow-convolution/convolution.hpp\"\
    \n\nint main() {\n\tint N;\n\tcin >> N;\n\tvector<vector<int>> T(N);\n\tfor (int\
    \ i = 1; i < N; i++) {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\tT[u].push_back(v);\n\
    \t\tT[v].push_back(u);\n\t}\n\n\tvector<long long> weight(N), ans(2 * N, 0);\n\
    \tvector<bool> block(N, false);\n\n\tconst auto init_weights = [&](const auto\
    \ &self, int u, int p = -1) -> int {\n\t\tweight[u] = 1;\n\t\tfor (int v : T[u])\
    \ {\n\t\t\tif (v == p)\n\t\t\t\tcontinue;\n\t\t\tif (!block[v])\n\t\t\t\tweight[u]\
    \ += self(self, v, u);\n\t\t}\n\t\treturn weight[u];\n\t};\n \n\tconst auto find_centroid\
    \ = [&](const auto &self, int n, int u, int p = -1) -> int {\n\t\tfor (int v :\
    \ T[u]) {\n\t\t\tif (v == p)\n\t\t\t\tcontinue;\n\t\t\tif (!block[v] && weight[v]\
    \ * 2 > n)\n\t\t\t\treturn self(self, n, v, u);\n\t\t}\n\t\treturn u;\n\t};\n\n\
    \tvector<long long> cen_dis, cen_cur;\n\n\tconst auto get_max_depth = [&](const\
    \ auto &self, int u, int p = -1) -> int {\n\t\tint ret = 0;\n\t\tfor (int v :\
    \ T[u]) {\n\t\t\tif (v == p)\n\t\t\t\tcontinue;\n\t\t\tif (!block[v])\n\t\t\t\t\
    ret = max(ret, self(self, v, u));\n\t\t}\n\t\treturn ret + 1;\n\t};\n\n\tconst\
    \ auto dfs_child = [&](const auto &self, int u, int p, int d) -> void {\n\t\t\
    cen_cur[d]++;\n\t\tfor (int v : T[u]) {\n\t\t\tif (v == p)\n\t\t\t\tcontinue;\n\
    \t\t\tif (!block[v])\n\t\t\t\tself(self, v, u, d + 1);\n\t\t}\n\t};\n\n\tconst\
    \ auto centroid_decomp = [&](const auto &self, int u) -> void {\n\t\tu = find_centroid(find_centroid,\
    \ init_weights(init_weights, u), u);\n\t\tint n = get_max_depth(get_max_depth,\
    \ u);\n\n\t\tcen_dis.assign(n, 0);\n\t\tcen_cur.resize(n);\n\t\tcen_dis[0]++;\n\
    \t\tfor (int v : T[u]) {\n\t\t\tif (block[v])\n\t\t\t\tcontinue;\n\t\t\tfill(cen_cur.begin(),\
    \ cen_cur.end(), 0);\n\t\t\tdfs_child(dfs_child, v, u, 1);\n\t\t\tauto tem = conv::convolution(cen_dis,\
    \ cen_cur);\n\t\t\tfor (int i = 0; i < tem.size(); i++)\n\t\t\t\tans[i] += tem[i];\n\
    \t\t\tfor (int i = 0; i < n; i++)\n\t\t\t\tcen_dis[i] += cen_cur[i];\n\t\t}\n\
    \ \n\t\tblock[u] = true;\n\t\tfor (int v : T[u]) \n\t\t\tif (!block[v]) \n\t\t\
    \t\tself(self, v);\n\t};\n\n\tcentroid_decomp(centroid_decomp, 0);\n\n\tfor (int\
    \ i = 1; i < N; i++)\n\t\tcout << ans[i] << ' ';\n\tcout << '\\n';\n}\n\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/slow-convolution.yosupo-frequency-table-of-tree-distances.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/slow-convolution.yosupo-frequency-table-of-tree-distances.test.cpp
layout: document
redirect_from:
- /verify/verify/slow-convolution.yosupo-frequency-table-of-tree-distances.test.cpp
- /verify/verify/slow-convolution.yosupo-frequency-table-of-tree-distances.test.cpp.html
title: verify/slow-convolution.yosupo-frequency-table-of-tree-distances.test.cpp
---
