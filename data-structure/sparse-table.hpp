#pragma region sparse_table

template<typename T>
class sparse_table {
	int n, logn;
	vector<vector<T>> table;

public:
	sparse_table() = default;

	template<typename I>
	sparse_table(I l, I r) { init(l, r); }

	template<typename I>
	void init(I l, I r) {
		n = distance(l, r);
		logn = 32 - __builtin_clz(n);
		table.assign(logn, vector<T>(n));
		copy(l, r, table[0].begin());
		for (int k = 1; k < logn; k++)
			for (int i = 0; i + (1 << k) <= n; i++)
				table[k][i] = min(table[k - 1][i], table[k - 1][i + (1 << (k - 1))]);
	}

	T query(int l, int r) {
		int k = 31 - __builtin_clz(r - l + 1);
		return min(table[k][l], table[k][r - (1 << k) + 1]);
	}
};

#pragma endregion sparse_table