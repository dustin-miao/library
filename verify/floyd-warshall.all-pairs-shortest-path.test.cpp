#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"

#include <bits/stdc++.h>
using namespace std;

#include "graph/floyd-warshall.hpp"

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<long long>> G(N, vector<long long>(N, LLONG_MAX));
	for (int i = 0; i < M; i++) {
		int u, v; long long w;
		cin >> u >> v >> w;
		G[u][v] = w;
	}
	for (int i = 0; i < N; i++)
		G[i][i] = 0;

	floyd_warshall(G);

	bool cycle = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (G[i][j] == -LLONG_MAX)
				cycle = 1;
	if (cycle) {
		cout << "NEGATIVE CYCLE\n";
		return 0;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (G[i][j] == LLONG_MAX)
				cout << "INF";
			else 
				cout << G[i][j];
			cout << " \n"[j == N - 1];
		}
	}
}