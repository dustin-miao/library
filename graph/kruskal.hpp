#include "data-structure/union-find.hpp"

template<class T>
vector<vector<pair<int, T>>> kruskal(int n, vector<tuple<int, int, T>> E) {
	vector<vector<pair<int, T>>> mst(n);
	if (n <= 1)
		return mst;
	UnionFind dsu(n);
	sort(E.begin(), E.end(), 
		[](auto a, auto b) { 
			return get<2>(a) < get<2>(b); 
		}
	);
	for (auto [u, v, w] : E) {
		if (dsu.merge(u, v)) {
			mst[u].emplace_back(v, w);
			mst[v].emplace_back(u, w);
		}
		if (dsu.size(0) == n)
			break;
	}
	return mst;
}