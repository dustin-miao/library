#include "convolution/convolution.hpp"

namespace conv {
	template<typename T, typename U = double>
	vector<T> cyclic_product(vector<T> a, vector<T> b) {
		assert(a.size() == b.size());
		int n = a.size();
		reverse(a.begin(), a.end());
		a.resize(2 * n);
		b.insert(b.end(), b.begin(), b.end());
		auto c = convolution<T, U>(a, b);
		vector<T> ret(n);
		for (int i = 0; i < n; i++)
			ret[i] = c[i + n - 1];
		return ret;
	}
}