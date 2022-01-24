---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/union-find.hpp
    title: Union Find
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.hpp
    title: Kruskal's Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
  bundledCode: "#line 1 \"verify/kruskal.aizu-minimum-spanning-tree.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data-structure/union-find.hpp\"\
    \nstruct UnionFind {\n    vector<int> parent, setsize;\n\n    UnionFind() = default;\n\
    \n    UnionFind(int n) { init(n); }\n\n    void init(int n) {\n        parent.resize(n);\n\
    \        setsize.resize(n);\n        iota(parent.begin(), parent.end(), 0);\n\
    \        fill(setsize.begin(), setsize.end(), 1);\n    }\n\n    int find(int u)\
    \ {\n        if (u == parent[u])\n            return u;\n        return parent[u]\
    \ = find(parent[u]);\n    }\n\n    bool merge(int u, int v) {\n        u = find(u),\
    \ v = find(v);\n        if (u == v)\n            return false;\n        if (setsize[u]\
    \ > setsize[v]) {\n            parent[v] = u;\n            setsize[u] += setsize[v];\n\
    \        } else {\n            parent[u] = v;\n            setsize[v] += setsize[u];\n\
    \        }\n        return true;\n    }\n\n    int size(int u) {\n        return\
    \ setsize[find(u)];\n    }\n};\n#line 2 \"graph/kruskal.hpp\"\n\ntemplate<typename\
    \ G>\nlong long kruskal(const G &graph) {\n\tvector<tuple<long long, int, int>>\
    \ edges;\n\tfor (int u = 0; u < graph.size(); u++)\n\t\tfor (auto [v, w] : graph[u])\n\
    \t\t\tedges.emplace_back(u, v, w);\n\treturn kruskal(graph.size(), edges);\n}\n\
    \nlong long kruskal(int n, vector<tuple<int, int, long long>> edges) {\n\tUnionFind\
    \ dsu(n);\n\tsort(edges.begin(), edges.end(), [](const tuple<int, int, long long>\
    \ &a, const tuple<int, int, long long> &b) {\n\t\treturn get<2>(a) < get<2>(b);\
    \ \n\t});\n\tlong long ret = 0;\n\tfor (auto [u, v, w] : edges) {\n\t\tif (dsu.merge(u,\
    \ v))\n\t\t\tret += w;\n\t\tif (dsu.size(0) == n)\n\t\t\treturn ret;\n\t}\n\t\
    return n <= 1 ? 0 : LLONG_MAX;\n}\n#line 7 \"verify/kruskal.aizu-minimum-spanning-tree.test.cpp\"\
    \n\nint main() {\n\tint N, M;\n\tcin >> N >> M;\n\tvector<tuple<int, int, long\
    \ long>> E;\n\tfor (int i = 0; i < M; i++) {\n\t\tint u, v; long long w;\n\t\t\
    cin >> u >> v >> w;\n\t\tE.emplace_back(u, v, w);\n\t}\n\tcout << kruskal(N, E)\
    \ << '\\n';\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"graph/kruskal.hpp\"\
    \n\nint main() {\n\tint N, M;\n\tcin >> N >> M;\n\tvector<tuple<int, int, long\
    \ long>> E;\n\tfor (int i = 0; i < M; i++) {\n\t\tint u, v; long long w;\n\t\t\
    cin >> u >> v >> w;\n\t\tE.emplace_back(u, v, w);\n\t}\n\tcout << kruskal(N, E)\
    \ << '\\n';\n}"
  dependsOn:
  - graph/kruskal.hpp
  - data-structure/union-find.hpp
  isVerificationFile: true
  path: verify/kruskal.aizu-minimum-spanning-tree.test.cpp
  requiredBy: []
  timestamp: '2022-01-24 07:06:40-08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/kruskal.aizu-minimum-spanning-tree.test.cpp
layout: document
redirect_from:
- /verify/verify/kruskal.aizu-minimum-spanning-tree.test.cpp
- /verify/verify/kruskal.aizu-minimum-spanning-tree.test.cpp.html
title: verify/kruskal.aizu-minimum-spanning-tree.test.cpp
---
