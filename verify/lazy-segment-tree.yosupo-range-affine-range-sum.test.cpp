#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include <bits/stdc++.h>
using namespace std;

#include "data-structure/lazy-segment-tree.hpp"

const int MAX = 5e5 + 5;
const long long MOD = 998244353;

struct stinfo {
	using T = long long;
	using L = pair<long long, long long>;

	const T Tdval = 0;
	const L Ldval = {1, 0};

	void apply(T &a, L &b, L c, int l, int r) {
		a = (c.first * a % MOD + c.second * (r - l + 1)) % MOD;
		b = {c.first * b.first % MOD, (c.first * b.second + c.second) % MOD};
	}	

	T merge(T a, T b) { return (a + b) % MOD; }
};

int main() {
	int N, Q; 
	cin >> N >> Q;
	Segtree<stinfo> sgt(N);
	for (int i = 0; i < N; i++) {
		long long a; cin >> a;
		sgt.update(i, i, {1, a});
	}
	while (Q--) {
		int t; cin >> t;
		if (t == 0) {
			int l, r; long long b, c;
			cin >> l >> r >> b >> c;
			sgt.update(l, r - 1, {b, c});
		} else {
			int l, r;
			cin >> l >> r;
			cout << sgt.query(l, r - 1) << '\n';
		}
	}
}