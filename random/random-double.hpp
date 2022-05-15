#pragma region rng

#ifndef RANDOM_DOUBLE
#define RANDOM_DOUBLE

mt19937 _rng(chrono::steady_clock::now().time_since_epoch().count());

template<typename T = double>
typename enable_if<is_floating_point<T>::value, T>::type rng(T l, T r) { return uniform_real_distribution<T>(l, r)(_rng); }

#endif

#pragma endregion rng