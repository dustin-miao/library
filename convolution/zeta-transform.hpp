#pragma region zeta_transform

namespace conv {
	template<typename T>
	void zeta_transform(vector<T> &a, int n) {
		assert((1 << n) == a.size());
		for (int i = 0; i < n; i++)
			for (int mask = 0; mask < (1 << n); mask++)
				if (mask >> i & 1)
					a[mask] += a[mask ^ (1 << i)];
	}
}

#pragma endregion zeta_transform