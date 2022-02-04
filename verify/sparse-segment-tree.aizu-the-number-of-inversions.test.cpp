#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D"

#include <bits/stdc++.h>
using namespace std;

#include "data-structure/sparse-segment-tree.hpp"

const int MAX = 1e9 + 5;

int main() {
	int N;
	cin >> N;

	struct stinfo {
		using T = int;
		const T dval = 0;
		T merge(T a, T b) { return a + b; }
		void apply(T &a, T b) { a += b; }
	};

	long long ans = 0;
	Segtree<stinfo> sgt(MAX);
	sgt.reserve(N * 30);
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		ans += sgt.query(a, MAX - 1);
		sgt.update(a, 1);
	}
	cout << ans << '\n';
}