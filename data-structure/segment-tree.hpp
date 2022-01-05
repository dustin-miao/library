class segtree {
	using T = long long;

	const static T dval = T();

	static T merge(const T &a, const T &b) { return a + b; }

	static void apply(T &a, const T &b) { a += b; }

	int n;
	vector<T> tree;

public:
	void init(int _n) {
		n = _n;
		tree.assign(2 * n, dval);
		for (int i = n - 1; i > 0; i--)
			tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);
	}

	template<typename Iterator>
	void init(Iterator begin, Iterator end) {
		n = distance(begin, end);
		tree.resize(2 * n);
		for (int i = n; i < 2 * n; i++, begin++)
			tree[i] = *begin;
		for (int i = n - 1; i > 0; i--)
			tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);
	}

	void update(int i, T v) {
		for (apply(tree[i += n], v); i > 1; i >>= 1)
			tree[i >> 1] = merge(tree[i], tree[i ^ 1]);
	}

	T query(int l, int r) {
		T ret = segtree::dval;
		for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ret = merge(ret, tree[l++]);
			if (r & 1) ret = merge(ret, tree[--r]);
		}
		return ret;
	}

	T operator[](int i) { return tree[i += n]; }
};