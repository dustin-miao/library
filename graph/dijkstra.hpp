#include "utility/chmin.hpp"

#pragma region dijkstra

#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

template<typename T>
pair<vector<long long>, vector<int>> dijkstra(const vector<vector<pair<int, T>>> &G, int s) {
	int n = G.size();
	priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
	vector<T> dis(n, numeric_limits<T>::max());
	vector<int> par(n, -1);

	pq.emplace(0, s);
	dis[s] = 0;
	par[s] = s;
	while (!pq.empty()) {
		auto [d, u] = pq.top(); pq.pop();
		if (d != dis[u])
			continue;
		for (auto [v, w] : G[u])
			if (chmin(dis[v], d + w)) {
				par[v] = u;
				pq.emplace(dis[v], v);
			}
	}
	return {dis, par};
}

#endif

#pragma endregion dijkstra