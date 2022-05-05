#pragma region find_cycle

#ifndef CYCLE_FINDING_HPP
#define CYCLE_FINDING_HPP

vector<pair<int, int>> find_cycle(const vector<vector<int>> &G, bool directed) {
	int n = G.size();
	vector<int> idx(n, -1);
	vector<bool> vis(n, false);
	vector<pair<int, int>> cycle;
	bool fin = 0;

	const auto dfs = [&](const auto &self, int u, int id, int p) -> int {
		idx[u] = id;
		vis[u] = true;
		for (int v : G[u]) {
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

	for (int i = 0; i < n; i++) {
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

template<typename T>
vector<pair<int, int>> find_cycle(const vector<vector<pair<int, T>>> &G, bool directed) {
	int n = G.size();
	vector<int> idx(n, -1);
	vector<bool> vis(n, false);
	vector<pair<int, int>> cycle;
	bool fin = 0;

	const auto dfs = [&](const auto &self, int u, int id, int p) -> int {
		idx[u] = id;
		vis[u] = true;
		for (auto [v, w] : G[u]) {
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

	for (int i = 0; i < n; i++) {
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

#endif

#pragma endregion find_cycle