#include "utility/chmin.hpp"

template<class T>
vector<vector<pair<int, T>>> prim(const vector<vector<pair<int, T>>> &G) {
	int n = G.size();
	vector<vector<pair<int, T>>> mst(n);
	if (n <= 1)
		return mst;
	priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
	vector<T> dis(n, numeric_limits<T>::max());
	vector<int> par(n, -1);
	vector<bool> vis(n, false);

	pq.emplace(0, 0);
	dis[0] = 0;
	par[0] = 0;
	while (!pq.empty()) {
		auto [d, u] = pq.top(); pq.pop();
		if (vis[u])
			continue;
		vis[u] = true;
		if (u != 0) {
			mst[u].emplace_back(par[u], d);
			mst[par[u]].emplace_back(u, d);
		}
		for (auto [v, w] : G[u])
			if (!vis[v] && chmin(dis[v], w)) {
				par[v] = u;
				pq.emplace(dis[v], v);
			}
	}
	return mst;
}