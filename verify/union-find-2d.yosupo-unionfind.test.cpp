#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <bits/stdc++.h>
using namespace std;

#include "data-structure/union-find-2d.hpp"

int main() {
	int N, Q;
  	cin >> N >> Q;
	UnionFind2d dsu(1, N);
  	while (Q--) {
    	int t, u, v;
    	cin >> t >> u >> v;
		if (t == 0)
	      	dsu.merge(0, u, 0, v);
    	else
      		cout << (dsu.find(0, u) == dsu.find(0, v) ? 1 : 0) << '\n';
  	}
}
