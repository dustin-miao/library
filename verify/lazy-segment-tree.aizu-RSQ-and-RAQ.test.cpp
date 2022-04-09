#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

#include <bits/stdc++.h>
using namespace std;

#include "data-structure/lazy-segment-tree.hpp"

int main() {
	int N, Q;
	cin >> N >> Q;

	struct segment_tree_template {
		using node_type = long long;
		using lazy_type = long long;

		const node_type node_default_value = 0;
		const lazy_type lazy_default_value = 0;

		void apply(node_type &a, lazy_type &b, lazy_type c, int l, int r) {
			a += c * (r - l + 1);
			b += c;
		}

		node_type merge(node_type a, node_type b) { return a + b; }
	};

	lazy_segment_tree<segment_tree_template> sgt(N + 1);
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