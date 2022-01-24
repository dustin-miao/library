---
title: Kruskal's Algorithm
documentation_of: //graph/kruskal.hpp
---

## Kruskal's Algorithm

### Summary

Finds the minimum spanning tree of an undirected graph if it exists in $\mathcal{O}(\lvert E \rvert \log \lvert E \rvert)$. Returns `LLONG_MAX` if no spanning tree exists

### Parameters
- `std::vector<std::tuple<int, int, long long>> edges`: A list of undirected edges $(\texttt{node1}, \texttt{node2}, \texttt{weight})$. 

