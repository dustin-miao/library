---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/wavelet-tree.hpp
    title: Wavelet Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"verify/wavelet-tree.yosupo-range-kth-largest.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/wavelet-tree.hpp\"\
    \n#pragma region wavelet_tree\n\n#ifndef WAVELET_TREE_HPP\n#define WAVELET_TREE_HPP\n\
    \nclass wavelet_tree {\n\tint n, vlb, vrb;\n\tvector<vector<int>> tree;\n\n\t\
    template<typename I>\n\tvoid build(I begin, I end, int t, int vl, int vr) {\n\t\
    \tif (vl == vr)\n\t\t\treturn;\n\t\tint vm = (vl + vr) / 2;\n\t\ttree[t].reserve(end\
    \ - begin + 1);\n\t\ttree[t].push_back(0);\n\t\tfor (auto it = begin; it != end;\
    \ it++)\n\t\t\ttree[t].push_back(tree[t].back() + (*it <= vm));\n\t\tauto pivot\
    \ = stable_partition(begin, end, [vm](int x) { return x <= vm; });\n\t\tbuild(begin,\
    \ pivot, t * 2, vl, vm);\n\t\tbuild(pivot, end, t * 2 + 1, vm + 1, vr);\n\t}\n\
    \n\tint quantile(int l, int r, int k, int t, int vl, int vr) {\n\t\tif (vl ==\
    \ vr)\n\t\t\treturn vl;\n\t\tint vm = (vl + vr) / 2, lv = tree[t][r] - tree[t][l\
    \ - 1];\n\t\tif (k <= lv)\n\t\t\treturn quantile(tree[t][l - 1] + 1, tree[t][r],\
    \ k, t * 2, vl, vm);\n\t\telse \n\t\t\treturn quantile(l - tree[t][l - 1], r -\
    \ tree[t][r], k - lv, t * 2 + 1, vm + 1, vr);\n\t}\n\n\tint cnt_leq(int l, int\
    \ r, int k, int t, int vl, int vr) {\n\t\tif (k < vl)\n\t\t\treturn 0;\n\t\tif\
    \ (vr <= k)\n\t\t\treturn r - l + 1;\n\t\tint vm = (vl + vr) / 2;\n\t\treturn\
    \ cnt_leq(tree[t][l - 1] + 1, tree[t][r], k, t * 2, vl, vm) + \\\n\t\t\tcnt_leq(l\
    \ - tree[t][l - 1], r - tree[t][r], k, t * 2 + 1, vm + 1, vr);\n\t}\n\n\tint cnt_eq(int\
    \ l, int r, int k, int t, int vl, int vr) {\n\t\tif (k < vl || k > vr)\n\t\t\t\
    return 0;\n\t\tif (vl == vr)\n\t\t\treturn r - l + 1;\n\t\tint vm = (vl + vr)\
    \ / 2;\n\t\tif (k <= vm)\n\t\t\treturn cnt_eq(tree[t][l - 1] + 1, tree[t][r],\
    \ k, t * 2, vl, vm);\n\t\telse\n\t\t\treturn cnt_eq(l - tree[t][l - 1], r - tree[t][r],\
    \ k, t * 2 + 1, vm + 1, vr);\n\t}\n\npublic:\n\twavelet_tree() = default;\n\n\t\
    template<typename I>\n\twavelet_tree(I begin, I end, int vl, int vr) { init(begin,\
    \ end, vl, vr); }\n\n\ttemplate<typename I>\n\tvoid init(I begin, I end, int vl,\
    \ int vr) {\n\t\tn = vr - vl + 1;\n\t\tvlb = vl, vrb = vr;\n\t\ttree.resize(4\
    \ * n);\n\t\tbuild(begin, end, 1, vl, vr);\n\t}\n\n\tint quantile(int l, int r,\
    \ int k) { return quantile(l + 1, r + 1, k + 1, 1, vlb, vrb); }\n\n\tint cnt_leq(int\
    \ l, int r, int k) { return cnt_leq(l + 1, r + 1, k, 1, vlb, vrb); }\n\n\tint\
    \ cnt_eq(int l, int r, int k) { return cnt_eq(l + 1, r + 1, k, 1, vlb, vrb); }\n\
    };\n\n#endif \n\n#pragma endregion wavelet_tree\n#line 7 \"verify/wavelet-tree.yosupo-range-kth-largest.test.cpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\tvector<int> A(N);\n\tmap<int,\
    \ int> M;\n\tfor (int &a : A) {\n\t\tcin >> a;\n\t\tM[a] = 0;\n\t}\n\tint c =\
    \ 0;\n\tfor (auto &[k, v] : M)\n\t\tv = c++;\n\tvector<int> I(c);\n\tfor (auto\
    \ [k, v] : M)\n\t\tI[v] = k;\n\tfor (int &a : A)\n\t\ta = M[a];\n\t\n\twavelet_tree\
    \ wt(A.begin(), A.end(), 0, c);\n\twhile (Q--) {\n\t\tint l, r, k;\n\t\tcin >>\
    \ l >> r >> k;\n\t\tcout << I[wt.quantile(l, r - 1, k)] << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/wavelet-tree.hpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\tvector<int> A(N);\n\tmap<int,\
    \ int> M;\n\tfor (int &a : A) {\n\t\tcin >> a;\n\t\tM[a] = 0;\n\t}\n\tint c =\
    \ 0;\n\tfor (auto &[k, v] : M)\n\t\tv = c++;\n\tvector<int> I(c);\n\tfor (auto\
    \ [k, v] : M)\n\t\tI[v] = k;\n\tfor (int &a : A)\n\t\ta = M[a];\n\t\n\twavelet_tree\
    \ wt(A.begin(), A.end(), 0, c);\n\twhile (Q--) {\n\t\tint l, r, k;\n\t\tcin >>\
    \ l >> r >> k;\n\t\tcout << I[wt.quantile(l, r - 1, k)] << '\\n';\n\t}\n}"
  dependsOn:
  - data-structure/wavelet-tree.hpp
  isVerificationFile: true
  path: verify/wavelet-tree.yosupo-range-kth-largest.test.cpp
  requiredBy: []
  timestamp: '2022-05-07 19:56:49-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/wavelet-tree.yosupo-range-kth-largest.test.cpp
layout: document
redirect_from:
- /verify/verify/wavelet-tree.yosupo-range-kth-largest.test.cpp
- /verify/verify/wavelet-tree.yosupo-range-kth-largest.test.cpp.html
title: verify/wavelet-tree.yosupo-range-kth-largest.test.cpp
---
