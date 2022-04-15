#include "utility/pi.hpp"

namespace conv {
	template<typename T>
	typename enable_if<is_floating_point<T>::value, void>::type
	fast_fourier_transform(vector<complex<T>> &a) {
		int n = a.size(), logn = 31 - __builtin_clz(n);

		vector<int> rev(n);
		rev[0] = 0;
		for (int i = 1; i < n; i++) {
			rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (logn - 1));
			if (i < rev[i])
				swap(a[i], a[rev[i]]);
		}

		vector<complex<T>> root(n);
		root[1] = {1, 0};
		for (int k = 1; k < logn; k++) {
			T the = 2 * PI / (1 << (k + 1));
			complex<T> z = {cos(the), sin(the)};
			for (int i = (1 << (k - 1)); i < (1 << k); i++) {
				root[i << 1] = root[i];
				root[i << 1 | 1] = root[i] * z;
			}
		}

		for (int l = 1; l < n; l <<= 1) {
			for (int i = 0; i < n; i += (l << 1)) {
				for (int j = 0; j < l; j++) {
					auto z = root[j + l] * a[i + j + l];
					a[i + j + l] = a[i + j] - z;
					a[i + j] += z;
				}
			}
		}
	}
}