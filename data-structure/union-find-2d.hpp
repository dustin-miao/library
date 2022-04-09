#include "data-structure/union-find.hpp"

struct union_find_2d {
	int n, m;
	union_find dsu;

	union_find_2d() = default;

	union_find_2d(int _n, int _m) { init(_n, _m); }

	void init(int _n, int _m) { 
		n = _n, m = _m;
		dsu.init(n * m); 
	}

	int find(int ui, int uj) { return dsu.find(ui * m + uj); }

	bool merge(int ui, int uj, int vi, int vj) { return dsu.merge(ui * m + uj, vi * m + vj); }
};

