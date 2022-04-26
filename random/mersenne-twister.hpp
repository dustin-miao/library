mt19937 _rng(chrono::steady_clock::now().time_since_epoch().count());

template<typename T = int>
typename enable_if<is_integral<T>::value, T>::type rng(T l, T r) { return uniform_int_distribution<T>(l, r)(_rng); }