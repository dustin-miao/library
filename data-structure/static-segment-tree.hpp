#pragma region sta_segment_tree

class sta_segment_tree {
	using T = long long;

	static constexpr T default_value = 0;

	static void apply(T &a, T b) { a += b; }

	static T merge(T a, T b) { return a + b; }

protected:
	int n;
	vector<T> tree;

public:
	sta_segment_tree() = default;

	sta_segment_tree(int _n) { init(_n); }

	void init(int _n) {
		n = _n;
		tree.assign(n * 2, default_value);
	}

	void update(int i, T v) {
		for (apply(tree[i += n], v); i >>= 1;)
			tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);
	}

	T query(int l, int r) {
		T ret = default_value;
		for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
			if (l & 1) 
				ret = merge(ret, tree[l++]);
			if (r & 1) 
				ret = merge(ret, tree[--r]);
		}
		return ret;
	}

	T operator[](int i) { return tree[i + n]; }
};

#pragma endregion sta_segment_tree