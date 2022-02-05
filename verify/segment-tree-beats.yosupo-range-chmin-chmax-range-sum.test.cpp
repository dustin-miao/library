#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

#include <bits/stdc++.h>
using namespace std;

#include "data-structure/segment-tree-beats.hpp"

int main() {
	int N, Q;
	cin >> N >> Q;
	SegtreeBeats stb(N);
	for (int i = 0; i < N; i++) {
		long long a; cin >> a;
		stb.update_add(i, i, a);
	}
	while (Q--) {
		int t; cin >> t;
		if (t == 0) {
			int l, r; long long v;
			cin >> l >> r >> v;
			stb.update_chmin(l, r - 1, v);
		} else if (t == 1) {
			int l, r; long long v;
			cin >> l >> r >> v;
			stb.update_chmax(l, r - 1, v);
		} else if (t == 2) {
			int l, r; long long v;
			cin >> l >> r >> v;
			stb.update_add(l, r - 1, v);
		} else if (t == 3) {
			int l, r;
			cin >> l >> r;
			cout << stb.query(l, r - 1) << '\n';
		}	
	}
}