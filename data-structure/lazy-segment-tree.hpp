template<class segment_tree_template>
class lazy_segment_tree : public segment_tree_template {
	using T = typename segment_tree_template::node_type;
	using L = typename segment_tree_template::lazy_type;
	using segment_tree_template::node_default_value;
	using segment_tree_template::lazy_default_value;
	using segment_tree_template::merge;
	using segment_tree_template::apply;

protected:
	int n;
	vector<T> tree;
	vector<L> lazy;

private:
	void pushdown(int t, int tl, int tr) {
		if (lazy[t] == lazy_default_value)
			return;
		int tm = (tl + tr) / 2;
		apply(tree[t * 2], lazy[t * 2], lazy[t], tl, tm);
		apply(tree[t * 2 + 1], lazy[t * 2 + 1], lazy[t], tm + 1, tr);
		lazy[t] = lazy_default_value;
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
			return node_default_value;
		if (l <= tl && tr <= r)
			return tree[t];
		pushdown(t, tl, tr);
		int tm = (tl + tr) / 2;
		return merge(query(l, r, t * 2, tl, tm), query(l, r, t * 2 + 1, tm + 1, tr));
	}

public:
	lazy_segment_tree() = default;

	lazy_segment_tree(int _n) { init(_n); }

	void init(int _n) {
		n = _n;
		tree.assign(4 * n, node_default_value);
		lazy.assign(4 * n, lazy_default_value);
	}

	void update(int l, int r, L v) { update(l, r, v, 1, 0, n - 1); }

	T query(int l, int r) { return query(l, r, 1, 0, n - 1); }
};