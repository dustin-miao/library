#define PROBLEM "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"

#include <bits/stdc++.h>
using namespace std;

#include "poly/polynomial.hpp"

using namespace poly;

const int MOD = 998244353;
using mint = polynomial_internal::Modular<MOD>;

int main() {
	int N;
	long long K;
	cin >> N >> K;
	vector<mint> A(N), C(N);
	for (auto &a : A)
		cin >> a;
	for (auto &c : C)
		cin >> c;

	auto Q = polynomial(mint(1)) - polynomial(C).multiply_k(1);
	auto P = (polynomial(A) * Q).modulo_k(N);
	cout << polynomial<mint>::kth_recurrence(P, Q, K) << '\n';
}