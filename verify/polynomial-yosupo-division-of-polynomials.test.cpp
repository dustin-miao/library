#define PROBLEM "https://judge.yosupo.jp/problem/division_of_polynomials"

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
	auto [U, V] = P.division(Q);
	cout << U.deg() + 1 << ' ' << V.deg() + 1 << '\n';
	for (int i = 0; i <= U.deg(); i++)
		cout << U[i] << ' ';
	cout << '\n';
	for (int i = 0; i <= V.deg(); i++)
		cout << V[i] << ' ';
	cout << '\n';
}