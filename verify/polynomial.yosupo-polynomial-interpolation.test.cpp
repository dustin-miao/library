#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"

#include <bits/stdc++.h>
using namespace std;

#include "poly/polynomial.hpp"

using namespace poly;

const int MOD = 998244353;
using mint = polynomial_internal::Modular<MOD>;

int main() {
	int N;
	cin >> N;
	vector<mint> X(N), Y(N);
	for (auto &x : X)
		cin >> x;
	for (auto &y : Y)
		cin >> y;
	
	polynomial<mint> P = polynomial<mint>::interpolate(X, Y);
	for (int i = 0; i < N; i++)
		cout << (i < P.size() ? P[i] : 0) << ' ';
	cout << '\n';
}