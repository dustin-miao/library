template<class segment_tree_template>
class segment_tree : public segment_tree_template {
	using T = typename segment_tree_template::type;
	using segment_tree_template::default_value;
	using segment_tree_template::merge;
	using segment_tree_template::apply;

protected:
	int n;
	vector<T> tree;

public:
	segment_tree() = default;

	segment_tree(int _n) { init(_n); }

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

	T operator[](int i) { return tree[i += n]; }
};