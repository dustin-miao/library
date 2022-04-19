---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/fast-set.hpp
    title: data-structure/fast-set.hpp
  - icon: ':heavy_check_mark:'
    path: graph/cycle-finding.hpp
    title: Cycle Finding
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/cycle_detection
    links:
    - https://judge.yosupo.jp/problem/cycle_detection
  bundledCode: "#line 1 \"verify/cycle-finding.yosupo-cycle-detection.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/fast-set.hpp\"\
    \n#pragma region fast set\n\nstruct custom_hash {\n    static uint64_t splitmix64(uint64_t\
    \ x) {\n        x += 0x9e3779b97f4a7c15;\n        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n\
    \        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n        return x ^ (x >> 31);\n\
    \    }\n\n    size_t operator()(uint64_t x) const {\n        static const uint64_t\
    \ FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();\n   \
    \     return splitmix64(x + FIXED_RANDOM);\n    }\n\n\ttemplate<typename T>\n\
    \    size_t operator()(const pair<T, T> &x) const { \n\t\treturn (*this)(x.first)\
    \ ^ __builtin_bswap64((*this)(x.second)); \n\t}\n\n\ttemplate<typename T>\n  \
    \  size_t operator()(const tuple<T, T, T> &x) const { \n\t\treturn (*this)(get<0>(x))\
    \ + __builtin_bswap64((*this)(make_pair(get<1>(x), get<2>(x)))); \n\t}\n\n\ttemplate<typename\
    \ T>\n    size_t operator()(const tuple<T, T, T, T> &x) const { \n\t\treturn (*this)(get<0>(x))\
    \ + __builtin_bswap64((*this)(make_tuple(get<1>(x), get<2>(x), get<3>(x)))); \n\
    \t}\n};\n\n#include <ext/pb_ds/assoc_container.hpp>\nusing namespace __gnu_pbds;\n\
    \ntemplate <class K, class V>\nusing fast_map = gp_hash_table<K, V, custom_hash>;\n\
    \ntemplate <class K>\nusing fast_set = gp_hash_table<K, null_type, custom_hash>;\n\
    \n#pragma endregion fast set\n#line 1 \"graph/cycle-finding.hpp\"\nvector<pair<int,\
    \ int>> find_cycle(const vector<vector<int>> &G, bool directed) {\n\tint n = G.size();\n\
    \tvector<int> idx(n, -1);\n\tvector<bool> vis(n, false);\n\tvector<pair<int, int>>\
    \ cycle;\n\tbool fin = 0;\n\n\tconst auto dfs = [&](const auto &self, int u, int\
    \ id, int p) -> int {\n\t\tidx[u] = id;\n\t\tvis[u] = true;\n\t\tfor (int v :\
    \ G[u]) {\n\t\t\tif (fin)\n\t\t\t\treturn -1;\n\t\t\tif (!directed && v == p)\n\
    \t\t\t\tcontinue;\n\t\t\tif (idx[u] == idx[v]) {\n\t\t\t\tcycle.emplace_back(u,\
    \ v);\n\t\t\t\treturn v;\n\t\t\t}\n\t\t\tif (vis[v])\n\t\t\t\tcontinue;\n\t\t\t\
    int k = self(self, v, id, u);\n\t\t\tif (k != -1) {\n\t\t\t\tcycle.emplace_back(u,\
    \ v);\n\t\t\t\tif (u == k) {\n\t\t\t\t\tfin = 1;\n\t\t\t\t\treturn -1;\n\t\t\t\
    \t}\n\t\t\t\treturn k;\n\t\t\t}\n\t\t}\n\t\tidx[u] = -1;\n\t\treturn -1;\n\t};\n\
    \n\tfor (int i = 0; i < n; i++) {\n\t\tif (vis[i])\n\t\t\tcontinue;\n\t\tdfs(dfs,\
    \ i, i, -1);\n\t\tif (fin) {\n\t\t\treverse(cycle.begin(), cycle.end());\n\t\t\
    \treturn cycle;\n\t\t}\n\t}\n\treturn vector<pair<int, int>>{};\n}\n\ntemplate<typename\
    \ T>\nvector<pair<int, int>> find_cycle(const vector<vector<pair<int, T>>> &G,\
    \ bool directed) {\n\tint n = G.size();\n\tvector<int> idx(n, -1);\n\tvector<bool>\
    \ vis(n, false);\n\tvector<pair<int, int>> cycle;\n\tbool fin = 0;\n\n\tconst\
    \ auto dfs = [&](const auto &self, int u, int id, int p) -> int {\n\t\tidx[u]\
    \ = id;\n\t\tvis[u] = true;\n\t\tfor (auto [v, w] : G[u]) {\n\t\t\tif (fin)\n\t\
    \t\t\treturn -1;\n\t\t\tif (!directed && v == p)\n\t\t\t\tcontinue;\n\t\t\tif\
    \ (idx[u] == idx[v]) {\n\t\t\t\tcycle.emplace_back(u, v);\n\t\t\t\treturn v;\n\
    \t\t\t}\n\t\t\tif (vis[v])\n\t\t\t\tcontinue;\n\t\t\tint k = self(self, v, id,\
    \ u);\n\t\t\tif (k != -1) {\n\t\t\t\tcycle.emplace_back(u, v);\n\t\t\t\tif (u\
    \ == k) {\n\t\t\t\t\tfin = 1;\n\t\t\t\t\treturn -1;\n\t\t\t\t}\n\t\t\t\treturn\
    \ k;\n\t\t\t}\n\t\t}\n\t\tidx[u] = -1;\n\t\treturn -1;\n\t};\n\n\tfor (int i =\
    \ 0; i < n; i++) {\n\t\tif (vis[i])\n\t\t\tcontinue;\n\t\tdfs(dfs, i, i, -1);\n\
    \t\tif (fin) {\n\t\t\treverse(cycle.begin(), cycle.end());\n\t\t\treturn cycle;\n\
    \t\t}\n\t}\n\treturn vector<pair<int, int>>{};\n}\n#line 8 \"verify/cycle-finding.yosupo-cycle-detection.test.cpp\"\
    \n\nint main() {\n\tint N, M;\n\tcin >> N >> M;\n\tvector<vector<int>> G(N);\n\
    \tfast_map<pair<int, int>, vector<int>> id;\n\tfor (int i = 0; i < M; i++) {\n\
    \t\tint u, v;\n\t\tcin >> u >> v;\n\t\tG[u].push_back(v);\n\t\tid[make_pair(u,\
    \ v)].push_back(i);\n\t}\n\n\tauto cycle = find_cycle(G, true);\n\n\tif (cycle.empty())\
    \ {\n\t\tcout << -1 << '\\n';\n\t} else {\n\t\tcout << cycle.size() << '\\n';\n\
    \t\tfor (auto [u, v] : cycle) {\n\t\t\tauto &vec = id[make_pair(u, v)];\n\t\t\t\
    cout << vec.back() << '\\n';\n\t\t\tvec.pop_back();\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"data-structure/fast-set.hpp\"\
    \n#include \"graph/cycle-finding.hpp\"\n\nint main() {\n\tint N, M;\n\tcin >>\
    \ N >> M;\n\tvector<vector<int>> G(N);\n\tfast_map<pair<int, int>, vector<int>>\
    \ id;\n\tfor (int i = 0; i < M; i++) {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\t\
    G[u].push_back(v);\n\t\tid[make_pair(u, v)].push_back(i);\n\t}\n\n\tauto cycle\
    \ = find_cycle(G, true);\n\n\tif (cycle.empty()) {\n\t\tcout << -1 << '\\n';\n\
    \t} else {\n\t\tcout << cycle.size() << '\\n';\n\t\tfor (auto [u, v] : cycle)\
    \ {\n\t\t\tauto &vec = id[make_pair(u, v)];\n\t\t\tcout << vec.back() << '\\n';\n\
    \t\t\tvec.pop_back();\n\t\t}\n\t}\n}"
  dependsOn:
  - data-structure/fast-set.hpp
  - graph/cycle-finding.hpp
  isVerificationFile: true
  path: verify/cycle-finding.yosupo-cycle-detection.test.cpp
  requiredBy: []
  timestamp: '2022-04-19 10:23:34-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/cycle-finding.yosupo-cycle-detection.test.cpp
layout: document
redirect_from:
- /verify/verify/cycle-finding.yosupo-cycle-detection.test.cpp
- /verify/verify/cycle-finding.yosupo-cycle-detection.test.cpp.html
title: verify/cycle-finding.yosupo-cycle-detection.test.cpp
---
