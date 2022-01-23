template<class Base>
class Segtree : public Base {
	using node = typename Base::T;

	size_t n;
	vector<node> tree;

public:
	Segtree() = default;

	Segtree(size_t _n) { init(n); }

	void init(size_t _n) {
		n = _n;
		tree.assign(n * 2, Base::dval);
	}

	void update(int i, node v) {
		for (Base::apply(tree[i += n], v); i > 1; i >>= 1)
			tree[i >> 1] = Base::merge(tree[i], tree[i ^ 1]);
	}

	node query(int l, int r) {
		node ret = Base::dval;
		for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ret = Base::merge(ret, tree[l++]);
			if (r & 1) ret = Base::merge(ret, tree[--r]);
		}
		return ret;
	}

	node operator[](int i) { return tree[i += n]; }
};