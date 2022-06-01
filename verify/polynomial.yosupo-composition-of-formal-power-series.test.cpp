#define PROBLEM "https://judge.yosupo.jp/problem/composition_of_formal_power_series"

#include <bits/stdc++.h>
using namespace std;

#include "poly/polynomial.hpp"

using namespace poly;

const int MOD = 998244353;
using mint = polynomial_internal::Modular<MOD>;

int main() {
	int N;
	cin >> N;
	vector<mint> A(N), B(N);
	for (auto &a : A)
		cin >> a;
	for (auto &b : B)
		cin >> b;
	
	polynomial<mint> P(A), Q(B);
	auto R = polynomial<mint>::compose(P, Q, N);
	for (int i = 0; i < N; i++)
		cout << (i < R.size() ? R[i] : 0) << ' ';
	cout << '\n';
}