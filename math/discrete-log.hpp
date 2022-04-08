#include "utility/mint.hpp"

int discrete_log(mint a, mint b) {
    int n = sqrt(MOD) + 1;

    mint an = fast_pow(a, n);
	map<mint, int> vals;
    for (int q = 0, cur = b; q <= n; q++, cur *= a) 
        vals[cur] = q;
    for (int p = 1, cur = 1; p <= n; p++) {
        cur *= an;
        if (vals.find(cur) != vals.end()) 
            return int(n * p - vals[cur]);
    }
    return -1;
}