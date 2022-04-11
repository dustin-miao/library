#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include <bits/stdc++.h>
using namespace std;

#include "utility/mint.hpp"
#include "data-structure/general-segment-tree.hpp"

int main() {
	MOD = 998244353;

	int N, Q;
	cin >> N >> Q;

	struct segment_tree_template {
		struct node { mint a, b; };
		using type = node;
		const type default_value = {1, 0};
		void apply(type &a, type b) { a = b; }
		type merge(type a, type b) { return {a.a * b.a, b.a * a.b + b.b}; }
	};

	gen_segment_tree<segment_tree_template> sgt(N);
	for (int i = 0; i < N; i++) {
		long long a, b; 
		cin >> a >> b;
		sgt.update(i, {a, b});
	}

	while (Q--) {
		int t; cin >> t;
		if (t == 0) {
			int p; long long c, d;
			cin >> p >> c >> d;
			sgt.update(p, {c, d});
		} else {
			int l, r; long long x;
			cin >> l >> r >> x;
			auto [a, b] = sgt.query(l, r - 1);
			cout << a * x + b << '\n';
		}
	}
}