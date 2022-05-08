---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/wavelet-tree.hpp
    title: Wavelet Tree
  - icon: ':heavy_check_mark:'
    path: random/mersenne-twister.hpp
    title: Mersenne Twister
  - icon: ':heavy_check_mark:'
    path: random/mersenne-twister.hpp
    title: Mersenne Twister
  - icon: ':heavy_check_mark:'
    path: random/random-vector.hpp
    title: Randomized Vector
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/wavelet-tree.yosupo-a+b.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n#line 1 \"data-structure/wavelet-tree.hpp\"\n#pragma region\
    \ wavelet_tree\n\n#ifndef WAVELET_TREE_HPP\n#define WAVELET_TREE_HPP\n\nclass\
    \ wavelet_tree {\n\tint n, vlb, vrb;\n\tvector<vector<int>> tree;\n\n\ttemplate<typename\
    \ I>\n\tvoid build(I begin, I end, int t, int vl, int vr) {\n\t\tif (vl == vr)\n\
    \t\t\treturn;\n\t\tint vm = (vl + vr) / 2;\n\t\ttree[t].reserve(end - begin +\
    \ 1);\n\t\ttree[t].push_back(0);\n\t\tfor (auto it = begin; it != end; it++)\n\
    \t\t\ttree[t].push_back(tree[t].back() + (*it <= vm));\n\t\tauto pivot = stable_partition(begin,\
    \ end, [vm](int x) { return x <= vm; });\n\t\tbuild(begin, pivot, t * 2, vl, vm);\n\
    \t\tbuild(pivot, end, t * 2 + 1, vm + 1, vr);\n\t}\n\n\tint quantile(int l, int\
    \ r, int k, int t, int vl, int vr) {\n\t\tif (vl == vr)\n\t\t\treturn vl;\n\t\t\
    int vm = (vl + vr) / 2, lv = tree[t][r] - tree[t][l - 1];\n\t\tif (k <= lv)\n\t\
    \t\treturn quantile(tree[t][l - 1] + 1, tree[t][r], k, t * 2, vl, vm);\n\t\telse\
    \ \n\t\t\treturn quantile(l - tree[t][l - 1], r - tree[t][r], k - lv, t * 2 +\
    \ 1, vm + 1, vr);\n\t}\n\n\tint cnt_leq(int l, int r, int k, int t, int vl, int\
    \ vr) {\n\t\tif (k < vl)\n\t\t\treturn 0;\n\t\tif (vr <= k)\n\t\t\treturn r -\
    \ l + 1;\n\t\tint vm = (vl + vr) / 2;\n\t\treturn cnt_leq(tree[t][l - 1] + 1,\
    \ tree[t][r], k, t * 2, vl, vm) + \\\n\t\t\tcnt_leq(l - tree[t][l - 1], r - tree[t][r],\
    \ k, t * 2 + 1, vm + 1, vr);\n\t}\n\n\tint cnt_eq(int l, int r, int k, int t,\
    \ int vl, int vr) {\n\t\tif (k < vl || k > vr)\n\t\t\treturn 0;\n\t\tif (vl ==\
    \ vr)\n\t\t\treturn r - l + 1;\n\t\tint vm = (vl + vr) / 2;\n\t\tif (k <= vm)\n\
    \t\t\treturn cnt_eq(tree[t][l - 1] + 1, tree[t][r], k, t * 2, vl, vm);\n\t\telse\n\
    \t\t\treturn cnt_eq(l - tree[t][l - 1], r - tree[t][r], k, t * 2 + 1, vm + 1,\
    \ vr);\n\t}\n\npublic:\n\twavelet_tree() = default;\n\n\ttemplate<typename I>\n\
    \twavelet_tree(I begin, I end, int vl, int vr) { init(begin, end, vl, vr); }\n\
    \n\ttemplate<typename I>\n\tvoid init(I begin, I end, int vl, int vr) {\n\t\t\
    n = vr - vl + 1;\n\t\tvlb = vl, vrb = vr;\n\t\ttree.resize(4 * n);\n\t\tbuild(begin,\
    \ end, 1, vl, vr);\n\t}\n\n\tint quantile(int l, int r, int k) { return quantile(l\
    \ + 1, r + 1, k + 1, 1, vlb, vrb); }\n\n\tint cnt_leq(int l, int r, int k) { return\
    \ cnt_leq(l + 1, r + 1, k, 1, vlb, vrb); }\n\n\tint cnt_eq(int l, int r, int k)\
    \ { return cnt_eq(l + 1, r + 1, k, 1, vlb, vrb); }\n};\n\n#endif \n\n#pragma endregion\
    \ wavelet_tree\n#line 1 \"random/mersenne-twister.hpp\"\n#pragma region rng\n\n\
    #ifndef MERSENNE_TWISTER_HPP\n#define MERSENNE_TWISTER_HPP\n\nmt19937 _rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    \ntemplate<typename T = int>\ntypename enable_if<is_integral<T>::value, T>::type\
    \ rng(T l, T r) { return uniform_int_distribution<T>(l, r)(_rng); }\n\n#endif\n\
    \n#pragma endregion rng\n#line 1 \"random/mersenne-twister.hpp\"\n#pragma region\
    \ rng\n\n#ifndef MERSENNE_TWISTER_HPP\n#define MERSENNE_TWISTER_HPP\n\nmt19937\
    \ _rng(chrono::steady_clock::now().time_since_epoch().count());\n\ntemplate<typename\
    \ T = int>\ntypename enable_if<is_integral<T>::value, T>::type rng(T l, T r) {\
    \ return uniform_int_distribution<T>(l, r)(_rng); }\n\n#endif\n\n#pragma endregion\
    \ rng\n#line 2 \"random/random-vector.hpp\"\n\n#pragma region rng_vector\n\n#ifndef\
    \ RNG_VECTOR_HPP\n#define RNG_VECTOR_HPP\n\ntemplate<typename T>\ntypename enable_if<is_integral<T>::value,\
    \ vector<T>>::type rng_vector(int n, T l, T r) {\n\tvector<T> v(n);\n\tfor (auto\
    \ &a : v)\n\t\ta = rng(l, r);\n\treturn v;\n}\n\n#endif\n\n#pragma endregion rng_vector\n\
    #line 9 \"verify/wavelet-tree.yosupo-a+b.test.cpp\"\n\nint main() {\n\t{\n\t\t\
    int N = 10000, L = 300, Q = 10000;\n\t\tvector<int> A = rng_vector(N, 0, L);\n\
    \t\tvector<int> B(A);\n\t\twavelet_tree wt(B.begin(), B.end(), 0, L);\n\t\twhile\
    \ (Q--) {\n\t\t\tint t = rng(0, 1);\n\t\t\tif (t == 0) {\n\t\t\t\tint l = rng(0,\
    \ N - 1), r = rng(0, N - 1), k = rng(0, L);\n\t\t\t\tif (r < l)\n\t\t\t\t\tswap(l,\
    \ r);\n\t\t\t\tint ret = 0;\n\t\t\t\tfor (int i = l; i <= r; i++)\n\t\t\t\t\t\
    if (A[i] <= k)\n\t\t\t\t\t\tret++;\n\t\t\t\tassert(ret == wt.cnt_leq(l, r, k));\n\
    \t\t\t} else if (t == 1) {\n\t\t\t\tint l = rng(0, N - 1), r = rng(0, N - 1),\
    \ k = rng(0, L);\n\t\t\t\tif (r < l)\n\t\t\t\t\tswap(l, r);\n\t\t\t\tint ret =\
    \ 0;\n\t\t\t\tfor (int i = l; i <= r; i++)\n\t\t\t\t\tif (A[i] == k)\n\t\t\t\t\
    \t\tret++;\n\t\t\t\tassert(ret == wt.cnt_eq(l, r, k));\n\t\t\t}\n\t\t}\n\t}\n\n\
    \tint A, B;\n\tcin >> A >> B;\n\tcout << A + B << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"data-structure/wavelet-tree.hpp\"\n#include\
    \ \"random/mersenne-twister.hpp\"\n#include \"random/random-vector.hpp\"\n\nint\
    \ main() {\n\t{\n\t\tint N = 10000, L = 300, Q = 10000;\n\t\tvector<int> A = rng_vector(N,\
    \ 0, L);\n\t\tvector<int> B(A);\n\t\twavelet_tree wt(B.begin(), B.end(), 0, L);\n\
    \t\twhile (Q--) {\n\t\t\tint t = rng(0, 1);\n\t\t\tif (t == 0) {\n\t\t\t\tint\
    \ l = rng(0, N - 1), r = rng(0, N - 1), k = rng(0, L);\n\t\t\t\tif (r < l)\n\t\
    \t\t\t\tswap(l, r);\n\t\t\t\tint ret = 0;\n\t\t\t\tfor (int i = l; i <= r; i++)\n\
    \t\t\t\t\tif (A[i] <= k)\n\t\t\t\t\t\tret++;\n\t\t\t\tassert(ret == wt.cnt_leq(l,\
    \ r, k));\n\t\t\t} else if (t == 1) {\n\t\t\t\tint l = rng(0, N - 1), r = rng(0,\
    \ N - 1), k = rng(0, L);\n\t\t\t\tif (r < l)\n\t\t\t\t\tswap(l, r);\n\t\t\t\t\
    int ret = 0;\n\t\t\t\tfor (int i = l; i <= r; i++)\n\t\t\t\t\tif (A[i] == k)\n\
    \t\t\t\t\t\tret++;\n\t\t\t\tassert(ret == wt.cnt_eq(l, r, k));\n\t\t\t}\n\t\t\
    }\n\t}\n\n\tint A, B;\n\tcin >> A >> B;\n\tcout << A + B << '\\n';\n}"
  dependsOn:
  - data-structure/wavelet-tree.hpp
  - random/mersenne-twister.hpp
  - random/random-vector.hpp
  - random/mersenne-twister.hpp
  isVerificationFile: true
  path: verify/wavelet-tree.yosupo-a+b.test.cpp
  requiredBy: []
  timestamp: '2022-05-07 19:56:49-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/wavelet-tree.yosupo-a+b.test.cpp
layout: document
redirect_from:
- /verify/verify/wavelet-tree.yosupo-a+b.test.cpp
- /verify/verify/wavelet-tree.yosupo-a+b.test.cpp.html
title: verify/wavelet-tree.yosupo-a+b.test.cpp
---
