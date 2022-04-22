#include "fast-walsh-hadamard-transform.hpp"
#include "inverse-fast-walsh-hadamard-transform.hpp"

#pragma region xor convolution

namespace conv {
	template<typename T>
	vector<T> xor_convolution(const vector<T> &a, const vector<T> &b) {
		vector<T> pa(a.begin(), a.end()), pb(b.begin(), b.end());
		int n = 1;
		while (n < a.size() + b.size()) 
			n <<= 1;
		pa.resize(n), pb.resize(n);
		fast_walsh_hadamard_transform(pa);
		fast_walsh_hadamard_transform(pb);
		for (int i = 0; i < n; i++)
			pa[i] *= pb[i];
		inverse_fast_walsh_hadamard_transform(pa);
		return pa;
	}
}

#pragma endregion xor convolution