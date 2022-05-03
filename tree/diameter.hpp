#include "tree/depth.hpp"
#include "tree/distance.hpp"

#pragma region tree_diameter

#ifndef TREE_DIAMETER_HPP
#define TREE_DIAMETER_HPP

namespace tree {
	tuple<int, int, int> diameter(const vector<vector<int>> &tree) {
		auto dep1 = depth(tree, 0);
		int u = max_element(dep1.begin(), dep1.end()) - dep1.begin();
		auto dep2 = depth(tree, u);
		int v = max_element(dep2.begin(), dep2.end()) - dep2.begin();
		return make_tuple(u, v, dep2[v]);
	}

	template<typename T>
	tuple<int, int, T> diameter(const vector<vector<pair<int, T>>> &tree) {
		auto dis1 = distance(tree, 0);
		int u = max_element(dis1.begin(), dis1.end()) - dis1.begin();
		auto dis2 = distance(tree, u);
		int v = max_element(dis2.begin(), dis2.end()) - dis2.begin();
		return make_tuple(u, v, dis2[v]);
	}
}

#endif

#pragma endregion tree_diameter