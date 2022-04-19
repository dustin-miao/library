#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"

#include <bits/stdc++.h>
using namespace std;

#include "math/discrete-log.hpp"

int main() {
	int TC;
	cin >> TC;
	while (TC--) {
		long long A, B, mod;
		cin >> A >> B >> mod;
		cout << math::discrete_log(A, B, mod) << '\n';
	}
}