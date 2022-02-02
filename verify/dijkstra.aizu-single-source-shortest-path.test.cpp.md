---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: Dijkstra's Algorithm
  - icon: ':question:'
    path: graph/graph-util.hpp
    title: Graph Utility
  - icon: ':heavy_check_mark:'
    path: utility/chmin.hpp
    title: Chmin
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
  bundledCode: "#line 1 \"verify/dijkstra.aizu-single-source-shortest-path.test.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"utility/chmin.hpp\"\
    \ntemplate<typename T>\nbool chmin(T &a, T b) {\n\tif (a > b) {\n\t\ta = b;\n\t\
    \treturn true;\n\t}\n\treturn false;\n}\n#line 1 \"graph/graph-util.hpp\"\nusing\
    \ u_graph = vector<vector<int>>;\n\nusing u_edgelist = vector<pair<int, int>>;\n\
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
    \tfor (auto [u, v, w] : E)\n\t\tM[u][v] = w;\n\treturn M;\n}\n#line 3 \"graph/dijkstra.hpp\"\
    \n\ntemplate<typename T>\npair<vector<long long>, vector<int>> dijkstra(const\
    \ graph<T> &G, int s) {\n\tsize_t n = G.size();\n\tpriority_queue<pair<T, int>,\
    \ vector<pair<T, int>>, greater<pair<T, int>>> pq;\n\tvector<T> dis(n, numeric_limits<T>::max());\n\
    \tvector<int> par(n, -1);\n\n\tpq.emplace(0, s);\n\tdis[s] = 0;\n\tpar[s] = s;\n\
    \twhile (!pq.empty()) {\n\t\tauto [d, u] = pq.top(); pq.pop();\n\t\tif (d != dis[u])\n\
    \t\t\tcontinue;\n\t\tfor (auto [v, w] : G[u])\n\t\t\tif (chmin(dis[v], d + w))\
    \ {\n\t\t\t\tpar[v] = u;\n\t\t\t\tpq.emplace(dis[v], v);\n\t\t\t}\n\t}\n\treturn\
    \ {dis, par};\n}\n#line 7 \"verify/dijkstra.aizu-single-source-shortest-path.test.cpp\"\
    \n\nint main() {\n\tint N, M, S;\n\tcin >> N >> M >> S;\n\tgraph<long long> G(N);\n\
    \tfor (int i = 0; i < M; i++) {\n\t\tint u, v; long long w;\n\t\tcin >> u >> v\
    \ >> w;\n\t\tG[u].emplace_back(v, w);\n\t}\n\t\n\tauto [dis, par] = dijkstra(G,\
    \ S);\n\n\tfor (int i = 0; i < N; i++) {\n\t\tif (par[i] == -1)\n\t\t\tcout <<\
    \ \"INF\\n\";\n\t\telse \n\t\t\tcout << dis[i] << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"graph/dijkstra.hpp\"\
    \n\nint main() {\n\tint N, M, S;\n\tcin >> N >> M >> S;\n\tgraph<long long> G(N);\n\
    \tfor (int i = 0; i < M; i++) {\n\t\tint u, v; long long w;\n\t\tcin >> u >> v\
    \ >> w;\n\t\tG[u].emplace_back(v, w);\n\t}\n\t\n\tauto [dis, par] = dijkstra(G,\
    \ S);\n\n\tfor (int i = 0; i < N; i++) {\n\t\tif (par[i] == -1)\n\t\t\tcout <<\
    \ \"INF\\n\";\n\t\telse \n\t\t\tcout << dis[i] << '\\n';\n\t}\n}"
  dependsOn:
  - graph/dijkstra.hpp
  - utility/chmin.hpp
  - graph/graph-util.hpp
  isVerificationFile: true
  path: verify/dijkstra.aizu-single-source-shortest-path.test.cpp
  requiredBy: []
  timestamp: '2022-02-02 10:15:02-08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/dijkstra.aizu-single-source-shortest-path.test.cpp
layout: document
redirect_from:
- /verify/verify/dijkstra.aizu-single-source-shortest-path.test.cpp
- /verify/verify/dijkstra.aizu-single-source-shortest-path.test.cpp.html
title: verify/dijkstra.aizu-single-source-shortest-path.test.cpp
---
