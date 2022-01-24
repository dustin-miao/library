#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"

#include <bits/stdc++.h>
using namespace std;

#include "graph/kruskal.hpp"

int main() {
	int N, M;
	cin >> N >> M;
	vector<tuple<int, int, long long>> E;
	for (int i = 0; i < M; i++) {
		int u, v; long long w;
		cin >> u >> v >> w;
		E.emplace_back(u, v, w);
	}
	cout << kruskal(N, E) << '\n';
}