#define PROBLEM "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"

#include <bits/stdc++.h>
using namespace std;

#include "slow-convolution/convolution.hpp"

int main() {
	int N;
	cin >> N;
	vector<vector<int>> T(N);
	for (int i = 1; i < N; i++) {
		int u, v;
		cin >> u >> v;
		T[u].push_back(v);
		T[v].push_back(u);
	}

	vector<long long> weight(N), ans(2 * N, 0);
	vector<bool> block(N, false);

	const auto init_weights = [&](const auto &self, int u, int p = -1) -> int {
		weight[u] = 1;
		for (int v : T[u]) {
			if (v == p)
				continue;
			if (!block[v])
				weight[u] += self(self, v, u);
		}
		return weight[u];
	};
 
	const auto find_centroid = [&](const auto &self, int n, int u, int p = -1) -> int {
		for (int v : T[u]) {
			if (v == p)
				continue;
			if (!block[v] && weight[v] * 2 > n)
				return self(self, n, v, u);
		}
		return u;
	};

	vector<long long> cen_dis, cen_cur;

	const auto get_max_depth = [&](const auto &self, int u, int p = -1) -> int {
		int ret = 0;
		for (int v : T[u]) {
			if (v == p)
				continue;
			if (!block[v])
				ret = max(ret, self(self, v, u));
		}
		return ret + 1;
	};

	const auto dfs_child = [&](const auto &self, int u, int p, int d) -> void {
		cen_cur[d]++;
		for (int v : T[u]) {
			if (v == p)
				continue;
			if (!block[v])
				self(self, v, u, d + 1);
		}
	};

	const auto centroid_decomp = [&](const auto &self, int u) -> void {
		u = find_centroid(find_centroid, init_weights(init_weights, u), u);
		int n = get_max_depth(get_max_depth, u);

		cen_dis.assign(n, 0);
		cen_cur.resize(n);
		cen_dis[0]++;
		for (int v : T[u]) {
			if (block[v])
				continue;
			fill(cen_cur.begin(), cen_cur.end(), 0);
			dfs_child(dfs_child, v, u, 1);
			auto tem = conv::convolution(cen_dis, cen_cur);
			for (int i = 0; i < tem.size(); i++)
				ans[i] += tem[i];
			for (int i = 0; i < n; i++)
				cen_dis[i] += cen_cur[i];
		}
 
		block[u] = true;
		for (int v : T[u]) 
			if (!block[v]) 
				self(self, v);
	};

	centroid_decomp(centroid_decomp, 0);

	for (int i = 1; i < N; i++)
		cout << ans[i] << ' ';
	cout << '\n';
}

