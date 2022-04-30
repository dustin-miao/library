#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_4_B"

#include <bits/stdc++.h>
using namespace std;

#include "utility/pi.hpp"

int main() {
	long double r;
	cin >> r;
	cout << fixed << setprecision(10) << PI * r * r << ' ' << 2 * PI * r << '\n';
}