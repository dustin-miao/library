#include "convolution/fast-walsh-hadamard-transform.hpp"

#pragma region inverse_fast_walsh_hadamard_transform

namespace conv {
	template<typename T>
	void inverse_fast_walsh_hadamard_transform(vector<T> &a) {
		fast_walsh_hadamard_transform<T>(a);
		if constexpr (is_integral<T>::value) {
			int n = a.size();
			for (auto &x : a)
				x /= n;
		} else {
			T t = T(1) / T(a.size());
			for (auto &x : a)
				x *= t;
		}
	}
}

#pragma endregion inverse_fast_walsh_hadamard_transform