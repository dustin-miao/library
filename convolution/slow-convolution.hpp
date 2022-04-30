#include "convolution/slow-fast-fourier-transform.hpp"

#pragma region slow_convolution

namespace conv {
	template<typename T, typename U = double>
	vector<T> slow_convolution(const vector<T> &a, const vector<T> &b) {
		vector<complex<U>> pa(a.begin(), a.end()), pb(b.begin(), b.end());
		int n = 1;
		while (n < a.size() + b.size()) 
			n <<= 1;
		pa.resize(n), pb.resize(n);

		slow_fast_fourier_transform(pa);
		slow_fast_fourier_transform(pb);
		for (int i = 0; i < n; i++)
			pa[i] *= pb[i];
		slow_inverse_fast_fourier_transform(pa);

		n = a.size() + b.size() - 1;
		vector<T> ret(n);
		for (int i = 0; i < n; i++)
			ret[i] = static_cast<T>(pa[i].real() + 0.5);
		return ret;
	}
}

#pragma endregion slow_convolution