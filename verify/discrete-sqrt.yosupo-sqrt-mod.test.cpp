#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"

#include <bits/stdc++.h>
using namespace std;

#include "math/discrete-sqrt.hpp"

int main() {
	int TC;
	cin >> TC;
	while (TC--) {
		long long A, mod;
		cin >> A >> mod;
		cout << math::discrete_sqrt(A, mod) << '\n';
	}
}