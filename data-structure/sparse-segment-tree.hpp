template<class segment_tree_template>
class sparse_segment_tree : public segment_tree_template {
	using T = typename segment_tree_template::type;
	using segment_tree_template::default_value;
	using segment_tree_template::merge;
	using segment_tree_template::apply;

protected:
	long long n;

	struct node {
		T v;
		long long l, r;
		node() = default;
		node(T _v, long long _l, long long _r) : v(_v), l(_l), r(_r) {}
	};

	int root;
	vector<node> tree;

	int new_node() {
		tree.emplace_back(default_value, -1, -1);
		return tree.size() - 1;
	}

private:
	void update(long long i, T v, int t, long long tl, long long tr) {
		if (tl == tr) {
			apply(tree[t].v, v);
			return;
		}
		long long tm = (tl + tr) / 2;
		if (i <= tm) {
			if (tree[t].l == -1)
				tree[t].l = new_node();
			update(i, v, tree[t].l, tl, tm);
		} else {
			if (tree[t].r == -1)
				tree[t].r = new_node();
			update(i, v, tree[t].r, tm + 1, tr);
		}
		tree[t].v = merge(tree[t].l == -1 ? default_value : tree[tree[t].l].v, 
			tree[t].r == -1 ? default_value : tree[tree[t].r].v);
	}

	T query(long long l, long long r, int t, long long tl, long long tr) {
		if (r < tl || tr < l)
			return default_value;
		if (l <= tl && tr <= r)
			return tree[t].v;
		long long tm = (tl + tr) / 2;
		return merge(tree[t].l == -1 ? default_value : query(l, r, tree[t].l, tl, tm), 
			tree[t].r == -1 ? default_value : query(l, r, tree[t].r, tm + 1, tr));
	}

public:
	sparse_segment_tree() = default;

	sparse_segment_tree(long long _n) { init(_n); }

	void init(int _n) {
		n = _n;
		root = new_node();
	}

	void reserve(int _n) { tree.reserve(_n); }

	void clear() { tree.clear(); }

	void update(long long i, T v) { update(i, v, root, 0, n - 1); }

	T query(long long l, long long r) { return query(l, r, root, 0, n - 1); }
};