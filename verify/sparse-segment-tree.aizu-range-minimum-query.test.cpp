#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"

#include <bits/stdc++.h>
using namespace std;

#include "data-structure/sparse-segment-tree.hpp"

int main() {
	int N, Q;
	cin >> N >> Q;

	struct stinfo {
		using T = long long;
		const T dval = LLONG_MAX;
		void apply(T &a, T b) { a = b; }
		T merge(T a, T b) { return min(a, b); }
	};

	Segtree<stinfo> sgt(N);
	sgt.reserve(N * 4);
	for (int i = 0; i < N; i++)
		sgt.update(i, INT_MAX);
	while (Q--) {
		int t; cin >> t;
		if (t == 0) {
			int i; long long v;
			cin >> i >> v;
			sgt.update(i, v);
		} else if (t == 1) {
			int l, r;
			cin >> l >> r;
			cout << sgt.query(l, r) << '\n';
		}
	}
}