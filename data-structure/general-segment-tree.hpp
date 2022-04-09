template<class segment_tree_template>
class gen_segment_tree : public segment_tree_template {
	using T = typename segment_tree_template::type;
	using segment_tree_template::default_value;
	using segment_tree_template::merge;
	using segment_tree_template::apply;

protected:
	int n;
	vector<T> tree;

public:
	gen_segment_tree() = default;

	gen_segment_tree(int _n) { init(_n); }

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