#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include <bits/stdc++.h>
using namespace std;

#include "graph/dijkstra.hpp"

int main() {
	int N, M, S, T;
	cin >> N >> M >> S >> T;
	vector<vector<pair<int, long long>>> G(N);
	for (int i = 0; i < M; i++) {
		int u, v; long long w;
		cin >> u >> v >> w;
		G[u].emplace_back(v, w);
	}
	
	auto [dis, par] = graph::dijkstra(G, S);

	if (par[T] == -1) {
		cout << -1 << '\n';
		return 0;
	}

	vector<int> path;
	for (int u = T; u != S; u = par[u])
		path.push_back(u);
	path.push_back(S);
	reverse(path.begin(), path.end());

	cout << dis[T] << ' ' << path.size() - 1 << '\n';
	for (int i = 1; i < path.size(); i++)
		cout << path[i - 1] << ' ' << path[i] << '\n';
}