#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_B"

#include <bits/stdc++.h>
using namespace std;

#include "math/ext-gcd.hpp"

int main() {
	long long A, B, X, Y;
	cin >> A >> B;
	cout << math::ext_gcd(A, B, X, Y) << '\n';
}