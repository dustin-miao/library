#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include <bits/stdc++.h>
using namespace std;

#include "utility/zip.hpp"
#include "random/mersenne-twister.hpp"
#include "random/random-vector.hpp"

int main() {
	{
		int N = rng<int>(1e5, 1e6);
		vector<int> A = rng_vector<int>(N, 0, 1e9), B = rng_vector<int>(N, 0, 1e9), C(N);
		for (auto &&[a, b, c] : zip(A, B, C)) 
			c = a + b;
		for (int i = 0; i < N; i++)
			assert(C[i] == A[i] + B[i]);
	}

	int A, B;
	cin >> A >> B;
	cout << A + B << '\n';
}