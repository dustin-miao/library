template<class Base>
class Segtree : public Base {
	using node = typename Base::T;
	using upd = typename Base::L;

protected:
	size_t n;
	vector<node> tree;
	vector<upd> lazy;

private:
	void pushdown(int t, int tl, int tr) {
		if (lazy[t] == Base::Ldval)
			return;
		int tm = (tl + tr) / 2;
		Base::apply(tree[t * 2], lazy[t * 2], lazy[t], tl, tm);
		Base::apply(tree[t * 2 + 1], lazy[t * 2 + 1], lazy[t], tm + 1, tr);
		lazy[t] = Base::Ldval;
	}

	void update(int l, int r, upd v, int t, int tl, int tr) {
		if (r < tl || tr < l)
			return;
		if (l <= tl && tr <= r) {
			Base::apply(tree[t], lazy[t], v, tl, tr);
			return;
		}
		pushdown(t, tl, tr);
		int tm = (tl + tr) / 2;
		update(l, r, v, t * 2, tl, tm);
		update(l, r, v, t * 2 + 1, tm + 1, tr);
		tree[t] = Base::merge(tree[t * 2], tree[t * 2 + 1]);
	}

	node query(int l, int r, int t, int tl, int tr) {
		if (r < tl || tr < l)
			return Base::Tdval;
		if (l <= tl && tr <= r)
			return tree[t];
		pushdown(t, tl, tr);
		int tm = (tl + tr) / 2;
		return Base::merge(query(l, r, t * 2, tl, tm), query(l, r, t * 2 + 1, tm + 1, tr));
	}

public:
	Segtree() = default;

	Segtree(size_t _n) { init(_n); }

	void init(size_t _n) {
		n = _n;
		tree.assign(4 * n, Base::Tdval);
		lazy.assign(4 * n, Base::Ldval);
	}

	void update(int l, int r, upd v) { update(l, r, v, 1, 0, n - 1); }

	node query(int l, int r) { return query(l, r, 1, 0, n - 1); }
};