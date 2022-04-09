#include "utility/mint.hpp"

namespace math {
	int discrete_log(mint a, mint b) {
		int n = sqrt(MOD) + 1;

		mint an = fast_pow(a, n);
		map<mint, int> vals;
		mint cur = b;
		for (int q = 0; q <= n; q++) { 
			vals[cur] = q;
			cur *= a;
		}
		cur = 1;
		for (int p = 1; p <= n; p++) {
			cur *= int(an);
			if (vals.find(cur) != vals.end()) 
				return int(n * p - vals[cur]);
		}
		return -1;
	}
}