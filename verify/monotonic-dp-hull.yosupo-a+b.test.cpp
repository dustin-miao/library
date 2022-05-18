#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include <bits/stdc++.h>
using namespace std;

#include "geometry/line-container.hpp"
#include "geometry/monotonic-dp-hull.hpp"
#include "random/random-int-vector.hpp"

int main() {
	{
		int T = 2e5;
		auto slope = rng::rivec<long long>(T, -1e6, 1e6), intercept = rng::rivec<long long>(T, -1e9, 1e9);
		auto x_coord = rng::rivec<long long>(5 * T, -1e6, 1e6);

		sort(slope.begin(), slope.end());
		sort(x_coord.begin(), x_coord.end());

		line_container lc;
		monotonic_dp_hull mdh;
		for (int tc = 0; tc < T; tc++) {
			lc.add(slope[tc], intercept[tc]);
			mdh.add(slope[tc], intercept[tc]);
			for (int i = tc * 5; i < (tc + 1) * 5; i++) 
				assert(lc.query(x_coord[i]) == mdh.query(x_coord[i]));
		}
	}

	long long A, B;
	cin >> A >> B;
	cout << A + B << '\n';
}