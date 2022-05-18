#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include <bits/stdc++.h>
using namespace std;

#include "utility/zip.hpp"
#include "random/random-int.hpp"
#include "random/random-int-vector.hpp"

int main() {
	{
		int N = rng::rint<int>(1e5, 1e6);
		vector<int> A = rng::rivec<int>(N, 0, 1e9), B = rng::rivec<int>(N, 0, 1e9), C(N);
		for (auto &&[a, b, c] : zip(A, B, C)) 
			c = a + b;
		for (int i = 0; i < N; i++)
			assert(C[i] == A[i] + B[i]);
	}

	int A, B;
	cin >> A >> B;
	cout << A + B << '\n';
}