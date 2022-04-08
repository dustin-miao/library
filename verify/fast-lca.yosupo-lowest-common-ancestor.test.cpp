#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include <bits/stdc++.h>
using namespace std;

#include "data-structure/fast-lca.hpp"

int main() {
	int N, Q;
	cin >> N >> Q;
	vector<vector<int>> T(N);
	for (int i = 1; i < N; i++) {
		int p;
		cin >> p;
		T[p].push_back(i);
	}
	LowestCommonAncestor lca(T);
	while (Q--) {
		int u, v;
		cin >> u >> v;
		cout << lca(u, v) << '\n';
	}
}