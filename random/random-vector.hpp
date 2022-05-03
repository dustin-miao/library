#include "mersenne-twister.hpp"

#pragma region rng_vector

#ifndef RNG_VECTOR_HPP
#define RNG_VECTOR_HPP

template<typename T>
typename enable_if<is_integral<T>::value, vector<T>>::type rng_vector(int n, T l, T r) {
	vector<T> v(n);
	for (auto &a : v)
		a = rng(l, r);
	return v;
}

#endif

#pragma endregion rng_vector