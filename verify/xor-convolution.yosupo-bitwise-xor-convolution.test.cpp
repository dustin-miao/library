#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_xor_convolution"

#include <bits/stdc++.h>
using namespace std;

#include "convolution/xor-convolution.hpp"
#include "utility/mint.hpp"

int main() {
	MOD = 998244353;

	int N;
	cin >> N;
	vector<mint> A(1 << N), B(1 << N);
	for (auto &a : A)
		cin >> a;
	for (auto &b : B)
		cin >> b;
	auto C = conv::xor_convolution(A, B);
	for (int i = 0; i < (1 << N); i++)
		cout << C[i] << ' ';
	cout << '\n';
}