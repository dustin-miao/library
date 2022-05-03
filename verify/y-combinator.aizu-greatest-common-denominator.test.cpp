#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_B"

#include <bits/stdc++.h>
using namespace std;

#include "utility/y-combinator.hpp"

int main() {
	long long A, B; 
	cin >> A >> B;

	auto gcd_test = y_combinator([](auto gcd_test, long long a, long long b) -> long long { 
		return b == 0 ? a : gcd_test(b, a % b); 
	});
	
	cout << gcd_test(A, B) << endl;
}