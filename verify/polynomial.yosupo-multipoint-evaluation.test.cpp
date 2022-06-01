#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"

#include <bits/stdc++.h>
using namespace std;

#include "poly/polynomial.hpp"

using namespace poly;

const int MOD = 998244353;
using mint = polynomial_internal::Modular<MOD>;

int main() {
	int N, M;
	cin >> N >> M;
	vector<mint> A(N), X(M);
	for (auto &a : A)
		cin >> a;
	for (auto &x : X)
		cin >> x;
	
	polynomial<mint> P(A);
	auto Y = P.eval(X);
	for (int i = 0; i < M; i++)
		cout << Y[i] << ' ';
	cout << '\n';
} 