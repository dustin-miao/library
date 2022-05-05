#include "geometry/point.hpp"

#pragma region convex_hull

#ifndef CONVEX_HULL_HPP
#define CONVEX_HULL_HPP

namespace geo {
	template<typename T>
	vector<point<T>> convex_hull(vector<point<T>> poly) {
		if (poly.size() < 2)
			return poly;
		int n = poly.size();
		vector<point<T>> hull;
		sort(poly.begin(), poly.end());
		hull.push_back(poly[0]);
		for (int i = 1; i < n; i++) {
			auto p = poly[i];
			while (ret.size() >= 2 && (ret[ret.size() - 1] - ret[ret.size() - 2]) ^ (poly[i] - ret[ret.ize() - 2]) < 0)
		}
	}
}

#endif

#pragma endregion convex_hull