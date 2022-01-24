template<class Base>
class Segtree : public Base {
	using node = typename Base::T;

protected:
	size_t n;
	vector<node> tree;

private:
	void update(int i, node v, int t, int tl, int tr) {
		if (tl == tr) {
			Base::apply(tree[t], v);
			return;
		}
		int tm = (tl + tr) / 2;
		if (i <= tm)
			update(i, v, t * 2, tl, tm);
		else 
			update(i, v, t * 2 + 1, tm + 1, tr);
		tree[t] = Base::merge(tree[t * 2], tree[t * 2 + 1]);
	}

	node query(int l, int r, int t, int tl, int tr) {
		if (r < tl || tr < l)
			return Base::dval;
		if (l <= tl && tr <= r)
			return tree[t];
		int tm = (tl + tr) / 2;
		return Base::merge(query(l, r, t * 2, tl, tm), query(l, r, t * 2 + 1, tm + 1, tr));
	}

public:
	Segtree() = default;

	Segtree(size_t _n) { init(_n); }

	void init(size_t _n) {
		n = _n;
		tree.assign(n * 4, Base::dval);
	}

	void update(int i, node v) { update(i, v, 1, 0, n - 1); }

	node query(int l, int r) { return query(l, r, 1, 0, n - 1); }
};