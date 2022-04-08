#include "data-structure/sparse-table.hpp"

class LowestCommonAncestor {
	SparseTable<pair<int, int>> st;
	vector<int> pos;

public:
	LowestCommonAncestor() = default;

	LowestCommonAncestor(const vector<vector<int>> &tree) { init(tree); }

	template<typename T>
	LowestCommonAncestor(const vector<vector<pair<int, T>>> &tree) { init(tree); }

	void init(const vector<vector<int>> &tree) {
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

		dfs(dfs, 0);

		st.init(A.begin(), A.end());
	}

	template<typename T>
	void init(const vector<vector<pair<int, T>>> &tree) {
		int n = tree.size();
		pos.resize(n);
		vector<pair<int, int>> A;
		A.reserve(2 * n);

		const auto dfs = [&](const auto &self, int u, int d = 0, int p = -1) -> void {
			pos[u] = A.size();
			A.emplace_back(d, u);
			for (auto [v, w] : tree[u]) {
				if (v == p)
					continue;
				self(self, v, d + 1, u);
				A.emplace_back(d, u);
			}
		};

		dfs(dfs, 0);

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