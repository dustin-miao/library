template<typename T>
T addmod(T a, T b, long long MOD) {
	T t = a + b;
	return t >= MOD ? t - MOD : t;
}