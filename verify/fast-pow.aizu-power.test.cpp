#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"

#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

#include "utility/fast-pow.hpp"

int main() {
	long long N, M;
	cin >> N >> M;
	cout << fast_pow(N, M, MOD) << '\n';
}