#include "math/inverse.hpp"

namespace math {
	template<typename T = long long>
	T discrete_log(T a, T b, T mod) {
		if ((a %= mod) < 0) 
			a += mod;
		if ((b %= mod) < 0) 
			b += mod;
		T f, g, r = 1 % mod;
		for (f = 0; (g = __gcd(a, mod)) > 1; f++) {
			if (b % g) 
				return (r == b) ? f : -1;
			b /= g;
			mod /= g;
			r = r * (a / g) % mod;
		}
		if (mod == 1) 
			return f;
		T ir = inverse(r, mod);
		b = b * ir % mod;
		T k = 0, ak = 1;
		map<T, T> baby;
		for (; k * k < mod; k++) {
			if (baby.find(ak) == baby.end()) 
				baby[ak] = k;
			ak = ak * a % mod;
		}
		T iak = inverse(ak, mod);
		for (T i = 0; i < k; i++) {
			if (baby.find(b) != baby.end()) 
				return f + i * k + baby[b];
			b = b * iak % mod;
		}
		return -1;
	}
}