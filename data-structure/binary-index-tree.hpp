template<typename T>
class fentree {
	int n;
	vector<T> tree;

public:
	void init(int _n) {
		n = _n;
		tree.assign(n + 1, T());
	}

	template<class Iterator>
	void init(Iterator begin, Iterator end) {
		n = distance(begin, end);
		tree.resize(n + 1);
		for (int i = 1; begin != end; i++, begin++)
			update(i, *begin);
	}

	void update(int i, T v) {
		for (; i <= n; i += i & -i)
			tree[i] += v;
	}

	T query(int i) {
		T ret = 0;
		for (; i; i -= i & -i)
			ret += tree[i];
		return ret;
	}

	T query(int l, int r) { return query(r) - query(l - 1); }

	T operator[](int i) { return query(i, i); }
};
