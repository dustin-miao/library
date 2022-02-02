#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"

#include <bits/stdc++.h>
using namespace std;

#include "graph/floyd-warshall.hpp"

int main() {
	int N, M;
	cin >> N >> M;
	matgraph<long long> G(N, vector<long long>(N, LLONG_MAX));
	for (int i = 0; i < M; i++) {
		int u, v; long long w;
		cin >> u >> v >> w;
		G[u][v] = w;
	}

	floyd_warshall(G, LLONG_MAX); 

	bool cycle = false;
	for (int i = 0; i < N; i++)
		if (G[i][i] < 0)
			cycle = true;
	
	if (cycle) {
		cout << "NEGATIVE CYCLE\n";
	} else {
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
}