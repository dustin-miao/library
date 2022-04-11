#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"

#include <bits/stdc++.h>
using namespace std;

#include "utility/ceil-div.hpp"

int main() {
	int TC;
	cin >> TC;
	while (TC--) {
		long long a, b;
		cin >> a >> b;
		cout << a + b << '\n';
		assert(b == 0 || ceil_div(a, b) == (a % b == 0 ? a / b : a / b + 1));
	}
}