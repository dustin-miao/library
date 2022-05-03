#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include <bits/stdc++.h>
using namespace std;

#include "tree/diameter.hpp"
#include "tree/parent.hpp"
#include "tree/unweight.hpp"

int main() {
	int N;
	cin >> N;
	vector<vector<pair<int, long long>>> T(N);
	for (int i = 1; i < N; i++) {
		int u, v;
		long long w;
		cin >> u >> v >> w;
		T[u].emplace_back(v, w);
		T[v].emplace_back(u, w);
	}

	auto [e1, e2, d] = tree::diameter(T);
	auto par = tree::parent(tree::unweight(T), e1);

	vector<int> ans;
	for (int u = e2; u != e1; u = par[u]) 
		ans.push_back(u);
	ans.push_back(e1);

	cout << d << ' ' << ans.size() << '\n';
	for (int u : ans)
		cout << u << ' ';
	cout << '\n';
}