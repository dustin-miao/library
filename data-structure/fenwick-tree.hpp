#pragma region fenwick_tree

template<typename T>
class fenwick_tree {
	int n;
	vector<T> tree;

public:
	fenwick_tree() = default;

	fenwick_tree(int _n) { init(_n); }

	void init(int _n) {
		n = _n;
		tree.assign(n + 1, T());
	}

	void update(int i, T v) {
		for (i++; i <= n; i += i & -i)
			tree[i] += v;
	}

	T query(int i) {
		T ret = T();
		for (i++; i; i -= i & -i)
			ret += tree[i];
		return ret;
	}

	T query(int l, int r) { return query(r) - query(l - 1); }
};

#pragma endregion fenwick_tree