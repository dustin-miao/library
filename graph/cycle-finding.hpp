template<typename G>
vector<pair<int, int>> find_cycle(const G &graph, const bool directed = true) {
	vector<int> idx(graph.size(), -1), vis(graph.size(), 0);
	vector<pair<int, int>> cycle;
	bool fin = 0;

	const auto dfs = [&](const auto &self, int u, int id, int p) -> int {
		idx[u] = id, vis[u] = 1;
		for (int v : graph[u]) {
			if (fin)
				return -1;
			if (!directed && v == p)
				continue;
			if (idx[u] == idx[v]) {
				cycle.emplace_back(u, v);
				return v;
			}
			if (vis[v])
				continue;
			int k = self(self, v, id, u);
			if (k != -1) {
				cycle.emplace_back(u, v);
				if (u == k) {
					fin = 1;
					return -1;
				}
				return k;
			}
		}
		idx[u] = -1;
		return -1;
	};

	for (int i = 0; i < graph.size(); i++) {
		if (vis[i])
			continue;
		dfs(dfs, i, i, -1);
		if (fin) {
			reverse(cycle.begin(), cycle.end());
			return cycle;
		}
	}
	return vector<pair<int, int>>{};
}