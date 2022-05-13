#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"

#include <bits/stdc++.h>
using namespace std;

#include "graph/prim.hpp"

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<pair<int, long long>>> G(N);
	for (int i = 0; i < M; i++) {
		int u, v; long long w;
		cin >> u >> v >> w;
		G[u].emplace_back(v, w);
		G[v].emplace_back(u, w);
	}
	auto T = graph::prim(G);
	long long ans = 0;
	for (int u = 0; u < N; u++)
		for (auto [v, w] : T[u])
			ans += w;
	cout << ans / 2 << '\n';
}