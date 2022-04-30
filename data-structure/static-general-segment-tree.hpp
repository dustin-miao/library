#pragma region sta_gen_segment_tree

class sta_gen_segment_tree {
	using T = long long;

	static constexpr T default_value = 0;

	static void apply(T &a, T b) { a += b; }

	static T merge(T a, T b) { return a + b; }

protected:
	int n;
	vector<T> tree;

public:
	sta_gen_segment_tree() = default;

	sta_gen_segment_tree(size_t _n) { init(_n); }

	void init(int _n) {
		for (n = 1; n < _n; n *= 2);
		tree.assign(n * 2, default_value);
	}

	void update(int i, T v) {
		for (apply(tree[i += n], v); i >>= 1;)
			tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);
	}

	T query(int l, int r) {
		T lret = default_value, rret = default_value;
		for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
			if (l & 1) 
				lret = merge(lret, tree[l++]);
			if (r & 1) 
				rret = merge(tree[--r], rret);
		}
		return merge(lret, rret);
	}

	T operator[](int i) { return tree[i + n]; }
};

#pragma endregion sta_gen_segment_tree