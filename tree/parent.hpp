#include "utility/y-combinator.hpp"

#pragma region tree_parent

#ifndef TREE_PARENT_HPP
#define TREE_PARENT_HPP

namespace tree {
	vector<int> parent(const vector<vector<int>> &tree, int s = 0) {
		int n = tree.size();
		vector<int> par(n);

		auto dfs = y_combinator([&](auto dfs, int u) -> void {
			for (int v : tree[u]) {
				if (v == par[u])
					continue;
				par[v] = u;
				dfs(v);
			}
		});
		
		par[s] = s;
		dfs(s);
		return par;
	}
}

#endif

#pragma endregion tree_parent
