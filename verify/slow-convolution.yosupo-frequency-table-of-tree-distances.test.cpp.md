---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: convolution/reverse-bit-radix-sort.hpp
    title: Reverse Bit Radix Sort
  - icon: ':x:'
    path: convolution/slow-convolution.hpp
    title: Slow Convolution
  - icon: ':x:'
    path: convolution/slow-fast-fourier-transform.hpp
    title: Slow Fast Fourier Transform
  - icon: ':question:'
    path: utility/pi.hpp
    title: Pi
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
    links:
    - https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
  bundledCode: "#line 1 \"verify/slow-convolution.yosupo-frequency-table-of-tree-distances.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"utility/pi.hpp\"\
    \n#pragma region Pi\n\nconst double PI = acos(-1);\n\n#pragma endregion Pi\n#line\
    \ 1 \"convolution/reverse-bit-radix-sort.hpp\"\n#pragma region reverse_bit_radix_sort\n\
    \ntemplate<typename T>\nvoid reverse_bit_radix_sort(vector<T> &a) {\n\tint n =\
    \ a.size();\n\tfor (int i = 1, j = 0; i < n; i++) {\n\t\tint t = n >> 1;\n\t\t\
    for (; t & j; t >>= 1)\n\t\t\tj ^= t;\n\t\tj ^= t;\n\t\tif (i < j)\n\t\t\tswap(a[i],\
    \ a[j]);\n\t}\n}\n\n#pragma endregion reverse_bit_radix_sort\n#line 3 \"convolution/slow-fast-fourier-transform.hpp\"\
    \n\n#pragma region slow_fast_fourier_transform\n\nnamespace conv {\n\ttemplate<typename\
    \ T> \n\ttypename enable_if<is_floating_point<T>::value, void>::type\n\tslow_fast_fourier_transform(vector<complex<T>>\
    \ &a) {\n\t\tint n = a.size();\n\t\treverse_bit_radix_sort(a);\n\t\tfor (int l\
    \ = 2; l <= n; l <<= 1) {\n\t\t\tT theta = 2 * PI / l;\n\t\t\tcomplex<T> dw(cos(theta),\
    \ sin(theta));\n\t\t\tfor (int i = 0; i < n; i += l) {\n\t\t\t\tcomplex<T> w =\
    \ 1;\n\t\t\t\tfor (int j = 0; j < l / 2; j++) {\n\t\t\t\t\tauto t1 = a[i + j],\
    \ t2 = a[i + j + l / 2] * w;\n\t\t\t\t\ta[i + j] = t1 + t2;\n\t\t\t\t\ta[i + j\
    \ + l / 2] = t1 - t2;\n\t\t\t\t\tw *= dw;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\n\t\
    template<typename T> \n\ttypename enable_if<is_floating_point<T>::value, void>::type\n\
    \tslow_inverse_fast_fourier_transform(vector<complex<T>> &a) {\n\t\tint n = a.size();\n\
    \t\treverse_bit_radix_sort(a);\n\t\tfor (int l = 2; l <= n; l <<= 1) {\n\t\t\t\
    T theta = -2 * PI / l;\n\t\t\tcomplex<T> dw(cos(theta), sin(theta));\n\t\t\tfor\
    \ (int i = 0; i < n; i += l) {\n\t\t\t\tcomplex<T> w = 1;\n\t\t\t\tfor (int j\
    \ = 0; j < l / 2; j++) {\n\t\t\t\t\tauto t1 = a[i + j], t2 = a[i + j + l / 2]\
    \ * w;\n\t\t\t\t\ta[i + j] = t1 + t2;\n\t\t\t\t\ta[i + j + l / 2] = t1 - t2;\n\
    \t\t\t\t\tw *= dw;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tfor (int i = 0; i < n; i++)\n\
    \t\t\ta[i] /= n;\n\t}\n}\n\n#pragma endregion slow_fast_fourier_transform\n#line\
    \ 2 \"convolution/slow-convolution.hpp\"\n\n#pragma region slow_convolution\n\n\
    namespace conv {\n\ttemplate<typename T, typename U = double>\n\tvector<T> slow_convolution(const\
    \ vector<T> &a, const vector<T> &b) {\n\t\tvector<complex<U>> pa(a.begin(), a.end()),\
    \ pb(b.begin(), b.end());\n\t\tint n = 1;\n\t\twhile (n < a.size() + b.size())\
    \ \n\t\t\tn <<= 1;\n\t\tpa.resize(n), pb.resize(n);\n\n\t\tslow_fast_fourier_transform(pa);\n\
    \t\tslow_fast_fourier_transform(pb);\n\t\tfor (int i = 0; i < n; i++)\n\t\t\t\
    pa[i] *= pb[i];\n\t\tslow_inverse_fast_fourier_transform(pa);\n\n\t\tn = a.size()\
    \ + b.size() - 1;\n\t\tvector<T> ret(n);\n\t\tfor (int i = 0; i < n; i++)\n\t\t\
    \tret[i] = static_cast<T>(pa[i].real() + 0.5);\n\t\treturn ret;\n\t}\n}\n\n#pragma\
    \ endregion slow_convolution\n#line 7 \"verify/slow-convolution.yosupo-frequency-table-of-tree-distances.test.cpp\"\
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
    \ cen_cur.end(), 0);\n\t\t\tdfs_child(dfs_child, v, u, 1);\n\t\t\tauto tem = conv::slow_convolution(cen_dis,\
    \ cen_cur);\n\t\t\tfor (int i = 0; i < tem.size(); i++)\n\t\t\t\tans[i] += tem[i];\n\
    \t\t\tfor (int i = 0; i < n; i++)\n\t\t\t\tcen_dis[i] += cen_cur[i];\n\t\t}\n\
    \ \n\t\tblock[u] = true;\n\t\tfor (int v : T[u]) \n\t\t\tif (!block[v]) \n\t\t\
    \t\tself(self, v);\n\t};\n\n\tcentroid_decomp(centroid_decomp, 0);\n\n\tfor (int\
    \ i = 1; i < N; i++)\n\t\tcout << ans[i] << ' ';\n\tcout << '\\n';\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"convolution/slow-convolution.hpp\"\
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
    \ cen_cur.end(), 0);\n\t\t\tdfs_child(dfs_child, v, u, 1);\n\t\t\tauto tem = conv::slow_convolution(cen_dis,\
    \ cen_cur);\n\t\t\tfor (int i = 0; i < tem.size(); i++)\n\t\t\t\tans[i] += tem[i];\n\
    \t\t\tfor (int i = 0; i < n; i++)\n\t\t\t\tcen_dis[i] += cen_cur[i];\n\t\t}\n\
    \ \n\t\tblock[u] = true;\n\t\tfor (int v : T[u]) \n\t\t\tif (!block[v]) \n\t\t\
    \t\tself(self, v);\n\t};\n\n\tcentroid_decomp(centroid_decomp, 0);\n\n\tfor (int\
    \ i = 1; i < N; i++)\n\t\tcout << ans[i] << ' ';\n\tcout << '\\n';\n}\n\n"
  dependsOn:
  - convolution/slow-convolution.hpp
  - convolution/slow-fast-fourier-transform.hpp
  - utility/pi.hpp
  - convolution/reverse-bit-radix-sort.hpp
  isVerificationFile: true
  path: verify/slow-convolution.yosupo-frequency-table-of-tree-distances.test.cpp
  requiredBy: []
  timestamp: '2022-04-29 22:36:50-07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/slow-convolution.yosupo-frequency-table-of-tree-distances.test.cpp
layout: document
redirect_from:
- /verify/verify/slow-convolution.yosupo-frequency-table-of-tree-distances.test.cpp
- /verify/verify/slow-convolution.yosupo-frequency-table-of-tree-distances.test.cpp.html
title: verify/slow-convolution.yosupo-frequency-table-of-tree-distances.test.cpp
---
