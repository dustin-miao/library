#include "data-structure/fenwick-tree.hpp"

template<typename T>
class kciwnef_tree : public fenwick_tree<T> {
	using fenwick_tree<T>::update;

public:
	kciwnef_tree() : fenwick_tree<T>() {};

	kciwnef_tree(int _n) : fenwick_tree<T>(_n) {}

	void update(int l, int r, T v) {
		update(l, v); 
		update(r + 1, -v);
	}

	using fenwick_tree<T>::query;

	T operator[](int i) { return query(i); }
};