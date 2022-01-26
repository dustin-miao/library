#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"

#include <bits/stdc++.h>
using namespace std;

#include "data-structure/lazy-segment-tree.hpp"

int main() {
	int N, Q;
	cin >> N >> Q;

	struct stinfo {
		using T = long long;
		using L = long long;

		const T Tdval = LLONG_MAX;
		const L Ldval = LLONG_MAX;

		void apply(T &a, L &b, L c, int l, int r) {
			a = c;
			b = c;
		}

		T merge(T a, T b) { return min(a, b); }
	};

	Segtree<stinfo> sgt(N);
	for (int i = 0; i < N; i++) 
		sgt.update(i, i, INT_MAX);
	while (Q--) {
		int t; cin >> t;
		if (t == 0) {
			int l, r; long long v;
			cin >> l >> r >> v;
			sgt.update(l, r, v);
		} else if (t == 1) {
			int l, r; 
			cin >> l >> r;
			cout << sgt.query(l, r) << '\n';
		}
	}
}