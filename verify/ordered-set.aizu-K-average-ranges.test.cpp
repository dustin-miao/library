#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3117"

#include <bits/stdc++.h>
using namespace std;

#include "data-structure/ordered-set.hpp"

int main() {
	int N;
	long long K;
	cin >> N >> K;
	vector<long long> A(N);
	for (auto &a : A) {
		cin >> a;
		a -= K;
	}

	ordered_set<pair<long long, int>> S;
	long long sum = 0, ans = 0;
	S.insert(make_pair(sum, -1));
	for (int i = 0; i < N; i++) {
		sum += A[i];
		S.insert(make_pair(sum, i));
		ans += S.order_of_key(make_pair(sum, i));
	}
	cout << ans << '\n';
}