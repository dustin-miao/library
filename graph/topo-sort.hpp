#pragma region topo_sort

#ifndef TOPO_SORT_HPP
#define TOPO_SORT_HPP

vector<int> topo_sort(const vector<vector<int>> &G) {
	int n = G.size();
	vector<bool> vis(n, false);
	vector<int> ord;
	ord.reserve(n);

	const auto dfs = [&](const auto &self, int u) -> void {
		vis[u] = true;
		for (int v : G[u])
			if (!vis[v])
				self(self, v);
		ord.push_back(u);
	};

	for (int i = 0; i < n; i++)
		if (!vis[i])
			dfs(dfs, i);
	reverse(ord.begin(), ord.end());
	return ord;
}

#endif

#pragma endregion topo_sort