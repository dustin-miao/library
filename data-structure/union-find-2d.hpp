#include "data-structure/union-find.hpp"

struct UnionFind2d {
	int n, m;
	UnionFind dsu;

	UnionFind2d() = default;

	UnionFind2d(int _n, int _m) { init(_n, _m); }

	void init(int _n, int _m) { 
		n = _n, m = _m;
		dsu.init(n * m); 
	}

	int find(int ui, int uj) { return dsu.find(ui * m + uj); }

	bool merge(int ui, int uj, int vi, int vj) { return dsu.merge(ui * m + uj, vi * m + vj); }
};

