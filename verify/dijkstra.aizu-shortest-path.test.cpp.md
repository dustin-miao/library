---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: Dijkstra's Algorithm
  - icon: ':question:'
    path: utility/chmin.hpp
    title: Chmin
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"verify/dijkstra.aizu-shortest-path.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"utility/chmin.hpp\"\n#pragma region chmin\n\n\
    template<typename T>\nbool chmin(T &a, T b) {\n\tif (a > b) {\n\t\ta = b;\n\t\t\
    return true;\n\t}\n\treturn false;\n}\n\n#pragma endregion chmin\n#line 2 \"graph/dijkstra.hpp\"\
    \n\n#pragma region dijkstra\n\ntemplate<typename T>\npair<vector<long long>, vector<int>>\
    \ dijkstra(const vector<vector<pair<int, T>>> &G, int s) {\n\tint n = G.size();\n\
    \tpriority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;\n\
    \tvector<T> dis(n, numeric_limits<T>::max());\n\tvector<int> par(n, -1);\n\n\t\
    pq.emplace(0, s);\n\tdis[s] = 0;\n\tpar[s] = s;\n\twhile (!pq.empty()) {\n\t\t\
    auto [d, u] = pq.top(); pq.pop();\n\t\tif (d != dis[u])\n\t\t\tcontinue;\n\t\t\
    for (auto [v, w] : G[u])\n\t\t\tif (chmin(dis[v], d + w)) {\n\t\t\t\tpar[v] =\
    \ u;\n\t\t\t\tpq.emplace(dis[v], v);\n\t\t\t}\n\t}\n\treturn {dis, par};\n}\n\n\
    #pragma endregion dijkstra\n#line 7 \"verify/dijkstra.aizu-shortest-path.test.cpp\"\
    \n\nint main() {\n\tint N, M, S, T;\n\tcin >> N >> M >> S >> T;\n\tvector<vector<pair<int,\
    \ long long>>> G(N);\n\tfor (int i = 0; i < M; i++) {\n\t\tint u, v; long long\
    \ w;\n\t\tcin >> u >> v >> w;\n\t\tG[u].emplace_back(v, w);\n\t}\n\t\n\tauto [dis,\
    \ par] = dijkstra(G, S);\n\n\tif (par[T] == -1) {\n\t\tcout << -1 << '\\n';\n\t\
    \treturn 0;\n\t}\n\n\tvector<int> path;\n\tfor (int u = T; u != S; u = par[u])\n\
    \t\tpath.push_back(u);\n\tpath.push_back(S);\n\treverse(path.begin(), path.end());\n\
    \n\tcout << dis[T] << ' ' << path.size() - 1 << '\\n';\n\tfor (int i = 1; i <\
    \ path.size(); i++)\n\t\tcout << path[i - 1] << ' ' << path[i] << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"graph/dijkstra.hpp\"\n\n\
    int main() {\n\tint N, M, S, T;\n\tcin >> N >> M >> S >> T;\n\tvector<vector<pair<int,\
    \ long long>>> G(N);\n\tfor (int i = 0; i < M; i++) {\n\t\tint u, v; long long\
    \ w;\n\t\tcin >> u >> v >> w;\n\t\tG[u].emplace_back(v, w);\n\t}\n\t\n\tauto [dis,\
    \ par] = dijkstra(G, S);\n\n\tif (par[T] == -1) {\n\t\tcout << -1 << '\\n';\n\t\
    \treturn 0;\n\t}\n\n\tvector<int> path;\n\tfor (int u = T; u != S; u = par[u])\n\
    \t\tpath.push_back(u);\n\tpath.push_back(S);\n\treverse(path.begin(), path.end());\n\
    \n\tcout << dis[T] << ' ' << path.size() - 1 << '\\n';\n\tfor (int i = 1; i <\
    \ path.size(); i++)\n\t\tcout << path[i - 1] << ' ' << path[i] << '\\n';\n}"
  dependsOn:
  - graph/dijkstra.hpp
  - utility/chmin.hpp
  isVerificationFile: true
  path: verify/dijkstra.aizu-shortest-path.test.cpp
  requiredBy: []
  timestamp: '2022-04-29 22:36:50-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/dijkstra.aizu-shortest-path.test.cpp
layout: document
redirect_from:
- /verify/verify/dijkstra.aizu-shortest-path.test.cpp
- /verify/verify/dijkstra.aizu-shortest-path.test.cpp.html
title: verify/dijkstra.aizu-shortest-path.test.cpp
---
