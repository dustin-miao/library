#include "convolution/fast-fourier-transform.hpp"

namespace conv {
	template<typename T, typename U = double>
	vector<T> convolution(const vector<T> &a, const vector<T> &b) {
		vector<complex<U>> pa(a.begin(), a.end()), pb(b.begin(), b.end());
		int n = 1;
		while (n < a.size() + b.size()) 
			n <<= 1;
		pa.resize(n), pb.resize(n);

		fast_fourier_transform(pa);
		fast_fourier_transform(pb);
		for (int i = 0; i < n; i++)
			pa[i] *= pb[i];
		inverse_fast_fourier_transform(pa);

		n = a.size() + b.size() - 1;
		vector<T> ret(n);
		for (int i = 0; i < n; i++)
			ret[i] = round(pa[i].real());
		return ret;
	}
}