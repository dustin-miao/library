---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/convolution.hpp
    title: Convolution
  - icon: ':heavy_check_mark:'
    path: convolution/fast-fourier-transform.hpp
    title: Fast Fourier Transform
  - icon: ':question:'
    path: utility/pi.hpp
    title: Pi
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
    links:
    - https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
  bundledCode: "#line 1 \"verify/convolution.yosupo-frequency-table-of-tree-distances.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"utility/pi.hpp\"\
    \n#pragma region Pi\n\nconst double PI = acos(-1);\n\n#pragma endregion Pi\n#line\
    \ 2 \"convolution/fast-fourier-transform.hpp\"\n\n#pragma region fast_fourier_transform\n\
    \nnamespace conv {\n\ttemplate<typename T>\n\ttypename enable_if<is_floating_point<T>::value,\
    \ void>::type\n\tfast_fourier_transform(vector<complex<T>> &a) {\n\t\tint n =\
    \ a.size(), logn = 31 - __builtin_clz(n);\n\t\t\n\t\tvector<int> rev(n);\n\t\t\
    rev[0] = 0;\n\t\tfor (int i = 1; i < n; i++) {\n\t\t\trev[i] = (rev[i >> 1] >>\
    \ 1) + ((i & 1) << (logn - 1));\n\t\t\tif (i < rev[i])\n\t\t\t\tswap(a[i], a[rev[i]]);\n\
    \t\t}\n\n\t\tvector<complex<T>> root(n);\n\t\troot[1] = {1, 0};\n\t\tfor (int\
    \ k = 1; k < logn; k++) {\n\t\t\tT the = 2 * PI / (1 << (k + 1));\n\t\t\tcomplex<T>\
    \ z = {cos(the), sin(the)};\n\t\t\tfor (int i = (1 << (k - 1)); i < (1 << k);\
    \ i++) {\n\t\t\t\troot[i << 1] = root[i];\n\t\t\t\troot[i << 1 | 1] = root[i]\
    \ * z;\n\t\t\t}\n\t\t}\n\n\t\tfor (int l = 1; l < n; l <<= 1) {\n\t\t\tfor (int\
    \ i = 0; i < n; i += (l << 1)) {\n\t\t\t\tfor (int j = 0; j < l; j++) {\n\t\t\t\
    \t\tauto z = root[j + l] * a[i + j + l];\n\t\t\t\t\ta[i + j + l] = a[i + j] -\
    \ z;\n\t\t\t\t\ta[i + j] += z;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n}\n\n#pragma endregion\
    \ fast_fourier_transform\n#line 2 \"convolution/convolution.hpp\"\n\n#pragma region\
    \ convolution\n\nnamespace conv {\n\ttemplate<typename T, typename U = double>\n\
    \tvector<T> convolution(const vector<T> &a, const vector<T> &b) {\n\t\tint n =\
    \ 1;\n\t\twhile (n < a.size() + b.size()) \n\t\t\tn <<= 1;\n\t\tvector<complex<U>>\
    \ c(n);\n\t\tfor (int i = 0; i < a.size(); i++)\n\t\t\tc[i] = static_cast<U>(a[i]);\n\
    \t\tfor (int i = 0; i < b.size(); i++)\n\t\t\tc[i] = {c[i].real(), static_cast<U>(b[i])};\n\
    \t\tfast_fourier_transform(c);\n\n\t\tvector<complex<U>> d(n);\n\t\tfor (int i\
    \ = 0, j; i < n; i++) {\n\t\t\tj = (n - i) & (n - 1);\n\t\t\td[i] = (c[j] * c[j]\
    \ - conj(c[i] * c[i])) * complex<U>{0, -0.25 / n};\n\t\t}\n\t\tfast_fourier_transform(d);\n\
    \n\t\tn = a.size() + b.size() - 1;\n\t\tvector<T> ret(n);\n\t\tfor (int i = 0;\
    \ i < n; i++)\n\t\t\tret[i] = static_cast<T>(d[i].real() + 0.5);\n\t\treturn ret;\n\
    \t}\n}\n\n#pragma endregion convolution\n#line 7 \"verify/convolution.yosupo-frequency-table-of-tree-distances.test.cpp\"\
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"convolution/convolution.hpp\"\
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
  dependsOn:
  - convolution/convolution.hpp
  - convolution/fast-fourier-transform.hpp
  - utility/pi.hpp
  isVerificationFile: true
  path: verify/convolution.yosupo-frequency-table-of-tree-distances.test.cpp
  requiredBy: []
  timestamp: '2022-04-29 22:36:50-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/convolution.yosupo-frequency-table-of-tree-distances.test.cpp
layout: document
redirect_from:
- /verify/verify/convolution.yosupo-frequency-table-of-tree-distances.test.cpp
- /verify/verify/convolution.yosupo-frequency-table-of-tree-distances.test.cpp.html
title: verify/convolution.yosupo-frequency-table-of-tree-distances.test.cpp
---
