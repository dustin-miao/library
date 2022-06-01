#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include <bits/stdc++.h>
using namespace std;

#include "poly/polynomial.hpp"

using namespace poly;

const int MOD = 1e9 + 7;
using mint = polynomial_internal::Modular<MOD>;

int main() {
	int N, M;
	cin >> N >> M;
	vector<mint> A(N), B(M);
	for (auto &a : A)
		cin >> a;
	for (auto &b : B)
		cin >> b;
	
	polynomial<mint> P(A), Q(B);
	auto R = P * Q;
	for (int i = 0; i < N + M - 1; i++)
		cout << (i < R.size() ? R[i] : 0) << ' ';
	cout << '\n';
}