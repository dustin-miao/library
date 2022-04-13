namespace conv {
	/**
	 * @brief Permutes an array of numbers by the inverse of its binary index.
	 * @tparam T The type of value contained in $a$. 
	 * @param a A reference to a vector that is to be sorted.
	 * @return Nothing.
	 * 
	 * Changes $a$ by the reverse of the binary representation of each index
	 * from $[0, \texttt{a}.size())$. 
	 * 
	 * For instance, let $a = [0, 1, 2, 3, 4, 5, 6, 7]$. Applying `
	 * reverse_bit_sort(a)` would change $a$ into $[0, 4, 2, 6, 1, 5, 3, 7]$. 
	 * 
	 * Note that the contents of $a$ are modified. 
	 */
	template<typename T>
	void reverse_bit_sort(vector<T> &a) {
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

	/**
	 * @brief Computes the discrete fourier transform of $a$.
	 * @tparam T A floating point type, such that $a$ contains `std::complex<T>`.
	 * @param a A reference to a vector that is to have the DFT computed.
	 * @return Nothing.
	 * 
	 * Given a polynomial $a = a[0] + a[1]x + a[2]x^2 + \dots = \sum_{i = 0}^{n - 1} a[i]x^i$, 
	 * computes a vector $z$ such that $z[i] = a(w_n^i)$ for $i \in [0, n)$; that is, evaluates
	 * $a$ at each of the roots of unity for order $n$. 
	 * 
	 * Note that the contents of $a$ are modified. 
	 */
	template<typename T> 
	typename enable_if<is_floating_point<T>::value, void>::type
	fast_fourier_transform(vector<complex<T>> &a) {
		int n = a.size();
		reverse_bit_sort(a);
		for (int l = 2; l <= n; l <<= 1) {
			T theta = 2 * PI / l;
			complex<T> dw(cos(theta), sin(theta));
			for (int i = 0; i < n; i += l) {
				complex<T> w = 1;
				for (int j = 0; j < l / 2; j++) {
					auto t1 = a[i + j], t2 = a[i + j + l / 2] * w;
					a[i + j] = t1 + t2;
					a[i + j + l / 2] = t1 - t2;
					w *= dw;
				}
			}
		}
	}
}