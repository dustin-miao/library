#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <bits/stdc++.h>
using namespace std;

#include "data-structure/sparse-table.hpp"

int main() {
	int N, Q;
	cin >> N >> Q;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	sparse_table<int> st(A.begin(), A.end());
	while (Q--) {
		int l, r;
		cin >> l >> r;
		cout << st.query(l, r - 1) << '\n';
	}
}
