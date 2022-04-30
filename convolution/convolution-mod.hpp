#include "convolution/fast-fourier-transform.hpp"

#pragma region convolution_mod

namespace conv {
	template<typename T, typename U = double>
	vector<T> convolution_mod(const vector<T> &a, const vector<T> &b, int mod) {
		int n = 1;
		while (n < a.size() + b.size()) 
			n <<= 1;

		int c = sqrt(mod);
		vector<complex<U>> aa(n), bb(n);
		for (int i = 0; i < a.size(); i++) 
			aa[i] = complex<U>(int(a[i]) / c, int(a[i]) % c);
		for (int i = 0; i < b.size(); i++)
			bb[i] = complex<U>(int(b[i]) / c, int(b[i]) % c);
		fast_fourier_transform(aa);
		fast_fourier_transform(bb);

		vector<complex<U>> pa(n), pb(n);
		for (int i = 0; i < n; i++) {
			int j = -i & (n - 1);
			pa[j] = (aa[i] + conj(aa[j])) * bb[i] / static_cast<U>(2.0 * n);
			pb[j] = (aa[i] - conj(aa[j])) * bb[i] / static_cast<U>(2.0 * n) / complex<U>(0, 1);
		}
		fast_fourier_transform(pa);
		fast_fourier_transform(pb);

		n = a.size() + b.size() - 1;
		vector<T> ret(n);
		for (int i = 0; i < n; i++) {
			T av = static_cast<T>(real(pa[i]) + 0.5), cv = static_cast<T>(imag(pb[i]) + 0.5);
			T bv = static_cast<T>(imag(pa[i]) + 0.5) + static_cast<T>(real(pb[i]) + 0.5);
			ret[i] = ((av % mod * c + bv) % mod * c + cv) % mod;
		}
		return ret;
	}
}

#pragma endregion convolution_mod