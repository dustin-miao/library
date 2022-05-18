#include "mersenne-twister.hpp"

#pragma region rng_int

#ifndef RANDOM_INT_HPP
#define RANDOM_INT_HPP

namespace rng {
	template<typename T = int>
	typename enable_if<is_integral<T>::value, T>::type 
	rint(T l, T r) { return uniform_int_distribution<T>(l, r)(mst); }
}

#endif

#pragma endregion rng_int