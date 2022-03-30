#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C"

#include <bits/stdc++.h>
using namespace std;

#include "geometry/point.hpp"

using namespace geo;

int main() {
	cout << fixed << setprecision(10);
	point<double> p0, p1; 
	cin >> p0.x >> p0.y >> p1.x >> p1.y;

	int Q;
	cin >> Q;
	while (Q--) {
		point<double> p2;
		cin >> p2.x >> p2.y;
		auto p = p1 - p0, q = p2 - p0;
		auto c = p ^ q;
		if (c > 0) {
			cout << "COUNTER_CLOCKWISE\n";
		} else if (c < 0) {
			cout << "CLOCKWISE\n";
		} else {
			if (p * q >= 0) {
				if (abs(p) < abs(q)) 
					cout << "ONLINE_FRONT\n";
				else 
					cout << "ON_SEGMENT\n";
			} else {
				cout << "ONLINE_BACK\n";
			}
		}
	}
}