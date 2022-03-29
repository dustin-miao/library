#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"

#include <bits/stdc++.h>
using namespace std;

#include "graph/cycle-finding.hpp"

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> G(N);
	map<pair<int, int>, vector<int>> id;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		id[{u, v}].push_back(i);
	}

	auto cycle = find_cycle(G);

	if (cycle.empty()) {
		cout << -1 << '\n';
	} else {
		cout << cycle.size() << '\n';
		for (auto [u, v] : cycle) {
			auto &vec = id[{u, v}];
			cout << vec.back() << '\n';
			vec.pop_back();
		}
	}
}