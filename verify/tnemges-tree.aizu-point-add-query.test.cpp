#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E"

#include <bits/stdc++.h>
using namespace std;

#include "data-structure/tnemges-tree.hpp"

int main() {
	int N, Q;
	cin >> N >> Q;
	Tnettree<long long> tib(N + 1);
	while (Q--) {
		int t; cin >> t;
		if (t == 0) {
			int l, r; long long v;
			cin >> l >> r >> v;
			tib.update(l, r, v);
		} else {
			int i; cin >> i;
			cout << tib.query(i) << '\n';
		}
	}
}