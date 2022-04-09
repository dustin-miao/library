#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D"

#include <bits/stdc++.h>
using namespace std;

#include "data-structure/sparse-segment-tree.hpp"

const int MAX = 1e9 + 5;

int main() {
	int N;
	cin >> N;

	struct segment_tree_template {
		using type = int;
		const type default_value = 0;
		type merge(type a, type b) { return a + b; }
		void apply(type &a, type b) { a += b; }
	};

	long long ans = 0;
	sparse_segment_tree<segment_tree_template> sgt(MAX);
	sgt.reserve(N * 30);
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		ans += sgt.query(a, MAX - 1);
		sgt.update(a, 1);
	}
	cout << ans << '\n';
}