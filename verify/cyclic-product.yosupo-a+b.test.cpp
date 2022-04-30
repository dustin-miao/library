#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include <bits/stdc++.h>
using namespace std;

#include "convolution/cyclic-product.hpp"
#include "random/random-vector.hpp"

const int N = 5e4;

int main() { 
	{
		vector<long long> A = rng_vector<long long>(N, 1, 1e5);
		vector<long long> B = rng_vector<long long>(N, 1, 1e5);
		auto C = conv::cyclic_product(A, B);
		B.insert(B.end(), B.begin(), B.end());
		for (int i = 0; i < N; i++) {
			long long cur = 0;
			for (int j = 0; j < N; j++)
				cur += A[j] * B[i + j];
			assert(cur == C[i]);
		}
	}

	int A, B;
	cin >> A >> B;
	cout << A + B << '\n';
}