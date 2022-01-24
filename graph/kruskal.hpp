#include "data-structure/union-find.hpp"

vector<vector<pair<int, long long>>> kruskal(int n, vector<tuple<int, int, long long>> edges) {
	vector<vector<pair<int, long long>>> mst(n);
	if (n <= 1)
		return mst;
	UnionFind dsu(n);
	sort(edges.begin(), edges.end(), [](const tuple<int, int, long long> &a, const tuple<int, int, long long> &b) { return get<2>(a) < get<2>(b); });
	for (auto [u, v, w] : edges) {
		if (dsu.merge(u, v)) {
			mst[u].emplace_back(v, w);
			mst[v].emplace_back(u, w);
		}
		if (dsu.size(0) == n)
			break;
	}
	return mst;
}