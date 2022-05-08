#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include <bits/stdc++.h>
using namespace std;

#include "data-structure/wavelet-tree.hpp"
#include "random/mersenne-twister.hpp"
#include "random/random-vector.hpp"

int main() {
	{
		int N = 10000, L = 300, Q = 10000;
		vector<int> A = rng_vector(N, 0, L);
		vector<int> B(A);
		wavelet_tree wt(B.begin(), B.end(), 0, L);
		while (Q--) {
			int t = rng(0, 1);
			if (t == 0) {
				int l = rng(0, N - 1), r = rng(0, N - 1), k = rng(0, L);
				if (r < l)
					swap(l, r);
				int ret = 0;
				for (int i = l; i <= r; i++)
					if (A[i] <= k)
						ret++;
				assert(ret == wt.cnt_leq(l, r, k));
			} else if (t == 1) {
				int l = rng(0, N - 1), r = rng(0, N - 1), k = rng(0, L);
				if (r < l)
					swap(l, r);
				int ret = 0;
				for (int i = l; i <= r; i++)
					if (A[i] == k)
						ret++;
				assert(ret == wt.cnt_eq(l, r, k));
			}
		}
	}

	int A, B;
	cin >> A >> B;
	cout << A + B << '\n';
}