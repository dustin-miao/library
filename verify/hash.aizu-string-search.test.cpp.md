---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/hash.hpp
    title: String Hash
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"verify/hash.aizu-string-search.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"string/hash.hpp\"\n\
    #pragma region str_hash\n\n#ifndef STR_HASH_HPP\n#define STR_HASH_HPP\n\nnamespace\
    \ str {\n\tnamespace hash_internal {\n\t\tconst int MAX_N = 1e6 + 5;\n\t\tconst\
    \ int M1 = 1e9 + 7, M2 = 1e9 + 9;\n\t\tstruct pair_hash {\n\t\t\tint h1, h2;\n\
    \n\t\t\tpair_hash() : h1(), h2() {}\n\n\t\t\tpair_hash(int _h1, int _h2) : h1(_h1),\
    \ h2(_h2) {}\n\n\t\t\tpair_hash operator+=(const pair_hash &p) {\n\t\t\t\th1 +=\
    \ p.h1;\n\t\t\t\tif (h1 >= M1)\n\t\t\t\t\th1 -= M1;\n\t\t\t\th2 += p.h2;\n\t\t\
    \t\tif (h2 >= M2)\n\t\t\t\t\th2 -= M2;\n\t\t\t\treturn *this;\n\t\t\t}\n\n\t\t\
    \tpair_hash operator-=(const pair_hash &p) {\n\t\t\t\th1 -= p.h1;\n\t\t\t\tif\
    \ (h1 < 0)\n\t\t\t\t\th1 += M1;\n\t\t\t\th2 -= p.h2;\n\t\t\t\tif (h2 < 0)\n\t\t\
    \t\t\th2 += M2;\n\t\t\t\treturn *this;\n\t\t\t}\n\n\t\t\tpair_hash operator*=(const\
    \ pair_hash &p) {\n\t\t\t\th1 = (static_cast<long long>(h1) * p.h1) % M1;\n\t\t\
    \t\th2 = (static_cast<long long>(h2) * p.h2) % M2;\n\t\t\t\treturn *this;\n\t\t\
    \t}\n\n\t\t\ttemplate<typename T>\n\t\t\tpair_hash operator*=(const T &s) { \n\
    \t\t\t\th1 = (static_cast<long long>(h1) * s) % M1;\n\t\t\t\th2 = (static_cast<long\
    \ long>(h2) * s) % M2;\n\t\t\t\treturn *this;\n\t\t\t}\n\n\t\t\tbool operator==(const\
    \ pair_hash &p) const { return h1 == p.h1 && h2 == p.h2; }\n\n\t\t\ttemplate<typename\
    \ T = int>\n\t\t\texplicit operator pair<T, T>() const {\n\t\t\t\treturn make_pair(static_cast<T>(h1),\
    \ static_cast<T>(h2));\n\t\t\t}\n\t\t};\n\n\t\tpair_hash operator+(pair_hash p,\
    \ const pair_hash &q) { return p += q; }\n\n\t\tpair_hash operator-(pair_hash\
    \ p, const pair_hash &q) { return p -= q; }\n\n\t\tpair_hash operator*(pair_hash\
    \ p, const pair_hash &q) { return p *= q; }\n\n\t\ttemplate<typename T>\n\t\t\
    pair_hash operator*(pair_hash p, const T &s) { return p *= s; }\n\t\ttemplate<typename\
    \ T>\n\t\tpair_hash operator*(const T &s, pair_hash p) { return p *= s; }\n\n\t\
    \tostream &operator<<(ostream &os, const pair_hash &p) { \n\t\t\treturn os <<\
    \ '(' << p.h1 << \", \" << p.h2 << ')';\n\t\t}\n\n\t\tconst pair_hash B(131, 137),\
    \ I(190839696, 262773725);\n\t\tarray<pair_hash, MAX_N> bpow, ipow;\n\n\t\tvoid\
    \ init_hash_pow() {\n\t\t\tstatic bool init = false;\n\n\t\t\tif (init)\n\t\t\t\
    \treturn;\n\t\t\tbpow[0] = ipow[0] = pair_hash(1, 1);\n\t\t\tfor (int i = 1; i\
    \ < MAX_N; i++) {\n\t\t\t\tbpow[i] = bpow[i - 1] * B;\n\t\t\t\tipow[i] = ipow[i\
    \ - 1] * I;\n\t\t\t}\n\t\t\tinit = true;\n\t\t}\n\t}\n\n\tusing namespace hash_internal;\n\
    \n\tstruct hash {\n\t\tint n;\n\t\tvector<pair_hash> roll;\n\n\t\thash() { init_hash_pow();\
    \ };\n\n\t\thash(const string &s) {\n\t\t\tinit_hash_pow();\n\n\t\t\tn = s.size();\n\
    \t\t\troll.resize(n + 1);\n\t\t\tfor (int i = 1; i <= n; i++) \n\t\t\t\troll[i]\
    \ = roll[i - 1] + bpow[i - 1] * s[i - 1];\n\t\t}\n\n\t\tpair_hash query(int l,\
    \ int r) const {\n\t\t\treturn (roll[r + 1] - roll[l]) * ipow[l];\n\t\t}\n\n\t\
    \tpair_hash query() const { return roll[n]; }\n\n\t\tpair_hash operator()(int\
    \ l, int r) const { return query(l, r); }\n\n\t\tpair_hash operator()() const\
    \ { return query(); }\n\t};\n}\n\n#endif\n\n#pragma endregion str_hash\n#line\
    \ 7 \"verify/hash.aizu-string-search.test.cpp\"\n\nint main() {\n\tstring T, P;\n\
    \tcin >> T >> P;\n\tstr::hash A(T), B(P);\n\tfor (int i = 0; i + P.size() - 1\
    \ < T.size(); i++) \n\t\tif (A(i, i + P.size() - 1) == B())\n\t\t\tcout << i <<\
    \ '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"string/hash.hpp\"\
    \n\nint main() {\n\tstring T, P;\n\tcin >> T >> P;\n\tstr::hash A(T), B(P);\n\t\
    for (int i = 0; i + P.size() - 1 < T.size(); i++) \n\t\tif (A(i, i + P.size()\
    \ - 1) == B())\n\t\t\tcout << i << '\\n';\n}"
  dependsOn:
  - string/hash.hpp
  isVerificationFile: true
  path: verify/hash.aizu-string-search.test.cpp
  requiredBy: []
  timestamp: '2022-06-05 10:11:54-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/hash.aizu-string-search.test.cpp
layout: document
redirect_from:
- /verify/verify/hash.aizu-string-search.test.cpp
- /verify/verify/hash.aizu-string-search.test.cpp.html
title: verify/hash.aizu-string-search.test.cpp
---
