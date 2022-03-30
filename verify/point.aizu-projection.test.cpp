#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A"

#include <bits/stdc++.h>
using namespace std;

#include "geometry/point.hpp"

using namespace geo;

int main() {
	point<double> p1, p2; 
	cin >> p1.x >> p1.y >> p2.x >> p2.y;
	auto q = p2 - p1;

	int Q;
	cin >> Q;
	cout << fixed << setprecision(10);
	while (Q--) {
		point<double> p;
		cin >> p.x >> p.y;
		p -= p1;
		auto r = p1 + p * q / abs(q) * q;
		cout << r.x << ' ' << r.y << '\n';
	}
}