#include "convolution/fast-fourier-transform.hpp"

namespace conv {
	/**
	 * @brief Computes the convolution of two vectors using fast fourier transform.
	 * @tparam T The type contained in the vectors.
	 * @tparam U A floating point type (defaulted to double) used in FFT.
	 * @param a The first vector
	 * @param b The second vector
	 * @return The convolution of $a$ and $b$. 
	 * 
	 * Given two vectors $a$ and $b$, computes $c$ such that 
	 * $c[i] = \sum_{j = 0}^i a[j]b[i - j]$ for $i \in [0, n + m - 1)$. 
	 * 
	 * Note that this method runs in $\mathcal{O}(n\log n)$ (as opposed to the $\mathcal{O}(n^2)$
	 * naive solution). However, there may be issues with floating-point arithmatics and overflow. 
	 * For best results, set `U` to `long double`. 
	 */
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