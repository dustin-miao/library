class Segtree {
	using T = long long;

	const T dval = 0;

	static void apply(T &a, T b) { a += b; }

	static T merge(T a, T b) { return a + b; }

protected:
	int n;
	vector<T> tree;

public:
	Segtree() = default;

	Segtree(int _n) { init(_n); }

	void init(int _n) {
		n = _n;
		tree.assign(n * 2, Segtree::dval);
	}

	void update(int i, T v) {
		for (apply(tree[i += n], v); i >>= 1;)
			tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);
	}

	T query(int l, int r) {
		T ret = Segtree::dval;
		for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ret = merge(ret, tree[l++]);
			if (r & 1) ret = merge(ret, tree[--r]);
		}
		return ret;
	}

	T operator[](int i) { return tree[i += n]; }
};