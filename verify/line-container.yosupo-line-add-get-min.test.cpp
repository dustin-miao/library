#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include <bits/stdc++.h>
using namespace std;

#include "geometry/line-container.hpp"

int main() {
	int N, Q;
	cin >> N >> Q;
	line_container lc;
	for (int i = 0; i < N; i++) {
		long long m, b;
		cin >> m >> b;
		lc.add(-m, -b);
	}
	while (Q--) {
		int t; cin >> t;
		if (t == 0) {
			long long m, b;
			cin >> m >> b;
			lc.add(-m, -b);
		} else if (t == 1) {
			long long x;
			cin >> x;
			cout << -lc.query(x) << '\n';
		}
	}
}