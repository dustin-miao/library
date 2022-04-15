#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D"

#include <bits/stdc++.h>
using namespace std;

#include "utility/ordered-set.hpp"

int main() {
	int N;
	cin >> N;
	long long ans = 0;
	ordered_set<int> s;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		ans += i - s.order_of_key(a);
		s.insert(a);
	}
	cout << ans << '\n';
}