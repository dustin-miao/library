#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include <bits/stdc++.h>
using namespace std;

#include "string/hash.hpp"

int main() {
	string T, P;
	cin >> T >> P;
	str::hash A(T), B(P);
	for (int i = 0; i + P.size() - 1 < T.size(); i++) 
		if (A(i, i + P.size() - 1) == B())
			cout << i << '\n';
}