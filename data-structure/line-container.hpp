#include "utility/floor-div.hpp"

struct Line {
    mutable long long m, b, p;
    bool operator<(const Line &o) const { return m < o.m; }
    bool operator<(long long x) const { return p < x; }
};

class LineContainer : multiset<Line, less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    static const long long inf = INT_MAX;

    bool isect(iterator x, iterator y) {
        if (y == end()) {
			x->p = inf;
			return false;
		}
        if (x->m == y->m)
            x->p = x->b > y->b ? inf : -inf;
        else
            x->p = floor_div(y->b - x->b, x->m - y->m);
        return x->p >= y->p;
    }

public:
    void add(long long m, long long b) {
        auto z = insert({m, b, 0}), y = z++, x = y;
        while (isect(y, z)) 
            z = erase(z);
        if (x != begin() && isect(--x, y)) 
            isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p) 
            isect(x, erase(y));
    }

    long long query(long long x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.m * x + l.b;
    }
};