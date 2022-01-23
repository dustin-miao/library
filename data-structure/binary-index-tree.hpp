template<typename T>
class Fentree {
	size_t n;
	vector<T> tree;

public:
	Fentree() = default;

	Fentree(size_t _n) { init(_n); }

	void init(size_t _n) {
		n = _n;
		tree.assign(n + 1, T());
	}

	void update(int i, T v) {
		for (i++; i <= n; i += i & -i)
			tree[i] += v;
	}

	T query(int i) {
		T ret = 0;
		for (i++; i; i -= i & -i)
			ret += tree[i];
		return ret;
	}

	T query(int l, int r) { return query(r) - query(l - 1); }
};
