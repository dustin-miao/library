#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"

#include <bits/stdc++.h>
using namespace std;

#include "poly/polynomial.hpp"

using namespace poly;

const int MOD = 998244353;
using mint = polynomial_internal::Modular<MOD>;

int main() {
	int N;
	mint C;
	cin >> N >> C;
	vector<mint> A(N);
	for (auto &a : A)
		cin >> a;
	
	polynomial<mint> P(A);
	auto Q = P.shift(C);
	for (int i = 0; i < N; i++)
		cout << (i < Q.size() ? Q[i] : 0) << ' ';
	cout << '\n';
} 