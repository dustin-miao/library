---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/topo-sort.hpp
    title: Topological Sort
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
  bundledCode: "#line 1 \"verify/topo-sort.topological-sort.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"graph/topo-sort.hpp\"\n#pragma\
    \ region topo_sort\n\n#ifndef TOPO_SORT_HPP\n#define TOPO_SORT_HPP\n\nnamespace\
    \ graph {\n\tvector<int> topo_sort(const vector<vector<int>> &G) {\n\t\tint n\
    \ = G.size();\n\t\tvector<bool> vis(n, false);\n\t\tvector<int> ord;\n\t\tord.reserve(n);\n\
    \n\t\tconst auto dfs = [&](const auto &self, int u) -> void {\n\t\t\tvis[u] =\
    \ true;\n\t\t\tfor (int v : G[u])\n\t\t\t\tif (!vis[v])\n\t\t\t\t\tself(self,\
    \ v);\n\t\t\tord.push_back(u);\n\t\t};\n\n\t\tfor (int i = 0; i < n; i++)\n\t\t\
    \tif (!vis[i])\n\t\t\t\tdfs(dfs, i);\n\t\treverse(ord.begin(), ord.end());\n\t\
    \treturn ord;\n\t}\n}\n\n#endif\n\n#pragma endregion topo_sort\n#line 7 \"verify/topo-sort.topological-sort.test.cpp\"\
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
  timestamp: '2022-05-13 08:14:05-07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/topo-sort.topological-sort.test.cpp
layout: document
redirect_from:
- /verify/verify/topo-sort.topological-sort.test.cpp
- /verify/verify/topo-sort.topological-sort.test.cpp.html
title: verify/topo-sort.topological-sort.test.cpp
---
