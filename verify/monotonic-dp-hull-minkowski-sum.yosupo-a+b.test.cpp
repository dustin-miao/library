#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include <bits/stdc++.h>
using namespace std;

#include "geometry/monotonic-dp-hull.hpp"
#include "geometry/monotonic-dp-hull-minkowski-sum.hpp"
#include "random/random-int-vector.hpp"

int main() {
	{
		int T = 1e6;
		auto slope1 = rng::rivec<long long>(T, -1e6, 1e6), intercept1 = rng::rivec<long long>(T, -1e9, 1e9);
		auto slope2 = rng::rivec<long long>(T, -1e6, 1e6), intercept2 = rng::rivec<long long>(T, -1e9, 1e9);
		sort(slope1.begin(), slope1.end());
		sort(slope2.begin(), slope2.end());
		monotonic_dp_hull a, b;
		for (int i = 0; i < T; i++)
			a.add(slope1[i], intercept1[i]);
		for (int i = 0; i < T; i++)
			b.add(slope2[i], intercept2[i]);
		monotonic_dp_hull c = minkowski_sum(a, b);

		auto x_coord = rng::rivec<long long>(T, -1e6, 1e6);
		sort(x_coord.begin(), x_coord.end());

		for (int x : x_coord)
			assert(c.query(x) == a.query(x) + b.query(x));
	}

	int A, B;
	cin >> A >> B;
	cout << A + B << '\n';
}