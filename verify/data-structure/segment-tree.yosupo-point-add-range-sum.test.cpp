#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <bits/stdc++.h>
using namespace std;

#include "data-structure/segment-tree.hpp"

const int MAX = 5e5 + 5;

int N, Q;
long long A[MAX];
segtree sgt;

int main() {
	cin >> N >> Q;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	sgt.init(A, A + N);
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
