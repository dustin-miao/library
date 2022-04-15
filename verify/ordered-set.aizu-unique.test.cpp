#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_4_D"

#include <bits/stdc++.h>
using namespace std;

#include "data-structure/ordered-set.hpp"

int main() {
	int N;
	cin >> N;
	ordered_set<int> S;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		S.insert(a);
	}
	for (int a : S)
		cout << a << ' ';
	cout << '\n';
}