#include "utility/y-combinator.hpp"

#pragma region tree_depth

#ifndef TREE_DEPTH_HPP
#define TREE_DEPTH_HPP

namespace tree {
	vector<int> depth(const vector<vector<int>> &tree, int s = 0) {
		int n = tree.size();
		vector<int> dep(n);

		auto dfs = y_combinator([&](auto dfs, int u, int p = -1) -> void {
			for (int v : tree[u]) {
				if (v == p)
					continue;
				dep[v] = dep[u] + 1;
				dfs(v, u);
			}
		});

		dep[s] = 0;
		dfs(s);
		return dep;
	}
}

#endif

#pragma endregion tree_depth