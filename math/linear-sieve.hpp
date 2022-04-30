#pragma region linear_sieve

namespace math {
	pair<vector<int>, vector<int>> linear_sieve(int n) {
		vector<int> leastFactor(n + 1, 0), primes;
		for (int i = 2; i <= n; i++) {
			if (leastFactor[i] == 0) {
				leastFactor[i] = i;
				primes.push_back(i);
			}
			for (int j = 0; j < primes.size() && primes[j] <= leastFactor[i] && i * primes[j] <= N; j++)
				leastFactor[i * primes[j]] = primes[j];
		}
		return make_pair(leastFactor, primes);
	}
}

#pragma endregion linear_sieve