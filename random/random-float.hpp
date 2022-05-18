#include "mersenne-twister.hpp"

#pragma region rng_float

#ifndef RANDOM_FLOAT_HPP
#define RANDOM_FLOAT_HPP

mt19937 _rng(chrono::steady_clock::now().time_since_epoch().count());

namespace rng {
	template<typename T = double>
	typename enable_if<is_floating_point<T>::value, T>::type 
	rflt(T l, T r) { return uniform_real_distribution<T>(l, r)(mst); }
}

#endif

#pragma endregion rng_float