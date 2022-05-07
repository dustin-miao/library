#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include <bits/stdc++.h>
using namespace std;

#include "tree/euler-tour.hpp"
#include "data-structure/static-segment-tree.hpp"

int main() {
	int N, Q;
	cin >> N >> Q;
	vector<long long> A(N);
	for (auto &a : A)
		cin >> a;
	vector<vector<int>> T(N);
	for (int i = 1; i < N; i++) {
		int p;
		cin >> p;
		T[p].push_back(i);
	}

	auto [ltime, rtime] = tree::euler_tour(T);

	sta_segment_tree st(N);
	for (int u = 0; u < N; u++)
		st.update(ltime[u], A[u]);
	while (Q--) {
		int t;
		cin >> t;
		if (t == 0) {
			int u;
			long long x;
			cin >> u >> x;
			st.update(ltime[u], x);
		} else if (t == 1) {
			int u;
			cin >> u;
			cout << st.query(ltime[u], rtime[u]) << '\n';
		}
	}

}