template<typename T>
void reverse_bit_radix_sort(vector<T> &a) {
	int n = a.size();
	for (int i = 1, j = 0; i < n; i++) {
		int t = n >> 1;
		for (; t & j; t >>= 1)
			j ^= t;
		j ^= t;
		if (i < j)
			swap(a[i], a[j]);
	}
}