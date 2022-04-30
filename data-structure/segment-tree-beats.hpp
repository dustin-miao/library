#pragma region segment_tree_beats

class segment_tree_beats {
protected:
	int n;

	struct node { 
		long long sum, max1, max2, maxc, min1, min2, minc, lazy; 
	};

	vector<node> tree;

private:
	void merge(int t) {
		// sum
		tree[t].sum = tree[t * 2].sum + tree[t * 2 + 1].sum;

		// max
		if (tree[t * 2].max1 == tree[t * 2 + 1].max1) {
			tree[t].max1 = tree[t * 2].max1;
			tree[t].max2 = max(tree[t * 2].max2, tree[t * 2 + 1].max2);
			tree[t].maxc = tree[t * 2].maxc + tree[t * 2 + 1].maxc;
		}
		else {
			if (tree[t * 2].max1 > tree[t * 2 + 1].max1) {
				tree[t].max1 = tree[t * 2].max1;
				tree[t].max2 = max(tree[t * 2].max2, tree[t * 2 + 1].max1);
				tree[t].maxc = tree[t * 2].maxc;
			}
			else {
				tree[t].max1 = tree[t * 2 + 1].max1;
				tree[t].max2 = max(tree[t * 2].max1, tree[t * 2 + 1].max2);
				tree[t].maxc = tree[t * 2 + 1].maxc;
			}
		}

		// min
		if (tree[t * 2].min1 == tree[t * 2 + 1].min1) {
			tree[t].min1 = tree[t * 2].min1;
			tree[t].min2 = min(tree[t * 2].min2, tree[t * 2 + 1].min2);
			tree[t].minc = tree[t * 2].minc + tree[t * 2 + 1].minc;
		}
		else {
			if (tree[t * 2].min1 < tree[t * 2 + 1].min1) {
				tree[t].min1 = tree[t * 2].min1;
				tree[t].min2 = min(tree[t * 2].min2, tree[t * 2 + 1].min1);
				tree[t].minc = tree[t * 2].minc;
			}
			else {
				tree[t].min1 = tree[t * 2 + 1].min1;
				tree[t].min2 = min(tree[t * 2].min1, tree[t * 2 + 1].min2);
				tree[t].minc = tree[t * 2 + 1].minc;
			}
		}
	}

	void push_add(int t, int tl, int tr, long long v) {
		if (v == 0)
			return;
		tree[t].sum += (tr - tl + 1) *v;
		tree[t].max1 += v;
		if (tree[t].max2 != LLONG_MIN)
			tree[t].max2 += v;
		tree[t].min1 += v;
		if (tree[t].min2 != LLONG_MAX)
			tree[t].min2 += v;
		tree[t].lazy += v;
	}

	// corresponds to a chmin update
	void push_max(int t, long long v, bool l) {
		if (v >= tree[t].max1)
			return;
		tree[t].sum -= tree[t].max1 * tree[t].maxc;
		tree[t].max1 = v;
		tree[t].sum += tree[t].max1 * tree[t].maxc;
		if (l) 
			tree[t].min1 = tree[t].max1;
		else {
			if (v <= tree[t].min1)
				tree[t].min1 = v;
			else if (v < tree[t].min2)
				tree[t].min2 = v;
		}
	}

	// corresponds to a chmax update
	void push_min(int t, long long v, bool l) {
		if (v <= tree[t].min1)
			return;
		tree[t].sum -= tree[t].min1 * tree[t].minc;
		tree[t].min1 = v;
		tree[t].sum += tree[t].min1 * tree[t].minc;
		if (l)
			tree[t].max1 = tree[t].min1;
		else {
			if (v >= tree[t].max1)
				tree[t].max1 = v;
			else if (v > tree[t].max2)
				tree[t].max2 = v;
		}
	}

	void pushdown(int t, int tl, int tr) {
		if (tl == tr)
			return;
		// sum
		int tm = (tl + tr) / 2;
		push_add(t * 2, tl, tm, tree[t].lazy);
		push_add(t * 2 + 1, tm + 1, tr, tree[t].lazy);
		tree[t].lazy = 0;

		// max
		push_max(t * 2, tree[t].max1, tl == tm);
		push_max(t * 2 + 1, tree[t].max1, tm + 1 == tr);

		// min
		push_min(t * 2, tree[t].min1, tl == tm);
		push_min(t * 2 + 1, tree[t].min1, tm + 1 == tr);
	}

	void build(int t, int tl, int tr) {
		tree[t].lazy = 0;
		if (tl == tr) {
			tree[t].sum = tree[t].max1 = tree[t].min1 = 0;
			tree[t].maxc = tree[t].minc = 1;
			tree[t].max2 = LLONG_MIN;
			tree[t].min2 = LLONG_MAX;
			return;
		}

		int tm = (tl + tr) / 2;
		build(t * 2, tl, tm);
		build(t * 2 + 1, tm + 1, tr);
		merge(t);
	}

	void update_add(int l, int r, long long v, int t, int tl, int tr) {
		if (r < tl || tr < l)
			return;
		if (l <= tl && tr <= r) {
			push_add(t, tl, tr, v);
			return;
		}
		pushdown(t, tl, tr);

		int tm = (tl + tr) / 2;
		update_add(l, r, v, t * 2, tl, tm);
		update_add(l, r, v, t * 2 + 1, tm + 1, tr);
		merge(t);
	}

	void update_chmin(int l, int r, long long v, int t, int tl, int tr) {
		if (r < tl || tr < l || v >= tree[t].max1)
			return;
		if (l <= tl && tr <= r && v > tree[t].max2) {
			push_max(t, v, tl == tr);
			return;
		}
		pushdown(t, tl, tr);

		int tm = (tl + tr) / 2;
		update_chmin(l, r, v, t * 2, tl, tm);
		update_chmin(l, r, v, t * 2 + 1, tm + 1, tr);
		merge(t);
	}

	void update_chmax(int l, int r, long long v, int t, int tl, int tr) {
		if (r < tl || tr < l || v <= tree[t].min1)
			return;
		if (l <= tl && tr <= r && v < tree[t].min2) {
			push_min(t, v, tl == tr);
			return;
		}
		pushdown(t, tl, tr);

		int tm = (tl + tr) / 2;
		update_chmax(l, r, v, t * 2, tl, tm);
		update_chmax(l, r, v, t * 2 + 1, tm + 1, tr);
		merge(t);
	}

	long long query(int l, int r, int t, int tl, int tr) {
		if (r < tl || tr < l)
			return 0;
		if (l <= tl && tr <= r)
			return tree[t].sum;
		pushdown(t, tl, tr);

		int tm = (tl + tr) / 2;
		return query(l, r, t * 2, tl, tm) + query(l, r, t * 2 + 1, tm + 1, tr);
	}

public:
	segment_tree_beats() = default;

	segment_tree_beats(int _n) { init(_n); }

	void init(int _n) {
		n = _n;
		tree.resize(n * 4);
		build();
	}

	void build() { build(1, 0, n - 1); }

	void update_add(int l, int r, long long v) { update_add(l, r, v, 1, 0, n - 1); }

	void update_chmin(int l, int r, long long v) { update_chmin(l, r, v, 1, 0, n - 1); }

	void update_chmax(int l, int r, long long v) { update_chmax(l, r, v, 1, 0, n - 1); }

	long long query(int l, int r) { return query(l, r, 1, 0, n - 1); }
};

#pragma endregion segment_tree_beats