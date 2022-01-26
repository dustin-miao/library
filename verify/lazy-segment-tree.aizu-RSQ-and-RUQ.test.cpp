#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I"

#include <bits/stdc++.h>
using namespace std;

#include "data-structure/lazy-segment-tree.hpp"

int main() {
	int N, Q;
	cin >> N >> Q;

	struct stinfo {
		using T = long long;
		using L = long long;

		const T Tdval = 0;
		const L Ldval = LLONG_MAX;

		void apply(T &a, L &b, L c, int l, int r) {
			a = c * (r - l + 1);
			b = c;
		}

		T merge(T a, T b) { return a + b; }
	};

	Segtree<stinfo> sgt(N);
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