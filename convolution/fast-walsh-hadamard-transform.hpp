#pragma region fast walsh hadamard transform

namespace conv {
	template<typename T>
	void fast_walsh_hadamard_transform(vector<T> &a) {
		int n = a.size();
		for (int i = 1; i < n; i <<= 1) {
			for (int j = 0; j < n; j++) {
				if ((j & i) == 0) {
					T x = a[j], y = a[j | i];
					a[j] = x + y;
					a[j | i] = x - y;
				}
			}
		}
	}
}

#pragma endregion fast walsh hadamard transform