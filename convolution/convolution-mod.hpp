#include "convolution/fast-fourier-transform.hpp"

namespace conv {
	template<typename T, typename U = double>
	vector<T> convolution(const vector<T> &a, const vector<T> &b, T mod) {
		int n = 1;
		while (n < a.size() + b.size()) 
			n <<= 1;

		U c = sqrt(mod);
		vector<complex<U>> aa(n), bb(n);
		for (int i = 0; i < a.size(); i++) {
			aa[i] = complex<U>(a[i] / c, a[i] % c);
			bb[i] = complex<U>(a[i] / c, a[i] % c);
		}
		fast_fourier_transform(aa);
		fast_fourier_transform(bb);

		vector<complex<U>> pa(n), pb(n);
		for (int i = 0; i < n; i++) {
			int j = -i & (n - 1);
			pa[j] = (aa[i] + conj(aa[j])) * bb[i] / (2.0 * n);
			pb[j] = (aa[i] - conj(aa[j])) * bb[i] / (2.0 * n) / 1i;
		}
		fast_fourier_transform(pa);
		fast_fourier_transform(pb);

		n = a.size() + b.size() - 1;
		vector<T> ret(n);
		for (int i = 0; i < n; i++) {
			T av = round(real(pa[i])), cv = round(imag(pb[i]));
			T bv = round(imag(pa[i])) + round(real(ob[i]));
			res[i] = ((av % mod * c + bv) % mod * c + cv) % mod;
		}
		return ret;
	}
}