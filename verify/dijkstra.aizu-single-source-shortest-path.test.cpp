#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include <bits/stdc++.h>
using namespace std;

#include "graph/dijkstra.hpp"

int main() {
	int N, M, S;
	cin >> N >> M >> S;
	vector<vector<pair<int, long long>>> G(N);
	for (int i = 0; i < M; i++) {
		int u, v; long long w;
		cin >> u >> v >> w;
		G[u].emplace_back(v, w);
	}
	
	auto [dis, par] = dijkstra(G, S);

	for (int i = 0; i < N; i++) {
		if (par[i] == -1)
			cout << "INF\n";
		else 
			cout << dis[i] << '\n';
	}
}