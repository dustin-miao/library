#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_B"

#include <bits/stdc++.h>
using namespace std;

#include "math/ext-gcd.hpp"
#include "random/mersenne_twister.hpp"

int main() {
	int T = 2e5;
	while (T--) {
		long long A = rng<long long>(1, 1e9);
		long long B = rng<long long>(1, 1e9);
		long long X, Y;
		auto G = math::ext_gcd(A, B, X, Y);
		assert(G == __gcd(A, B));
		assert(A * X + B * Y == G);
	}

	long long A, B;
	cin >> A >> B;
	cout << A + B << '\n';
}