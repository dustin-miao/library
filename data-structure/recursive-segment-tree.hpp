template<class Base>
class Segtree : public Base {
	using T = typename Base::T;
	using Base::dval;
	using Base::merge;
	using Base::apply;

protected:
	size_t n;
	vector<T> tree;

private:
	void update(int i, T v, int t, int tl, int tr) {
		if (tl == tr) {
			apply(tree[t], v);
			return;
		}
		int tm = (tl + tr) / 2;
		if (i <= tm)
			update(i, v, t * 2, tl, tm);
		else 
			update(i, v, t * 2 + 1, tm + 1, tr);
		tree[t] = merge(tree[t * 2], tree[t * 2 + 1]);
	}

	T query(int l, int r, int t, int tl, int tr) {
		if (r < tl || tr < l)
			return dval;
		if (l <= tl && tr <= r)
			return tree[t];
		int tm = (tl + tr) / 2;
		return merge(query(l, r, t * 2, tl, tm), query(l, r, t * 2 + 1, tm + 1, tr));
	}

public:
	Segtree() = default;

	Segtree(size_t _n) { init(_n); }

	void init(size_t _n) {
		n = _n;
		tree.assign(n * 4, dval);
	}

	void update(int i, T v) { update(i, v, 1, 0, n - 1); }

	T query(int l, int r) { return query(l, r, 1, 0, n - 1); }
};