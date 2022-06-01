#define PROBLEM "https://judge.yosupo.jp/problem/find_linear_recurrence"

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

	auto P = polynomial(A).linear_recurrence(N - 1);
	int d = P.deg();
	cout << d << '\n';
	P = -P.reverse().divide_k(1);
	for (int i = 0; i < d; i++)
		cout << (i < P.size() ? P[i] : 0) << ' ';
	cout << '\n';
}