#define PROBLM "https://judge.yosupo.jp/problem/static_range_sum"

#include <bits/stdc++.h>
using namespace std;

#include "utility/prefix-sum.hpp"

int main() {
	int N, Q;
	cin >> N >> Q;
	vector<long long> A(N);
	for (auto &a : A)
		cin >> a;
	auto P = prefix_sum(A);
	while (Q--) {
		int l, r;
		cin >> l >> r;
		cout << P[r - 1] - (l == 0 ? 0 : P[l - 1]) << '\n';
	}
} 