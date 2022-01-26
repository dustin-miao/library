---
title: Dijkstra's Algorithm
documentation_of: //graph/dijkstra.hpp
---

## Dijkstra's Algorithm

### Summary

Finds the shortest path from a source $S$ in a directed or undirected weighted graph. Returns both the distance to each node as well as the shortest path tree. 

### Parameters
- `const G& graph`: A `std::vector<T>` that describes the graph, where `T` is an iterable data structure containing integers.
- `int S`: The source vertex, `S` must be in `graph`. 