#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include <bits/stdc++.h>
using namespace std;

#include "data-structure/wavelet-tree.hpp"

int main() {
	int N, Q;
	cin >> N >> Q;
	vector<int> A(N);
	map<int, int> M;
	for (int &a : A) {
		cin >> a;
		M[a] = 0;
	}
	int c = 0;
	for (auto &[k, v] : M)
		v = c++;
	vector<int> I(c);
	for (auto [k, v] : M)
		I[v] = k;
	for (int &a : A)
		a = M[a];
	
	wavelet_tree wt(A.begin(), A.end(), 0, c);
	while (Q--) {
		int l, r, k;
		cin >> l >> r >> k;
		cout << I[wt.quantile(l, r - 1, k)] << '\n';
	}
}