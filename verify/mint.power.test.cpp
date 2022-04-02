#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"

#include <bits/stdc++.h>
using namespace std;

#include "utility/mint.hpp"

int main() {
	MOD = 1e9 + 7;

	mint N; int M;
	cin >> N >> M;
	cout << fast_pow(N, M) << '\n';
}