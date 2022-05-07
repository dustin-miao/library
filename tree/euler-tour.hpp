#include "utility/y-combinator.hpp"

#pragma region euler_tour

#ifndef EULER_TOUR_HPP
#define EULER_TOUR_HPP

namespace tree {
	pair<vector<int>, vector<int>> euler_tour(const vector<vector<int>> &tree, int s = 0) {
		int n = tree.size();
		vector<int> ltime(n), rtime(n);
		int time = -1;

		auto dfs = y_combinator([&](auto dfs, int u, int p = -1) -> void {
			ltime[u] = ++time;
			for (int v : tree[u]) {
				if (v == p)
					continue;
				dfs(v, u);
			}
			rtime[u] = time;
		});

		dfs(s);
		return make_pair(ltime, rtime);
	}
}

#endif

#pragma endregion euler_tour