#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include <bits/stdc++.h>
using namespace std;

#include "convolution/convolution-mod.hpp"

int main() {
	int N, M;
	cin >> N >> M;
	vector<long long> A(N), B(M);
	for (long long &a : A)
		cin >> a;
	for (long long &b : B)
		cin >> b;
	auto C = conv::convolution_mod<long long, long double>(A, B, 998244353);
	for (long long c : C)
		cout << c << ' ';
	cout << '\n';
}