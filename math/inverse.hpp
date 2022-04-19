namespace math {
	template <typename T>
	T inverse(T a, T p) {
		T b = p, x = 1, y = 0;
		while (a) {
			T q = b / a;
			swap(a, b %= a);
			swap(x, y -= q * x);
		}
		assert(b == 1);
		return y < 0 ? y + p : y;
	}
}