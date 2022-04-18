#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_A"

#include <bits/stdc++.h>
using namespace std;

#include "math/matrix.hpp"

int main() {
	long long N;
	cin >> N;
	if (N == 0) {
		cout << 0 << '\n';
	} else {
		matrix<long long> expo(2);
		expo[0][0] = expo[0][1] = expo[1][0] = 1, expo[1][1] = 0;
		vector<long long> base = {1, 1};
		cout << (fast_pow(expo, N - 1) * base)[0] << '\n';
	}
}