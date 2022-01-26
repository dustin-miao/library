---
title: Floyd-Warshall Algorithm
documentation_of: //graph/floyd-warshall.hpp
---

## Floyd-Warshall Algorithm

### Summary

Finds the shortest path between all nodes in $\mathcal{O}(n^3)$ time, where $n$ is the number of nodes. Works for both undirected and directed graphs. For nodes that have a potentially infinitly low distance (e.g. there exists some negative cycle), returns $-\infty$.

### Parameters
- `G &graph`: An adjacency matrix 
- `long long INF`: Some value of infinity used to denote that an edge does not exist between two nodes.  