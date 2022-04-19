#include "utility/mint.hpp"

namespace math {
	template<typename T = long long>
	T discrete_sqrt(const T &a, const T &mod) {
		assert(0 <= a && a < mod);
		if (a < 2) 
			return a;
		MOD = mod;
		if (fast_pow(mint(a), (mod - 1) >> 1) != 1) 
			return -1;
		mint b = 1;
		for (; fast_pow(b, (mod - 1) >> 1) == 1; b++);
		T m = mod - 1, e = 0;
		for (; m % 2 == 0; m >>= 1, e++);
		mint x = fast_pow(mint(a), (m - 1) >> 1), y = mint(a) * x * x, z = fast_pow(mint(b), m);
		x *= a;
		while (y != 1) {
			T j = 0;
			mint t = y;
			while (t != 1) {
				j += 1;
				t *= t;
			}
			z = fast_pow(z, T(1) << (e - j - 1));
			x *= z;
			z *= z;
			y *= z;
			e = j;
		}
		return x();
	}
}
