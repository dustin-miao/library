---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/topo-sort.hpp
    title: Topological Sort
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
  bundledCode: "#line 1 \"verify/topo-sort.topological-sort.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"graph/topo-sort.hpp\"\nvector<int>\
    \ topo_sort(const vector<vector<int>> &G) {\n\tint n = G.size();\n\tvector<bool>\
    \ vis(n, false);\n\tvector<int> ord;\n\tord.reserve(n);\n\n\tconst auto dfs =\
    \ [&](const auto &self, int u) -> void {\n\t\tvis[u] = true;\n\t\tfor (int v :\
    \ G[u])\n\t\t\tif (!vis[v])\n\t\t\t\tself(self, v);\n\t\tord.push_back(u);\n\t\
    };\n\n\tfor (int i = 0; i < n; i++)\n\t\tif (!vis[i])\n\t\t\tdfs(dfs, i);\n\t\
    reverse(ord.begin(), ord.end());\n\treturn ord;\n}\n#line 7 \"verify/topo-sort.topological-sort.test.cpp\"\
    \n\nint main() {\n\tint N, M;\n\tcin >> N >> M;\n\tvector<vector<int>> G(N);\n\
    \tfor (int i = 0; i < M; i++) {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\tG[u].push_back(v);\n\
    \t}\n\tauto ord = topo_sort(G);\n\tfor (int u : ord)\n\t\tcout << u << '\\n';\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"graph/topo-sort.hpp\"\
    \n\nint main() {\n\tint N, M;\n\tcin >> N >> M;\n\tvector<vector<int>> G(N);\n\
    \tfor (int i = 0; i < M; i++) {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\tG[u].push_back(v);\n\
    \t}\n\tauto ord = topo_sort(G);\n\tfor (int u : ord)\n\t\tcout << u << '\\n';\n\
    }"
  dependsOn:
  - graph/topo-sort.hpp
  isVerificationFile: true
  path: verify/topo-sort.topological-sort.test.cpp
  requiredBy: []
  timestamp: '2022-03-29 14:42:43-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/topo-sort.topological-sort.test.cpp
layout: document
redirect_from:
- /verify/verify/topo-sort.topological-sort.test.cpp
- /verify/verify/topo-sort.topological-sort.test.cpp.html
title: verify/topo-sort.topological-sort.test.cpp
---
