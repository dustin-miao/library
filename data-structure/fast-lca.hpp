#include "data-structure/sparse-table.hpp"

#pragma region fast_lca

class fast_lca {
	sparse_table<pair<int, int>> st;
	vector<int> pos;

public:
	fast_lca() = default;

	fast_lca(const vector<vector<int>> &tree, int s = 0) { init(tree, s); }

	template<typename T>
	fast_lca(const vector<vector<pair<int, T>>> &tree, int s = 0) { 
		int n = tree.size();
		vector<vector<int>> _tree(n);
		for (int u = 0; u < n; u++)
			for (auto [v, w] : tree[u])
				_tree[u].push_back(v);
		init(_tree, s); 
	}

	void init(const vector<vector<int>> &tree, int s = 0) {
		int n = tree.size();
		pos.resize(n);
		vector<pair<int, int>> A;
		A.reserve(2 * n);

		const auto dfs = [&](const auto &self, int u, int d = 0, int p = -1) -> void {
			pos[u] = A.size();
			A.emplace_back(d, u);
			for (int v : tree[u]) {
				if (v == p)
					continue;
				self(self, v, d + 1, u);
				A.emplace_back(d, u);
			}
		};

		dfs(dfs, s);

		st.init(A.begin(), A.end());
	}

	int query(int u, int v) {
		if (pos[u] > pos[v])
			swap(u, v);
		auto [d, a] = st.query(pos[u], pos[v]);
		return a;
	}

	int operator()(int u, int v) { return query(u, v); }
};

#pragma endregion fast_lca