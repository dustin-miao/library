#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"

#include <bits/stdc++.h>
using namespace std;

#include "utility/fast-pow.hpp"

const long long MOD = 1e9 + 7;

int main() {
	long long M, N;
	cin >> M >> N;
	cout << fast_pow(M, N, MOD) << '\n';
}