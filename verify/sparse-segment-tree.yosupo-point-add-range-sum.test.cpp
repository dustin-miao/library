#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <bits/stdc++.h>
using namespace std;

#include "data-structure/sparse-segment-tree.hpp"

int main() {
	int N, Q;
	cin >> N >> Q;

	struct segment_tree_template {
		using type = long long;
		const type default_value = 0;
		void apply(type &a, type b) { a += b; }
		type merge(type a, type b) { return a + b; }
	};

	sparse_segment_tree<segment_tree_template> sgt(N);
	sgt.reserve(N * 4);
	for (int i = 0; i < N; i++) {
		long long a; cin >> a;
		sgt.update(i, a);
	}
	while (Q--) {
		int t; cin >> t;
		if (t == 0) {
			int p; long long x;
			cin >> p >> x;
			sgt.update(p, x);
		} else {
			int l, r;
			cin >> l >> r;
			cout << sgt.query(l, r - 1) << '\n';
		}
	}
}