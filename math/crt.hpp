#include "math/ext-gcd.hpp"

#pragma region chinese_remainder_theorem

namespace math {
	template<typename T>
	T crt(const pair<T, T> &p1, const pair<T, T> &p2) {
		auto [a1, m1] = p1;
		auto [a2, m2] = p2;
		if (a2 < a1) {
			swap(a1, a2);
			swap(m1, m2);
		}
		T n1, n2;
		T g = ext_gcd(m1, m2, n1, n2), l = m1 / g * m2; 
		if ((a2 - a1) % g != 0)
			return -1;
		return (n1 * (a2 - a1) / g % (m2 / g) * m1 + a1 + l) % l;
	}
}

#pragma endregion chinese_remainder_theorem