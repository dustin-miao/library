---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/edmonds-karp.hpp\"\n#pragma region graph_flow_edmonds_karp\n\
    \n#ifndef EDMONDS_KARP_HPP\n#define EDMONDS_KARP_HPP\n\ntemplate<typename T>\n\
    T edmonds_karp(const vector<vector<pair<int, T>> &G, int s, int t) {\n\tint n\
    \ = G.size();\n\tT flow = 0, mx = numeric_limits<T>::max();\n\tvector<vector<T>>\
    \ cap(n, vector<T>(n));\n\tvector<int> par(n);\n\n\twhile (true) {\n\t\tqueue<pair<int,\
    \ T>> q;\n\t\tfill(par.begin(), par.end(), -1);\n\t\tT nflow = 0;\n\n\t\tq.emplace(s,\
    \ mx)\n\t\tpar[s] = s;\n\t\twhile (!q.empty()) {\n\t\t\tauto [u, f] = q.front();\
    \ q.pop();\n\t\t\tfor (int v : G[u]) {\n\t\t\t\tif (par[v] == -1 && cap[u][v])\
    \ {\n\t\t\t\t\tpar[v] = u;\n\t\t\t\t\tif (v == t) {\n\t\t\t\t\t\tnflow = min(f,\
    \ cap[u][v]);\n\t\t\t\t\t\tgoto bfs_end\n\t\t\t\t\t} else {\n\t\t\t\t\t\tq.emplace(v,\
    \ min(f, cap[u][v]));\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\t\n\t\tbfs_end:\n\
    \n\t\tif (nflow == 0)\n\t\t\tbreak;\n\t\tflow += nflow;\n\t\tfor (int u = t; u\
    \ != s; u = par[u]) {\n\t\t\tcap[par[u]][u] -= nflow;\n\t\t\tcap[u][par[u]] -=\
    \ nflow;\n\t\t}\n\t}\n\t\n\treturn flow;\n}\n\n\n#endif \n\n#pragma endregion\
    \ graph_flow_edmonds_karp\n"
  code: "#pragma region graph_flow_edmonds_karp\n\n#ifndef EDMONDS_KARP_HPP\n#define\
    \ EDMONDS_KARP_HPP\n\ntemplate<typename T>\nT edmonds_karp(const vector<vector<pair<int,\
    \ T>> &G, int s, int t) {\n\tint n = G.size();\n\tT flow = 0, mx = numeric_limits<T>::max();\n\
    \tvector<vector<T>> cap(n, vector<T>(n));\n\tvector<int> par(n);\n\n\twhile (true)\
    \ {\n\t\tqueue<pair<int, T>> q;\n\t\tfill(par.begin(), par.end(), -1);\n\t\tT\
    \ nflow = 0;\n\n\t\tq.emplace(s, mx)\n\t\tpar[s] = s;\n\t\twhile (!q.empty())\
    \ {\n\t\t\tauto [u, f] = q.front(); q.pop();\n\t\t\tfor (int v : G[u]) {\n\t\t\
    \t\tif (par[v] == -1 && cap[u][v]) {\n\t\t\t\t\tpar[v] = u;\n\t\t\t\t\tif (v ==\
    \ t) {\n\t\t\t\t\t\tnflow = min(f, cap[u][v]);\n\t\t\t\t\t\tgoto bfs_end\n\t\t\
    \t\t\t} else {\n\t\t\t\t\t\tq.emplace(v, min(f, cap[u][v]));\n\t\t\t\t\t}\n\t\t\
    \t\t}\n\t\t\t}\n\t\t}\n\t\t\n\t\tbfs_end:\n\n\t\tif (nflow == 0)\n\t\t\tbreak;\n\
    \t\tflow += nflow;\n\t\tfor (int u = t; u != s; u = par[u]) {\n\t\t\tcap[par[u]][u]\
    \ -= nflow;\n\t\t\tcap[u][par[u]] -= nflow;\n\t\t}\n\t}\n\t\n\treturn flow;\n\
    }\n\n\n#endif \n\n#pragma endregion graph_flow_edmonds_karp"
  dependsOn: []
  isVerificationFile: false
  path: graph/edmonds-karp.hpp
  requiredBy: []
  timestamp: '2022-05-13 08:32:57-07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/edmonds-karp.hpp
layout: document
title: Edmonds-Karp Algorithm
---

## Network Flow

Define a network to be a graph $G = \langle V, E \rangle$ and a function $c: E \rightarrow W$ that maps each edge to a capacity. Label two vertices $s, t \in V$ as the source and the sink. 

The flow of a network is a function $f: E \rightarrow W$ that satisfies the following properties for all $e \in E$ and $u \in V, u \neq s, u \neq t$:
1. $$f(e) \leq c(e)$$
2. $$\sum_{e \in E, \; \text{e ends at } u} f(e) = \sum_{e \in E, \; \text{e begins at } u} f(e)$$

In other words, the flow of an edge cannot exceed its capacity, and the sum of the incoming flows to any node other than the source or sink must equal to the outgoing flows. 

Define the cost of a network as 

$$\sum_{e \in E, \; \text{e ends at } t} f(e)$$

or the sum of the incoming flows to the sink. The maximal flow problem seeks to find the maximum cost of a given network. 

## Ford-Fulkerson Method

Define the residual capacity $r$ of some edge $e$ as $c(e) - f(e)$. For every edge $e = (u, v)$, define the capacity of edge $(v, u)$ to be $0$ and the flow of $(v, u)$ to be $-f(e)$. Let $G' = \langle V, E \rangle$ with capacity function $r$ be the residual flow network. 

If exists a positively weighted path in $G'$ from $s$ to $t$, let the edges in the path be $P = \{e_1, e_2, \cdots, e_k\}$, and let $m = \min_{e \in P}r(e)$. For each edge $e \in P$, increase the flow of $e$ by $m$ and decrease the flow of the inverse edge by $m$. Repeat this process until a path does not exist. 

A path can be found in $\mathcal{O}(|E|)$ time using DFS or BFS, so if the capacities are integral then the total complexity is $\mathcal{O}(|E|F)$, where $F$ is the maximum flow.

## Edmonds-Karp Algorithm

An implementation of the Ford-Fulkerson Method that uses BFS to find the paths. The algorithm runs in $\mathcal{O}(|V||E|^2)$.