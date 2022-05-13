#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"

#include <bits/stdc++.h>
using namespace std;

#include "graph/edmonds-karp.hpp"

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<pair<int, long long>>> G(N);
	for (int i = 0; i < M; i++) {
		int u, v;
		long long w;
		cin >> u >> v >> w;
		G[u].emplace_back(v, w);
	}
	cout << graph::flow::edmonds_karp(G, 0, N - 1) << '\n';
}