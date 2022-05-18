#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include <bits/stdc++.h>
using namespace std;

#include "math/ext-gcd.hpp"
#include "random/random-int.hpp"

int main() {
	{
		int T = 2e5;
		while (T--) {
			long long A = rng::rint<long long>(1, 1e6);
			long long B = rng::rint<long long>(1, 1e6);
			long long X, Y;
			auto G = math::ext_gcd(A, B, X, Y);
			assert(G == __gcd(A, B));
			assert(A * X + B * Y == G);
		}
	}

	long long A, B;
	cin >> A >> B;
	cout << A + B << '\n';
}