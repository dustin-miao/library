#include "data-structure/union-find.hpp"

template<typename G>
long long kruskal(const G &graph) {
	vector<tuple<long long, int, int>> edges;
	for (int u = 0; u < graph.size(); u++)
		for (auto [v, w] : graph[u])
			edges.emplace_back(u, v, w);
	return kruskal(graph.size(), edges);
}

long long kruskal(int n, vector<tuple<int, int, long long>> edges) {
	UnionFind dsu(n);
	sort(edges.begin(), edges.end(), [](const tuple<int, int, long long> &a, const tuple<int, int, long long> &b) {
		return get<2>(a) < get<2>(b); 
	});
	long long ret = 0;
	for (auto [u, v, w] : edges) {
		if (dsu.merge(u, v))
			ret += w;
		if (dsu.size(0) == n)
			return ret;
	}
	return n <= 1 ? 0 : LLONG_MAX;
}