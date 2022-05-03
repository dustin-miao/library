#include "utility/y-combinator.hpp"

#pragma region tree_distance

#ifndef TREE_DISTANCE_HPP
#define TREE_DISTANCE_HPP

namespace tree {
	template<typename T>
	vector<T> distance(const vector<vector<pair<int, T>>> &tree, int s = 0) {
		int n = tree.size();
		vector<T> dis(n);

		auto dfs = y_combinator([&](auto dfs, int u, int p = -1) -> void {
			for (auto [v, w] : tree[u]) {
				if (v == p)
					continue;
				dis[v] = dis[u] + w;
				dfs(v, u);
			}
		});

		dis[s] = 0;
		dfs(s);
		return dis;
	}
}

#endif

#pragma endregion tree_distance
