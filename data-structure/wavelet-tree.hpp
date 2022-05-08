#pragma region wavelet_tree

#ifndef WAVELET_TREE_HPP
#define WAVELET_TREE_HPP

class wavelet_tree {
	int n, vlb, vrb;
	vector<vector<int>> tree;

	template<typename I>
	void build(I begin, I end, int t, int vl, int vr) {
		if (vl == vr)
			return;
		int vm = (vl + vr) / 2;
		tree[t].reserve(end - begin + 1);
		tree[t].push_back(0);
		for (auto it = begin; it != end; it++)
			tree[t].push_back(tree[t].back() + (*it <= vm));
		auto pivot = stable_partition(begin, end, [vm](int x) { return x <= vm; });
		build(begin, pivot, t * 2, vl, vm);
		build(pivot, end, t * 2 + 1, vm + 1, vr);
	}

	int quantile(int l, int r, int k, int t, int vl, int vr) {
		if (vl == vr)
			return vl;
		int vm = (vl + vr) / 2, lv = tree[t][r] - tree[t][l - 1];
		if (k <= lv)
			return quantile(tree[t][l - 1] + 1, tree[t][r], k, t * 2, vl, vm);
		else 
			return quantile(l - tree[t][l - 1], r - tree[t][r], k - lv, t * 2 + 1, vm + 1, vr);
	}

	int cnt_leq(int l, int r, int k, int t, int vl, int vr) {
		if (k < vl)
			return 0;
		if (vr <= k)
			return r - l + 1;
		int vm = (vl + vr) / 2;
		return cnt_leq(tree[t][l - 1] + 1, tree[t][r], k, t * 2, vl, vm) + \
			cnt_leq(l - tree[t][l - 1], r - tree[t][r], k, t * 2 + 1, vm + 1, vr);
	}

	int cnt_eq(int l, int r, int k, int t, int vl, int vr) {
		if (k < vl || k > vr)
			return 0;
		if (vl == vr)
			return r - l + 1;
		int vm = (vl + vr) / 2;
		if (k <= vm)
			return cnt_eq(tree[t][l - 1] + 1, tree[t][r], k, t * 2, vl, vm);
		else
			return cnt_eq(l - tree[t][l - 1], r - tree[t][r], k, t * 2 + 1, vm + 1, vr);
	}

public:
	wavelet_tree() = default;

	template<typename I>
	wavelet_tree(I begin, I end, int vl, int vr) { init(begin, end, vl, vr); }

	template<typename I>
	void init(I begin, I end, int vl, int vr) {
		n = vr - vl + 1;
		vlb = vl, vrb = vr;
		tree.resize(4 * n);
		build(begin, end, 1, vl, vr);
	}

	int quantile(int l, int r, int k) { return quantile(l + 1, r + 1, k + 1, 1, vlb, vrb); }

	int cnt_leq(int l, int r, int k) { return cnt_leq(l + 1, r + 1, k, 1, vlb, vrb); }

	int cnt_eq(int l, int r, int k) { return cnt_eq(l + 1, r + 1, k, 1, vlb, vrb); }
};

#endif 

#pragma endregion wavelet_tree
