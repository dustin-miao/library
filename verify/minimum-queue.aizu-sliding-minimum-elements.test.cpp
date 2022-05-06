#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D"

#include <bits/stdc++.h>
using namespace std;

#include "data-structure/minimum-queue.hpp"

int main() {
	int N, L;
	cin >> N >> L;
	minimum_queue<int> q;
	for (int i = 0; i < L - 1; i++) {
		int a;
		cin >> a;
		q.push(a);
	}
	for (int i = L - 1; i < N; i++) {
		int a;
		cin >> a;
		q.push(a);
		assert(q.size() == L);
		cout << q.query() << " \n"[i == N - 1];
		q.pop();
	}
}