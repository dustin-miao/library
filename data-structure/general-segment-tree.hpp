template<class Base>
class Segtree : public Base {
	using node = typename Base::T;

	size_t n;
	vector<node> tree;

public:
	Segtree() = default;

	Segtree(size_t _n) { init(_n); }

	void init(size_t _n) {
		for (n = 1; n < _n; n *= 2);
		tree.assign(n * 2, Base::dval);
	}

	void update(int i, node v) {
		Base::apply(tree[i += n], v);
		for (i >>= 1; i > 1; i >>= 1)
			tree[i] = Base::merge(tree[i << 1], tree[i << 1 | 1]);
	}

	node query(int l, int r) {
		node lret = Base::dval, rret = Base::dval;
		for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
			if (l & 1) lret = Base::merge(lret, tree[l++]);
			if (r & 1) rret = Base::merge(tree[--r], rret);
		}
		return Base::merge(lret, rret);
	}

	node operator[](int i) { return tree[i += n]; }
};