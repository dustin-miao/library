#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include <bits/stdc++.h>
using namespace std;

#include "string/z.hpp"

int main() {
	string T, P;
	cin >> T >> P;
	string S = P + '#' + T;
	auto z = str::z(S);
	for (int i = 0; i < T.size(); i++)
		if (z[i + P.size() + 1] == P.size())
			cout << i << '\n';
}