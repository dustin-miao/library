#include "geometry/monotonic-dp-hull.hpp"

#pragma region monotonic_dp_hull_minkowski_sum

#ifndef MONOTONIC_DP_HULL_MINKOWSKI_SUM_HPP
#define MONOTONIC_DP_HULL_MINKOWSKI_SUM_HPP

monotonic_dp_hull minkowski_sum(const monotonic_dp_hull &h1, const monotonic_dp_hull &h2) {
	assert(h1.size() > 0 && h2.size() > 0);
	monotonic_dp_hull sum;
	for (int i = 0, j = 0; i < h1.size() - 1 || j < h2.size() - 1;) {
		sum.add(h1.points[i] + h2.points[j]);
		if (i == h1.size() - 1) {
			j++;
			continue;
		}
		if (j == h2.size() - 1) {
			i++;
			continue;
		}
 
		auto d1 = h1.points[i + 1] - h1.points[i];
		auto d2 = h2.points[j + 1] - h2.points[j];
		if ((d2 ^ d1) > 0)
			i++;
		else
			j++;
	}
	sum.add(h1.points.back() + h2.points.back());
	return sum;
}

#endif

#pragma endregion monotonic_dp_hull_minkowski_sum