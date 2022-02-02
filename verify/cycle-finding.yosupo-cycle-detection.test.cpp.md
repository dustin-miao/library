---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/cycle-finding.hpp
    title: Cycle Finding
  - icon: ':question:'
    path: graph/graph-util.hpp
    title: Graph Utility
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/cycle_detection
    links:
    - https://judge.yosupo.jp/problem/cycle_detection
  bundledCode: "#line 1 \"verify/cycle-finding.yosupo-cycle-detection.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"graph/graph-util.hpp\"\n\
    using u_graph = vector<vector<int>>;\n\nusing u_edgelist = vector<pair<int, int>>;\n\
    \nusing u_matgraph = vector<vector<bool>>;\n\nu_graph to_graph(size_t n, const\
    \ u_edgelist &E) {\n\tu_graph G(n);\n\tfor (auto [u, v] : E)\n\t\tG[u].push_back(v);\n\
    \treturn G;\n}\n\nu_graph to_graph(const u_matgraph &M) {\n\tsize_t n = M.size();\n\
    \tu_graph G(n);\n\tfor (int u = 0; u < n; u++)\n\t\tfor (int v = 0; v < n; v++)\n\
    \t\t\tif (M[u][v])\n\t\t\t\tG[u].push_back(v);\n\treturn G;\n}\n\nu_edgelist to_edgelist(const\
    \ u_graph &G) {\n\tsize_t n = G.size();\n\tu_edgelist E;\n\tfor (int u = 0; u\
    \ < n; u++) \n\t\tfor (int v : G[u])\n\t\t\tE.emplace_back(u, v);\n\treturn E;\n\
    }\n\nu_edgelist to_edgelist(const u_matgraph &M) {\n\tsize_t n = M.size();\n\t\
    u_edgelist E;\n\tfor (int u = 0; u < n; u++)\n\t\tfor (int v = 0; v < n; v++)\n\
    \t\t\tif (M[u][v])\n\t\t\t\tE.emplace_back(u, v);\n\treturn E;\n}\n\nu_matgraph\
    \ to_matgraph(const u_graph &G) {\n\tint n = G.size();\n\tu_matgraph M(n, vector<bool>(n,\
    \ false));\n\tfor (int u = 0; u < n; u++)\n\t\tfor (int v : G[u])\n\t\t\tM[u][v]\
    \ = true;\n\treturn M;\n}\n\nu_matgraph to_matgraph(size_t n, const u_edgelist\
    \ &E) {\n\tu_matgraph M(n, vector<bool>(n, false));\n\tfor (auto [u, v] : E)\n\
    \t\tM[u][v] = true;\n\treturn M;\n}\n\ntemplate<typename T>\nusing graph = vector<vector<pair<int,\
    \ T>>>;\n\ntemplate<typename T>\nusing edgelist = vector<tuple<int, int, T>>;\n\
    \ntemplate<typename T>\nusing matgraph = vector<vector<T>>;\n\ntemplate<typename\
    \ T>\ngraph<T> to_graph(size_t n, const edgelist<T> &E) {\n\tgraph<T> G(n);\n\t\
    for (auto [u, v, w] : E)\n\t\tG[u].emplace_back(v, w);\n\treturn G;\n}\n\ntemplate<typename\
    \ T>\ngraph<T> to_graph(const matgraph<T> &M, const T dval) {\n\tsize_t n = M.size();\n\
    \tgraph<T> G(n);\n\tfor (int u = 0; u < n; u++)\n\t\tfor (int v = 0; v < n; v++)\n\
    \t\t\tif (M[u][v] != dval)\n\t\t\t\tG[u].emplace_back(v, M[u][v]);\n\treturn G;\n\
    }\n\ntemplate<typename T>\nedgelist<T> to_edgelist(const graph<T> &G) {\n\tsize_t\
    \ n = G.size();\n\tedgelist<T> E;\n\tfor (int u = 0; u < n; u++)\n\t\tfor (auto\
    \ [v, w] : G[u])\n\t\t\tE.emplace_back(u, v, w);\n\treturn E;\n}\n\ntemplate<typename\
    \ T>\nedgelist<T> to_edgelist(const matgraph<T> &M, const T dval) {\n\tsize_t\
    \ n = M.size();\n\tedgelist<T> E;\n\tfor (int u = 0; u < n; u++)\n\t\tfor (int\
    \ v = 0; v < n; v++)\n\t\t\tif (M[u][v] != dval)\n\t\t\t\tE.emplace_back(u, v,\
    \ M[u][v]);\n\treturn E;\n}\n\ntemplate<typename T>\nmatgraph<T> to_matgraph(const\
    \ graph<T> &G, const T dval) {\n\tsize_t n = G.size();\n\tmatgraph<T> M(n, vector<T>(n,\
    \ dval));\n\tfor (int u = 0; u < n; u++)\t\n\t\tfor (auto [v, w] : G[u])\n\t\t\
    \tM[u][v] = w;\n\treturn M;\n}\n\ntemplate<typename T>\nmatgraph<T> to_matgraph(size_t\
    \ n, const edgelist<T> &E, const T dval) {\n\tmatgraph<T> M(n, vector<T>(n, dval));\n\
    \tfor (auto [u, v, w] : E)\n\t\tM[u][v] = w;\n\treturn M;\n}\n#line 2 \"graph/cycle-finding.hpp\"\
    \n\ntemplate<typename T>\nvector<pair<int, int>> find_cycle(const u_graph<T> &G,\
    \ const bool directed = true) {\n\tsize_t n = G.size();\n\tvector<int> idx(n,\
    \ -1), vis(n, 0);\n\tvector<pair<int, int>> cycle;\n\tbool fin = 0;\n\n\tconst\
    \ auto dfs = [&](const auto &self, int u, int id, int p) -> int {\n\t\tidx[u]\
    \ = id, vis[u] = 1;\n\t\tfor (int v : G[u]) {\n\t\t\tif (fin)\n\t\t\t\treturn\
    \ -1;\n\t\t\tif (!directed && v == p)\n\t\t\t\tcontinue;\n\t\t\tif (idx[u] ==\
    \ idx[v]) {\n\t\t\t\tcycle.emplace_back(u, v);\n\t\t\t\treturn v;\n\t\t\t}\n\t\
    \t\tif (vis[v])\n\t\t\t\tcontinue;\n\t\t\tint k = self(self, v, id, u);\n\t\t\t\
    if (k != -1) {\n\t\t\t\tcycle.emplace_back(u, v);\n\t\t\t\tif (u == k) {\n\t\t\
    \t\t\tfin = 1;\n\t\t\t\t\treturn -1;\n\t\t\t\t}\n\t\t\t\treturn k;\n\t\t\t}\n\t\
    \t}\n\t\tidx[u] = -1;\n\t\treturn -1;\n\t};\n\n\tfor (int i = 0; i < n; i++) {\n\
    \t\tif (vis[i])\n\t\t\tcontinue;\n\t\tdfs(dfs, i, i, -1);\n\t\tif (fin) {\n\t\t\
    \treverse(cycle.begin(), cycle.end());\n\t\t\treturn cycle;\n\t\t}\n\t}\n\treturn\
    \ vector<pair<int, int>>{};\n}\n\ntemplate<typename T>\nvector<pair<int, int>>\
    \ find_cycle(const graph<T> &G, const bool directed = true) {\n\tsize_t n = G.size();\n\
    \tvector<int> idx(n, -1), vis(n, 0);\n\tvector<pair<int, int>> cycle;\n\tbool\
    \ fin = 0;\n\n\tconst auto dfs = [&](const auto &self, int u, int id, int p) ->\
    \ int {\n\t\tidx[u] = id, vis[u] = 1;\n\t\tfor (auto [v, w] : G[u]) {\n\t\t\t\
    if (fin)\n\t\t\t\treturn -1;\n\t\t\tif (!directed && v == p)\n\t\t\t\tcontinue;\n\
    \t\t\tif (idx[u] == idx[v]) {\n\t\t\t\tcycle.emplace_back(u, v);\n\t\t\t\treturn\
    \ v;\n\t\t\t}\n\t\t\tif (vis[v])\n\t\t\t\tcontinue;\n\t\t\tint k = self(self,\
    \ v, id, u);\n\t\t\tif (k != -1) {\n\t\t\t\tcycle.emplace_back(u, v);\n\t\t\t\t\
    if (u == k) {\n\t\t\t\t\tfin = 1;\n\t\t\t\t\treturn -1;\n\t\t\t\t}\n\t\t\t\treturn\
    \ k;\n\t\t\t}\n\t\t}\n\t\tidx[u] = -1;\n\t\treturn -1;\n\t};\n\n\tfor (int i =\
    \ 0; i < n; i++) {\n\t\tif (vis[i])\n\t\t\tcontinue;\n\t\tdfs(dfs, i, i, -1);\n\
    \t\tif (fin) {\n\t\t\treverse(cycle.begin(), cycle.end());\n\t\t\treturn cycle;\n\
    \t\t}\n\t}\n\treturn vector<pair<int, int>>{};\n}\n#line 7 \"verify/cycle-finding.yosupo-cycle-detection.test.cpp\"\
    \n\nint main() {\n\tint N, M;\n\tcin >> N >> M;\n\tu_graph G(N);\n\tmap<pair<int,\
    \ int>, vector<int>> id;\n\tfor (int i = 0; i < M; i++) {\n\t\tint u, v;\n\t\t\
    cin >> u >> v;\n\t\tG[u].push_back(v);\n\t\tid[{u, v}].push_back(i);\n\t}\n\n\t\
    auto cycle = find_cycle(G);\n\n\tif (cycle.empty()) {\n\t\tcout << -1 << '\\n';\n\
    \t} else {\n\t\tcout << cycle.size() << '\\n';\n\t\tfor (auto [u, v] : cycle)\
    \ {\n\t\t\tauto &vec = id[{u, v}];\n\t\t\tcout << vec.back() << '\\n';\n\t\t\t\
    vec.pop_back();\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"graph/cycle-finding.hpp\"\
    \n\nint main() {\n\tint N, M;\n\tcin >> N >> M;\n\tu_graph G(N);\n\tmap<pair<int,\
    \ int>, vector<int>> id;\n\tfor (int i = 0; i < M; i++) {\n\t\tint u, v;\n\t\t\
    cin >> u >> v;\n\t\tG[u].push_back(v);\n\t\tid[{u, v}].push_back(i);\n\t}\n\n\t\
    auto cycle = find_cycle(G);\n\n\tif (cycle.empty()) {\n\t\tcout << -1 << '\\n';\n\
    \t} else {\n\t\tcout << cycle.size() << '\\n';\n\t\tfor (auto [u, v] : cycle)\
    \ {\n\t\t\tauto &vec = id[{u, v}];\n\t\t\tcout << vec.back() << '\\n';\n\t\t\t\
    vec.pop_back();\n\t\t}\n\t}\n}"
  dependsOn:
  - graph/cycle-finding.hpp
  - graph/graph-util.hpp
  isVerificationFile: true
  path: verify/cycle-finding.yosupo-cycle-detection.test.cpp
  requiredBy: []
  timestamp: '2022-02-02 10:15:02-08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/cycle-finding.yosupo-cycle-detection.test.cpp
layout: document
redirect_from:
- /verify/verify/cycle-finding.yosupo-cycle-detection.test.cpp
- /verify/verify/cycle-finding.yosupo-cycle-detection.test.cpp.html
title: verify/cycle-finding.yosupo-cycle-detection.test.cpp
---
