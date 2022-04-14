#include "utility/pi.hpp"
#include "convolution/reverse-bit-radix-sort.hpp"

namespace conv {
	template<typename T> 
	typename enable_if<is_floating_point<T>::value, void>::type
	slow_fast_fourier_transform(vector<complex<T>> &a) {
		int n = a.size();
		reverse_bit_radix_sort(a);
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
	slow_inverse_fast_fourier_transform(vector<complex<T>> &a) {
		int n = a.size();
		reverse_bit_radix_sort(a);
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