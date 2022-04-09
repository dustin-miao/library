#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A"

#include <bits/stdc++.h>
using namespace std;

#include "data-structure/union-find-2d.hpp"

int main() {
	int N, Q;
  	cin >> N >> Q;
	union_find_2d dsu(1, N);
  	while (Q--) {
    	int t, u, v;
    	cin >> t >> u >> v;
		if (t == 0)
	      	dsu.merge(0, u, 0, v);
    	else
      		cout << (dsu.find(0, u) == dsu.find(0, v) ? 1 : 0) << '\n';
  	}
}
