---
title: Edmonds-Karp Algorithm
documentation_of: //graph/edmonds-karp.hpp
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

A path can be found in $\mathcal{O}(\lvert E \rvert)$ time using DFS or BFS, so if the capacities are integral then the total complexity is $\mathcal{O}(\lvert E \rvert F)$, where $F$ is the maximum flow.

## Edmonds-Karp Algorithm

An implementation of the Ford-Fulkerson Method that uses BFS to find the paths. The algorithm runs in $\mathcal{O}(\lvert V \rvert \lvert E \rvert ^ 2)$.