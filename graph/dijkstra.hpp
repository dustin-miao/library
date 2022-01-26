#include "utility/chmin.hpp"

template<typename G>
pair<vector<long long>, vector<int>> dijkstra(const G &graph, int s) {
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	vector<long long> dis(graph.size(), LLONG_MAX);
	vector<int> par(graph.size(), -1);

	pq.emplace(0, s);
	dis[s] = 0;
	par[s] = s;
	while (!pq.empty()) {
		auto [d, u] = pq.top(); pq.pop();
		if (d != dis[u])
			continue;
		for (auto [v, w] : graph[u])
			if (chmin(dis[v], d + w)) {
				par[v] = u;
				pq.emplace(dis[v], v);
			}
	}
	return {dis, par};
}