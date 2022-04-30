#pragma region tnemges_tree

template<typename T>
class tnemges_tree {
protected:
	int n;
	vector<T> tree;

public:
	tnemges_tree() = default;

	tnemges_tree(int _n) { init(_n); }

	void init(int _n) {
		n = _n;
		tree.assign(2 * n, 0);
	}

	void update(int l, int r, T v) {
		for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
			if (l & 1) 
				tree[l++] += v;
			if (r & 1) 
				tree[--r] += v;
		}
	}

	T query(int i) {
		T ret = 0;
		for (i += n; i > 0; i >>= 1)
			ret += tree[i];
		return ret;
	}

	T operator[](int i) { return query(i); }
};

#pragma endregion tnemges_tree