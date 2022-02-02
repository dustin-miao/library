template<class Base>
class Segtree : public Base {
	using T = typename Base::T;
	using L = typename Base::L;
	using Base::Tdval;
	using Base::Ldval;
	using Base::merge;
	using Base::apply;

protected:
	size_t n;
	vector<T> tree;
	vector<L> lazy;

private:
	void pushdown(int t, int tl, int tr) {
		if (lazy[t] == Ldval)
			return;
		int tm = (tl + tr) / 2;
		apply(tree[t * 2], lazy[t * 2], lazy[t], tl, tm);
		apply(tree[t * 2 + 1], lazy[t * 2 + 1], lazy[t], tm + 1, tr);
		lazy[t] = Ldval;
	}

	void update(int l, int r, L v, int t, int tl, int tr) {
		if (r < tl || tr < l)
			return;
		if (l <= tl && tr <= r) {
			apply(tree[t], lazy[t], v, tl, tr);
			return;
		}
		pushdown(t, tl, tr);
		int tm = (tl + tr) / 2;
		update(l, r, v, t * 2, tl, tm);
		update(l, r, v, t * 2 + 1, tm + 1, tr);
		tree[t] = merge(tree[t * 2], tree[t * 2 + 1]);
	}

	T query(int l, int r, int t, int tl, int tr) {
		if (r < tl || tr < l)
			return Tdval;
		if (l <= tl && tr <= r)
			return tree[t];
		pushdown(t, tl, tr);
		int tm = (tl + tr) / 2;
		return merge(query(l, r, t * 2, tl, tm), query(l, r, t * 2 + 1, tm + 1, tr));
	}

public:
	Segtree() = default;

	Segtree(size_t _n) { init(_n); }

	void init(size_t _n) {
		n = _n;
		tree.assign(4 * n, Tdval);
		lazy.assign(4 * n, Ldval);
	}

	void update(int l, int r, L v) { update(l, r, v, 1, 0, n - 1); }

	T query(int l, int r) { return query(l, r, 1, 0, n - 1); }
};