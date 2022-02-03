template<class Base>
class Segtree : public Base {
	using T = Base::T;
	using Base::dval;
	using Base::merge;
	using Base::apply;

protected:
	size_t n;

	struct node {
		T v;
		int l, r;
	};

	int root;
	vector<node> tree;

	size_t new_node() {
		tree.emplace_back(dval, -1, -1);
		return tree.size() - 1;
	}

private:
	void update(int i, T v, int t, int tl, int tr) {
		if (tl == tr) {
			apply(tree[t].v, v);
			return;
		}
		int tm = (tl + tr) / 2;
		if (i <= tm) {
			if (tree[t].l == -1)
				tree[t].l = new_node();
			update(i, v, tree[t].l, tl, tm);
		} else {
			if (tree[t].r == -1)
				tree[t].r = new_node();
			update(i, v, tree[t].r, tm + 1, tr);
		}
		tree[t].v = merge(tree[t].l == -1 ? dval : tree[tree[t].l].v, tree[t].r == -1 ? dval : tree[tree[t].r].v);
	}

	T query(int l, int r, int t, int tl, int tr) {
		if (r < tl || tr < l)
			return dval;
		if (l <= tl && tr <= r)
			return tree[t].v;
		int tm = (tl + tr) / 2;
		return merge(tree[t].l == -1 ? dval : query(l, r, tree[t].l, tl, tm), tree[t].r == -1 ? dval : query(l, r, tree[t].r, tm + 1, tr));
	}

public:
	Segtree() = default;

	Segtree(size_t _n) { init(_n); }

	void init(size_t _n) {
		n = _n;
		root = new_node();
	}

	void reserve(size_t _n) { tree.reserve(_n); }

	void clear() { tree.clear(); }

	void update(int i, T v) { update(i, v, root, 0, n - 1); }

	T query(int l, int r) { return query(l, r, root, 0, n - 1); }
};