#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include <bits/stdc++.h>
using namespace std;

#include "data-structure/segment-tree.hpp"

int main() {
	int N, Q;
	cin >> N >> Q;

	struct segment_tree_template {
		using type = long long;
		const type default_value = 0;
		void apply(type &a, type b) { a += b; }
		type merge(type a, type b) { return a + b; }
	};

	segment_tree<segment_tree_template> sgt(N + 1);
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