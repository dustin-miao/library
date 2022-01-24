---
title: Kruskal's Algorithm
documentation_of: //graph/kruskal.hpp
---

## Kruskal's Algorithm

### Summary

Finds the minimum spanning tree of an undirected graph in $\mathcal{O}(\lvert E \rvert \log \lvert E \rvert)$. Returns the minimum spanning forest if a spanning tree doesn't exist

### Parameters
- `std::vector<std::tuple<int, int, long long>> edges`: A list of undirected edges $(\texttt{node1}, \texttt{node2}, \texttt{weight})$. 

