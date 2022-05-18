#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include <bits/stdc++.h>
using namespace std;

#include "string/pi.hpp"

int main() {
	string T, P;
	cin >> T >> P;
	string S = P + '#' + T;
	auto pi = str::pi(S);
	for (int i = 0; i + 2 * P.size() < S.size(); i++)
		if (pi[i + 2 * P.size()] == P.size())
			cout << i << '\n';
}