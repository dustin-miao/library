#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"

#include <bits/stdc++.h>
using namespace std;

#include "math/ext-gcd.hpp"

int main() {
	long long a, b;
	cin >> a >> b;
	long long x, y;
	math::ext_gcd(a, b, x, y);
	cout << x << ' ' << y << '\n';
}