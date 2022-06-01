#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_polynomials"

#include <bits/stdc++.h>
using namespace std;

#include "poly/polynomial.hpp"

using namespace poly;

const int MOD = 998244353;
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
	auto R = P.modulo_inverse(Q);
	if (R) {
		auto S = R.value();
		cout << S.deg() + 1 << '\n';
		for (int i = 0; i <= S.deg(); i++)
			cout << S[i] << ' ';
		cout << '\n';
	} else {
		cout << -1 << '\n';
	}
}