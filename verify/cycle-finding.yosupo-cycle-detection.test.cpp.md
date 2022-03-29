---
data:
  _extendedDependsOn:
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
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"graph/cycle-finding.hpp\"\
    \nvector<pair<int, int>> find_cycle(const vector<vector<int>> &G, bool directed)\
    \ {\n\tint n = G.size();\n\tvector<int> idx(n, -1);\n\tvector<bool> vis(n, false);\n\
    \tvector<pair<int, int>> cycle;\n\tbool fin = 0;\n\n\tconst auto dfs = [&](const\
    \ auto &self, int u, int id, int p) -> int {\n\t\tidx[u] = id;\n\t\tvis[u] = true;\n\
    \t\tfor (int v : G[u]) {\n\t\t\tif (fin)\n\t\t\t\treturn -1;\n\t\t\tif (!directed\
    \ && v == p)\n\t\t\t\tcontinue;\n\t\t\tif (idx[u] == idx[v]) {\n\t\t\t\tcycle.emplace_back(u,\
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
    \t\t}\n\t}\n\treturn vector<pair<int, int>>{};\n}\n#line 7 \"verify/cycle-finding.yosupo-cycle-detection.test.cpp\"\
    \n\nint main() {\n\tint N, M;\n\tcin >> N >> M;\n\tvector<vector<int>> G(N);\n\
    \tmap<pair<int, int>, vector<int>> id;\n\tfor (int i = 0; i < M; i++) {\n\t\t\
    int u, v;\n\t\tcin >> u >> v;\n\t\tG[u].push_back(v);\n\t\tid[make_pair(u, v)].push_back(i);\n\
    \t}\n\n\tauto cycle = find_cycle(G, true);\n\n\tif (cycle.empty()) {\n\t\tcout\
    \ << -1 << '\\n';\n\t} else {\n\t\tcout << cycle.size() << '\\n';\n\t\tfor (auto\
    \ [u, v] : cycle) {\n\t\t\tauto &vec = id[make_pair(u, v)];\n\t\t\tcout << vec.back()\
    \ << '\\n';\n\t\t\tvec.pop_back();\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"graph/cycle-finding.hpp\"\
    \n\nint main() {\n\tint N, M;\n\tcin >> N >> M;\n\tvector<vector<int>> G(N);\n\
    \tmap<pair<int, int>, vector<int>> id;\n\tfor (int i = 0; i < M; i++) {\n\t\t\
    int u, v;\n\t\tcin >> u >> v;\n\t\tG[u].push_back(v);\n\t\tid[make_pair(u, v)].push_back(i);\n\
    \t}\n\n\tauto cycle = find_cycle(G, true);\n\n\tif (cycle.empty()) {\n\t\tcout\
    \ << -1 << '\\n';\n\t} else {\n\t\tcout << cycle.size() << '\\n';\n\t\tfor (auto\
    \ [u, v] : cycle) {\n\t\t\tauto &vec = id[make_pair(u, v)];\n\t\t\tcout << vec.back()\
    \ << '\\n';\n\t\t\tvec.pop_back();\n\t\t}\n\t}\n}"
  dependsOn:
  - graph/cycle-finding.hpp
  isVerificationFile: true
  path: verify/cycle-finding.yosupo-cycle-detection.test.cpp
  requiredBy: []
  timestamp: '2022-03-29 13:08:57-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/cycle-finding.yosupo-cycle-detection.test.cpp
layout: document
redirect_from:
- /verify/verify/cycle-finding.yosupo-cycle-detection.test.cpp
- /verify/verify/cycle-finding.yosupo-cycle-detection.test.cpp.html
title: verify/cycle-finding.yosupo-cycle-detection.test.cpp
---
