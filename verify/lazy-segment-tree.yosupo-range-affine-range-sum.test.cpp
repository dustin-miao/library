#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include <bits/stdc++.h>
using namespace std;

#include "utility/mint.hpp"
#include "data-structure/lazy-segment-tree.hpp"

int main() {
	MOD = 998244353;

	int N, Q; 
	cin >> N >> Q;
	
	struct segment_tree_template {
		using node_type = mint;
		using lazy_type = pair<mint, mint>;

		const node_type node_default_value = 0;
		const lazy_type lazy_default_value = {1, 0};

		void apply(node_type &a, lazy_type &b, lazy_type c, int l, int r) {
			a = c.first * a + c.second * (r - l + 1);
			b = {c.first * b.first, c.first * b.second + c.second};
		}	

		node_type merge(node_type a, node_type b) { return a + b; }
	};
	
	lazy_segment_tree<segment_tree_template> sgt(N);
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