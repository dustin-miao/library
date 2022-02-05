#include "data-structure/fenwick-tree.hpp"

template<typename T>
class Kciwtree : public Fentree<T> {
	using Fentree<T>::update;
public:
	Kciwtree() : Fentree<T>() {};

	Kciwtree(size_t _n) : Fentree<T>(_n) {}

	void update(int l, int r, T v) {
		update(l, v); 
		update(r + 1, -v);
	}

	using Fentree<T>::query;

	T operator[](int i) { return query(i); }
};