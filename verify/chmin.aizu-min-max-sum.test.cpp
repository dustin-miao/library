#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_4_D"

#include <bits/stdc++.h>
using namespace std;

#include "utility/chmax.hpp"
#include "utility/chmin.hpp"

int main() {
	int N;
	cin >> N;
	long long mn = LLONG_MAX, mx = LLONG_MIN, sum = 0;
	for (int i = 0; i < N; i++) {
		long long a;
		cin >> a;
		chmin(mn, a);
		chmax(mx, a);
		sum += a;
	}
	cout << mn << ' ' << mx << ' ' << sum << '\n';
}