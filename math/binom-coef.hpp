#include "utility/mint.hpp"

struct binom_coef {
	vector<mint> fact, inv_fact;

	binom_coef() = default;

	binom_coef(int n) { init(n); }

	void init(int n) {
		fact.resize(n + 1);
		fact[0] = 1;
		inv_fact.resize(n + 1);
		inv_fact[0] = 1;
		for (int i = 1; i <= n; i++) {
			fact[i] = fact[i - 1] * i;
			inv_fact[i] = 1 / fact[i];
		}
	}

	mint operator()(int n, int k) { 
		return (0 <= K && K <= N ? fact[n] * inv_fact[k] * inv_fact[n - k] : 0); 
	}
};
