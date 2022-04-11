#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"

#include <bits/stdc++.h>
using namespace std;

#include "utility/floor-div.hpp"

int main() {
	int TC;
	cin >> TC;
	while (TC--) {
		long long a, b;
		cin >> a >> b;
		cout << a + b << '\n';
		assert(b == 0 || floor_div(a, b) == a / b);
	}
}