#include "random-int.hpp"

#pragma region rng_int_vector

#ifndef RNG_VECTOR_HPP
#define RNG_VECTOR_HPP

namespace rng {
	template<typename T>
	typename enable_if<is_integral<T>::value, vector<T>>::type 
	rivec(int n, T l, T r) {
		vector<T> v(n);
		for (auto &a : v)
			a = rint(l, r);
		return v;
	}
}

#endif

#pragma endregion rng_int_vector