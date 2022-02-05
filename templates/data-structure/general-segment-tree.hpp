template<class Base>
class Segtree : public Base {
	using T = typename Base::T;
	using Base::dval;
	using Base::merge;
	using Base::apply;

protected:
	size_t n;
	vector<T> tree;

public:
	Segtree() = default;

	Segtree(size_t _n) { init(_n); }

	void init(size_t _n) {
		for (n = 1; n < _n; n *= 2);
		tree.assign(n * 2, dval);
	}

	void update(int i, T v) {
		for (apply(tree[i += n], v); i >>= 1;)
			tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);
	}

	T query(int l, int r) {
		T lret = dval, rret = dval;
		for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
			if (l & 1) lret = merge(lret, tree[l++]);
			if (r & 1) rret = merge(tree[--r], rret);
		}
		return merge(lret, rret);
	}

	T operator[](int i) { return tree[i += n]; }
};