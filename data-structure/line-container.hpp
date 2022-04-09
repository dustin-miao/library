#include "utility/floor-div.hpp"

struct line_container_line {
    mutable long long m, b, p;
    bool operator<(const Line &o) const { return m < o.m; }
    bool operator<(long long x) const { return p < x; }
};

class line_container : multiset<line_container_line, less<>> {
    // for doubles, use inf = 1/.0
    static const long long INF = LLONG_MAX;

    bool isect(iterator x, iterator y) {
        if (y == end()) {
			x->p = INF;
			return false;
		}
        if (x->m == y->m)
            x->p = x->b > y->b ? INF : -INF;
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