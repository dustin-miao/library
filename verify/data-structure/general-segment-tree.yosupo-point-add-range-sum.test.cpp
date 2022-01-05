#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <bits/stdc++.h>
using namespace std;

#include "data-structure/general-segment-tree.hpp"

const int MAX = 5e5 + 5;

int N, Q;
long long A[MAX];

auto sgt_merge = [](long long a, long long b) { return a + b; };
auto sgt_apply = [](long long &a, long long b) { return a += b; };
segtree<long long, decltype(sgt_merge), decltype(sgt_apply)> sgt(sgt_merge, sgt_apply);

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