#pragma region tree_unweight 

#ifndef TREE_UNWEIGHT_HPP
#define TREE_UNWEIGHT_HPP

namespace tree {
	template<typename T>
	vector<vector<int>> unweight(const vector<vector<pair<int, T>>> &tree) {
		int n = tree.size();
		vector<vector<int>> ret(n);
		for (int u = 0; u < n; u++) 
			for (auto [v, w] : tree[u])
				ret[u].push_back(v);
		return ret;
	}
}

#endif

#pragma endregion tree_unweight