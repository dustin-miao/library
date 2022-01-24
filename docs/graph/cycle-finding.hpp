---
title: Cycle Finding
documentation_of: //graph/cycle-finding.hpp
---

## Cycle Finding

### Summary

Detects and finds a cycle in a given graph, which can be directed or undircted. If such a cycle exists, then edges (pairs of nodes)
are returned. If no cycles exist, then an empty `std::vector` is returned

### Parameters
- `const G& graph`: A `std::vector<T>` that describes the graph, where `T` is an iterable data structure containing integers.
- `bool directed`: Describes wether `graph` is directed or undirected. 

