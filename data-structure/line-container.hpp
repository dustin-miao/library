#include "utility/floor-div.hpp"

bool __LINE_COMPARE__;

struct Line {
	mutable long long m, b, p;
	bool operator<(const Line &l) const { return __LINE_COMPARE__ ? p < l.p : m < l.m; }
};

class LineContainer : multiset<Line> {
	bool intersect(iterator x, iterator y) {
		if (y == end()) { 
			x->p = LLONG_MAX; 
			return false; 
		}
		if (x->m == y->m) 
			x->p = x->b > y->b ? LLONG_MAX : LLONG_MIN;
		else 
			x->p = floor_div(y->b - x->b, x->m - y->m);
		return x->p >= y->p;
	}

public:
	void add(long long m, long long b) {
		auto z = insert({m, b, 0}), y = z++, x = y;
		while (intersect(y, z)) 
			z = erase(z);
		if (x != begin() && intersect(--x, y)) 
			intersect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			intersect(x, erase(y));
	}
	
	long long query(long long x) {
		assert(!empty());
		__LINE_COMPARE__ = true; 
		auto l = *lower_bound({0, 0, x}); 
		__LINE_COMPARE__ = false;
		return l.m * x + l.b;
	}
};