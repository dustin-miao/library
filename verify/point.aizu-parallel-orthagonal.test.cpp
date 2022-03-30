#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A"

#include <bits/stdc++.h>
using namespace std;

#include "geometry/point.hpp"

using namespace geo;

int main() {
	int Q;
	cin >> Q;
	while (Q--) {
		point<double> p1, p2, q1, q2;
		cin >> p1.x >> p1.y >> p2.x >> p2.y >> q1.x >> q1.y >> q2.x >> q2.y;
		auto p = p2 - p1, q = q2 - q1;
		if (abs(p ^ q) <= EPS)
			cout << 2 << '\n';
		else if (abs(p * q) <= EPS)
			cout << 1 << '\n';
		else 
			cout << 0 << '\n';
	}
}