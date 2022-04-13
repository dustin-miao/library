#include "utility/pi.hpp"

namespace conv {
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

	template<typename T> 
	typename enable_if<is_floating_point<T>::value, void>::type
	inverse_fast_fourier_transform(vector<complex<T>> &a) {
		int n = a.size();
		reverse_bit_sort(a);
		for (int l = 2; l <= n; l <<= 1) {
			T theta = -2 * PI / l;
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
		for (int i = 0; i < n; i++)
			a[i] /= n;
	}
}