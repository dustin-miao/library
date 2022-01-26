#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <bits/stdc++.h>
using namespace std;

#include "data-structure/binary-index-tree.hpp"

const int MAX = 5e5 + 5;

int main() {
	int N, Q;
  	cin >> N >> Q;
	Fentree<long long> bit(N);
  	for (int i = 0; i < N; i++) {
		long long a; cin >> a;
		bit.update(i + 1, a);
	}
  	while (Q--) {
		int t; cin >> t;
		if (t == 0) {
	  		int p; long long x;
	  		cin >> p >> x;
	  		bit.update(p + 1, x);
		} else {
	  		int l, r;
	  		cin >> l >> r;
	  		cout << bit.query(l + 1, r) << '\n';
		}
  	}
}
