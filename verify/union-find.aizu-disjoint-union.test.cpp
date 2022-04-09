#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A"

#include <bits/stdc++.h>
using namespace std;

#include "data-structure/union-find.hpp"

int main() {
	int N, Q;
  	cin >> N >> Q;
	union_find dsu(N);
  	while (Q--) {
    	int t, u, v;
    	cin >> t >> u >> v;
		if (t == 0)
	      	dsu.merge(u, v);
    	else
      		cout << (dsu.find(u) == dsu.find(v) ? 1 : 0) << '\n';
  	}
}
