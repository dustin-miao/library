#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include <bits/stdc++.h>
using namespace std;

#include "string/z.hpp"

int main() {
	string S;
	cin >> S;
	auto z = str::z(S);
	z[0] = S.size();
	for (int x : z)
		cout << x << ' ';
	cout << '\n';
}