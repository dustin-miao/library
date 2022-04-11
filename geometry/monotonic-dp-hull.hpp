#include "geometry/point.hpp"

struct monotonic_dp_hull {
	long long prev_x = LLONG_MIN, prev_y = 1;
	deque<geo::point<long long>> points;
 
	void insert(const geo::point<long long> &p) {
		assert(points.empty() || p.x >= points.back().x);
		if (!points.empty() && p.x == points.back().x) {
			if (p.y <= points.back().y)
				return;
			points.pop_back();
		}
		while (size() >= 2 && ((points.back() - p) ^ (points[size() - 2] - points.back())) <= 0)
			points.pop_back();
		points.push_back(p);
	}

	void insert(long long a, long long b) { insert(geo::point(a, b)); }

	long long query(long long x, long long y = 1) {
		assert(size() > 0);
		assert(prev_x == LLONG_MIN || x * prev_y >= prev_x * y);
		prev_x = x, prev_y = y;
		while (size() >= 2 && x * (points[1].x - points[0].x) >= (points[0].y - points[1].y) * y)
			points.pop_front();
		return points[0].x * x + points[0].y * y;
	}

	void clear() { points.clear(); prev_x = LLONG_MIN, prev_y = 1; }

	int size() const { return points.size(); }
};