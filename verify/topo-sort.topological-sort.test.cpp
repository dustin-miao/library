#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B"

#include <bits/stdc++.h>
using namespace std;

#include "graph/topo-sort.hpp"

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> G(N);
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
	}
	auto ord = topo_sort(G);
	for (int u : ord)
		cout << u << '\n';
}