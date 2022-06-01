#define PROBLEM "https://judge.yosupo.jp/problem/log_of_formal_power_series"

#include <bits/stdc++.h>
using namespace std;

#include "poly/polynomial.hpp"

using namespace poly;

const int MOD = 998244353;
using mint = polynomial_internal::Modular<MOD>;

int main() {
	int N;
	cin >> N;
	vector<mint> A(N);
	for (auto &a : A)
		cin >> a;
	
	polynomial<mint> P(A);
	auto Q = P.log(N);
	for (int i = 0; i < N; i++)
		cout << (i < Q.size() ? Q[i] : 0) << ' ';
	cout << '\n';
} 