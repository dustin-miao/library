#pragma region fast set

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }

	template<typename T>
    size_t operator()(const pair<T, T> &x) const { 
		return (*this)(x.first) ^ __builtin_bswap64((*this)(x.second)); 
	}

	template<typename T>
    size_t operator()(const tuple<T, T, T> &x) const { 
		return (*this)(get<0>(x)) + __builtin_bswap64((*this)(make_pair(get<1>(x), get<2>(x)))); 
	}

	template<typename T>
    size_t operator()(const tuple<T, T, T, T> &x) const { 
		return (*this)(get<0>(x)) + __builtin_bswap64((*this)(make_tuple(get<1>(x), get<2>(x), get<3>(x)))); 
	}
};

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class K, class V>
using fast_map = gp_hash_table<K, V, custom_hash>;

template <class K>
using fast_set = gp_hash_table<K, null_type, custom_hash>;

#pragma endregion fast set
